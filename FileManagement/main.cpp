#include"stdafx.h"
#include "Login.h"
#include "FileManagement.h"

#include "Register.h"
#include "UploadFile.h"
#include "MyMessageBox.h"

#include <QtWidgets/QApplication>
#include <qApplication.h>
#include <QResource>


//定义全局变量


int main(int argc, char *argv[])
{
	//图片文件打包
	QResource::registerResource("FileManagement.rcc");
	QApplication a(argc, argv);
	QApplication::addLibraryPath("./plugins");
	Login L;
	Register R;
	FileManagement F;
	//这里出个BUG，不能先初始化R，要先初始化L

	L.show();
	//槽函数，实现跳转
	QObject::connect(&L, SIGNAL(showRegister()), &R, SLOT(receiveLogin()));
	QObject::connect(&L, SIGNAL(showMain()), &F, SLOT(receiveLogin()));
	QObject::connect(&R, SIGNAL(showLogin()), &L, SLOT(receiveRegister()));
	QObject::connect(&F, SIGNAL(showLogin()), &L, SLOT(receiveMain()));
	return a.exec();
}
