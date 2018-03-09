#include "DownloadThread.h"

DownloadThread::DownloadThread(QString mFileName,QString mFilePath ,int num, QObject *parent) :
	QThread(parent)
{
	fileName = mFileName;
	filePath = mFilePath;
	index = num;
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
	downloadFile = new DownloadFile(fileName,filePath,index);
}