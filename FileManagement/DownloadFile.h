#pragma once
#ifndef DOWNLOADFILE_H_
#define DOWNLOADFILE_H_
#include "stdafx.h"
#include "ui_DownloadWindow.h"
#include <QFile>  
#include <QString> 
#include "FileInfo.h"
//extern TcpClient * tcp;
extern QString ip;
extern int port;
extern QString globalUserName;


//只负责下载就行了
class DownloadFile : public QObject
{
	Q_OBJECT

public:
	explicit DownloadFile(QString,QString,int);
	//这个构造函数是下载断点文件，第一个是总数据，第二个是断点位置
	DownloadFile(int,QString,QString, qint64 ,qint64 ,int );
	~DownloadFile();
	bool insertRecord();
	bool updateRecord();
	//发送查看该用户所上传文件的信息给服务器
	//void sendFileInfo(QString condition = "all");
	// 加载样式文件;
	//void loadStyleSheet(const QString &sheetName);

	//获取文件的图标
	//QIcon fileIcon(const QString &extension) const;
	//获取文件的类型？
	//QString fileType(const QString &extension) const;

	// 计算文件的大小，看情况返回MB或者KB
	//QString countFileSize(QString);   

private:
	//Ui::DownloadFile *ui;
	int index;  //序号
	QTcpSocket *tcpSocket;   //连接服务器的socket
	QTime downloadTime;
	QFile *newFile;
	QByteArray inBlock;
	QByteArray outBlock;  //发数据给服务器
	QByteArray buffer;  //用来缓存的
	QString fileName;
	QString saveFileName;   //文件路径加文件名
	QString filePath;
	QString openFileName;  //直接打开的文件名

	qint64 RtotalSize;  //总共需要发送的文件大小（文件内容&文件名信息）  
	qint64 byteReceived;  //已经接收的大小  ‘’

	qint64 receiveStatus = -1;  //默认为继续发送
	qint64 sumBlock;
	qint64 breakPoint;
	qint64 cbreakPoint;
	qint64 recordId;
	int breakFileId;
	QString breakFileName;
	QString breakFilePath;

	qint64 fileId;
	int receiveTime;	//接受的次数
	double speed;

	QString leftTime;  //剩余时间
	bool isBreakFile = false;
	void init();

	bool keepOn;
	void countLeftTime(float);
	

private slots:

	void receiveFile();  //从服务器下载文件到本地。
	void receiveBreakFile();
	void updateSpeed();
	void stopReceive(int);
	

	
	//void showToolTip(const QModelIndex &index);
	//void ClickSendButton();
	//void receiveMainwindow();

	//点击条件查询按钮
	//void ClickFindButton();

signals:
	//void sendDisconnect(QString);  //这是什么
	void downloadOver(int);
	void updateProgress(int, qint64, qint64);
	void updateSpeedLabel(int, double,QString);

	void addToBreakFile(int, qint64 recordId,int fileId,
		QString fileName,QString filePath,
	qint64 breakPoint);

};

//inline QDataStream &operator>>(QDataStream &in, FileInfo &fileInfo)
//{
//	int fileId;
//	QString fileName;
//	QString fileSize;
//	QString fileType;
//	QString fileTime;
//	QString fileUser;
//	int userId;
//
//	in >> fileId >> fileName >> fileSize
//		>> fileTime >> fileType >> fileUser >> userId;
//
//
//	fileInfo.fileId = fileId;
//	fileInfo.fileName = fileName;
//	fileInfo.fileSize = fileSize;
//	fileInfo.fileType = fileType;
//	fileInfo.fileTime = fileTime;
//	fileInfo.fileUser = fileUser;
//	fileInfo.userId = userId;
//
//	return in;
//}
#endif // !DOWNLOADFILE_H_ 

