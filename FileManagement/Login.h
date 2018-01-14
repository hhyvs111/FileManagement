#pragma once

#include"stdafx.h"
#include <QtWidgets/QDialog>
#include <QtNetwork>
#include <QMessageBox>
//#include"tcpclient.h"
#include "ui_Login.h"

#ifndef LOGIN_H_
#define LOGIN_H_
extern TcpClient * tcp;
//声明一个全局变量

class Login : public QDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();
	
	

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


	public slots:
	void Click_Login();  //点击登陆
	void Click_Register();  //点击跳转到注册框
	//void MessageBox();
	void close();//点击退出窗口
	void receiveRegister();   //接受注册框的信号
	void raise();//勾选记住密码框
	void receiveDataFromClient(QString data);   //接收从客户端传来的信息
	void lower();//勾选自动登录


signals: 
	void showMain();
	void showRegister();
};



#endif // LOGIN_H_

