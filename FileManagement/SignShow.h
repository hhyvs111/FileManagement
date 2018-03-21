#pragma once
#ifndef SIGNSHOW_H_ 
#define SIGNSHOW_H_
#include "stdafx.h"
#include "BaseWindow.h"
#include "SignCalender.h"
#include "ui_SignShow.h"
#include <QWebChannel>
#include <QtWebEngineWidgets/QWebEngineView>
extern TcpClient * tcp;    //全局变量，TCP 长连接
extern QString globalUserName;
class SignShow :public QWidget
{
	Q_OBJECT
public:
	SignShow(QWidget *parent = Q_NULLPTR);
	~SignShow();
	SignCalender *signCalender;
	public slots:
	void sendMySignLook();
	void showMySignLook();
signals:
	void sendMySignInfo(QString);

private:
	Ui::SignShow *ui;

	

};
#endif // !SignShow_H_


