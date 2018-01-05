#include "Login.h"
#include <QMessageBox> 
Login::Login(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

//点击登录
void Login::Click_Login()
{
	QMessageBox msg;
	msg.setText("hello world!");
	msg.exec();
}

//跳转到注册窗口
void Login::Click_Register()
{
	this->hide();			//屏蔽登录界面
	emit showRegister();	//激活信号，让信号传送到特定页面
}