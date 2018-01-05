#include "FileManagement.h"
#include "Login.h"
#include "Register.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//FileManagement w;
	Login L;
	Register R;
	L.show();
	QObject::connect(&L, SIGNAL(showRegister()), &R, SLOT(receiveLogin()));
	return a.exec();
}
