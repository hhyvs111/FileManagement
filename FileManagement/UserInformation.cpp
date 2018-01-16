#include "UserInformation.h"
#include "ui_UserInformation.h"
#include <QIcon>
#include <QPixmap>


UserInformation::UserInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInformation)
{
    ui->setupUi(this);

	//每次打开该页面则发查询信息发过去
	QString data = "QueryUserInfo#" + globalUserName;
	QByteArray datasend = data.toLocal8Bit();
	tcp->tcpSocket->write(datasend);



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

   //    this->setStyleSheet("background:gray");
   //    name = "abc";
   //    ui->nameLineEdit->setText(name);
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
    ui->nameLineEdit->setReadOnly(false);
    ui->IDlineEdit->setReadOnly(false);
    ui->phoneLineEdit->setReadOnly(false);
    ui->QQlineEdit->setReadOnly(false);
    ui->addressLineEdit->setReadOnly(false);

    //编辑栏显示
    ui->nameLineEdit->setStyleSheet("border-style:solid;border-width:1px");
    ui->IDlineEdit->setStyleSheet("border-style:solid;border-width:1px");
    ui->phoneLineEdit->setStyleSheet("border-style:solid;border-width:1px");
    ui->QQlineEdit->setStyleSheet("border-style:solid;border-width:1px");
    ui->addressLineEdit->setStyleSheet("border-style:solid;border-width:1px");

    //还原编辑状态
    ui->nameLineEdit->setDisabled(false);
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

}

void UserInformation::on_cancelButton_clicked()
{
    ui->alterButton->show();
    ui->cancelButton->hide();
    ui->confirmButton->hide();

    ui->nameLineEdit->setReadOnly(false);
    ui->nameLineEdit->setDisabled(true);
    ui->nameLineEdit->setText(userName);

    ui->IDlineEdit->setReadOnly(false);
    ui->IDlineEdit->setDisabled(true);
    ui->IDlineEdit->setText(studentId);

    ui->phoneLineEdit->setReadOnly(false);
    ui->phoneLineEdit->setDisabled(true);
    ui->phoneLineEdit->setText(phoneNumber);

    ui->QQlineEdit->setReadOnly(false);
    ui->QQlineEdit->setDisabled(true);
    ui->QQlineEdit->setText(qqNumber);

    ui->addressLineEdit->setReadOnly(false);
    ui->addressLineEdit->setDisabled(true);
    ui->addressLineEdit->setText(mail);

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
