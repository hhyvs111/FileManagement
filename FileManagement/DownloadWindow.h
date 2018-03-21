#pragma once
#ifndef DOWNLOADWINDOW_H_
#define DOWNLOADWINDOW_H_
#include "stdafx.h"
#include "ui_DownloadWindow.h"
#include <QFile>  
#include <QString> 
#include <QStandardItemModel>
#include <QMap>
#include "DownloadFile.h"
#include "DownloadThread.h"
#include "FileInfo.h"
extern TcpClient * tcp;
extern QString globalUserName;


//这个类主要是用来放界面的，以及一些信息

//友元吗？
class TableModel;
class ButtonDelegate;


class DownloadWindow : public QWidget
{
	Q_OBJECT

public:
	explicit DownloadWindow(QWidget *parent = 0);
	~DownloadWindow();

	//发送查看该用户所上传文件的信息给服务器
	void sendFileInfo(QString condition = "all");
	// 加载样式文件;
	void loadStyleSheet(const QString &sheetName);

	//获取文件的图标
	QIcon fileIcon(const QString &extension) const;
	//获取文件的类型？
	QString fileType(const QString &extension) const;

	// 计算文件的大小，看情况返回MB或者KB
	QString countFileSize(QString);
	void initModel(); // 初始化qtableview，就是初始化model
	bool saveFilePath(QString);   //选择下载路径
private:
	Ui::DownloadWindow *ui;

	//设置一个限制，不能下载太多！
	QMap<int, DownloadThread*> *downloadThreadMap;  //下载线程map

	//QTcpSocket *tcpClient;
	QTime downloadTime;
	QFile *newFile;
	QByteArray inBlock;
	QByteArray buffer;  //用来缓存的
	QString fileName;
	QString saveFileName;   //这个是路径，只是路径没有文件名
	QString openFileName;  //点击按钮所得的下载名

	QString filePath = "files/";


	
	//qint64 RtotalSize;  //总共需要发送的文件大小（文件内容&文件名信息）  
	//qint64 byteReceived;  //已经接收的大小  
	//int receiveTime;	//接受的次数

	QMap<int, DownloadFile*> *downloadFileMap;  //定义一个下载的map线程
	int index; //线程序号
	QStandardItemModel *model;
	QToolButton *m_download;
	QToolButton *m_delete;

	//TableModel *m_model;
	ButtonDelegate *m_buttonDelegate;


	void initWindow();
	void init();

	
private slots:

	//void receiveFile();  //从服务器下载文件到本地。
	//					 //void send();  //传送文件头信息  
	//					 //void goOnSend(qint64);  //传送文件内容 
	void ClickDownloadButton();
	void ClickDeleteButton();  // 删除按钮

	void showFileInfo();

	void receiveDataFromClient(QString);
	void showToolTip(const QModelIndex &index);
	//点击条件查询按钮
	void ClickFindButton();

	void receiveThreadClosed(int);

	void setFilePath();

	void receiveFilePath(QString);

signals:
	//void sendDisconnect(QString);  //这是什么
	void newDownloadFile(QString, QString, int);  //发送一个新的信号，在下载管理增加一个新的
	void addDownloadFile(QString, QString); //点击按钮后新增一个下载线程

};


#endif // !DownloadWindow_H_ 

