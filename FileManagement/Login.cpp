#include "Login.h"
#include "Database.h"
#include <QMessageBox> 
#include <QDialog>
Login::Login(QWidget *parent)
	: QDialog(parent), ui(new Ui::Login)
{
	ui->setupUi(this);
	ui->passwordLine->setEchoMode(QLineEdit::Password);//当输入密码时，显示为*******
}

Login::~Login()
{
	delete ui;
}

//点击登录
void Login::Click_Login()
{
	QString name = this->ui->nameLine->text();
	QString passwd = this->ui->passwordLine->text();

	QString sql = "select userName, userPassword from user where userName = '"
		+ name + "'and userPassword ='" + passwd + "'";
	MySql mySql;
	if (mySql.queryDB(sql))
	{
		QMessageBox::information(this, QString::fromLocal8Bit("登录成功"),
			QString::fromLocal8Bit("登录成功！欢迎进入本系统！"),
			QMessageBox::Ok);
		this->hide();
		emit showMain();
	}
	else
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("登录失败"),
			QString::fromLocal8Bit("用户名或密码错误！是否重新登录？"),
			QMessageBox::Yes | QMessageBox::No);
		ui->passwordLine->clear();  //清空密码passwardLine
		ui->passwordLine->setFocus();  //将鼠标重新定位到nameLine
	}
}

//跳转到注册窗口
void Login::Click_Register()
{
	this->hide();			//屏蔽登录界面
	emit showRegister();	//激活信号，让信号传送到特定页面
}

void Login::receiveRegister()
{
	this->show();  //显示登录窗口
}