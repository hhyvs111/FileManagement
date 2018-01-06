#pragma once

#include <QtWidgets/QDialog>
#include "ui_Register.h"

class Register : public QDialog
{
	Q_OBJECT

public:
	Register(QWidget *parent = Q_NULLPTR);
	~Register();

private:
	Ui::Register *ui;
	bool isAvailableUserName;

	//槽函数
public slots:
	void Click_Register();
	void Click_CheckUser();
	void Click_Reset();

	void receiveLogin();  //接收login中发射的信号关联的槽函数
signals:
	void showMain();
	void showLogin();
};
