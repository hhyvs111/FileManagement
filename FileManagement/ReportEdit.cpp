#include "ReportEdit.h"
#include "MyMessageBox.h"

ReportEdit::ReportEdit(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ReportEdit)
{
	ui->setupUi(this);
	connect(tcp, SIGNAL(sendDataToReportEdit(QString)), this, SLOT(receiveDataFromClient(QString)));

	//setFixedSize(500, 500);
	init();
}

ReportEdit::~ReportEdit()
{
	delete ui;
}

void ReportEdit::init()
{
	//初始化，现在还没想好放点什么，就放点数据吧。

}

void ReportEdit::sendReportEdit()
{
	//每次打开该页面则发查询信息发过去
	QString data = "QueryReporter#" + globalUserName;   //查询所有的文件
	QByteArray datasend = data.toUtf8();
	qDebug() << datasend;
	tcp->tcpSocket->write(datasend);

	//暂时取消TCP原本的验证消息
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	connect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(showReporter()));
}


//从服务器接收报告人的信息，就是登录者的信息
void ReportEdit::showReporter()
{
	QByteArray dataread = tcp->tcpSocket->readAll();
	QString data = QString::fromUtf8(dataread);
	qDebug() << "the data from client: " << dataread;

	//有些东西是空的
	QStringList reportInfoList = data.split("#");
	//这个就是初始化了，从服务端收到登录用户的信息
	reportInfo.reportName = reportInfoList[0];
	reportInfo.reportNumber = reportInfoList[1];
	reportInfo.reportLevel = reportInfoList[2];
	reportInfo.reportTeacher = reportInfoList[3];
	reportInfo.reportUserId = reportInfoList[4];
	//reportInfo.reportTerm = reportInfoList[4];
	//reportInfo.reportWeek = reportInfoList[5];
	//reportInfo.reportMain = reportInfoList[6];
	//reportInfo.reportQuestionForSolve = reportInfoList[7];
	//reportInfo.reportQuestionFromLastWeek = reportInfoList[8];
	//reportInfo.reportQuestionHasSolved = reportInfoList[9];
	//reportInfo.reportYourGet = reportInfoList[10];
	//reportInfo.reportUserId = reportInfoList[11];

	ui->reportName->setText(reportInfo.reportName);
	ui->reportName->setEnabled(false);
	ui->reportName->setFocusPolicy(Qt::NoFocus);

	ui->reportNumber->setText(reportInfo.reportNumber);
	ui->reportNumber->setEnabled(false);
	ui->reportNumber->setFocusPolicy(Qt::NoFocus);

	ui->reportLevel->setText(reportInfo.reportLevel);
	ui->reportLevel->setEnabled(false);
	ui->reportLevel->setFocusPolicy(Qt::NoFocus);

	ui->reportTeacher->setText(reportInfo.reportTeacher);
	ui->reportTeacher->setEnabled(false);
	ui->reportTeacher->setFocusPolicy(Qt::NoFocus);

	//周数自己设置吧
	//ui->reportTerm->setEditText(reportInfo.reportTerm);
	//ui->reportWeek->setText(reportInfo.reportWeek);


	//这个一般是空，先注释掉吧
	/*ui->reportMainPlainTextEdit->setPlainText(reportInfo.reportMain);
	ui->reportQuestionForSolve->setPlainText(reportInfo.reportQuestionForSolve);
	ui->reportQuestionFromLastWeek->setPlainText(reportInfo.reportQuestionForSolve);
	ui->reportQuestionHasSolved->setPlainText(reportInfo.reportQuestionHasSolved);
	ui->reportYourGet->setPlainText(reportInfo.reportYourGet);
*/

	//用后断开
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(showReporter()));
	connect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
}

//就是判断服务器给的数据，就是一个槽函数？
void ReportEdit::receiveDataFromClient(QString data)
{
	if (QString::compare(data, "submit_T") == 0)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("提交周报成功！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);

	}
	else if (QString::compare(data, "submit_F") == 0)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("提交周报失败！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}
}

//点击提交按钮
void ReportEdit::ClickSubmit()
{
	//ui->reportMainPlainTextEdit->toPlainText()这个就是QString类型的
	if (ui->reportMainPlainTextEdit->toPlainText().isEmpty()
		|| ui->reportQuestionForSolve->toPlainText().isEmpty()
		|| ui->reportQuestionFromLastWeek->toPlainText().isEmpty()
		|| ui->reportQuestionHasSolved->toPlainText().isEmpty()
		|| ui->reportYourGet->toPlainText().isEmpty())
	{
		qDebug() << "there are some null";
		//如果有为空则提醒
		QString messageReminder;
		if (ui->reportMainPlainTextEdit->toPlainText().isEmpty())
		{
			messageReminder = QString::fromLocal8Bit("学习内容");
			ui->reportMainPlainTextEdit->setFocus();

		}
		if (ui->reportQuestionForSolve->toPlainText().isEmpty())
		{
			messageReminder = QString::fromLocal8Bit("遇到的问题");
			ui->reportQuestionForSolve->setFocus();

		}
		if (ui->reportQuestionFromLastWeek->toPlainText().isEmpty())
		{
			messageReminder = QString::fromLocal8Bit("上周的问题");
			ui->reportQuestionFromLastWeek->setFocus();

		}
		if (ui->reportQuestionHasSolved->toPlainText().isEmpty())
		{
			messageReminder = QString::fromLocal8Bit("解决的问题");
			ui->reportQuestionHasSolved->setFocus();

		}
		if (ui->reportYourGet->toPlainText().isEmpty())
		{
			messageReminder = QString::fromLocal8Bit("学习心得");
			ui->reportYourGet->setFocus();

		}
		//提示确定以及返回
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("%1不能为空!").arg(messageReminder),
			MESSAGE_QUESTION, BUTTON_OK_AND_CANCEL, true);
	}
	else
	{
		qDebug() << "send report!";
		sendReport();
	}
}

void ReportEdit::sendReport()
{

	QString bs = "sendReport";

	//获取当前界面设置的学期和周数
	reportInfo.reportTerm = ui->reportTerm->currentText();
	reportInfo.reportWeek = ui->reportWeek->currentText();
	reportInfo.reportMain = ui->reportMainPlainTextEdit->toPlainText();
	reportInfo.reportQuestionForSolve = ui->reportQuestionForSolve->toPlainText();
	reportInfo.reportQuestionFromLastWeek = ui->reportQuestionFromLastWeek->toPlainText();
	reportInfo.reportQuestionHasSolved = ui->reportQuestionHasSolved->toPlainText();
	reportInfo.reportYourGet = ui->reportYourGet->toPlainText();

	QString data = bs + "#" + reportInfo.reportUserId + "#" + 
		reportInfo.reportTerm + "#" + reportInfo.reportWeek + "#" + reportInfo.reportMain
		+ "#"+ reportInfo.reportQuestionForSolve
		+ "#"+ reportInfo.reportQuestionFromLastWeek + "#" + reportInfo.reportQuestionHasSolved
		+ "#"+ reportInfo.reportYourGet;

	QByteArray datasend = data.toUtf8();
	if (tcp->tcpSocket->write(datasend))
	{
		qDebug() << "send data to server: " << data;
		/*MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("提交成功!"),
			MESSAGE_QUESTION, BUTTON_OK_AND_CANCEL, true);*/
	}
	else
	{
		qDebug() << "send failed!";
		/*MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("提交失败!"),
			MESSAGE_QUESTION, BUTTON_OK_AND_CANCEL, true);*/
	}

}
