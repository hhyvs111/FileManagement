#pragma once
#ifndef UPLOADFILE_H  
#define UPLOADFILE_H   
#include "stdafx.h"
#include <QObject>  
#include <QFile>  
#include <QTime>
#include <QTGui>
#include <string>  
//extern TcpClient * tcp;
extern QString globalUserName;
extern QString ip;
extern int port;
class UploadFile : public QObject
{
public:
	explicit UploadFile(QFile);
	~UploadFile();

private:

	QTcpSocket *tcpSocket;
	/*QThread *uploadThread;*/

	QFile *localFile;
	QString fileName;  //文件名  
	QTime sendTime;  //发送时间
	QByteArray outBlock;  //分次传  
	qint64 loadSize;  //每次发送数据的大小  
	qint64 byteToWrite;  //剩余数据大小  
	qint64 totalSize;  //文件总大小  
	

	void init();
	int sendTimes;  //用来标记是否为第一次发送，第一次以后连接信号触发，后面的则手动调用  

	void initFile();


	
private slots:
	void send();  //传送文件头信息  
	void goOnSend(qint64);  //传送文件内容  

	void receiveSendSignal();

};

#endif // UPLOADFILE_H  