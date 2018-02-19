#include "FileManagement.h"

#include "DownloadFile.h"
#include <QMessageBox> 
#include <QLabel>
#include <QMovie>
extern QString globalUserName;
FileManagement::FileManagement(QWidget *parent)
	: BaseWindow(parent), ui(new Ui::FileManagement)
{
	ui->setupUi(this);
	init();
	//initTitleBar();
	loadStyleSheet("mainWindow");

}

FileManagement::~FileManagement()
{
	delete ui;
}

void FileManagement::init()
{

	ui->titleLabel->setStyleSheet("background:transparent");//设置label透明色
	ui->titleLabel->setStyleSheet("color:rgb(27, 41, 234)");//label字体颜色为蓝色
	QPalette Pal(palette());
	// set black background
	Pal.setColor(QPalette::Background, Qt::gray);
	ui->ToolButtonWidget->setAutoFillBackground(true);
	ui->ToolButtonWidget->setPalette(Pal);
	//ui->ToolButtonWidget->setStyleSheet("backgroud-color : black;");

	QIcon personico("Resource/FunIcon/userInfo.png"); //创建QIcon对象
	ui->personButton->setIcon(personico); //将图片设置到按钮上
	ui->personButton->setIconSize(QSize(80, 20));//根据实际调整图片大小
	ui->personButton->setStyleSheet("border:none");   //隐藏button的边框线(true);
													  //ui->personButton->setStyleSheet("QToolButton{image-align : left;}");

	ui->personButton->setCheckable(true);

	ui->personButton->setAutoExclusive(true);

	//ui->personButton->setAlignment(Qt::AlignLeft);
	//ui->personLayout->setAlignment(Qt::AlignLeft);
	//toolbutton添加图片
	QIcon uploadico("Resource/FunIcon/upload.png"); //创建QIcon对象
	ui->uploadButton->setIcon(uploadico); //将图片设置到按钮上
	ui->uploadButton->setIconSize(QSize(80, 20));//根据实际调整图片大小
	ui->uploadButton->setStyleSheet("border:none");   //隐藏button的边框线(true);
	ui->uploadButton->setCheckable(true);

	ui->uploadButton->setAutoExclusive(true);

	QIcon downloadico("Resource/FunIcon/download.png"); //创建QIcon对象
	ui->downloadButton->setIcon(downloadico); //将图片设置到按钮上
	ui->downloadButton->setIconSize(QSize(80, 20));//根据实际调整图片大小
	ui->downloadButton->setStyleSheet("border:none");

	//检查check状态
	ui->downloadButton->setCheckable(true);
	ui->downloadButton->setAutoExclusive(true);

	QIcon chatico("Resource/FunIcon/showFile.png"); //创建QIcon对象
	ui->showFileButton->setIcon(chatico); //将图片设置到按钮上
	ui->showFileButton->setIconSize(QSize(80, 20));//根据实际调整图片大小
	ui->showFileButton->setStyleSheet("border:none");
	ui->showFileButton->setCheckable(true);

	ui->showFileButton->setAutoExclusive(true);

	QIcon deleteico("Resource/FunIcon/exit.png"); //创建QIcon对象
	ui->deleteButton->setIcon(deleteico); //将图片设置到按钮上
	ui->deleteButton->setIconSize(QSize(80, 20));//根据实际调整图片大小
	ui->deleteButton->setStyleSheet("border:none");
	ui->deleteButton->setCheckable(true);
	ui->deleteButton->setAutoExclusive(true);

	QIcon reportEditicon("Resource/FunIcon/reportEdit.png"); //创建QIcon对象
	ui->reportEditButton->setIcon(reportEditicon); //将图片设置到按钮上
	ui->reportEditButton->setIconSize(QSize(80, 20));//根据实际调整图片大小
	ui->reportEditButton->setStyleSheet("border:none");
	ui->reportEditButton->setCheckable(true);
	ui->reportEditButton->setAutoExclusive(true);

	QIcon reportLookicon("Resource/FunIcon/reportLook.png"); //创建QIcon对象
	ui->reportLookButton->setIcon(reportLookicon); //将图片设置到按钮上
	ui->reportLookButton->setIconSize(QSize(80, 20));//根据实际调整图片大小
	ui->reportLookButton->setStyleSheet("border:none");
	ui->reportLookButton->setCheckable(true);
	ui->reportLookButton->setAutoExclusive(true);

	//QMovie *movie = new QMovie("Resource/MainWindow.gif");//加载图片gif
	//ui->photoLabel->setGeometry(500, 20, 200, 0);
	//movie->setScaledSize(QSize(900, 580));//设置图片大小
	//ui->photoLabel->setMovie(movie);
	//	movie->start();
	setWindowIcon(QIcon("Resource/icon1.png"));//设置窗口左上角图标
	setFixedSize(800, 600); // 禁止改变窗口大小
	ui->personButton->setToolTip(tr("upload your photo"));//点击按钮提示相应信息
	ui->uploadButton->setToolTip(tr("upload"));
	ui->downloadButton->setToolTip(tr("download"));
	ui->showFileButton->setToolTip(tr("chat"));
	ui->deleteButton->setToolTip(tr("退出系统"));


	////自定义退出按钮
	//QToolButton *closeButton = new QToolButton(this);
	//QPixmap quitPixmap = QPixmap("Resource/icon2.png");
	//closeButton->setStyleSheet("QToolButton{border:none}");
	//closeButton->setFixedSize(QSize(20, 20));
	//closeButton->setIcon(quitPixmap);
	//closeButton->setGeometry(this->width() - 20, 0, 20, 20);
	//connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));


	//设置窗口背景色
	/*QPalette  palette(this->palette());
	palette.setColor(QPalette:: Background, QColor(255, 255,255, 255));
	this->setPalette(palette);*/
	//设置标题label字体颜色
	//ui.titleLabel->setStyleSheet("background-color:rgb(255, 255, 255)");//label背景颜色为白色
	//

	//this->setAttribute(Qt::WA_TranslucentBackground);
	////边框阴影效果
	//QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect;
	//effect->setBlurRadius(6);
	//effect->setColor(Qt::black);
	//effect->setOffset(0, 0);
	//this->setGraphicsEffect(effect);
	//this->update();
}
//
//void FileManagement::initTitleBar()
//{ 
//	//m_titleBar->move(1, 2);
//	//m_titleBar->raise();
//	//m_titleBar->setWindowBorderWidth(2);
//	//m_titleBar->setBackgroundColor(255, 255, 255);
//	//m_titleBar->setButtonType(MIN_BUTTON);
//	//m_titleBar->setTitleWidth(this->width());
//}



