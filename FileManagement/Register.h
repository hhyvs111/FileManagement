#pragma once
#include "stdafx.h"
#include <QtWidgets/QDialog>
#include "ui_Register.h"

extern TcpClient * tcp;
class Register : public QDialog
{
	Q_OBJECT

public:
	Register(QWidget *parent = Q_NULLPTR);
	~Register();

private:
	Ui::Register *ui;
	bool isAvailableUserName;
	bool isAvailablePassword;

	//槽函数
public slots:
	void Click_Register();
	void Click_Cancel();

	void checkIsAvailableUserName();		//检查用户名是否重复
	void checkIsAvailablePassword();			//密码是否一致

	void receiveLogin();  //接收login中发射的信号关联的槽函数

	void receiveDataFromServer(QString data);  //接受从服务器返回的数据
signals:
	void showMain();
	void showLogin();
};
