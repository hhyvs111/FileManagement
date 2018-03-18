#include "DownloadThread.h"

DownloadThread::DownloadThread(QString mFileName,QString mFilePath ,int num,bool mkeepOn, QObject *parent) :
	QThread(parent)
{
	fileName = mFileName;
	filePath = mFilePath;
	index = num;
	keepOn = mkeepOn;
	qDebug() << "download Thread gou zao :" << currentThreadId();
}
DownloadThread::DownloadThread(int mFileId,QString mFileName,QString mFilePath, qint64 mBreakPoint,qint64 mrecordId, int num, bool mkeepOn, QObject *parent):
	QThread(parent)
{
	fileId = mFileId;
	fileName = mFileName;
	filePath = mFilePath;
	breakPoint = mBreakPoint;
	recordId = mrecordId;
	index = num;
	keepOn = mkeepOn;
}


DownloadThread::~DownloadThread()
{
	requestInterruption();
	quit();
	wait();
	emit ThreadClosed(index);
	qDebug() << "the downloadThread has closed,the id is: " << currentThreadId();
}

void DownloadThread::run()
{
	while (!isInterruptionRequested())
	{
		qDebug() << "download Thread run :" << currentThreadId();
		if (!keepOn)
		{
			qDebug() << "new daaaaaaaaaaaaaaa";
			downloadFile = new DownloadFile(fileName, filePath, index);
		}
		else
		{
			downloadFile = new DownloadFile(fileId,fileName,filePath, breakPoint,recordId, index);
		} 
			emit downloadAvailable(index);  //给window发送一个线程已经开启的信号

		exec();
	}
}

void DownloadThread::quitThread()
{
	//exit();
	//qDebug() << "this Thread is closed!";
	//if (this->wait())
	//{
	//	qDebug() << "this Thread is closed!";
	//}
	this->~DownloadThread();
}