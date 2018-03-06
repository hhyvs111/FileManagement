#pragma once

#include "stdafx.h"
#include <QtWidgets/QMainWindow>
#include "UploadFile.h"
#include "DownloadFile.h"
#include "UserInformation.h"
#include "ReportEdit.h"
#include "ReportLook.h"
#include "BaseWindow.h"
#include "ui_FileManagement.h"
#include <QStackedLayout>

extern QString globalUserName;
class FileManagement : public BaseWindow
{
	Q_OBJECT

public:
	FileManagement(QWidget *parent = Q_NULLPTR);
	~FileManagement();

private:
	Ui::FileManagement *ui;


	UploadFile *uploadFile;  // 创建上传文件的指针
	DownloadFile *downloadFile;
	UserInformation *userInformation; 
	ReportEdit *reportEdit;
	ReportLook *reportLook;

	bool uploadFileWindowIsOpen = false,
		downloadFileWindowIsOpen = false,
		userInformationWindowIsOpen = false,
		reportEditWindowIsOpen = false,
		reportLookWindowIsOpen = false;

	QStackedLayout *m_pStackedLayout; 
	//窗口切换
	void StackWindow();

	//初始化界面
	void init();

	//初始化标题栏
	//void initTitleBar();
	
private slots:
	void Btn_Click();
	void ClickUserInformation();
	void ClickUploadFile();
	void ClickDownloadFile();
	void ClickReportEdit();
	void ClickReportLook();
	void ClickReturn();


	void receiveLogin();
signals:
	void showUploadFile();
	void showLogin();
	////显示按钮
	//void showInfo();


};
