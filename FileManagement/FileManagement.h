#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FileManagement.h"

class FileManagement : public QMainWindow
{
	Q_OBJECT

public:
	FileManagement(QWidget *parent = Q_NULLPTR);
	~FileManagement();

private:
	Ui::FileManagement *ui;

private slots:
void Btn_Click();


void receiveLogin();


};
