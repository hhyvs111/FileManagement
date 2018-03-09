#pragma once
#ifndef UPLOADTHREAD_H_
#define UPLOADTHREAD_H_
#include "stdafx.h"
#include <QThread>
#include <QTcpSocket>
#include <QtNetwork>
#include "UploadFile.h"
class QTcpSocket;
class UploadThread : public  QThread
{
	Q_OBJECT
public:
	UploadThread(QString, int, QObject *parent = 0);
	~UploadThread();
	void run();

	UploadFile * uploadFile;  // 先定义一个UploadFile
private:
	QString fileName;
	int index;
	bool sendSignal = false;

private slots:
//void receiveSendSignal();

signals:
	void sendAvailable(int);

};
#endif // !UPLOADTHREAD_H_



