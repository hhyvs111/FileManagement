#include "UploadThread.h"

UploadThread::UploadThread(QString mFileName,int num, QObject *parent):
	QThread(parent)
{
	fileName = mFileName;
	index = num;
	//qDebug() <<num<< "gouzao Worker Thread : " << QThread::currentThreadId();
	//
}


UploadThread::~UploadThread()
{
	//requestInterruption();
	quit();
	wait();
	//qDebug() << "the uploadThread has closed,the id is: " << currentThreadId();
}

void UploadThread::run()
{
	while (!isInterruptionRequested())
	{
		//msleep(50);
		uploadFile = new UploadFile(fileName, index);
		//qDebug() << index << "run Worker Thread : " << QThread::currentThreadId();
		emit sendAvailable(index);
		exec();
	}
	
	
	//uploadFile->sender();
	//// ºÄÊ±²Ù×÷

}


