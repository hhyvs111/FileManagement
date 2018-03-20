#include "Echarts.h"
#include "ui_Echarts.h"
#include "websocketclientwrapper.h"
#include <QWebEngineView>
#include <QWebChannel>
#include <QWebEngineSettings>
#include <QDebug>
#include <QWebSocketServer>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMessageBox>
#include <QFileInfo>
#include <ActiveQt\QAxObject>
#include <ActiveQt\QAxBase>
#include <QFileDialog>
#include <ActiveQt/QAxBase>
#include "previewpage.h"

Echarts::Echarts(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Echarts)
{
	ui->setupUi(this);
	
	mChartManager = new BDChart(this);
	PreviewPage *page = new PreviewPage(this);
	mWebView = new QWebEngineView(this);
	mWebView->setPage(page);
	QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
	QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
	channel = new QWebChannel(mWebView->page());

	channel->registerObject(QStringLiteral("chartManager"), mChartManager); //与页面链接
	mWebView->page()->setWebChannel(channel);
	mWebView->setUrl(QUrl("qrc:/chart/web/html/index.html"));

	ui->verticalLayout->addWidget(mWebView);
	//this->setCentralWidget(mWebView);
	//this->resize(1000,600);
	// connects();
	connect(ui->send, SIGNAL(clicked()), mChartManager, SLOT(slot1())); //槽函数与网页链接 不可发送信号到Echarts 接收到会没有反应
}

Echarts::~Echarts()
{
	delete ui;
}

//void Echarts::connects()
//{
// connect(ui->actionSend, SIGNAL(triggered(bool)), mChartManager, SLOT(slotTest()));
//}
//void  Echarts::importexcel()
//{
//	//QAxObject *excel  = new QAxObject("Excel.Application");
//	//QAxObject *workbooks = new QAxObject();
//	//QAxObject *workbook = new QAxObject();
//	//
//	//if (!excel) { QMessageBox::critical(this, "错误信息", "EXCEL对象丢失"); return; }
//	//excel->dynamicCall("SetVisible(bool)", false);
//	//workbooks = excel->querySubObject("WorkBooks");
//	//workbook = workbooks->querySubObject("Open(QString, QVariant)", QString(tr("g:\BFS.xls"))); QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1);//打开第一个sheet
//	//QAxObject * usedrange = worksheet->querySubObject("UsedRange");//获取该sheet的使用范围对象
//	//QAxObject * rows = usedrange->querySubObject("Rows");
//	//QAxObject * columns = usedrange->querySubObject("Columns");
//	//int intRowStart = usedrange->property("Row").toInt();
//	//int intColStart = usedrange->property("Column").toInt();
//	//int intCols = columns->property("Count").toInt();
//	//int intRows = rows->property("Count").toInt();
//
//	//for (int i = intRowStart; i < intRowStart + intRows; i++) //行 
//	//{
//	//	for (int j = intColStart; j < intColStart + intCols; j++) //列
//	//	{
//	//		QAxObject * range = worksheet->querySubObject("Cells(int,int)", i, j); //获取单元格  
//	//		qDebug() << i << j << range->property("Value"); //************出问题!!!!!!
//	//	}
//	//}
//	QAxObject *excel = NULL;
//	QAxObject *workbooks = NULL;
//	QAxObject *workbook = NULL;
//	excel = new QAxObject("Excel.Application");
//	if (!excel)
//	{
//		QMessageBox::critical(this, "错误信息", "EXCEL对象丢失");
//		return;
//	}
//	excel->dynamicCall("SetVisible(bool)", false);
//	workbooks = excel->querySubObject("WorkBooks");
//	workbook = workbooks->querySubObject("Open(QString, QVariant)", QString(tr("E:\\test.xlsx")));
//	QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1);//打开第一个sheet
//																		   //QAxObject * worksheet = workbook->querySubObject("WorkSheets");//获取sheets的集合指针
//																		   //int intCount = worksheet->property("Count").toInt();//获取sheets的数量
//
//	QAxObject * usedrange = worksheet->querySubObject("UsedRange");//获取该sheet的使用范围对象
//	QAxObject * rows = usedrange->querySubObject("Rows");
//	QAxObject * columns = usedrange->querySubObject("Columns");
//	/*获取行数和列数*/
//	int intRowStart = usedrange->property("Row").toInt();
//	int intColStart = usedrange->property("Column").toInt();
//	int intCols = columns->property("Count").toInt();
//	int intRows = rows->property("Count").toInt();
//	/*获取excel内容*/
//	for (int i = intRowStart; i < intRowStart + intRows; i++)  //行
//	{
//		for (int j = intColStart; j < intColStart + intCols; j++)  //列
//		{
//			QAxObject * cell = worksheet->querySubObject("Cells(int,int)", i, j);  //获取单元格
//																				   // qDebug() << i << j << cell->property("Value");         //*****************************出问题!!!!!!
//			qDebug() << i << j << cell->dynamicCall("Value2()").toString(); //正确
//		}
//	}
//	workbook->dynamicCall("Close (Boolean)", false);
//	//同样，设置值，也用dynamimcCall("SetValue(const QVariant&)", QVariant(QString("Help!")))这样才成功的。。
//	//excel->dynamicCall("Quit (void)");
//	delete excel;//一定要记得删除，要不线程中会一直打开excel.exe
//}

void Echarts::choosefilepath() //选择文件路径
{
	QString file_full, file_name, file_path;
	QFileInfo fi;
	file_full = QFileDialog::getOpenFileName(this);
	fi = QFileInfo(file_full);
	file_name = fi.fileName();
	file_path = fi.absolutePath();
	ui->lineEdit->setText(file_path + "\\" + file_name);

}
void Echarts::exportexcel()
{
	qDebug() << 1223;
}
void Echarts::onimportexcel()
{
	//QAxObject excel("Excel.Application");
	//excel.setProperty("Visible", false);
	//QAxObject *work_books = excel.querySubObject("WorkBooks");
	//work_books->dynamicCall("Open (const QString&)", "E:/test.xlsx");
	//QAxObject *work_book = excel.querySubObject("ActiveWorkBook");
	//QAxObject *work_sheets = work_book->querySubObject("Sheets");  //Sheets也可换用WorkSheets
	//int sheet_count = work_sheets->property("Count").toInt();  //获取工作表数目
	//if (sheet_count > 0)
	//{
	//	QAxObject *work_sheet = work_book->querySubObject("Sheets(int)", 1);
	//	QAxObject *used_range = work_sheet->querySubObject("UsedRange");
	//	QAxObject *rows = used_range->querySubObject("Rows");
	//	int row_count = rows->property("Count").toInt();  //获取行数
	//	QString txt = work_sheet->querySubObject("Cells(int,int)", i, 1)->property("Value").toString(); //获取单元格内容
	//	work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
	//	excel.dynamicCall("Quit(void)");  //退出
	//}
}