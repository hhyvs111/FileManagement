#include "tcpclient.h"
#include "MyMessageBox.h"
//#include "ui_tcpclient.h"
//
//#define ip "47.100.160.51"
#define port 3389
#define ip "127.0.0.1"
//#define port 3389



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

//void TcpClient::receiveSignalFromDown(QString msg)
//{
//	if(msg == "disconnect")
//		disconnect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessages()));
//	else
//		connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessages()));
//}
void TcpClient::displayError1()
{
		qDebug() << "the server is connected!";
}

void TcpClient::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString();   //输出出错信息
	MyMessageBox::showMyMessageBox(NULL, QString::fromUtf8("提示"), QString::fromUtf8("网络连接失败!"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
}


void TcpClient::readMessages()
{
    QString data=tcpSocket->readAll();
	qDebug() << "it is in client the data from server: " << data;
	
    QStringList list=data.split("#");

	//验证登陆是否成功
	if (list[0] == "L" )
	{
		if (list[1] == "true")
		{
			emit sendDataToLogin("T");	//将验证信息发给LOGIN
			qDebug() << "login is T";
		}
		else
		{
			emit sendDataToLogin("F");	//将验证信息发给LOGIN
			qDebug() << "login is F";
		}
	}
	//验证是否注册成功
	else if (list[0] == "R")
	{
		if (list[1] == "true")
		{
			emit sendDataToRegister("R_T");
			qDebug() << "R is T";
		}
		else
		{
			emit sendDataToRegister("R_F");
			qDebug() << "R is F";
		}
	}

	//验证用户名重复
	else if (list[0] == "RCU" )
	{
		if (list[1] == "true")
		{
			emit sendDataToRegister("RCU_T");
			qDebug() << "RCU is T";
		}
		else
		{
			emit sendDataToRegister("RCU_F");
			qDebug() << "RCU is F";
		}
	}
	else if (list[0] == "RCS")
	{
		if (list[1] == "true")
		{
			emit sendDataToRegister("RCS_T");
			qDebug() << "RCS is T";
		}
		else
		{
			emit sendDataToRegister("RCS_F");
			qDebug() << "RCS is F";
		}
	}
	else if (list[0] == "updateUserInfo")
	{
		if (list[1] == "true")
		{
			MyMessageBox::showMyMessageBox(NULL, QString::fromUtf8("提示"), QString::fromUtf8("修改成功!"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		}
		else
		{
			MyMessageBox::showMyMessageBox(NULL, QString::fromUtf8("提示"), QString::fromUtf8("修改失败!"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		}
	}
	else if (list[0] == "deleteFile")
	{
		if (list[1] == "true")
		{
			emit sendDataToDownload("delete_T");
			//MyMessageBox::showMyMessageBox(NULL, QString::fromUtf8("提示"), QString::fromUtf8("删除文件成功!"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		}
		else
		{
			emit sendDataToDownload("delete_F");
			//MyMessageBox::showMyMessageBox(NULL, QString::fromUtf8("提示"), QString::fromUtf8("删除文件失败!"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		}
	}
	else if (list[0] == "ReportEdit")
	{
		if (list[1] == "true")
		{
			emit sendDataToReportEdit("submit_T");
		}
		else if (list[1] == "repeatTrue")
		{
			emit sendDataToReportEdit("repeat");
		}
		else
			emit sendDataToReportEdit("submit_F");
	}
	else if (list[0] == "deleteReport")
	{
		if (list[1] == "true")
		{
			emit sendDataToReportLook("delete_T");
		}
		else
		{
			emit sendDataToReportLook("delete_F");
		}
	}

    else
        return ;
}

