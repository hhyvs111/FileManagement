#ifndef INFORMATIOM_H
#define INFORMATIOM_H

#include"stdafx.h"
#include"ui_UserInformation.h"
#include <QWidget>

extern TcpClient * tcp;
extern QString globalUserName;

namespace Ui {
class UserInformation;
}

class UserInformation : public QWidget
{
    Q_OBJECT

public:
    explicit  UserInformation(QWidget *parent = 0);
    ~UserInformation();
	void sendUserInfo();

	void firstLogin();

 private slots:
    void on_alterButton_clicked();

    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

    void on_passAlterButton_clicked();

	void showUserInfo();

	void sendSignToServer();
	void showSignList();
	void receiveDataFromClient(QString data);

	
private:
    Ui::UserInformation *ui;
	QString userName;
	QString userPassword;
	QString studentId;
	QString phoneNumber;
	QString qqNumber;
	QString mail;
	QString trueName;
	QString term;
	QString level;
	QString teacher;


};

#endif // INFORMATIOM_H
