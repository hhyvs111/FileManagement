#include "FileManagement.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FileManagement w;
	

	w.show();
	return a.exec();
}
