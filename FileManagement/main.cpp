#include "FileManagement.h"
#include "Login.h"
#include "Register.h"
#include "Database.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FileManagement F;
	Login L;
	Register R;
	L.show();
	
	MySql *mysql = new MySql();
	mysql->initsql();

	QObject::connect(&L, SIGNAL(showRegister()), &R, SLOT(receiveLogin()));
	QObject::connect(&L, SIGNAL(showMain()), &F, SLOT(receiveLogin()));
	return a.exec();
}
