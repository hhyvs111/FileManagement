#include "Accounting.h"
#include "MyMessageBox.h"

Accounting::Accounting(QWidget *parent) :
	BaseWindow(parent),
	ui(new Ui::Accounting)
{

	ui->setupUi(this);
	ui->outcomeDate->setDateTime(QDateTime::currentDateTime());
	ui->incomeDate->setDateTime(QDateTime::currentDateTime());
	
	connect(tcp, SIGNAL(sendDataToAccounting(QString)), this, SLOT(receiveDataFromClient(QString)));
}


Accounting::~Accounting()
{

}

void Accounting::sendIncomeToServer()
{
	QString data = "IncomeAccount#";
	data += ui->incomeNumber->text() + "#" + ui->incomeType->currentText()
		+ "#" + ui->incomeDate->text() + "#" + ui->incomeRemark->toPlainText() + "#" + globalUserName;
	tcp->tcpSocket->write(data.toUtf8());
}
void Accounting::sendOutcomeToServer()
{
	QString data = "OutcomeAccount#";
	data += ui->outcomeNumber->text() + "#" + ui->outcomeType->currentText() 
		+ "#" + ui->outcomeDate->text() +"#"+ ui->outcomeRemark->toPlainText() + "#" + globalUserName ;
	tcp->tcpSocket->write(data.toUtf8());
}
void Accounting::clickIncomeButton()
{
	sendIncomeToServer();
}
void Accounting::clickOutcomeButton()
{
	sendOutcomeToServer();
}

void Accounting::receiveDataFromClient(QString data)
{
	if (QString::compare(data, "account_T") == 0)
	{
		qDebug() << "account true";
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("记录成功！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);

	}

	else if (QString::compare(data, "account_F") == 0)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("记录失败！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}
}