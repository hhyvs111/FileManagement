#pragma once
#include <QWidget>
#include "TitleBar.h"


class BaseWindow : public QWidget
{
	Q_OBJECT

public:
	BaseWindow(QWidget *parent = 0);
	~BaseWindow();
	void loadStyleSheet(const QString &sheetName);

private:
	void initTitleBar();
	void paintEvent(QPaintEvent *event);

	private slots:
	void onButtonMinClicked();
	void onButtonRestoreClicked();
	void onButtonMaxClicked();
	void onButtonCloseClicked();

protected:
	TitleBar* m_titleBar;
	

};