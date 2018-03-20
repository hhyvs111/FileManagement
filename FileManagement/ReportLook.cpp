#include "ReportLook.h"
#include "MyMessageBox.h"
#include "ReportDetail.h"
#include <QToolTip>


ReportLook::ReportLook(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ReportLook)
{
	ui->setupUi(this);
	initModel();
	init();
	ui->tableView->setMouseTracking(true);   //设置鼠标追踪

	connect(ui->tableView, SIGNAL(entered(QModelIndex)),
		this, SLOT(showToolTip(QModelIndex)));
	//连接
	connect(ui->selectcomboBox, SIGNAL(activated(int)), this, SLOT(insertTermComboBox(int)));
	connect(tcp, SIGNAL(sendDataToReportLook(QString)), this, SLOT(receiveDataFromClient(QString)));
}
ReportLook::~ReportLook()
{
	delete ui;
}

//初始化一下这个界面
void ReportLook::init()
{

	//给输入框加个按钮
	ui->condition->setMinimumHeight(30);
	ui->condition->setTextMargins(0, 0, 30, 0);
	//ui->condition->setPlaceholderText(QString::fromLocal8Bit("请输入用户名"));

	QToolButton *find = new QToolButton();
	find->setMaximumSize(40, 40);
	find->setCursor(Qt::PointingHandCursor);
	find->setIcon(QIcon(":/Resource/icon/lookReport.png"));
	find->setIconSize(QSize(20, 20));//根据实际调整图片大小
	find->setStyleSheet("border:none");

	QSpacerItem *spaceItem1 = new QSpacerItem(150, 40, QSizePolicy::Expanding);
	QHBoxLayout *editLayout1 = new QHBoxLayout();
	editLayout1->setContentsMargins(1, 0, 1, 0);
	editLayout1->addSpacerItem(spaceItem1);
	editLayout1->addWidget(find);
	ui->condition->setLayout(editLayout1);
	connect(find, SIGNAL(clicked()), this, SLOT(ClickFindButton()));
	
}
//设置表头以及一些属性
void ReportLook::initModel()
{
	model = new QStandardItemModel();
	model->setColumnCount(9);
	ui->tableView->setShowGrid(false);
	ui->tableView->verticalHeader()->setVisible(false);// 垂直不可见
	//ui->tableView->horizontalHeader()->setVisible(false);// 水平不可见
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("用户名"));
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("学期"));
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("周数"));
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("内容概要"));
	model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("时间"));
	model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("姓名"));
	model->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("查看"));
	model->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("删除"));

	ui->tableView->setModel(model);
	ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui->tableView->setColumnWidth(0, 30);
	ui->tableView->setColumnWidth(1, 80);
	ui->tableView->setColumnWidth(2, 50);
	ui->tableView->setColumnWidth(3, 30);
	ui->tableView->setColumnWidth(4, 120);
	ui->tableView->setColumnWidth(5, 120);
	ui->tableView->setColumnWidth(6, 50);
	ui->tableView->setColumnWidth(7, 40);
	ui->tableView->setColumnWidth(8, 40);

	//设置列宽不可变 
	ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(7, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(8, QHeaderView::Fixed);
	ui->tableView->setAlternatingRowColors(true);//设置换行改变颜色
}

//插入周数的选择
void ReportLook::insertWeekComboBox(int index)
{
	//选择的是第三行，默认为2
	if (!isWeekCombox) 
	{
		WeekComboBox = new QComboBox();
		WeekComboBox->addItem(QString::fromLocal8Bit("all"));
		//二十周
		for (int i = 1;i <= 20;i++)
		{
			WeekComboBox->addItem(QString::number(i,10));
		}
		ui->comboboxLayout->addWidget(WeekComboBox);
		isWeekCombox = true;
	}
}

void ReportLook::insertTermComboBox(int index)
{	
	//如果选择的是学期，且学期combox还没插入到layout
	if (index == 2 && !isTermCombox)
	{
		TermComboBox = new QComboBox();
		TermComboBox->insertItems(0, QStringList()
			<< QApplication::translate("ReportLook", "\347\240\224\344\270\200\344\270\212", Q_NULLPTR)
			<< QApplication::translate("ReportLook", "\347\240\224\344\270\200\344\270\213", Q_NULLPTR)
			<< QApplication::translate("ReportLook", "\347\240\224\344\272\214\344\270\212", Q_NULLPTR)
			<< QApplication::translate("ReportLook", "\347\240\224\344\272\214\344\270\213", Q_NULLPTR)
			<< QApplication::translate("ReportLook", "\347\240\224\344\270\211\344\270\212", Q_NULLPTR)
			<< QApplication::translate("ReportLook", "\347\240\224\344\270\211\344\270\213", Q_NULLPTR)
		);
		ui->comboboxLayout->addWidget(TermComboBox);
		isTermCombox = true;
		connect(TermComboBox, SIGNAL(activated(int)), this, SLOT(insertWeekComboBox(int)));
	}
	//如果已经打开了但是后面又选了其他的，则要删除
	else if (index != 2 && isTermCombox)
	{
		TermComboBox->deleteLater();
		WeekComboBox->deleteLater();
		//ui->comboboxLayout->removeWidget(WeekComboBox);
		isTermCombox = false;
		isWeekCombox = false;
	}
}
void ReportLook::showToolTip(const QModelIndex &index) {
	if (!index.isValid()) {
		qDebug() << "Invalid index";
		return;
	}
	QToolTip::showText(QCursor::pos(), index.data().toString());
}

