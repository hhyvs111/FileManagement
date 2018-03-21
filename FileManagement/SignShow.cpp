#include "SignShow.h"



SignShow::SignShow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SignShow)
{
	ui->setupUi(this);
	signCalender = new SignCalender();
	ui->webEngineWidget->load(QUrl("qrc:/web/index.html"));
	ui->webEngineWidget->setZoomFactor(0.55);

	QWebChannel *channel = new QWebChannel(ui->webEngineWidget->page());
	channel->registerObject("myObject", signCalender);
	ui->webEngineWidget->page()->setWebChannel(channel);

	signCalender->setProperty("info", signCalender->getInfo());
	qDebug() << signCalender->getInfo();
	connect(this, SIGNAL(sendMySignInfo(QString)), signCalender, SLOT(receiveSignInfo(QString)));
	sendMySignLook();
}


SignShow::~SignShow()
{

}

void SignShow::sendMySignLook()
{
	QString data = "QueryMySign#" + globalUserName;
	tcp->tcpSocket->write(data.toUtf8());
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	connect(tcp->tcpSocket, SIGNAL(readyRead()),this, SLOT(showMySignLook()));
}

void SignShow::showMySignLook()
{
	QByteArray dataread = tcp->tcpSocket->readAll();
	QString data = QString::fromUtf8(dataread);
	qDebug() << data;
	emit sendMySignInfo(data);
	connect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(showMySignLook()));
}