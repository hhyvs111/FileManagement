#ifndef TCPCLIENT_H

#define TCPCLIENT_H

#include <QMainWindow>
#include <QtNetwork>
#include <QMessageBox>
#include <QFile>  
#include <string>  
#include "stdafx.h"
extern QString ip;
extern int port;
namespace Ui {
class TcpClient;
}

class TcpClient : public QObject
{
    Q_OBJECT

public:
    explicit TcpClient(QObject *parent = 0);
    ~TcpClient();
	QTcpSocket *tcpSocket;

protected:
    void init();
    void connectServer();
public slots:

	//读取数据
	void readMessages(); 

private slots:
    //void on_sendBtn_clicked();
    void displayError(QAbstractSocket::SocketError);
    //void on_signBtn_clicked();
	//void sendMeggages();  //发送数据
	void displayError1();
	void reConnectToServer();
	/*void receiveSignalFromDown(QString);*/


signals:
	void sendDataToLogin(QString);
	void sendDataToRegister(QString);
	void sendDataToDownload(QString);
	void sendDataToReportEdit(QString);
	void sendDataToReportLook(QString);
	void sendDataToAccounting(QString);
	void sendDataToSign(QString);
};

#endif // TCPCLIENT_H
