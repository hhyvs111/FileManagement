#include "Login.h"

//#include "tcpclient.h"
#include <QMessageBox> 
#include "MyMessageBox.h"
#include <QMovie>
#include<qdebug.h>
#include<QDialog>
#include<QCryptographicHash>
#include <MyMessageBox.h>
//定义一个全局变量



Login::Login(QWidget *parent)
	: BaseWindow(parent), ui(new Ui::Login)
{
	tcp = new TcpClient();
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	
	QString kk;
	QSettings *getting = new QSettings("E:/test.ini", QSettings::IniFormat);//初始化显示上一次登录账户密码
	ui->nameLine->setText(getting->value("uuu", "").toString());
	kk = getting->value("ppp", "").toString();
	QString xk = getting->value("position", "").toString();
	QString xx = getting->value("auto", "").toString();

	if (xk == "true")
	{
		ui->rem_pw->setChecked(true);
	}


	QByteArray tempass = QByteArray::fromBase64(kk.toLatin1());
	ui->passwordLine->setText(tempass);

	QMovie *movie = new QMovie("Resource/Logo.gif");
	ui->label->setMovie(movie);
	movie->start();
	setFixedSize(420, 350);
	ui->passwordLine->setEchoMode(QLineEdit::Password);//当输入密码时，显示为*******
	
	initTitleBar();
	if (xx == "true")
	{
		ui->auto_login->setChecked(true);
		Click_Login();
	}
	

	//TCP相关的信息,若客户端要发送数据给login
	connect(tcp, SIGNAL(sendDataToLogin(QString)), this, SLOT(receiveDataFromClient(QString)));
	//显示注册框
	//connect(this, SIGNAL(showRegister()), &R, SLOT(receiveLogin()));
}

void Login::initTitleBar()
{
	m_titleBar->move(1, 2);
	m_titleBar->raise();
	m_titleBar->setWindowBorderWidth(2);
	m_titleBar->setBackgroundColor(255, 255, 255);
	m_titleBar->setButtonType(MIN_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void Login::setWindowTitle(QString title, int titleFontSize)
{
	m_titleBar->setTitleContent(title, titleFontSize);
}

Login::~Login()
{
	delete ui;
}

//点击登录,不能实时通信，要该对话框结束后才能发送信息？
void Login::Click_Login()
{
	QString name = this->ui->nameLine->text();
	QString passwd = this->ui->passwordLine->text();
	 

	QString sql = "select * from user where userName = '"
		+ name + "'and userPassword ='" + passwd + "'";

	QString bs = "L";
	QString data = bs + "#" + sql;
	
	if (tcp->tcpSocket->write(data.toLatin1()))//将信息写入socket
		qDebug() << data;
	else
		qDebug() << "write is false";

	//放在这会多次连接槽函数，然后相应会多次触发
	//connect(tcp, SIGNAL(sendDataToLogin(QString)), this, SLOT(receiveDataFromClient(QString)));
	//MessageBox();
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

//验证登录，从服务端得来的数据
void Login::receiveDataFromClient(QString data)
{
	//验证成功！
	if (QString::compare(data, "T") == 0)
	{
		//将用户名设置给全局变量用户名
		globalUserName = this->ui->nameLine->text();
		//MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("登录成功！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		this->hide();
		emit showMain();
	}
	else if (QString::compare(data, "F") == 0)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("用户名或密码不正确！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		ui->passwordLine->clear();  //清空密码passwardLine
		ui->passwordLine->setFocus();  //将鼠标重新定位到password
	}
	else
		return;
}
void Login::hide1()
{
	ui->passwordLine->clear();
	ui->rem_pw->setChecked(false);
	ui->auto_login->setChecked(false);
}
void Login::raise()
{
	if (ui->rem_pw->isChecked())
	{
		remeberPasswd = true;//勾选了记住密码 将密码写入配置文件
		QSettings *settings = new  QSettings("E:/test.ini", QSettings::IniFormat);
		username = ui->nameLine->text();
		passwd = ui->passwordLine->text().trimmed();
		QByteArray passArray = passwd.toLatin1();

		QString password;
		password.prepend(passArray.toBase64());

		settings->setValue("uuu", username);
		settings->setValue("ppp", password);
		settings->setValue("position", remeberPasswd);
		qDebug() << password;
		delete settings;
	}
	else
	{
		//ui->passwordLine->clear();
		remeberPasswd = false;
		QSettings *setting = new  QSettings("E:/test.ini", QSettings::IniFormat);
		QString username = ui->nameLine->text();
		setting->setValue("uuu", username);
		setting->setValue("ppp", "");
		setting->setValue("position", remeberPasswd);
	}
}
void Login::lower()//自动登录
{
	if (ui->auto_login->isChecked())
	{
		autologin = true;
	}
	else
	{
		autologin = false;
	}
	QSettings *settingss = new  QSettings("E:/test.ini", QSettings::IniFormat);

	settingss->setValue("auto", autologin);
}