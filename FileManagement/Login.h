#pragma once

#include <QtWidgets/QDialog>
#include "ui_Login.h"

class Login : public QDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();
	

private:
	Ui::Login *ui;   //这个里面封装了一系列的输入框之类的，就不用重复定义了

public slots:
	void Click_Login();  //点击登陆
	void Click_Register();  //点击跳转到注册框\

	void receiveRegister();   //接受注册框的信号

signals:
	void showMain();
	void showRegister();
};

#ifndef LOGIN_H_
#define LOGIN_H_

#endif // LOGIN_H_

