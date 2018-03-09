#include "DownloadManage.h"
#include "MyMessageBox.h"

DownloadManage::DownloadManage(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::DownloadManage)
{
	ui->setupUi(this);
}

DownloadManage::~DownloadManage()
{

}