#include "Login.h"

#include "Database.h"
//#include "tcpclient.h"
#include <QMessageBox> 
#include <MyMessageBox.h>
#include <QDialog> 
#include <qdebug.h>
#include <QMovie>

//定义一个全局变量
 
Login::Login(QWidget *parent)
	: QDialog(parent), ui(new Ui::Login)
{
	tcp = new TcpClient();
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	QMovie *movie = new QMovie("C:/Users/44562/Desktop/Login/Login/Resources/timg.gif");
	ui->label->setMovie(movie);
	movie->start();
	setFixedSize(420, 350);
	ui->passwordLine->setEchoMode(QLineEdit::Password);//当输入密码时，显示为*******
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


	QString sql = "select userName, userPassword from user where userName = '"
		+ name + "'and userPassword ='" + passwd + "'";

	QString bs = "L";
	QString data = bs + "#" + sql;
	
	if (tcp->tcpSocket->write(data.toLatin1()))//将信息写入socket
		qDebug() << data;
	else
		qDebug() << "write is false";
	connect(tcp, SIGNAL(sendDataToLogin(QString)), this, SLOT(receiveDataFromClient(QString)));
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
		//MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("登录成功！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		this->hide();
		emit showMain();
	}
	else if (QString::compare(data, "F") == 0)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("用户名或密码不不正确！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		ui->passwordLine->clear();  //清空密码passwardLine
		ui->passwordLine->setFocus();  //将鼠标重新定位到password
	}
	else
		return;
}