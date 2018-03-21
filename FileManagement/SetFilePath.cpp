#include "SetFilePath.h"
#include <QFileDialog>



SetFilePath::SetFilePath(QWidget *parent) :
	BaseWindow(parent),
	ui(new Ui::SetFilePath)
{
	ui->setupUi(this);
	ui->filePathLine->setText(filePath);
}


SetFilePath::~SetFilePath()
{
}

void SetFilePath::selectFilePath()
{
	filePath = QFileDialog::getExistingDirectory(this);
	ui->filePathLine->setText(filePath);
}
void SetFilePath::ClickSaveButton()
{
	this->close();
	emit sendFilePath(filePath + "/");
}