void FileManagement::receiveLogin()
{
	this->show();
}
void FileManagement::Btn_Click()
{
	QMessageBox msg;
	msg.setText("hello world!");
	msg.exec();
}


//点击上传文件按钮显示上传界面
void FileManagement::ClickUploadFile()
{
	//检测自己
	if (uploadFileWindowIsOpen)
		uploadFile->show();
	//检测其他两个

	if (reportEditWindowIsOpen)
		reportEdit->hide();
	if (downloadFileWindowIsOpen)
		downloadFile->hide();
	if (userInformationWindowIsOpen)
		userInformation->hide();
	if (reportLookWindowIsOpen)
		reportLook->hide();
	if (!uploadFileWindowIsOpen)
	{
		uploadFile = new UploadFile(this);  //将指针实例化
		ui->SubLayout->insertWidget(1, uploadFile);
		uploadFile->show();
		
		uploadFileWindowIsOpen = true;
	}
	else
	{
		qDebug() << "uploadFileWindowIsOpen!";
	}

}

//点击下载文件按钮显示下载界面
void FileManagement::ClickDownloadFile()
{

	//点击显示文件信息
	if (downloadFileWindowIsOpen)
	{
		downloadFile->show();
		downloadFile->sendFileInfo();
	}

	if (reportEditWindowIsOpen)
	{
		reportEdit->hide();
	}

	if (userInformationWindowIsOpen)
		userInformation->hide();
	if (uploadFileWindowIsOpen)
		uploadFile->hide();
	if (reportLookWindowIsOpen)
		reportLook->hide();
	if (!downloadFileWindowIsOpen)
	{
		downloadFile = new DownloadFile(this);  //将指针实例化
		downloadFile->sendFileInfo();
		ui->SubLayout->insertWidget(1, downloadFile);
		downloadFile->show();
		downloadFileWindowIsOpen = true;
	}
	else
	{
		qDebug() << "uploadFileWindowIsOpen!";
	}
	//emit showUploadFile();
}

void FileManagement::ClickUserInformation()
{
	if (userInformationWindowIsOpen)
	{
		userInformation->show();
		userInformation->sendUserInfo();
	}

	if (reportEditWindowIsOpen)
	{
		reportEdit->hide();
	}

	if (downloadFileWindowIsOpen)
		downloadFile->hide();
	if (uploadFileWindowIsOpen)
		uploadFile->hide();

	if (reportLookWindowIsOpen)
		reportLook->hide();
	if (!userInformationWindowIsOpen)
	{
		userInformation = new UserInformation(this);
		//调用了发送用户信息
		userInformation->sendUserInfo();
		ui->SubLayout->insertWidget(1, userInformation);
		userInformation->show();
		userInformationWindowIsOpen = true;
	}
	else
		qDebug() << "userInformationWindowIsOpen!";

}

//点击ReportEdit
void FileManagement::ClickReportEdit()
{
	if (reportEditWindowIsOpen)
	{
		reportEdit->show();
		reportEdit->sendReportEdit();
	}

	if (userInformationWindowIsOpen)
		userInformation->hide();

	if (downloadFileWindowIsOpen)
		downloadFile->hide();
	if (uploadFileWindowIsOpen)
		uploadFile->hide();

	if (reportLookWindowIsOpen)
		reportLook->hide();

	if (!reportEditWindowIsOpen)
	{
		reportEdit = new ReportEdit(this);
		//调用了发送用户信息
		reportEdit->sendReportEdit();
		ui->SubLayout->insertWidget(1, reportEdit);
		reportEdit->show();
		reportEditWindowIsOpen = true;
	}
	else
		qDebug() << "reportEditWindowIsOpen!";
}

void FileManagement::ClickReportLook()
{
	if (reportLookWindowIsOpen)
	{
		reportLook->show();
		reportLook->sendReportLook();
	}

	if (userInformationWindowIsOpen)
		userInformation->hide();

	if (downloadFileWindowIsOpen)
		downloadFile->hide();

	if (uploadFileWindowIsOpen)
		uploadFile->hide();

	if (reportEditWindowIsOpen)
		reportEdit->hide();

	if (!reportLookWindowIsOpen)
	{
		reportLook = new ReportLook(this);
		//调用了发送用户信息
		reportLook->sendReportLook();
		ui->SubLayout->insertWidget(1, reportLook);
		reportLook->show();
		reportLookWindowIsOpen = true;
	}
	else
		qDebug() << "reportLookWindowIsOpen!";
}

void FileManagement::ClickReturn()
{
	this->hide();
	emit showLogin();
}