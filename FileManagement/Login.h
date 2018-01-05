#pragma once


#include <QtWidgets/QDialog>
#include "ui_Login.h"

class Login : public QDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);

private:
	Ui::Login ui;

//ï¿½Ûºï¿½ï¿½ï¿½
public slots:
	void Click_Login();

	void Click_Register();  //µã»÷Ìø×ªµ½×¢²á¿ò

signals:
	void showMain();
	void showRegister();
};

#ifndef LOGIN_H_
#define LOGIN_H_
//132112
#endif // LOGIN_H_

