
#include "Register.h"

#include <QMessageBox> 
#include <qdebug.h>
#include <MyMessageBox.h>
#include <QDialog> 
#include <QLabel>
#include<qpixmap.h>
#include<QRegExp>
#include <QCryptographicHash>


Register::Register(QWidget *parent)
	: BaseWindow(parent), ui(new Ui::Register)   //这里很重要，要对构造函数初始化！
{
	ui->setupUi(this);
	//this->setStyleSheet("background:#ffff");//背景
											//this->setStyleSheet("background:D:/FileManagement-master/FileManagement/Resource/back.jpg");
	isAvailableUserName = false;     //一开始用户名是不可用的
	isAvailablePassword = false;		//密码是否一致
	isokPassword = false;    //密码格式是否正确
	isAvailableStudentId = false;    //一开始学号是不可用的
	isOkTeacher = false;
	isOkTrueName = false;
	setWindowFlags(Qt::FramelessWindowHint);

	//setFixedSize(340, 350);
	//this->setWindowTitle("LOGIN");
	ui->userPassword->setEchoMode(QLineEdit::Password);//当输入密码时，显示为*******
	ui->userPassword2->setEchoMode(QLineEdit::Password);//当输入密码时，显示为*******

	initTitleBar();
	init();

	loadStyleSheet("Register");
	//当用户名输入完后检测是否重复
	connect(ui->userName, SIGNAL(editingFinished()), this, SLOT(checkIsAvailableUserName()));

	connect(ui->studentId, SIGNAL(editingFinished()), this, SLOT(checkIsAvailableStudentId()));
	//检测密码是否符合要求
	connect(ui->userPassword2, SIGNAL(editingFinished()), this, SLOT(checkIsAvailablePassword()));
	connect(ui->trueName, SIGNAL(editingFinished()), this, SLOT(checkIsOkTrueName()));
	connect(ui->teacher, SIGNAL(editingFinished()), this, SLOT(checkIsOkTeacher()));


	connect(tcp, SIGNAL(sendDataToRegister(QString)), this, SLOT(receiveDataFromServer(QString)));
}

Register::~Register()
{
	delete ui;
}

