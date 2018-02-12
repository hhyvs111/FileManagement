#pragma once
#include "stdafx.h"
#include "Report.h"
#include "ui_ReportLook.h"
#include <QStandardItemModel>
#ifndef REPORTLOOK_H_
#define REPORTLOOK_H_

extern TcpClient * tcp;    //全局变量，TCP 长连接
extern QString globalUserName;

class ReportLook :public QWidget
{
	Q_OBJECT

		//public 写函数！
public:
	ReportLook(QWidget *parent = Q_NULLPTR);
	~ReportLook();

	//发送查看条件到服务器服务器，默认为ALL
	void sendReportLook(QString condition = "all");

	// 加载样式文件;
	void loadStyleSheet(const QString &sheetName);

	//提示文本
	void showToolTip(const QModelIndex &index);

private:
	Ui::ReportLook *ui;

	QStandardItemModel *model;
	QPushButton *m_look;
	QPushButton *m_delete;

private slots:
	//显示从服务器接收的list
	void showReportList();

	//void receiveDataFromClient(QString);
	// 初始化qtableview，就是初始化model
	void initModel(); 

	//点击条件查询按钮
	void ClickFindButton();

	//查看我的报告的按钮
	void ClickLookMyReportButton();

	//查看报告按钮
	void ClickLookReportButton();



};
#endif // !REPORTLOOK_H_
