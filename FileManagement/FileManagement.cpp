#include "FileManagement.h"
#include <QMessageBox> 
FileManagement::FileManagement(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void FileManagement::Btn_Click()
{
	QMessageBox msg;
	msg.setText("hello world!");
	msg.exec();
}
