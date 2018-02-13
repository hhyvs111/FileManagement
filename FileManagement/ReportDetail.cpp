#include "ReportDetail.h"
#include "MyMessageBox.h"


ReportDetail::ReportDetail(QString reportId,QWidget *parent) :
	BaseWindow(parent),
	ui(new Ui::ReportDetail)
{
	ui->setupUi(this);

	
	connect(tcp, SIGNAL(sendDataToReportDetail(QString)), this, SLOT(receiveDataFromClient(QString)));
	


	//刚打开的时候要选点击按钮时候所在行的ID的报告
	sendReportDetail(reportId);
	init();
	//setFixedSize(700, 500); // 禁止改变窗口大小
	//initTitleBar();
}

ReportDetail::~ReportDetail()
{
	delete ui;
}

void ReportDetail::init()
{
	loadStyleSheet("ReportDetail");
	//设置为只读模式
	ui->reportMainPlainTextEdit->setReadOnly(true);
	ui->reportQuestionForSolve->setReadOnly(true);
	ui->reportQuestionFromLastWeek->setReadOnly(true);
	ui->reportQuestionHasSolved->setReadOnly(true);
	ui->reportYourGet->setReadOnly(true);

	QPalette Pal(palette());
	// set black background
	Pal.setColor(QPalette::Background, Qt::green);
	this->setAutoFillBackground(true);
	this->setPalette(Pal);
	this->raise();

}
//
//void ReportDetail::initTitleBar()
//{
//	m_titleBar->move(1, 2);
//	m_titleBar->raise();
//	m_titleBar->setWindowBorderWidth(2);
//	m_titleBar->setBackgroundColor(138, 109, 53);
//	m_titleBar->setButtonType(MIN_BUTTON);
//	m_titleBar->setTitleWidth(this->width());
//}


void ReportDetail::sendReportDetail(QString reportId)
{
	//每次打开该页面则发查询信息发过去
	QString data = "lookReport#reportId#" + reportId;   //查询报告人
	QByteArray datasend = data.toUtf8();
	qDebug() << datasend;
	tcp->tcpSocket->write(datasend);

	//暂时取消TCP原本的验证消息
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	connect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(showReport()));
}

void ReportDetail::showReport()
{
	QByteArray dataread = tcp->tcpSocket->readAll();
	QString data = QString::fromUtf8(dataread);
	qDebug() << "the data from client: " << data;

	//有些东西是空的
	QStringList reportInfoList = data.split("#");
	//这个就是初始化了，从服务端收到登录用户的信息
	reportInfo.reportId = reportInfoList[0];  //ID不需要显示
	reportInfo.reportUserName = reportInfoList[1];
	reportInfo.reportTerm = reportInfoList[2];
	reportInfo.reportWeek = reportInfoList[3];
	reportInfo.reportMain = reportInfoList[4];
	reportInfo.reportTime = reportInfoList[5];
	reportInfo.reportName = reportInfoList[6];
	reportInfo.reportQuestionForSolve = reportInfoList[7];
	reportInfo.reportQuestionHasSolved = reportInfoList[8];
	reportInfo.reportQuestionFromLastWeek = reportInfoList[9];
	reportInfo.reportYourGet = reportInfoList[10];
	reportInfo.reportUserId = reportInfoList[11].toInt();  //这个也不需要显示


	//设置界面标题，XX,XX学期第几周的周报
	ui->reporterDetail->setText(QString::fromLocal8Bit("%1,%2学期第%3周周报").arg(reportInfo.reportName)
		.arg(reportInfo.reportTerm).arg(reportInfo.reportWeek));
	ui->reportTime->setText(reportInfo.reportTime);

	//设置正文，要弄成不可修改的那种

	ui->reportMainPlainTextEdit->setPlainText(reportInfo.reportMain);
	ui->reportQuestionForSolve->setPlainText(reportInfo.reportQuestionForSolve);
	ui->reportQuestionFromLastWeek->setPlainText(reportInfo.reportQuestionFromLastWeek);
	ui->reportQuestionHasSolved->setPlainText(reportInfo.reportQuestionHasSolved);
	ui->reportYourGet->setPlainText(reportInfo.reportYourGet);
	
	//用后断开
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(showReport()));
	connect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
}


void ReportDetail::receiveDataFromClient(QString data)
{

}
//点击删除按钮，暂时不要
void ReportDetail::ClickDeleteButton()
{

}
//修改按钮，也暂时不要
void ReportDetail::ClickUpdateButton()
{

}