#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FileManagement.h"

class FileManagement : public QMainWindow
{
	Q_OBJECT

public:
	FileManagement(QWidget *parent = Q_NULLPTR);

private:
	Ui::FileManagementClass ui;

public slots:
void Btn_Click();
};
