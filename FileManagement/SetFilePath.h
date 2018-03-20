#pragma once
#ifndef SETFILEPATH_H_
#define SETFILEPATH_H_
#include "stdafx.h"
#include "BaseWindow.h"
#include "ui_SetFilePath.h"
class SetFilePath :public BaseWindow
{
	Q_OBJECT
public:
	SetFilePath(QWidget *parent = Q_NULLPTR);
	~SetFilePath();

public slots:
	void selectFilePath();
	void ClickSaveButton();
signals:
	void sendFilePath(QString);


private:
	Ui::SetFilePath *ui;
	QString filePath;
};

#endif // !SETFILEPATH_H_


