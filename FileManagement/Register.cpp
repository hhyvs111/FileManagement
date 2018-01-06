#include "Register.h"
#include "Database.h"
#include "Login.h"
#include <QMessageBox> 
#include <qdebug.h>

Register::Register(QWidget *parent)
	: QDialog(parent), ui(new Ui::Register)   //这里很重要，要对构造函数初始化！
{
	ui->setupUi(this);
	isAvailableUserName = false;
}

Register::~Register()
{
	delete ui;
}
//点击注册
void Register::Click_Register()
{
	if (!isAvailableUserName)
	{
		qDebug() << "please check your username!";
		
		QMessageBox::warning(this, QString::fromLocal8Bit("Warning!"),
			QString::fromLocal8Bit("请先检查用户名是否可用！"),
			QMessageBox::Yes);
	}
	else
	{
		qDebug() << "get into the register";
		QString name = this->ui->userName->text();
		QString password = this->ui->userPassword->text();
		QString password2 = this->ui->userPassword2->text();

		if (QString::compare(password, password2) == 0)
		{
			qDebug() << "password is same!";
			QString sql1 = "select userName, userPassword from user where userName = '"
				+ name + "'";

			QString sql = "insert into user (userName,userPassword)values('" + name + "','" + password + "')";
			MySql mySql;
			if(!mySql.queryDB(sql1))
				if (mySql.insertDB(sql))
				{
					qDebug() << "insert sucess!";
					QMessageBox::information(this, QString::fromLocal8Bit("tips!"),
						QString::fromLocal8Bit("注册成功！点击返回登录界面！"),
						QMessageBox::Yes);
					this->hide();
					emit showLogin();
				}
				else
				{
					qDebug() << "insert false!";
					QMessageBox::warning(this, QString::fromLocal8Bit("Warning!"),
						QString::fromLocal8Bit("注册失败！！"),
						QMessageBox::Yes);
				}
			else 
			{
				qDebug() << "insert false! the user has exist!";
				QMessageBox::warning(this, QString::fromLocal8Bit("Warning!"),
					QString::fromLocal8Bit("注册失败！用户已存在"),
					QMessageBox::Yes);
			}
		}
		else
		{
			qDebug() << " please check your password!";
			QMessageBox::warning(this, QString::fromLocal8Bit("Warning!"),
				QString::fromLocal8Bit("密码不一致！"),
				QMessageBox::Yes);
		}
	}
}

void Register::Click_CheckUser()
{
	QString name = this->ui->userName->text();
	QString sql = "select userName, userPassword from user where userName = '"
		+ name + "'";
	MySql mySql;
	//如果用户名重复了
	if (mySql.queryDB(sql))
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("Warning!"),
			QString::fromLocal8Bit("用户名重复！"),
			QMessageBox::Yes);
		ui->userName->setFocus();  //将鼠标重新定位到nameLine
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("该用户名可用！"),
			QMessageBox::Ok);
		isAvailableUserName = true;
	}

}


void Register::Click_Reset()
{
	ui->userName->clear();  //清空密码passwardLine
	ui->userPassword->clear();  //清空密码passwardLine
	ui->userPassword2->clear();  //清空密码passwardLine
}
//接收信号
void Register::receiveLogin()
{
	this->show();   //显示注册窗口
}
