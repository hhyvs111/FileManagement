#include "FileManagement.h"
#include "UploadFile.h"
#include <QMessageBox> 

extern QString globalUserName;
FileManagement::FileManagement(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::FileManagement)
{
	ui->setupUi(this);

	qDebug() << globalUserName << " welcome! ";
	//UploadFile U;
	//connect(this, SIGNAL(showUploadFile()), &U, SLOT(receiveMainwindow()));
}

FileManagement::~FileManagement()
{
	delete ui;
}

void FileManagement::receiveLogin()
{
	this->show();
}
void FileManagement::Btn_Click()
{
	QMessageBox msg;
	msg.setText("hello world!");
	msg.exec();
}

void FileManagement::ClickUploadFile()
{
	UploadFile *U = new UploadFile();
	U->show();
	//emit showUploadFile();
}
