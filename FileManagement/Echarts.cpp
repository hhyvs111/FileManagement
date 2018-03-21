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
	connect(ui->send, SIGNAL(clicked()), mChartManager, SLOT(slot1())); //槽函数与网页链接 
}

Echarts::~Echarts()
{
	delete ui;
}

//void Echarts::connects()
//{
// connect(ui->actionSend, SIGNAL(triggered(bool)), mChartManager, SLOT(slotTest()));
//}


void  Echarts::import_excel()
{

	QAxObject *excel = NULL;
	QAxObject *workbooks = NULL;
	QAxObject *workbook = NULL;
	excel = new QAxObject("Excel.Application");
	if (!excel)
	{
		QMessageBox::critical(this, "错误信息", "EXCEL对象丢失");
		return;
	}
	excel->dynamicCall("SetVisible(bool)", false);
	workbooks = excel->querySubObject("WorkBooks");
	QString  str = ui->lineEdit->text();
	const char*  ch;
	QByteArray ba = str.toLatin1();
	ch = ba.data();
	
	workbook = workbooks->querySubObject("Open(QString, QVariant)", QString(tr(ch)));
	QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1);//打开第一个sheet
																		   //QAxObject * worksheet = workbook->querySubObject("WorkSheets");//获取sheets的集合指针
																		   //int intCount = worksheet->property("Count").toInt();//获取sheets的数量

	QAxObject * usedrange = worksheet->querySubObject("UsedRange");//获取该sheet的使用范围对象
	QAxObject * rows = usedrange->querySubObject("Rows");
	QAxObject * columns = usedrange->querySubObject("Columns");
	/*获取行数和列数*/
	int intRowStart = usedrange->property("Row").toInt();
	int intColStart = usedrange->property("Column").toInt();
	int intCols = columns->property("Count").toInt();
	int intRows = rows->property("Count").toInt();
	/*获取excel内容*/


	QString data ;
	QString edata;
	QString qdata;
	QString outdata;
	QString indata;
	QString ddata = "OutcomeAccount#";
	QString adata = "IncomeAccount#";
	for (int i = intRowStart; i < intRowStart + intRows; i++)  //行
	{
		for (int j = intColStart; j < intColStart + intCols; j++)  //列
		{
			QAxObject * cell = worksheet->querySubObject("Cells(int,int)", i, j);  //获取单元格
																				   // qDebug() << i << j << cell->property("Value");         //*****************************出问题!!!!!!
			QAxObject *celt = worksheet->querySubObject("Cells(int,int,)", i, 1); 
			data = cell->dynamicCall("Value2()").toString();
			if (celt->dynamicCall("Value2()").toInt() < 0)
			{	
				ddata +=  data + "#";
			}
			if(celt ->dynamicCall("Value2()").toInt() > 0)
			{
				adata +=  data + "#";
			}
			qDebug() << i << j << cell->dynamicCall("Value2()").toString(); //正确
		
		}
		outdata = ddata + "$";
		indata = adata + "$";
		
		qDebug() << adata;
	}
	outdata=outdata+ globalUserName;
	indata=indata+ globalUserName;
	//tcp->tcpSocket->write(outdata.toUtf8());
	tcp->tcpSocket->write(indata.toUtf8());

	workbook->dynamicCall("Close (Boolean)", false);
	//同样，设置值，也用dynamimcCall("SetValue(const QVariant&)", QVariant(QString("Help!")))这样才成功的。。
	//excel->dynamicCall("Quit (void)");
	delete excel;//一定要记得删除，要不线程中会一直打开excel.exe
}


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
//void Echarts::exportexcel()
//{
//	qDebug() << 1223;
//}
void Echarts::export_excel()
{
	QAxObject excel("Excel.Application");
	excel.setProperty("Visible", true);
	QAxObject *work_books = excel.querySubObject("WorkBooks");
	work_books->dynamicCall("Open(const QString&)", "E:\\test121.xlsx");
	excel.setProperty("Caption", "Qt Excel");
	QAxObject *work_book = excel.querySubObject("ActiveWorkBook");
	QAxObject *work_sheets = work_book->querySubObject("Sheets");  //Sheets也可换用WorkSheets  

																   //删除工作表（删除第一个）  
	QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);
	first_sheet->dynamicCall("delete");

	//插入工作表（插入至最后一行）  
	int sheet_count = work_sheets->property("Count").toInt();  //获取工作表数目  
	QAxObject *last_sheet = work_sheets->querySubObject("Item(int)", sheet_count);
	QAxObject *work_sheet = work_sheets->querySubObject("Add(QVariant)", last_sheet->asVariant());
	last_sheet->dynamicCall("Move(QVariant)", work_sheet->asVariant());

	work_sheet->setProperty("Name", "Qt Sheet");  //设置工作表名称  

												  //操作单元格（第2行第2列）  
	QAxObject *cell = work_sheet->querySubObject("Cells(int,int)", 2, 2);
	cell->setProperty("Value", "Java C++ C# PHP Perl Python Delphi Ruby");  //设置单元格值  
	cell->setProperty("RowHeight", 50);  //设置单元格行高  
	cell->setProperty("ColumnWidth", 30);  //设置单元格列宽  
	cell->setProperty("HorizontalAlignment", -4108); //左对齐（xlLeft）：-4131  居中（xlCenter）：-4108  右对齐（xlRight）：-4152  
	cell->setProperty("VerticalAlignment", -4108);  //上对齐（xlTop）-4160 居中（xlCenter）：-4108  下对齐（xlBottom）：-4107  
	cell->setProperty("WrapText", true);  //内容过多，自动换行  
										  //cell->dynamicCall("ClearContents()");  //清空单元格内容  

	QAxObject* interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(0, 255, 0));   //设置单元格背景色（绿色）  

	QAxObject* border = cell->querySubObject("Borders");
	border->setProperty("Color", QColor(0, 0, 255));   //设置单元格边框色（蓝色）  

	QAxObject *font = cell->querySubObject("Font");  //获取单元格字体  
	font->setProperty("Name", QStringLiteral("华文彩云"));  //设置单元格字体  
	font->setProperty("Bold", true);  //设置单元格字体加粗  
	font->setProperty("Size", 20);  //设置单元格字体大小  
	font->setProperty("Italic", true);  //设置单元格字体斜体  
	font->setProperty("Underline", 2);  //设置单元格下划线  
	font->setProperty("Color", QColor(255, 0, 0));  //设置单元格字体颜色（红色）  

													//设置单元格内容，并合并单元格（第5行第3列-第8行第5列）  
	QAxObject *cell_5_6 = work_sheet->querySubObject("Cells(int,int)", 5, 3);
	cell_5_6->setProperty("Value", "Java");  //设置单元格值  
	QAxObject *cell_8_5 = work_sheet->querySubObject("Cells(int,int)", 8, 5);
	cell_8_5->setProperty("Value", "C++");

	QString merge_cell;
	merge_cell.append(QChar(3 - 1 + 'A'));  //初始列  
	merge_cell.append(QString::number(5));  //初始行  
	merge_cell.append(":");
	merge_cell.append(QChar(5 - 1 + 'A'));  //终止列  
	merge_cell.append(QString::number(8));  //终止行  
	QAxObject *merge_range = work_sheet->querySubObject("Range(const QString&)", merge_cell);
	merge_range->setProperty("HorizontalAlignment", -4108);
	merge_range->setProperty("VerticalAlignment", -4108);
	merge_range->setProperty("WrapText", true);
	merge_range->setProperty("MergeCells", true);  //合并单元格  
												   //merge_range->setProperty("MergeCells", false);  //拆分单元格  

												   //work_book->dynamicCall("Save()");  //保存文件（为了对比test与下面的test2文件，这里不做保存操作） work_book->dynamicCall("SaveAs(const QString&)", "E:\\test2.xlsx");  //另存为另一个文件   
	work_book->dynamicCall("Close(Boolean)", false);  //关闭文件  
	excel.dynamicCall("Quit(void)");  //退出  
}