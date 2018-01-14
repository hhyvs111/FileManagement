#include "Login.h"

#include "Database.h"
//#include "tcpclient.h"
#include <QMessageBox> 
#include<Qtcore/QCoreApplication>
#include <MyMessageBox.h>
#include <QDialog> 
#include <qdebug.h>
#include<QCryptographicHash>
#include "AesHelper.h"


 
Login::Login(QWidget *parent)
	: QDialog(parent), ui(new Ui::Login)
{
	tcp = new TcpClient();
	ui->setupUi(this);

	AesHelper *bbb = new AesHelper;
	QString kk;
	QSettings *getting = new QSettings("E:/test.ini", QSettings::IniFormat);//初始化显示上一次登录账户密码
	ui->nameLine->setText(getting->value("uuu", "").toString());
	kk = getting->value("ppp","").toString();
	QString xk = getting->value("position", "").toString();
	QString xx = getting->value("auto", "").toString();
	if (xk == "true")
	{
		ui->rem_pw->setChecked(true);
	}
	
	
	QByteArray tempass = QByteArray::fromBase64(kk.toLatin1());
	ui->passwordLine->setText(tempass); 
	ui->passwordLine->setEchoMode(QLineEdit::Password);//当输入密码时，显示为*******
	
	if (xx == "true")
	{
		ui->auto_login->setChecked(true);
		Click_Login();
	}
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

		AesHelper *aaa = new AesHelper;
		
		QSettings *settings = new  QSettings("E:/test.ini", QSettings::IniFormat);
		username = ui->nameLine->text();
		passwd = ui->passwordLine->text().trimmed();

		QByteArray passArray=passwd.toLatin1();
		
		QString password ;
		password.prepend(passArray.toBase64());

		settings->setValue("uuu", username);
		settings->setValue("ppp",password);
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





QString AesHelper::aesEncrypt(QString mingwen)
{
	QString result = QString("");
	char ch_mingwen[10240];
	char ch_miwen[10240];
	strcpy(ch_mingwen, mingwen.toUtf8().data());
	aes->Cipher(ch_mingwen, ch_miwen);
	result = QString(ch_miwen);
	return result;
}
QString AesHelper::aesUncrypt(QString miwen)
{
	QString result = QString("");
	char ch_mingwen[10240];
	char ch_miwen[10240];
	strcpy(ch_miwen, miwen.toUtf8().data());
	aes->InvCipher(ch_miwen, ch_mingwen);
	result = QString(ch_mingwen);

	return result;
}
AesHelper::~AesHelper()
{
	delete aes;
	aes = 0;
}
AesHelper::AesHelper()
{
	unsigned char key[] = "1p2w3e4r";
	aes = new AES(key);
	qDebug() <<"the aes:" << aes;
}