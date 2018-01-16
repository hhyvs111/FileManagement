#include"stdafx.h"
#include "Login.h"
#include "FileManagement.h"

#include "Register.h"
#include "UploadFile.h"
#include "MyMessageBox.h"

#include <QtWidgets/QApplication>
#include <qApplication.h>


//定义全局变量


int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	FileManagement F;
	Login L;
	Register R;
	L.show();

	//槽函数，实现跳转
	QObject::connect(&L, SIGNAL(showRegister()), &R, SLOT(receiveLogin()));
	QObject::connect(&L, SIGNAL(showMain()), &F, SLOT(receiveLogin()));
	QObject::connect(&R, SIGNAL(showLogin()), &L, SLOT(receiveRegister()));
	return a.exec();
}
