#include "Accounting.h"

Accounting::Accounting(QWidget *parent) :
	QWidget(parent), ui(new Ui::Accounting)
{
	ui->setupUi(this);
}


Accounting::~Accounting()
{
}
