#include "UserInformation.h"
#include "MyMessageBox.h"
#include "ui_UserInformation.h"
#include "SignShow.h"
#include <QIcon>
#include <QPixmap>
#include "Sign.h"


UserInformation::UserInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInformation)
{
    ui->setupUi(this);

       ui->cancelButton->hide();
       ui->confirmButton->hide();

       QPixmap pix = QPixmap("D://code/LabApp/Information/pic.jpg");
       ui->picLabel->setPixmap(pix);

       //编辑栏初始状态不可编辑
       ui->nameLineEdit->setReadOnly(true);
       ui->IDlineEdit->setReadOnly(true);
       ui->phoneLineEdit->setReadOnly(true);
       ui->QQlineEdit->setReadOnly(true);
       ui->addressLineEdit->setReadOnly(true);

       //边框取消
       ui->nameLineEdit->setStyleSheet("border-style:outset");
       ui->IDlineEdit->setStyleSheet("border-style:outset");
       ui->phoneLineEdit->setStyleSheet("border-style:outset");
       ui->QQlineEdit->setStyleSheet("border-style:outset");
       ui->addressLineEdit->setStyleSheet("border-style:outset");

	   connect(ui->SignButton, SIGNAL(clicked()), this, SLOT(sendSignToServer()));
	   connect(ui->LookSignButton, SIGNAL(clicked()), this, SLOT(showSignList()));
	   connect(ui->LookMySignButton, SIGNAL(clicked()), this, SLOT(showMySign()));
	   
	   connect(tcp, SIGNAL(sendDataToSign(QString)), this, SLOT(receiveDataFromClient(QString)));

}

UserInformation::~UserInformation()
{
    delete ui;
}


void UserInformation::on_alterButton_clicked()
{
    ui->alterButton->hide();//修改按钮
    ui->cancelButton->show();//取消按钮
    ui->confirmButton->show();//确认按钮
    //ui->passAlterButton->hide();//密码修改按钮

    //显示编辑状态
    //ui->nameLineEdit->setReadOnly(false);
    ui->IDlineEdit->setReadOnly(false);
    ui->phoneLineEdit->setReadOnly(false);
    ui->QQlineEdit->setReadOnly(false);
    ui->addressLineEdit->setReadOnly(false);

    //编辑栏显示
    //ui->nameLineEdit->setStyleSheet("border-style:solid;border-width:1px");
    ui->IDlineEdit->setStyleSheet("border-style:solid;border-width:1px");
    ui->phoneLineEdit->setStyleSheet("border-style:solid;border-width:1px");
    ui->QQlineEdit->setStyleSheet("border-style:solid;border-width:1px");
    ui->addressLineEdit->setStyleSheet("border-style:solid;border-width:1px");

    //还原编辑状态
    //ui->nameLineEdit->setDisabled(false);
    ui->IDlineEdit->setDisabled(false);
    ui->addressLineEdit->setDisabled(false);
    ui->QQlineEdit->setDisabled(false);
    ui->phoneLineEdit->setDisabled(false);


}

void UserInformation::on_confirmButton_clicked()
{
    ui->alterButton->show();
    ui->confirmButton->hide();
    ui->cancelButton->hide();

    ui->nameLineEdit->setReadOnly(true);
    ui->IDlineEdit->setReadOnly(true);
    ui->phoneLineEdit->setReadOnly(true);
    ui->QQlineEdit->setReadOnly(true);
    ui->addressLineEdit->setReadOnly(true);

    ui->nameLineEdit->setStyleSheet("border-style:outset");
    ui->IDlineEdit->setStyleSheet("border-style:outset");
    ui->phoneLineEdit->setStyleSheet("border-style:outset");
    ui->QQlineEdit->setStyleSheet("border-style:outset");
    ui->addressLineEdit->setStyleSheet("border-style:outset");


	//把用户信息发给tcp，包括学号手机号和QQ还有email

	QString data = "alterUserInfo#" +  ui->nameLineEdit->text() + "#"+ ui->IDlineEdit->text() 
		+ "#" + ui->phoneLineEdit->text() + "#" + ui->QQlineEdit->text()
		+ "#" + ui->addressLineEdit->text();
	QByteArray datasend = data.toUtf8();
	qDebug() << datasend;
	tcp->tcpSocket->write(datasend);

}

