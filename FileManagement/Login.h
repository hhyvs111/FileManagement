#pragma once

#include <QtWidgets/QDialog>
#include "ui_Login.h"

class Login : public QDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();
	

private:
	Ui::Login *ui;

public slots:
	void Click_Login();  //µã»÷µÇÂ½

	void Click_Register();  //µã»÷Ìø×ªµ½×¢²á¿ò

signals:
	void showMain();
	void showRegister();
};

#ifndef LOGIN_H_
#define LOGIN_H_

#endif // LOGIN_H_

