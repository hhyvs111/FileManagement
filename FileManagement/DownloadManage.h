#pragma once
#ifndef DOWNLOADMANAGE_H_
#define DOWNLOADMANAGE_H_
#include "stdafx.h"
#include "ui_DownlaodManage.h"
#include <QStandardItemModel>
#include <QMap>
#include <QFile>
#include "FileInfo.h"
#include "DownloadThread.h"
extern TcpClient * tcp;
extern QString globalUserName;


class DownloadManage : public QWidget
{
	Q_OBJECT

public:
	explicit DownloadManage(QWidget *parent = 0);
	~DownloadManage();
	void initModel();   //初始化TableView还是直接插入比较好？
	void initMap();  //初始化Map
	void loadStyleSheet(const QString &sheetName);
	QIcon fileIcon(const QString &extension) const;
	//获取文件的类型？
	QString fileType(const QString &extension) const;

	void setFileIcon(QString);  //将后缀放进去

	QString countFileSize(QString);

private:
	Ui::DownloadManage *ui;
	QStandardItemModel *model;


	QMap<int, DownloadThread*> *downloadThreadMap;
	QMap<int, QProgressBar*> *downloadProgressBarMap;
	QMap<int, QLabel*> *downloadSpeedMap;
	QMap<int, QWidget*> *downloadWidgetMap;  //试一下只用QWidget实现，不对啊，要插入QTableView里面去，还是不行
	QMap<int, QLabel*> *downloadLeftTimeMap;
	QMap<int, QLabel*> *fileSizeMap;
	int index;

	DownloadThread *downloadThread;  //下载线程
	QWidget *IconName;  //同时放Icon和文件名

	QLabel *mFileName;   //放label
	QLabel *mFileIcon;  //文件名和图标的label
	QLabel *mFileSpeed;
	QLabel *mFileSize;
	QLabel *mLeftTime;
	QFile *localFile;  //

private slots:
	void showToolTip(const QModelIndex &index);
	void insertDownloadFile(QString name,QString path); 
	void beginToDownload(int); 
	void checkDownloadOver(int);
	void updateProgressBar(int, qint64, qint64);
	void updateSpeedLabel(int, double, QString);

	//void addNewDownloadFile();
};
#endif // !DOWNLOADMANAGE_N_
	 