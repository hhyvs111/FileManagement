#include "FileManagement.h"

#include "DownloadFile.h"
#include <QMessageBox> 
#include <QLabel>
#include <QMovie>
extern QString globalUserName;
FileManagement::FileManagement(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::FileManagement)
{
	ui->setupUi(this);

	QIcon personico("Resource/person1.png"); //创建QIcon对象
	ui->personButton->setIcon(personico); //将图片设置到按钮上
	ui->personButton->setIconSize(QSize(70, 58));//根据实际调整图片大小
	ui->personButton->setStyleSheet("border:none");   //隐藏button的边框线(true);
	//toolbutton添加图片
	QIcon uploadico("Resource/upload.png"); //创建QIcon对象
	ui->uploadButton->setIcon(uploadico); //将图片设置到按钮上
	ui->uploadButton->setIconSize(QSize(70, 55));//根据实际调整图片大小
	ui->uploadButton->setStyleSheet("border:none");   //隐藏button的边框线(true);
	QIcon downloadico("Resource/download.png"); //创建QIcon对象
	ui->downloadButton->setIcon(downloadico); //将图片设置到按钮上
	ui->downloadButton->setIconSize(QSize(70, 55));//根据实际调整图片大小
	ui->downloadButton->setStyleSheet("border:none");
	QIcon chatico("Resource/chat.png"); //创建QIcon对象
	ui->chatButton->setIcon(chatico); //将图片设置到按钮上
	ui->chatButton->setIconSize(QSize(70, 55));//根据实际调整图片大小
	ui->chatButton->setStyleSheet("border:none");
	QIcon deleteico("Resource/delete.png"); //创建QIcon对象
	ui->deleteButton->setIcon(deleteico); //将图片设置到按钮上
	ui->deleteButton->setIconSize(QSize(70, 55));//根据实际调整图片大小
	ui->deleteButton->setStyleSheet("border:none");
	
	//QMovie *movie = new QMovie("Resource/MainWindow.gif");//加载图片gif
	//ui->photoLabel->setGeometry(500, 20, 200, 0);
	//movie->setScaledSize(QSize(900, 580));//设置图片大小
	//ui->photoLabel->setMovie(movie);
	//	movie->start();
		setWindowIcon(QIcon("Resource/icon1.png"));//设置窗口左上角图标
		setFixedSize(700, 600); // 禁止改变窗口大小
		ui->personButton->setToolTip(tr("upload your photo"));//点击按钮提示相应信息
		ui->uploadButton->setToolTip(tr("upload"));
		ui->downloadButton->setToolTip(tr("download"));
		ui->chatButton->setToolTip(tr("chat"));
		ui->deleteButton->setToolTip(tr("delete"));
		//自定义退出按钮
		QToolButton *closeButton = new QToolButton(this);
		QPixmap quitPixmap = QPixmap("Resource/icon2.png");
		closeButton->setStyleSheet("QToolButton{border:none}");
		closeButton->setFixedSize(QSize(20, 20));
		closeButton->setIcon(quitPixmap);
		closeButton->setGeometry(this->width() - 20, 0, 20, 20);
		connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
		//设置窗口背景色
		QPalette  palette(this->palette());
		palette.setColor(QPalette::Background, QColor(255, 255,255, 255));
		this->setPalette(palette);
	    //设置标题label字体颜色
		ui->titleLabel->setStyleSheet("background:transparent");//设置label透明色
		//ui.titleLabel->setStyleSheet("background-color:rgb(255, 255, 255)");//label背景颜色为白色
		ui->titleLabel->setStyleSheet("color:rgb(27, 41, 234)");//label字体颜色为蓝色
		//

	qDebug() << globalUserName << " welcome! ";

}

FileManagement::~FileManagement()
{
	delete ui;
}
//
//void FileManagement::initTitleBar()
//{
//	m_titleBar->move(1, 2);
//	m_titleBar->raise();
//	m_titleBar->setWindowBorderWidth(2);
//	m_titleBar->setBackgroundColor(255, 255, 255);
//	m_titleBar->setButtonType(MIN_BUTTON);
//	m_titleBar->setTitleWidth(this->width());
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
	if (downloadFileWindowIsOpen)
		downloadFile->hide();
	if (userInformationWindowIsOpen)
		userInformation->hide();
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
	if (userInformationWindowIsOpen)
		userInformation->hide();
	if (uploadFileWindowIsOpen)
		uploadFile->hide();
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
	if (downloadFileWindowIsOpen)
		downloadFile->hide();
	if (uploadFileWindowIsOpen)
		uploadFile->hide();
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

void FileManagement::ClickReturn()
{
	this->hide();
	emit showLogin();
}