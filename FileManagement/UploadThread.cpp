#include "UploadThread.h"



UploadThread::UploadThread(QString filename,int index, QObject *parent):
	QThread(parent)
{
	uploadFile = new UploadFile(filename, index);
}


UploadThread::~UploadThread()
{
}
