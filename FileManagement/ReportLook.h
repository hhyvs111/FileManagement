#pragma once

#ifndef REPORTLOOK_H_
#define REPORTLOOK_H_
#include "stdafx.h"
#include "Report.h"
#include "ui_ReportLook.h"
#include <QStandardItemModel>
#include <qtoolbutton.h>
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
	

private:
	Ui::ReportLook *ui;

	QStandardItemModel *model;
	QToolButton *m_look;
	QToolButton *m_delete;

	QComboBox *TermComboBox;
	QComboBox *WeekComboBox;



	//判断这两个combox是否已经插入了
	bool isWeekCombox = false,
		isTermCombox = false;

private slots:
	//显示从服务器接收的list
	void showReportList();

	void receiveDataFromClient(QString);
	// 初始化qtableview，就是初始化model
	void initModel(); 

	void init();
	void showToolTip(const QModelIndex &index);

	//点击条件查询按钮
	void ClickFindButton();

	//点击学期后插入周数的combobox
	void insertWeekComboBox(int);
	void insertTermComboBox(int);
	//查看我的报告的按钮
	void ClickLookMyReportButton();

	//查看报告按钮
	void ClickLookReportButton();

	//删除报告按钮
	void ClickDeleteButton();


};
#endif // !REPORTLOOK_H_
