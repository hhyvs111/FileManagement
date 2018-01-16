#pragma once

#include"stdafx.h"
#include <QtWidgets/QDialog>
#include <QtNetwork>
#include <QMessageBox>
//#include"tcpclient.h"
#include "ui_Login.h"
#include "BaseWindow.h"

#ifndef LOGIN_H_
#define LOGIN_H_
extern TcpClient * tcp;
extern QString globalUserName ;
//声明一个全局变量,来自stdafx的全局变量，说明login可以使用本变量

class Login : public BaseWindow
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();
	void setWindowTitle(QString title, int titleFontSize = 10);  //设置标题栏

private:
	Ui::Login *ui;   //这个里面封装了一系列的输入框之类的，就不用重复定义了
	QString     username;
	QString    passwd;
	QString     AutoLogin;
	QString     RemeberPasswd;

	bool        remeberPasswd;
	bool        autologin;
	void        savecfg();
	void        loadcfg();

	void initTitleBar();

public slots:
	void Click_Login();  //点击登陆
	void Click_Register();  //点击跳转到注册框
	//void MessageBox();
	void receiveRegister();   //接受注册框的信号
	void receiveMain();
	void raise();//记住密码
	void lower();//自动登录

	void hide1();//修改账号框内容
	void receiveDataFromClient(QString data);   //接收从客户端传来的信息
signals: 
	void showMain();
	void showRegister();

};



#endif // LOGIN_H_

