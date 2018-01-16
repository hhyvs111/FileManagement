#pragma once

#include "stdafx.h"
#include <QtWidgets/QMainWindow>
#include "UploadFile.h"
#include "DownloadFile.h"
#include "ui_FileManagement.h"

extern QString globalUserName;
class FileManagement : public QMainWindow
{
	Q_OBJECT

public:
	FileManagement(QWidget *parent = Q_NULLPTR);
	~FileManagement();

private:
	Ui::FileManagement *ui;
	UploadFile *uploadFile;  // 创建上传文件的指针
	DownloadFile *downloadFile;
	bool uploadFileWindowIsOpen = false, downloadFileWindowIsOpen = false;

private slots:
	void Btn_Click();
	void ClickUploadFile();
	void ClickDownloadFile();
	void receiveLogin();
signals:
	void showUploadFile();


};
