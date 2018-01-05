#include "FileManagement.h"
#include "Login.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//FileManagement w;
	Login l;
	l.show();
	return a.exec();
}
