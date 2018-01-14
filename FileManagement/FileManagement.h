#pragma once

#include "stdafx.h"
#include <QtWidgets/QMainWindow>
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

private slots:
	void Btn_Click();
	void ClickUploadFile();
	void receiveLogin();
signals:
	void showUploadFile();


};
