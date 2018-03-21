#pragma once
#ifndef SIGN_H
#define SIGN_H
#include "stdafx.h"
#include "ui_Sign.h"
#include "BaseWindow.h"
struct SignInfo
{
	int SignId;
	QString SignTime;
	QString userName;
	int userId;

};
extern TcpClient * tcp;    //全局变量，TCP 长连接
extern QString globalUserName;

class Sign :public BaseWindow
{
	Q_OBJECT
public:
	Sign(QWidget *parent = Q_NULLPTR);

	~Sign();
	void sendSignLook(QString condition = "all");

	void initModel();

	public slots:
	void showToolTip(const QModelIndex &index);
	void showSignList();
private:
	Ui::Sign *ui;
	QStandardItemModel *model;

};
#endif // !SIGN_H



