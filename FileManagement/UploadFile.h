#pragma once
#ifndef UPLOADFILE_H  
#define UPLOADFILE_H   
#include "stdafx.h"
#include <QWidget>  
#include <QFile>  
#include <QTime>
#include <QTGui>
#include <string>  

#include "ui_UploadFile.h"


extern TcpClient * tcp;
extern QString globalUserName;
class UploadFile : public QWidget
{
	Q_OBJECT

public:
	explicit UploadFile(QWidget *parent = 0);
	~UploadFile();

private:
	Ui::UploadFile *ui;

	//QTcpSocket *tcpClient;

	QFile *localFile;
	QString fileName;  //文件名  
	QTime sendTime;  //发送时间
	QByteArray outBlock;  //分次传  
	qint64 loadSize;  //每次发送数据的大小  
	qint64 byteToWrite;  //剩余数据大小  
	qint64 totalSize;  //文件总大小  
	
	//获取文件的图标
	QIcon fileIcon(const QString &extension) const;
	//获取文件的类型？
	QString fileType(const QString &extension) const;

	void init();
	int sendTimes;  //用来标记是否为第一次发送，第一次以后连接信号触发，后面的则手动调用  

	void initFile();
	// 加载样式文件;
	void loadStyleSheet(const QString &sheetName);
	// 文件拖放功能实现
	void dragEnterEvent(QDragEnterEvent* event = NULL);
	void dropEvent(QDropEvent* event = NULL);

	void setFileIcon(QString);  //将后缀放进去

	
private slots:
	void send();  //传送文件头信息  
	void goOnSend(qint64);  //传送文件内容  
	void ClickOpenButton();
	void ClickSendButton();
	void receiveMainwindow();
};

#endif // UPLOADFILE_H  