void UserInformation::on_cancelButton_clicked()
{
    ui->alterButton->show();
    ui->cancelButton->hide();
    ui->confirmButton->hide();

    ui->nameLineEdit->setReadOnly(false);
    ui->nameLineEdit->setDisabled(true);
    //ui->nameLineEdit->setText(userName);

    ui->IDlineEdit->setReadOnly(false);
    ui->IDlineEdit->setDisabled(true);
    //ui->IDlineEdit->setText(studentId);

    ui->phoneLineEdit->setReadOnly(false);
    ui->phoneLineEdit->setDisabled(true);
    //ui->phoneLineEdit->setText(phoneNumber);

    ui->QQlineEdit->setReadOnly(false);
    ui->QQlineEdit->setDisabled(true);
    //ui->QQlineEdit->setText(qqNumber);

    ui->addressLineEdit->setReadOnly(false);
    ui->addressLineEdit->setDisabled(true);
    //ui->addressLineEdit->setText(mail);

    ui->nameLineEdit->setStyleSheet("border-style:outset");
    ui->IDlineEdit->setStyleSheet("border-style:outset");
    ui->phoneLineEdit->setStyleSheet("border-style:outset");
    ui->QQlineEdit->setStyleSheet("border-style:outset");
    ui->addressLineEdit->setStyleSheet("border-style:outset");


}

void UserInformation::on_passAlterButton_clicked()
{
//    ui->confirmButton->show();
//    ui->cancelButton->show();
//    ui->passAlterButton->hide();
}

void UserInformation::sendUserInfo()
{
	//每次打开该页面则发查询信息发过去
	QString data = "QueryUserInfo#" + globalUserName;
	QByteArray datasend = data.toLocal8Bit();
	qDebug() << datasend;
	tcp->tcpSocket->write(datasend);

	//暂时取消TCP原本的验证消息
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	connect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(showUserInfo()));
}

void UserInformation::showUserInfo()
{
	//接受来自数据库的用户信息
	QByteArray dataread = tcp->tcpSocket->readAll();
	QString data = QString::fromLocal8Bit(dataread);
	qDebug() << "the data from client: " << data;
	QStringList list = data.split("#");  //用#分割
	
	ui->nameLineEdit->setText(list[0]);
	ui->IDlineEdit->setText(list[2]);
	ui->phoneLineEdit->setText(list[3]);
	ui->QQlineEdit->setText(list[4]);
	ui->addressLineEdit->setText(list[5]);
	
	//用完后把连接断开
	connect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(showUserInfo()));
}

void UserInformation::sendSignToServer()
{
	QString data = "InsertSign#" + globalUserName;
	QByteArray datasend = data.toUtf8();
	qDebug() << datasend;
	tcp->tcpSocket->write(datasend);


}

void UserInformation::showSignList()
{
	Sign *sign = new Sign(this);
	ui->SignLayout->addWidget(sign);
	sign->show();
}

void UserInformation::showMySign()
{
	SignShow *sign = new SignShow();
	sign->show();

}

void UserInformation::receiveDataFromClient(QString data)
{
	if (QString::compare(data, "sign_T") == 0)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromUtf8("提示"), QString::fromUtf8("签到成功!"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);

	}
	else if (QString::compare(data, "repeat") == 0)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromUtf8("提示"), QString::fromUtf8("今天已经签到,请勿重复签到!"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}
	else if (QString::compare(data, "notInLab") == 0)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromUtf8("提示"), QString::fromUtf8("请回实验室签到!"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}
	else if (QString::compare(data, "sign_F") == 0)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromUtf8("提示"), QString::fromUtf8("签到失败!"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}
}