#include "Login.h"

#include "Database.h"
//#include "tcpclient.h"
#include <QMessageBox> 
#include <MyMessageBox.h>
#include <QDialog> 
#include <qdebug.h>
#include<QCryptographicHash>

//定义一个全局变量
 
Login::Login(QWidget *parent)
	: QDialog(parent), ui(new Ui::Login)
{
	tcp = new TcpClient();
	ui->setupUi(this);
	QString kk;
	QString xk;
	QString md5;
	QByteArray bb;

	QSettings *getting = new QSettings("E:/test.ini", QSettings::IniFormat);//初始化显示上一次登录账户密码
	ui->nameLine->setText(getting->value("uname", "20").toString());
	//kk = getting->value("pws", 1000).toString();

	//bb = QCryptographicHash::hash(kk.toLatin1(), QCryptographicHash::Md5);
	//md5.append(bb.toHex());
	//bb.append(kk);
	//QCryptographicHash hash(QCryptographicHash::Md5);
	//hash.addData(bb);//添加数据到加密哈希值
	//QByteArray result = hash.result();//返回最终的哈希值
	//xk = result.toHex();

	ui->passwordLine->setText(getting->value("pws",20).toString());
	
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
void Login::close()
{
	QApplication* app;
	app->quit();
}

void Login::raise()//记住密码
{

	if (ui->rem_pw->isChecked())
	{
		remeberPasswd = true;//勾选了记住密码 将密码写入配置文件


		QString  md5;
		QByteArray  ba, bb;
		QCryptographicHash md(QCryptographicHash::Md5);
		QSettings *settings = new  QSettings("E:/test.ini", QSettings::IniFormat);
		username = ui->nameLine->text();
		passwd = ui->passwordLine->text();
		//ba.append(passwd);
		//md.addData(ba);
		//bb = md.result();
		//md5.append(bb.toHex());


		settings->setValue("uname", username);
		settings->setValue("pws", passwd);
		delete settings;
	}
	else
	{
		ui->passwordLine->clear();
		remeberPasswd = false;
	}

}