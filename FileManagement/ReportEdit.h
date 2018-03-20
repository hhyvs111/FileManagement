#pragma once
#include "stdafx.h"
#include "Report.h"
#include"ui_ReportEdit.h"

#ifndef REPORTEDIT_H_
#define REPORTEDIT_H_

extern TcpClient * tcp;    //全局变量，TCP 长连接
extern QString globalUserName;

class ReportEdit : public QWidget
{
	Q_OBJECT
public:
	ReportEdit(QWidget *parent = Q_NULLPTR);
	~ReportEdit();

	void sendReportEdit();  //发送接收界面请求

private:
	Ui::ReportEdit *ui;
	ReportInfo reportInfo;
	void init();
	void loadStyleSheet(const QString &sheetName);  //加载样式

	

private slots:
	void receiveDataFromClient(QString);
	void showReporter();  //显示报告人的信息
	void showLastWeek();
	void sendLastWeek();  //发送
	void sendReport();  //发送报告
	void ClickSubmit(); 
	//void ClickReset();

};
#endif // !REPORTEDIT_H_
