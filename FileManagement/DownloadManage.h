#pragma once
#ifndef DOWNLOADMANAGE_H_
#define DOWNLOADMANAGE_H_
#include "stdafx.h"
#include "ui_DownlaodManage.h"
#include <QStandardItemModel>
#include <QMap>
#include <QFile>
#include "FileInfo.h"
extern TcpClient * tcp;
extern QString globalUserName;


class DownloadManage : public QWidget
{
	Q_OBJECT

public:
	explicit DownloadManage(QWidget *parent = 0);
	~DownloadManage();

private:
	Ui::DownloadManage *ui;

private slots:
	//void addNewDownloadFile();
};
#endif // !DOWNLOADMANAGE_N_
	 