
#pragma once
#include "stdafx.h"
#include "Report.h"
#include "BaseWindow.h"
#include"ui_ReportDetail.h"

#ifndef REPORTDETAIL_H_
#define REPORTDETAIL_H_

extern TcpClient * tcp;    //全局变量，TCP 长连接
extern QString globalUserName;



class ReportDetail : public BaseWindow
{
	Q_OBJECT
public:
	ReportDetail(QString,QWidget *parent = Q_NULLPTR);
	~ReportDetail();

	void sendReportDetail(QString);  //发送接收界面请求

private:
	Ui::ReportDetail *ui;
	ReportInfo reportInfo;
	void init();
	//void initTitleBar();



private slots:
	void receiveDataFromClient(QString);
	void showReport();  //显示报告人的信息
	
	//修改
	//void sendReport();  //发送报告

	//点击删除按钮
	void ClickDeleteButton();

	//点击修改按钮
	void ClickUpdateButton();
	//void ClickReset();

};
#endif // !REPORTDetail_H_
