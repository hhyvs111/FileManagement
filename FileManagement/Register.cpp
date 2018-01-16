
#include "Register.h"

#include <QMessageBox> 
#include <qdebug.h>
#include <MyMessageBox.h>
#include <QDialog> 
#include <QLabel>
#include<qpixmap.h>


Register::Register(QWidget *parent)
	: QDialog(parent), ui(new Ui::Register)   //这里很重要，要对构造函数初始化！
{
	ui->setupUi(this);
	this->setStyleSheet("background:#ffff");//背景
											//this->setStyleSheet("background:D:/FileManagement-master/FileManagement/Resource/back.jpg");
	isAvailableUserName = false;     //一开始用户名是不可用的

	isAvailablePassword = false;		//密码是否一致
	ui->userMessage->hide();
	setFixedSize(340, 350);
	this->setWindowTitle("LOGIN");
	ui->userPassword->setEchoMode(QLineEdit::Password);//当输入密码时，显示为*******
	ui->userPassword2->setEchoMode(QLineEdit::Password);//当输入密码时，显示为*******
	
	/*LoginIcon = QIcon("D:/FileManagement-master/FileManagement/Resource/back.png");
	this->setWindowIcon(LoginIcon);
*/

	//添加图标
	//QPixmap backgroundPix("D:/FileManagement-master/FileManagement/Resource/back.jpg");
	//ui->label->setPixmap(backgroundPix);

	QPixmap userPix("Resource/ion/user.png");
	//ui->userLabel->setStyleSheet("QLabel{boeder:none;}");
	ui->userLabel->setPixmap(userPix);
	QPixmap passPix("Resource/ion/pass.png");
	//QPixmap passPix("D:/FileManagement-master/FileManagement/Resource/ion/pass.png");
	ui->passLabel->setPixmap(passPix);
	QPixmap confirmPix("Resource/ion/pass.png");
	ui->confirmLabel->setPixmap(confirmPix);
	QPixmap signPix("Resource/ion/register.jpg");

	QPixmap correctPix("Resource/ion/correct.png");
	ui->userLogo->setPixmap(correctPix);

	QPixmap passLogoPix("Resource/ion/correct.png");
	ui->passLogo->setPixmap(correctPix);
	QPixmap passLogoPix2("Resource/ion/correct.png");
	ui->passLogo2->setPixmap(correctPix);
	//ui->SignUp->setPixmap(signPix);
	//ui->horizontalLayoutWidget ->setStyleSheet("background:blue

	//ui->clickRegister->setStyleSheet("background:green");
	//ui->userName->setStyleSheet("border:4px groove gray");
	//ui->userPassword->setStyleSheet("border:4px groove gray");
	//ui->userPassword2->setStyleSheet("border:3px solid");

	//QDialog *dia;
	//QDialog *dia = new QDialog();
	//dia->setStyleSheet("background:red");

	ui->userLogo->hide();
	ui->passLogo->hide();
	ui->passLogo2->hide();
	ui->passwordMessage->hide();
	ui->passwordMessage2->hide();
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
		ui->passLogo->show();
		ui->passLogo2->show();
		ui->passwordMessage2->hide();
	}
	else
	{
		
		qDebug() << "the password is not equal";
		//在textlabel上显示错误信息
		ui->passwordMessage2->setText(QString::fromLocal8Bit("两次密码不一致！"));
		ui->passwordMessage2->setStyleSheet("color:red;");
		ui->passwordMessage2->show();
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
		ui->userLogo->show();
		////唤醒UI显示用户名可用！
	}
}

//接收信号
void Register::receiveLogin()
{
	this->show();   //显示注册窗口
}
