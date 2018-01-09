
#include "Register.h"
#include "Database.h"
//#include "Login.h"
//#include "tcpclient.h"
#include <QMessageBox> 
#include <qdebug.h>
#include <MyMessageBox.h>


Register::Register(QWidget *parent)
	: QDialog(parent), ui(new Ui::Register)   //这里很重要，要对构造函数初始化！
{
	ui->setupUi(this);
	isAvailableUserName = false;     //一开始用户名是不可用的
	isAvailablePassword = false;		//密码是否一致
	ui->userMessage->hide();

	//当用户名输入完后检测是否重复
	connect(ui->userName, SIGNAL(editingFinished()), this, SLOT(checkIsAvailableUserName()));

	//检测密码是否符合要求
	connect(ui->userPassword2, SIGNAL(editingFinished()), this, SLOT(checkIsAvailablePassword()));


	connect(tcp, SIGNAL(sendDataToRegister(QString)), this, SLOT(receiveDataFromServer(QString)));
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
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请先检查用户名是否可用！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}
	//m
	else if (!isAvailablePassword)
	{
		qDebug() << "the password is not same";
	}

	//如果密码和用户的验证都通过则进入注册
	else if (isAvailableUserName && isAvailablePassword)
	{
		qDebug() << "get into the register";
		QString name = this->ui->userName->text();
		QString password = this->ui->userPassword->text();
		QString password2 = this->ui->userPassword2->text();
		QString sql = "insert into user (userName,userPassword)values('" + name + "','" + password + "')";
		QString bs = "R";
		QString data = bs + "#" + sql;
		tcp->tcpSocket->write(data.toLatin1());//将信息写入socket
		qDebug() << data;
	}
	else
		return;
}

void Register::Click_Cancel()
{
	this->close();
	emit showLogin();
}
void Register::checkIsAvailableUserName()
{
	QString name = this->ui->userName->text();
	QString sql = "select userName, userPassword from user where userName = '"
		+ name + "'";
	QString bs = "RCU";
	QString data = bs + "#" + sql;
	tcp->tcpSocket->write(data.toLatin1());//将信息写入socket
	qDebug() << data;
}

void Register::checkIsAvailablePassword()
{
	QString password = this->ui->userPassword->text();
	QString password2 = this->ui->userPassword2->text();


	if (QString::compare(password, password2) == 0)
	{
		isAvailablePassword = true;
		qDebug() << "the password is equal";
		//在textlabel上显示正确信息
	}
	else
	{
		qDebug() << "the password is not equal";
		//在textlabel上显示错误信息
	}


}


void Register::receiveDataFromServer(QString data)
{
	//注册成功
	if (QString::compare(data, "R_T") == 0)
	{
		qDebug() << "Register success!";

		//提示框！

		this->close();
		emit showLogin();
	}
	else if (QString::compare(data, "R_F") == 0)
	{
		qDebug() << "Register failed";
	}
	//有一样的用户名
	else if (QString::compare(data, "RCU_T") == 0)
	{
		qDebug() << "it is a same username";
		//唤醒UI显示用户名重复
		ui->userMessage->setText(QString::fromLocal8Bit("该用户名已存在！"));
		ui->userMessage->setStyleSheet("color:red;");
		ui->userMessage->show();
	}
	else if (QString::compare(data, "RCU_F") == 0)
	{
		qDebug() << "good username";
		isAvailableUserName = true;
		ui->userMessage->setText(QString::fromLocal8Bit("该用户名可用！"));
		ui->userMessage->setStyleSheet("color:green;");
		ui->userMessage->show();
		////唤醒UI显示用户名可用！
	}
}

//接收信号
void Register::receiveLogin()
{
	this->show();   //显示注册窗口
}
