#include "tcpclient.h"
#include "MyMessageBox.h"
//#include "ui_tcpclient.h"

#define ip "47.100.160.51"
#define port 3389
//#define ip "47.100.160.51"
//#define port 4000



TcpClient::TcpClient(QObject *parent) :
	QObject(parent)
   
{
    init();
    connectServer();
}

TcpClient::~TcpClient()
{
	
}

void TcpClient::init()
{
    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayError(QAbstractSocket::SocketError)));   //发生错误时执行displayError函数
}

void TcpClient::connectServer()
{
    tcpSocket->abort();   //取消已有的连接
	tcpSocket->connectToHost(ip, port);
	connect(tcpSocket, SIGNAL(connected()), this, SLOT(displayError1()));
	
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessages()));
}

void TcpClient::displayError1()
{
	qDebug() << "the server is connected!";
}

void TcpClient::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString();   //输出出错信息
}


void TcpClient::readMessages()
{
    QString data=tcpSocket->readAll();
	qDebug() << "it is in client the data from server: " << data;
    QStringList list=data.split("#");
	if (list[0] == "L" && list[1] == "true")
	{
		emit sendDataToLogin("T");	//将验证信息发给LOGIN
		qDebug() << "login is T";
		//MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("登录成功！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}
	else if (list[0] == "L" && list[1] == "false")
	{
		emit sendDataToLogin("F");	//将验证信息发给LOGIN
		qDebug() << "login is F";
		//MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("用户名或密码不不正确！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}

	else if (list[0] == "R" && list[1] == "true")
	{
		emit sendDataToRegister("R_T");
		qDebug() << "R is T";
	}
	else if (list[0] == "R"&& list[1] == "false")
	{
		emit sendDataToRegister("R_F");
		qDebug() << "R is F";
	}
	else if (list[0] == "RCU" && list[1] == "true")
	{
		emit sendDataToRegister("RCU_T");
		qDebug() << "RCU is T";
	}
	else if (list[0] == "RCU" && list[1] == "false")
	{
		emit sendDataToRegister("RCU_F");
		qDebug() << "RCU is F";
	}

    else
        return ;
}

