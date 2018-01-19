#pragma once
#ifndef DOWNLOADFILE_H_
#define DOWNLOADFILE_H_
#include "stdafx.h"
#include "ui_DownloadFile.h"
#include <QFile>  
#include <QString> 
#include <QStandardItemModel>
extern TcpClient * tcp;
extern QString globalUserName;


struct FileInfo
{
	int fileId;
	QString fileName;
	QString fileSize;
	QString fileType;
	int userId;
};
class DownloadFile : public QWidget
{
	Q_OBJECT

public:
	explicit DownloadFile(QWidget *parent = 0);
	~DownloadFile();

	//发送查看该用户所上传文件的信息给服务器
	void sendFileInfo();

private:
	Ui::DownloadFile *ui;

	//QTcpSocket *tcpClient;
	QTime downloadTime;
	QFile *newFile;
	QByteArray inBlock;
	QString fileName;
	QString saveFileName;   //这个是路径？？还是直接是文件名？

	QString openFileName;  //直接打开的文件名
	qint64 RtotalSize;  //总共需要发送的文件大小（文件内容&文件名信息）  
	qint64 byteReceived;  //已经接收的大小  
	int receiveTime;	//接受的次数
	QStandardItemModel *model;
	QPushButton *mDownloadButton;


private slots:

	void receiveFile();  //从服务器下载文件到本地。
						 //void send();  //传送文件头信息  
						 //void goOnSend(qint64);  //传送文件内容 

	void ClickDownloadButton();
	void saveFilePath(QString);   //选择下载路径
	void showFileInfo();

	//void ClickSendButton();
	//void receiveMainwindow();

signals:
	void sendDisconnect(QString);

};
#endif // !DOWNLOADFILE_H_