void Register::initTitleBar()
{
	m_titleBar->move(1, 2);
	m_titleBar->raise();
	m_titleBar->setWindowBorderWidth(2);
	m_titleBar->setBackgroundColor(255, 255, 255);
	m_titleBar->setButtonType(MIN_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}
//void Register::setWindowTitle(QString title, int titleFontSize)
//{
//	m_titleBar->setTitleContent(title, titleFontSize);
//}


void Register::init()
{

	//设置用户名输入栏
	ui->userName->setMinimumHeight(30);
	ui->userName->setTextMargins(22, 0, 0, 0);
	ui->userName->setPlaceholderText(QString::fromLocal8Bit("请输入用户名"));


	QLabel *userLogo = new QLabel(this);
	userLogo->setMaximumSize(21, 21);
	userLogo->setCursor(QCursor(Qt::ArrowCursor));
	userLogo->setPixmap(QPixmap("Resource/ion/user.png"));

	QSpacerItem *spaceItem1 = new QSpacerItem(150, 20, QSizePolicy::Expanding);
	QHBoxLayout *editLayout1 = new QHBoxLayout();
	editLayout1->setContentsMargins(1, 0, 1, 0);
	editLayout1->addWidget(userLogo);
	editLayout1->addSpacerItem(spaceItem1);
	ui->userName->setLayout(editLayout1);

	//设置密码输入栏
	ui->userPassword->setMinimumHeight(30);
	ui->userPassword->setTextMargins(22, 0, 0, 0);

	ui->userPassword->setPlaceholderText(QString::fromLocal8Bit("请输入密码"));

	QLabel *pwd = new QLabel(this);
	pwd->setMaximumSize(21, 21);
	pwd->setCursor(QCursor(Qt::ArrowCursor));
	pwd->setPixmap(QPixmap("Resource/ion/pwd.png"));

	QSpacerItem *spaceItem2 = new QSpacerItem(150, 20, QSizePolicy::Expanding);
	QHBoxLayout *editLayout2 = new QHBoxLayout();
	editLayout2->setContentsMargins(1, 0, 1, 0);
	editLayout2->addWidget(pwd);
	editLayout2->addSpacerItem(spaceItem2);
	ui->userPassword->setLayout(editLayout2);

	//设置密码确认栏
	ui->userPassword2->setMinimumHeight(30);
	ui->userPassword2->setTextMargins(22, 0, 0, 0);

	ui->userPassword2->setPlaceholderText(QString::fromLocal8Bit("请再次输入密码"));

	QLabel *pwd2 = new QLabel(this);
	pwd2->setMaximumSize(21, 21);
	pwd2->setCursor(QCursor(Qt::ArrowCursor));
	pwd2->setPixmap(QPixmap("Resource/ion/pwd2.png"));

	QSpacerItem *spaceItem3 = new QSpacerItem(150, 20, QSizePolicy::Expanding);
	QHBoxLayout *editLayout3 = new QHBoxLayout();
	editLayout3->setContentsMargins(1, 0, 1, 0);
	editLayout3->addWidget(pwd2);
	editLayout3->addSpacerItem(spaceItem3);
	ui->userPassword2->setLayout(editLayout3);

	//设置真实姓名栏
	ui->trueName->setMinimumHeight(30);
	ui->trueName->setTextMargins(22, 0, 0, 0);

	ui->trueName->setPlaceholderText(QString::fromLocal8Bit("请输入真实姓名"));

	QLabel *trueNameLogo = new QLabel(this);
	trueNameLogo->setMaximumSize(21, 21);
	trueNameLogo->setCursor(QCursor(Qt::ArrowCursor));
	trueNameLogo->setPixmap(QPixmap("Resource/ion/truename.png"));

	QSpacerItem *spaceItem4 = new QSpacerItem(150, 20, QSizePolicy::Expanding);
	QHBoxLayout *editLayout4 = new QHBoxLayout();
	editLayout4->setContentsMargins(1, 0, 1, 0);
	editLayout4->addWidget(trueNameLogo);
	editLayout4->addSpacerItem(spaceItem4);
	ui->trueName->setLayout(editLayout4);

	//设置导师姓名栏
	ui->teacher->setMinimumHeight(30);
	ui->teacher->setTextMargins(22, 0, 0, 0);

	ui->teacher->setPlaceholderText(QString::fromLocal8Bit("请输入导师姓名"));
	QLabel *teacherLogo = new QLabel(this);
	teacherLogo->setMaximumSize(21, 21);
	teacherLogo->setCursor(QCursor(Qt::ArrowCursor));
	teacherLogo->setPixmap(QPixmap("Resource/ion/teacher.png"));

	QSpacerItem *spaceItem5 = new QSpacerItem(150, 20, QSizePolicy::Expanding);
	QHBoxLayout *editLayout5 = new QHBoxLayout();
	editLayout5->setContentsMargins(1, 0, 1, 0);
	editLayout5->addWidget(teacherLogo);
	editLayout5->addSpacerItem(spaceItem5);
	ui->teacher->setLayout(editLayout5);

	//设置学号输入栏
	ui->studentId->setMinimumHeight(30);
	ui->studentId->setTextMargins(22, 0, 0, 0);

	ui->studentId->setPlaceholderText(QString::fromLocal8Bit("请输入学号"));
	QLabel *stuIdLogo = new QLabel(this);
	stuIdLogo->setMaximumSize(21, 21);
	stuIdLogo->setCursor(QCursor(Qt::ArrowCursor));
	stuIdLogo->setPixmap(QPixmap("Resource/ion/studentId.png"));

	QSpacerItem *spaceItem6 = new QSpacerItem(150, 20, QSizePolicy::Expanding);
	QHBoxLayout *editLayout6 = new QHBoxLayout();
	editLayout6->setContentsMargins(1, 0, 1, 0);
	editLayout6->addWidget(stuIdLogo);
	editLayout6->addSpacerItem(spaceItem6);
	ui->studentId->setLayout(editLayout6);


	ui->userLogo->hide();
	ui->passLogo->hide();
	ui->passLogo2->hide();
	ui->trueNameLogo->hide();
	ui->teacherLogo->hide();
	ui->studentIdLogo->hide();
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
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请先检查密码是否一致！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		qDebug() << "the password is not same";
	}
	else if (!isAvailableStudentId)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请先检查学号是否正确！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		qDebug() << "studentId is not correct";
	}
	else if (!isokPassword)
	{
		qDebug() << "Password is not correct geshi";
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请先检查密码格式是否正确！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}
	else if (!isOkTrueName)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请先检查姓名是否正确！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}
	else if (!isOkTeacher)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请先检查导师姓名是否正确！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}

	//如果密码和用户的验证都通过则进入注册

	else if (isAvailableUserName && isAvailablePassword && isAvailableStudentId && 
		isokPassword && isOkTrueName && isOkTeacher)
	{
		qDebug() << "get into the register";
		QString name = this->ui->userName->text();
		QString password = this->ui->userPassword->text();
		QString password2 = this->ui->userPassword2->text();
		QString stuId = this->ui->studentId->text();
		QString trueName = this->ui->trueName->text();
		QString teacher = this->ui->teacher->text();
		QString level = this->ui->level->currentText();
		QString term = this->ui->term->currentText();

		QString md5;
		QByteArray qc, cc;
		QCryptographicHash md(QCryptographicHash::Md5);
		qc.append(password2);
		md.addData(qc);
		cc = md.result();
		md5.append(cc.toHex());


		QString sql = "insert into user (userName,userPassword,studentId,trueName,term,level,teacher)values('" + name + "','" +
			md5+ "','" + stuId+ "','" + trueName + "','" + term + "','" + level + "','" + teacher + "')";
		QString bs = "R";
		QString data = bs + "#" + sql;
		tcp->tcpSocket->write(data.toUtf8());//将信息写入socket
		qDebug() << data;
		return;
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

void Register::checkIsAvailableStudentId()
{
	QString stuId = this->ui->studentId->text();
	QString sql = "select userName, userPassword from user where studentId = '"
		+ stuId + "'";
	QString bs = "RCS";   //rigister check studentId
	QString data = bs + "#" + sql;
	tcp->tcpSocket->write(data.toLatin1());//将信息写入socket
	qDebug() << data;
}

void Register::checkIsAvailablePassword()
{
	QString password = this->ui->userPassword->text();
	QString password2 = this->ui->userPassword2->text();


	if (QString::compare(password, password2) == 0 && isokPassword)
	{
		isAvailablePassword = true;
		qDebug() << "the password is equal";
		//在textlabel上显示正确信息
		//ui->passLogo->show();
		//ui->passLogo2->show();
		//ui->passwordMessage2->hide();
		ui->passwordMessage2->setText(QString::fromLocal8Bit("密码一致！"));
		ui->passwordMessage2->setStyleSheet("color:green;");
		QPixmap Pix("Resource/ion/correct.png");
		ui->passLogo2->setPixmap(Pix);
		ui->passLogo2->show();
	}
	else if(isokPassword)
	{
		
		qDebug() << "the password is not equal";
		//在textlabel上显示错误信息
		ui->passwordMessage2->setText(QString::fromLocal8Bit("两次密码不一致！"));
		ui->passwordMessage2->setStyleSheet("color:red;");
		QPixmap Pix("Resource/ion/error.png");
		ui->passLogo2->setPixmap(Pix);
		ui->passLogo2->show();
	}
}

void Register::checkIsokPassword()
{
	QRegExp rx;
	QString passw=ui->userPassword->text();
	rx.setPatternSyntax(QRegExp::RegExp);
	rx.setCaseSensitivity(Qt::CaseInsensitive);//对大小写字母敏感
	rx.setPattern(QString("^[A-Za-z]+[0-9]+$"));
	//匹配格式为所有大小写字母和数字组成的字符串，位数不限
	if (rx.exactMatch(passw) == true)
	{
		isokPassword = true;
		ui->passwordMessage->setText(QString::fromLocal8Bit("密码格式正确！"));
		ui->passwordMessage->setStyleSheet("color:green;");
		ui->passwordMessage->show();

		QPixmap Pix("Resource/ion/correct.png");
		ui->passLogo->setPixmap(Pix);
		ui->passLogo->show();
	}
	else
	{
		isokPassword = false;
		ui->passwordMessage->setText(QString::fromLocal8Bit("密码必须以字母为首位！"));
		ui->passwordMessage->setStyleSheet("color:red;");
		ui->passwordMessage->show();

		QPixmap Pix("Resource/ion/error.png");
		ui->passLogo->setPixmap(Pix);
		ui->passLogo->show();
	}

}

void Register::checkIsOkTrueName()
{
	QString name = ui->trueName->text();
	//暂时不做中文校验了
	if (name == "")
	{
		ui->trueNameLabel->setText(QString::fromLocal8Bit("姓名不能为空！"));
		ui->trueNameLabel->setStyleSheet("color:red;");
		ui->trueNameLabel->show();

		QPixmap Pix("Resource/ion/error.png");
		ui->trueNameLogo->setPixmap(Pix);
		ui->trueNameLogo->show();

	}
	else
	{
		isOkTrueName = true;
		ui->trueNameLabel->setText(QString::fromLocal8Bit("天将降大任于%1也！").arg(name));
		ui->trueNameLabel->setStyleSheet("color:green;");
		ui->trueNameLabel->show();
		QPixmap Pix("Resource/ion/correct.png");
		ui->trueNameLogo->setPixmap(Pix);
		ui->trueNameLogo->show();
	}

}
void Register::checkIsOkTeacher()
{
	QString name = ui->teacher->text();
	//暂时不做中文校验了
	if (name == "")
	{
		ui->teacherLabel->setText(QString::fromLocal8Bit("姓名不能为空！"));
		ui->teacherLabel->setStyleSheet("color:red;");
		ui->teacherLabel->show();

		QPixmap Pix("Resource/ion/error.png");
		ui->teacherLogo->setPixmap(Pix);
		ui->teacherLogo->show();

	}
	else
	{
		isOkTeacher = true;
		ui->teacherLabel->setText(QString::fromLocal8Bit("著名的%1老师！").arg(name));
		ui->teacherLabel->setStyleSheet("color:green;");
		ui->teacherLabel->show();
		QPixmap Pix("Resource/ion/correct.png");
		ui->teacherLogo->setPixmap(Pix);
		ui->teacherLogo->show();
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

		//设置错误图片
		QPixmap Pix("Resource/ion/error.png");
		ui->userLogo->setPixmap(Pix);
		ui->userLogo->show();


		
	}
	else if (QString::compare(data, "RCU_F") == 0)
	{
		qDebug() << "good username";
		isAvailableUserName = true;
		ui->userMessage->setText(QString::fromLocal8Bit("该用户名可用！"));
		ui->userMessage->setStyleSheet("color:green;");
		ui->userMessage->show();
		////唤醒UI显示用户名可用！

		//设置图标
		QPixmap Pix("Resource/ion/correct.png");
		ui->userLogo->setPixmap(Pix);
		ui->userLogo->show();
	}
	else if (QString::compare(data, "RCS_F") == 0)
	{
		qDebug() << "this studentId is ok";
		isAvailableStudentId = true;
		ui->studentIdLabel->setText(QString::fromLocal8Bit("该学号尚未注册！"));
		ui->studentIdLabel->setStyleSheet("color:green;");
		ui->studentIdLabel->show();
		////唤醒UI显示用户名可用！

		//设置图标
		QPixmap Pix("Resource/ion/correct.png");
		ui->studentIdLogo->setPixmap(Pix);
		ui->studentIdLogo->show();
	}
	else if (QString::compare(data, "RCS_T") == 0)
	{
		qDebug() << "this studentId is not ok";

		ui->studentIdLabel->setText(QString::fromLocal8Bit("该学号已经注册！"));
		ui->studentIdLabel->setStyleSheet("color:red;");
		ui->studentIdLabel->show();
		////唤醒UI显示用户名可用！

		//设置图标
		QPixmap Pix("Resource/ion/error.png");
		ui->studentIdLogo->setPixmap(Pix);
		ui->studentIdLogo->show();
	}
}

//接收信号
void Register::receiveLogin()
{
	this->show();   //显示注册窗口
}
