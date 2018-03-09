#pragma once
#ifndef DOWNLOADTHREAD_H_
#define DOWNLOADTHREAD_H_
#include "stdafx.h"
#include <QThread>
#include <QTcpSocket>
#include <QtNetwork>
#include "DownloadFile.h"
class QTcpSocket;
class DownloadThread : public QThread
{
	Q_OBJECT
public:
	DownloadThread(QString,QString,int, QObject *parent = 0);
	~DownloadThread();
	void run();
	DownloadFile *downloadFile;  // 先定义一个DownloadFile
private:
	QString fileName;
	int index;
	QString filePath;  //文件路径

signals:
	void ThreadClosed(int);  //给主窗口发送线程关闭信号
};

#endif // !DOWNLOADTHREAD_H_



