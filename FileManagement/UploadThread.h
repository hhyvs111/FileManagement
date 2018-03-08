#pragma once
#include "stdafx.h"
#include<QThread>
#include <QTcpSocket>
#include <QtNetwork>
#include <UploadFile.h>
class QTcpSocket;
class UploadThread : QThread
{
	Q_OBJECT
public:
	UploadThread(QString,int, QObject *parent = 0);
	~UploadThread();
	//void run();
	UploadFile * uploadFile;  // 先定义一个UploadFile
private:
	
};

