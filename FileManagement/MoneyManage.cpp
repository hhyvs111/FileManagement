#include "MoneyManage.h"
#include "Echarts.h"

MoneyManage::MoneyManage(QWidget *parent) :
	QWidget(parent), ui(new Ui::MoneyManage)
{
	ui->setupUi(this);
	//ui->ShowLastLabel->setPixmap(QPixmap(":/Resource/moneyBackground.jpg"));
	Echarts *echarts = new Echarts();
	ui->verticalLayout->addWidget(echarts);
}


MoneyManage::~MoneyManage()
{
	delete ui;
}

void MoneyManage::sendAccountLook(QString condition )
{

}