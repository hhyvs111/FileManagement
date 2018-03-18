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
	DownloadThread(QString,QString,int,bool, QObject *parent = 0);
	DownloadThread(int,QString,QString, qint64, qint64,int, bool, QObject *parent = 0);
	~DownloadThread();
	void run();
	DownloadFile *downloadFile;  // 先定义一个DownloadFile
private:
	QString fileName;
	int index;
	QString filePath;  //文件路径
	int fileId;
	qint64 breakPoint;
	bool keepOn;  //断点下载还是初始下载
	qint64 recordId;
	private slots:
	void quitThread();   //退出线程

signals:
	void ThreadClosed(int);  //给主窗口发送线程关闭信号
	void downloadAvailable(int);
};

#endif // !DOWNLOADTHREAD_H_



