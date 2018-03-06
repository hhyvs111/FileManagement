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


//友元吗？
class TableModel;
class ButtonDelegate;

struct FileInfo
{
	int fileId;
	QString fileName;
	QString fileSize;
	QString fileType;
	QString fileTime;
	QString fileUser;
	int userId;
};
class DownloadFile : public QWidget
{
	Q_OBJECT

public:
	explicit DownloadFile(QWidget *parent = 0);
	~DownloadFile();

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
private:
	Ui::DownloadFile *ui;

	//QTcpSocket *tcpClient;
	QTime downloadTime;
	QFile *newFile;
	QByteArray inBlock;
	QByteArray buffer;  //用来缓存的
	QString fileName;
	QString saveFileName;   //这个是路径？？还是直接是文件名？

	QString openFileName;  //直接打开的文件名
	qint64 RtotalSize;  //总共需要发送的文件大小（文件内容&文件名信息）  
	qint64 byteReceived;  //已经接收的大小  
	int receiveTime;	//接受的次数

	QStandardItemModel *model;
	QToolButton *m_download;
	QToolButton *m_delete;
	
	//TableModel *m_model;
	ButtonDelegate *m_buttonDelegate;


	void init();
private slots:

	void receiveFile();  //从服务器下载文件到本地。
						 //void send();  //传送文件头信息  
						 //void goOnSend(qint64);  //传送文件内容 

	void ClickDownloadButton();
	void ClickDeleteButton();  // 删除按钮
	bool saveFilePath(QString);   //选择下载路径
	void showFileInfo();

	void initModel(); // 初始化qtableview，就是初始化model

	void receiveDataFromClient(QString);

	
	void showToolTip(const QModelIndex &index);
	//void ClickSendButton();
	//void receiveMainwindow();

	//点击条件查询按钮
	void ClickFindButton();

signals:
	//void sendDisconnect(QString);  //这是什么

};

inline QDataStream &operator>>(QDataStream &in, FileInfo &fileInfo)
{
	int fileId;
	QString fileName;
	QString fileSize;
	QString fileType;
	QString fileTime;
	QString fileUser;
	int userId;

	in >> fileId >> fileName >> fileSize
		>> fileTime >> fileType >> fileUser >> userId;


	fileInfo.fileId = fileId;
	fileInfo.fileName = fileName;
	fileInfo.fileSize = fileSize;
	fileInfo.fileType = fileType;
	fileInfo.fileTime = fileTime;
	fileInfo.fileUser = fileUser;
	fileInfo.userId = userId;

	return in;
}
#endif // !DOWNLOADFILE_H_ 

