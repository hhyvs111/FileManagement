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
	Q_OBJECT
public:
	explicit UploadFile(QString,int);
	~UploadFile();
	bool isOver = false;

	void send();  //传送文件头信息  
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
	QString currentFileName;

	//void init(QString);
	int sendTimes;  //用来标记是否为第一次发送，第一次以后连接信号触发，后面的则手动调用  

	void initFile();

	int index;  //该类的ID值
	
private slots:
	
	void goOnSend(qint64);  //传送文件内容  
	void receiveSendSignal();  //发送信号

	//void receiveSendSignal();
signals:
	//发送当前数据和总数据
	void sendOver(int);  //发送结束
	void updateProgress(int,qint64, qint64,double);

	
};

#endif // UPLOADFILE_H   