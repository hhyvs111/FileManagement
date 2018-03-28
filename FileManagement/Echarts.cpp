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
#include "AccountInfo.h"
#include "MyMessageBox.h"


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

void Echarts::receiveDataFromMoney(QString data)
{
	dataToExcel = data;
}
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

	MyMessageBox::showMyMessageBox(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("导入成功!"),
		MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);

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
	/*receiveDataFromMoney(QString data);*/
	//QMessageBox::information(NULL, "Title", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	
	QStringList listNumber = dataToExcel.split("$");
	QList<AccountInfo> accountInfo;		//容器中插入同样类型的结构体
	for (int i = 1; i <= listNumber[0].toInt(); i++)
	{
		AccountInfo account;
		QStringList accountList = listNumber[i].split("#");
		qDebug() << accountList;
		account.accountId = accountList[0].toInt();
		account.money = accountList[1].toInt();
		account.type = accountList[2];
		account.time = accountList[3];
		account.remark = accountList[4];
		account.name = accountList[5];
		accountInfo.append(account);
	}
	qDebug() << accountInfo.size()+121312;
	QString filepath = QFileDialog::getSaveFileName(this, tr("Save orbit"), ".", tr("Microsoft Office 2007 (*.xlsx)"));//获取保存路径
	if (!filepath.isEmpty()) {
		QAxObject *excel = new QAxObject(this);
		excel->setControl("Excel.Application");//连接Excel控件
		excel->dynamicCall("SetVisible (bool Visible)", "false");//不显示窗体
		excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示

		QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
		workbooks->dynamicCall("Add");//新建一个工作簿
		QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
		QAxObject *worksheets = workbook->querySubObject("Sheets");//获取工作表集合
		QAxObject *worksheet = worksheets->querySubObject("Item(int)", 1);//获取工作表集合的工作表1，即sheet1

		QAxObject *cellA, *cellB, *cellC, *cellD;

		//设置标题
		
		int cellrow =1;
		qDebug() << accountInfo.size();


		QString A = "A" + QString::number(cellrow);//设置要操作的单元格，如A1
		QString B = "B" + QString::number(cellrow);
		QString C = "C" + QString::number(cellrow);
		QString D = "D" + QString::number(cellrow);
		cellA = worksheet->querySubObject("Range(QVariant, QVariant)", A);//获取单元格
		cellB = worksheet->querySubObject("Range(QVariant, QVariant)", B);
		cellC = worksheet->querySubObject("Range(QVariant, QVariant)", C);
		cellD = worksheet->querySubObject("Range(QVariant, QVariant)", D);
		cellA->dynamicCall("SetValue(const QVariant&)", QVariant("type"));//设置单元格的值
		cellB->dynamicCall("SetValue(const QVariant&)", QVariant("money"));
		cellC->dynamicCall("SetValue(const QVariant&)", QVariant("time"));
		cellD->dynamicCall("SetValue(const QVariant&)", QVariant("remark"));
		cellrow++;

		int rows = accountInfo.size();
		for (int i = 0; i<rows; i++) {
			QString A = "A" + QString::number(cellrow);//设置要操作的单元格，如A1
			QString B = "B" + QString::number(cellrow);
			QString C = "C" + QString::number(cellrow);
			QString D = "D" + QString::number(cellrow);
			cellA = worksheet->querySubObject("Range(QVariant, QVariant)", A);//获取单元格
			cellB = worksheet->querySubObject("Range(QVariant, QVariant)", B);
			cellC = worksheet->querySubObject("Range(QVariant, QVariant)", C);
			cellD = worksheet->querySubObject("Range(QVariant, QVariant)", D);
			cellA->dynamicCall("SetValue(const QVariant&)", QVariant(accountInfo.at(i).type));//设置单元格的值
			cellB->dynamicCall("SetValue(const QVariant&)", QVariant(accountInfo.at(i).money));
			cellC->dynamicCall("SetValue(const QVariant&)", QVariant(accountInfo.at(i).time));
			cellD->dynamicCall("SetValue(const QVariant&)", QVariant(accountInfo.at(i).remark));
			qDebug() << accountInfo.at(i).type;
			cellrow++;
		}
		
		workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filepath));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
		workbook->dynamicCall("Close()");//关闭工作簿
		excel->dynamicCall("Quit()");//关闭excel
		delete excel;
		MyMessageBox::showMyMessageBox(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("导出成功!"),
			MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		excel = NULL;
	}
	
	
}