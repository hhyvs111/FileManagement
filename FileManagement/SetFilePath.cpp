#include "SetFilePath.h"
#include <QFileDialog>



SetFilePath::SetFilePath(QWidget *parent) :
	BaseWindow(parent),
	ui(new Ui::SetFilePath)
{
	ui->setupUi(this);
}


SetFilePath::~SetFilePath()
{
}

void SetFilePath::selectFilePath()
{
	filePath = QFileDialog::getExistingDirectory(this);
	ui->filePathLine->setText(filePath);
}

void SetFilePath::defaultPath()
{
	QDir *temp = new QDir;
	bool exist = temp->exists("D:/download");
	if (exist)
	{
		qDebug() << "the dir is exists!";
	}
	//QMessageBox::warning(this, tr(“创建文件夹”), tr(“文件夹已经存在！”));
	else
	{
		bool ok = temp->mkdir("D:/download");
		
	}
	filePath = "D:/download";
	ui->filePathLine->setText(filePath);
	emit sendFilePath(filePath + "/");
}
void SetFilePath::ClickSaveButton()
{
	this->close();
	emit sendFilePath(filePath + "/");
}