void ReportLook::sendReportLook(QString condition)
{
	//每次打开该页面则发查询信息发过去
	QString data = "lookReport#" + condition;   //查询所有的报告
	QByteArray datasend = data.toUtf8();
	qDebug() << datasend;
	tcp->tcpSocket->write(datasend);

	//暂时取消TCP原本的验证消息
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	connect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(showReportList()));
}

void ReportLook::showReportList()
{
	initModel();
	QByteArray dataread = tcp->tcpSocket->readAll();
	QString data = QString::fromUtf8(dataread);
	qDebug() << "show report the data from client: " << dataread;
	QStringList listNumber = data.split("$");

	QList<ReportInfo> reportInfo;
	//在这里就要加入到表里去
	//把数据都放到QList里去！
	//listNumber[0] 是文件个数
	for (int i = 1;i <= listNumber[0].toInt();i++)
	{
		ReportInfo littleReport;
		QStringList reportList = listNumber[i].split("#");
		littleReport.reportId = reportList[0];  //ID不需要显示
		littleReport.reportUserName = reportList[1];
		littleReport.reportTerm = reportList[2];
		littleReport.reportWeek = reportList[3];
		littleReport.reportMain = reportList[4];
		littleReport.reportTime = reportList[5];
		littleReport.reportName = reportList[6];
		littleReport.reportQuestionForSolve = reportList[7];
		littleReport.reportQuestionHasSolved = reportList[8];
		littleReport.reportQuestionFromLastWeek = reportList[9];
		littleReport.reportYourGet = reportList[10];
		littleReport.reportUserId = reportList[11].toInt();  //这个也不需要显示

		qDebug() << littleReport.reportId << " " << littleReport.reportUserName << " " <<
			littleReport.reportTerm << " " << littleReport.reportWeek << " "
			<< littleReport.reportMain << " " << littleReport.reportTime << " " << littleReport.reportName;
		//将这个报告加入报告list
		reportInfo.append(littleReport);
	}
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	for (int i = 0; i < listNumber[0].toInt(); i++)
	{
		//设置前四列的数据
		model->setItem(i, 1, new QStandardItem(reportInfo.at(i).reportUserName));
		model->setItem(i, 2, new QStandardItem(reportInfo.at(i).reportTerm));  //countFileSize根据大小显示KB还是MB
		model->setItem(i, 3, new QStandardItem(reportInfo.at(i).reportWeek));
		model->setItem(i, 4, new QStandardItem(reportInfo.at(i).reportMain));
		model->setItem(i, 5, new QStandardItem(reportInfo.at(i).reportTime));
		model->setItem(i, 6, new QStandardItem(reportInfo.at(i).reportName));

		//为这个第五列添加按钮
		m_look = new QToolButton();
		QIcon lookReport(":/Resource/icon/lookReport.png"); //创建QIcon对象
		m_look->setIcon(lookReport); //将图片设置到按钮上
		m_look->setIconSize(QSize(20, 20));//根据实际调整图片大小
		m_look->setStyleSheet("border:none");

		m_look->setCursor(Qt::PointingHandCursor);

		m_delete = new QToolButton();
		QIcon deleteReport(":/Resource/icon/deleteFile.png"); //创建QIcon对象
		m_delete->setIcon(deleteReport); //将图片设置到按钮上
		m_delete->setIconSize(QSize(20, 20));//根据实际调整图片大小
		m_delete->setStyleSheet("border:none");
		m_delete->setCursor(Qt::PointingHandCursor);

		//触发下载按钮的槽函数
		connect(m_look, SIGNAL(clicked(bool)), this, SLOT(ClickLookReportButton()));
		connect(m_delete, SIGNAL(clicked(bool)), this, SLOT(ClickDeleteButton()));
		//直接把文件名发给row得了！

		m_look->setProperty("row", i);  //为按钮设置row属性

		m_look->setProperty("reportId", reportInfo.at(i).reportId);  //为按钮设置filename属性


		m_delete->setProperty("row", i);
		m_delete->setProperty("deleteReportId", reportInfo.at(i).reportId);


		ui->tableView->setIndexWidget(model->index(model->rowCount() - 1, 7), m_look);
		ui->tableView->setIndexWidget(model->index(model->rowCount() - 1, 8), m_delete);

		//这里设置一下头像，暂时没有

		//QIcon icon = fileIcon(fileInfo.at(i).fileType);
		//QPixmap pixmap = icon.pixmap(icon.actualSize(QSize(20, 30)));
		//QLabel *fIcon = new QLabel();
		//fIcon->setPixmap(pixmap);
		//ui->downloadTable->setIndexWidget(model->index(model->rowCount() - 1, 0), fIcon);

		//设置数据居中
		for (int j = 2;j < 7;j++)
			model->item(i, j)->setTextAlignment(Qt::AlignCenter);
	}
	//m_model->setData(data);
	//用完后断开
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(showReportList()));
	connect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));

}

