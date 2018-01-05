#include "Login.h"
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
	if (this->ui->nameLine->text().trimmed() == tr("123") &&
		this->ui->passwordLine->text().trimmed() == tr("123"))  //去除lineEdit内的用户名和密码进行校验
	{
		//登陆成功后显示对话框
		QMessageBox msg;
		msg.setText(QString::fromLocal8Bit("登录成功！"));
		msg.setWindowTitle(QString::fromLocal8Bit("提示"));
		msg.exec();
		this->hide();
		emit showMain();

	}
	else
	{
		//用户输入存在错误
		QMessageBox::warning(this, tr("waring"), tr("your passward is wrong"), QMessageBox::Yes);
		//ui->nameLine->clear();  //清空姓名nameLine
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