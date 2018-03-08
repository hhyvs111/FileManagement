#pragma once

#ifndef UPLOADWINDOW_H_
#define UPLOADWINDOW_H_
#include "stdafx.h"
#include <QWidget>  
#include <QFile>  
#include <QTime>
#include <QTGui>
#include <string>  
#include <QStackedLayout>
#include <QFileDialog>
#include <QProgressBar>
#include "UploadFile.h"
#include "ui_UploadWindow.h"
#include "UploadThread.h"
//界面库

extern QString globalUserName;
extern QString ip;
extern int port;
class UploadWindow : public QWidget
{
	Q_OBJECT

public:
	explicit UploadWindow(QWidget *parent = 0);
	~UploadWindow();
	

private:
	Ui::UploadWindow *ui;

	QMap<int, UploadFile*> *uploadFileMap;  //定义一个新的UploadFileMap
	QMap<int, QString> fileNameMap;
	//这里主要是要循环显示
	QMap<int,QProgressBar*> *fileProgressBarMap;  //QString是关键字？
	//QMap<int, QThread*> *uploadQThreadMap;
	QMap<int, UploadThread*> *uploadQThreadMap;
	int index;
	//QProgressBar fileProgressBar[6];  //最多上传5个，进度条是单独的
	QStackedLayout *stackLayout;	//  这个放fileWidget和fileLayout
	QHBoxLayout *fileInfoLayout;	//用来存放文件信息
	QWidget *fileWidget;  //用来存放文件名和图标
	QString fileName;  //文件名  
	QLabel *mFileName;
	QLabel *mFileIcon;  //文件名和图标的label
	QStringList fileNameList;
	QFile *localFile;


	//QTcpSocket *tcpSocket;
	//QThread *uploadThread;

					   //获取文件的图标
	QIcon fileIcon(const QString &extension) const;
	//获取文件的类型？
	QString fileType(const QString &extension) const;

	void init();
	//int sendTimes;  //用来标记是否为第一次发送，第一次以后连接信号触发，后面的则手动调用  

	void initFile();
	// 加载样式文件;
	void loadStyleSheet(const QString &sheetName);
	// 文件拖放功能实现
	void dragEnterEvent(QDragEnterEvent* event = NULL);
	void dropEvent(QDropEvent* event = NULL);

	void setFileIcon(QString);  //将后缀放进去

	void insertFile(QString);  //插入文件名？


private slots:
	//void send();  //传送文件头信息  
	//void goOnSend(qint64);  //传送文件内容  
	void ClickOpenButton();
	void ClickSendButton();
	void receiveMainwindow();
	void updataProgressBar(int, qint64, qint64);
	void checkSendOver();
signals:
	void sendFileSignal();	//发送信号
	

};
#endif // !UPLOADWINDOW_H_