void ReportLook::ClickLookReportButton()
{
	QPushButton *btn = (QPushButton *)sender();   //产生事件的对象，按的谁就取谁
	QString row = btn->property("row").toString();  //取得按钮的row属性
	qDebug() << "the row is: " << row;
	
	QString ReportId = btn->property("reportId").toString();  //获取按钮的id属性
	qDebug() << "the ReportId is: " << ReportId;
	//直接调用一个ReportDetail界面出来
	ReportDetail *reportDetail = new ReportDetail(ReportId);
	////设置窗口背景色
	//QPalette Pal(palette());
	//// set black background
	//Pal.setColor(QPalette::Background, Qt::green);
	//reportDetail->setAutoFillBackground(true);
	//reportDetail->setPalette(Pal);
	//reportDetail->raise();
	reportDetail->show();
}

void ReportLook::ClickDeleteButton()
{
	QPushButton *btn = (QPushButton *)sender();   //产生事件的对象，按的谁就取谁
	QString row = btn->property("row").toString();  //取得按钮的row属性
	qDebug() << "the row is: " << row;

	QString ReportId = btn->property("deleteReportId").toString();  //获取按钮的id属性
	qDebug() << "the ReportId is: " << ReportId;

	if (!MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("确定要删除该报告吗？"),
		MESSAGE_QUESTION, BUTTON_OK_AND_CANCEL, true))
	{
		QString bs = "deleteReport";
		QString data = bs + "#" + ReportId;

		QByteArray datasend = data.toUtf8();
		if (tcp->tcpSocket->write(datasend))
		{
			qDebug() << "send data to server: " << data;

		}
		else
			qDebug() << "send failed!";
	}

}
 
//查看我的报告
void ReportLook::ClickLookMyReportButton()
{
	//发送用户名过去
	sendReportLook("UserName#" + globalUserName);
}

void ReportLook::ClickFindButton()
{
	//这个是输入框的值
	QString condition = ui->condition->text();
	QString data = "";

	bool WeekIsAll = true;
	//如果周数选择的是ALL则为真
	if (isWeekCombox)
	{
		WeekIsAll = (QString::compare(WeekComboBox->currentText(), "all") == 0);
		qDebug() << "the WeekIsAll :" << WeekIsAll;
		qDebug() << "the week :" << WeekComboBox->currentText();
	}
	
	//如果这学期和周数都打开了则代表要选周数
	if (isTermCombox && isWeekCombox)
	{
		if (condition.isEmpty() && !WeekIsAll)
			//学期和周数
		{
			data += "TW#";
			data += TermComboBox->currentText() + "#" + WeekComboBox->currentText();
		}
		else if (!condition.isEmpty() && !WeekIsAll)
		{
			//学期周数条件
			data += "TWC#";
			data += TermComboBox->currentText() + "#" + WeekComboBox->currentText() +
				"#" + condition;
		}
		else if (condition.isEmpty() && WeekIsAll)
		{
			qDebug() << "the condition" << condition;
			//学期所有周
			data += "TAW#";
			data += TermComboBox->currentText();
		}
		else
		{
			//学期、所有周和条件
			data += "TAWC#";
			data += TermComboBox->currentText() + "#" + condition;
		}
		
	}
	//如果只弹出来了学期没有周
	else if (isTermCombox && !isWeekCombox && condition.isEmpty())
	{
		data += "TAW#" + TermComboBox->currentText();
	}
	else if (isTermCombox && !isWeekCombox && !condition.isEmpty())
	{
		data += "TAWC#";
		data += TermComboBox->currentText() + "#" + condition;
	}
	//如果都没有打开
	else if (!isTermCombox && !isWeekCombox)
	{
		if (ui->selectcomboBox->currentText() == QString::fromLocal8Bit("姓名"))
		{
			//如果选中了而不输入就点查询
			if (condition.isEmpty())
			{
				MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"),
					QString::fromLocal8Bit("请输入姓名再点击查询！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
				return;
			}
			else
			{
				data += "TrueName#" + condition;
			}
		}
	}

	//暂时这么多吧！
	sendReportLook(data);

	//这里要判断一下combox里的是什么值！
}

void ReportLook::receiveDataFromClient(QString data)
{
	if (QString::compare(data, "delete_T") == 0)
	{
		//ui->downloadTable->clearn

		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("删除报告成功！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		//实现实时更新
		initModel();  //删除后在这里初始化
		sendReportLook();  //然后发信息给服务器查询当前文件情况
						 //model.
	}
	else if (QString::compare(data, "delete_F") == 0)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("删除文件失败！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}
}