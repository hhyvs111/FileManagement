#include"stdafx.h"
#include "Login.h"
#include "FileManagement.h"

#include "Register.h"
#include "Database.h"
#include "UploadFile.h"
#include "MyMessageBox.h"
#include <Qdir.h>
#include <QtWidgets/QApplication>
#include <qApplication.h>


//定义全局变量


int main(int argc, char *argv[])
{

	QString strLibPath(QDir::toNativeSeparators(QApplication::applicationDirPath()) +
		QDir::separator() + "plugins");  
	
	QApplication a(argc, argv);
	FileManagement F;
	Login L;
	Register R;
	UploadFile U;
	L.show();

	//槽函数，实现跳转
	QObject::connect(&L, SIGNAL(showRegister()), &R, SLOT(receiveLogin()));
	QObject::connect(&L, SIGNAL(showMain()), &F, SLOT(receiveLogin()));
	QObject::connect(&R, SIGNAL(showLogin()), &L, SLOT(receiveRegister()));
	QObject::connect(&F, SIGNAL(showUploadFile()), &U, SLOT(receiveMainwindow()));
	return a.exec();
}
