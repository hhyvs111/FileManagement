#include "UploadWindow.h"  
#include <QByteArray>
#include <QDataStream>
#include <QHostAddress>
#include <QIODevice>
#include <QString>
#include <Qtime>
#include <QtWin>
#include <QFileIconProvider>
#include "MyMessageBox.h"

//问题1： 用户拖曳了文件但是没有点击发送的话，服务器已经接收了“接收文件”的信号。这个时候
//就会出问题，服务器不能正常接收常规的命令。
int sendtimes = 0;
UploadWindow::UploadWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::UploadWindow)
{
	fileDialog = new QFileDialog();
	fileProgressBarMap = new QMap<QString, QProgressBar*>;   //需要初始化
	ui->setupUi(this);
	init();  //初始化
}

UploadWindow::~UploadWindow()
{
	delete ui;
}

//主要是初始化界面
void UploadWindow::init()
{
	//这个重叠显示要根据文件
	//QStackedLayout *stackLayout = new QStackedLayout();
	////stackLayout->addWidget(ui->mFileIcon);
	////stackLayout->addWidget(ui->mFileName);
	////重叠显示
	//stackLayout->addWidget(ui->horizontalWidget);
	//stackLayout->addWidget(ui->sendProgressBar);
	//ui->sendProgressBar->setTextVisible(false);   //不显示百分比
	//stackLayout->setStackingMode(QStackedLayout::StackAll);
	//ui->horizontalLayout_3->addLayout(stackLayout);

	////速度啊，标签什么的都先隐藏起来
	//ui->uploadSpeedLabel->hide();
	//ui->mFileIcon->hide();
	//ui->mFileName->hide();
	//ui->sendProgressBar->hide();


	setAcceptDrops(true);
	QPixmap DragDrop(":/Resource/FunIcon/Drag-Drop.png");  //用来放文件的图标
														   //Drag = fil.scaled(QSize(50, 60), Qt::KeepAspectRatio);
	ui->Drag->setPixmap(DragDrop);
	//ui->Drag->setAlignment(Qt::AlignCenter);
	//connect(tcp, SIGNAL(connected()), this, SLOT(send()));  //当连接成功时，就开始传送文件 

	loadStyleSheet("UploadFile");  //

}

//这里放图标
void UploadWindow::insertFile(QString m_fileName)
{
	QProgressBar *fileProgressBar = new QProgressBar(this);
	fileProgressBar->setTextVisible(false);   //不显示百分比
	
	fileProgressBarMap->insert(m_fileName, fileProgressBar);  //将这个进度条放入map

	 stackLayout = new QStackedLayout();
	 
	 fileWidget = new QWidget(this);
	 //fileWidget->setLayout(fileInfoLayout);  //设置水平layout
	 //插入文件和名字
	 fileInfoLayout = new QHBoxLayout(fileWidget);
	 mFileIcon = new QLabel(fileWidget);
	 mFileName = new QLabel(fileWidget);
	 fileInfoLayout->addWidget(mFileIcon);
	 fileInfoLayout->addWidget(mFileName);
	 
	 
	 setFileIcon(m_fileName);	//设置该文件的名字和图标
	 

	 //fileInfoLayout->insertWidget(0, mFileIcon);
	 //fileInfoLayout->insertWidget(1, mFileName);
	 //找到该文件所在行列
	 
	 
	
	 //stackLayout->addItem(fileInfoLayout);
	 stackLayout->addWidget(fileWidget);
	 stackLayout->addWidget(fileProgressBar);

	 //fileWidget->raise();
	 fileProgressBar->setTextVisible(false);
	 //fileProgressBar->hide();
	

	 stackLayout->setStackingMode(QStackedLayout::StackAll);
	 ui->FileListLayout->addLayout(stackLayout);  //垂直的放置多个文件

}
void UploadWindow::loadStyleSheet(const QString &sheetName)
{
	QFile file("Resource/qss/" + sheetName + ".qss");
	qDebug() << sheetName + ".qss";
	file.open(QFile::ReadOnly);
	if (file.isOpen())
	{
		qDebug() << "is  css";
		QString styleSheet = this->styleSheet();
		styleSheet += QLatin1String(file.readAll());
		this->setStyleSheet(styleSheet);
	}
	else
		qDebug() << "is not css";
}
void UploadWindow::dragEnterEvent(QDragEnterEvent *event)
{
	//如果为文件，则支持拖放
	if (event->mimeData()->hasFormat("text/uri-list"))
		event->acceptProposedAction();
}

void UploadWindow::dropEvent(QDropEvent *event)
{
	//注意：这里如果有多文件存在，意思是用户一下子拖动了多个文件，而不是拖动一个目录
	//如果想读取整个目录，则在不同的操作平台下，自己编写函数实现读取整个目录文件名
	QList<QUrl> urls = event->mimeData()->urls();
	if (urls.isEmpty())
		return;
	//往文本框中追加文件名
	foreach(QUrl url, urls) {
		fileName = url.toLocalFile();
		qDebug() << fileName;
		//ui->sendStatusLabel->setText(fileName);
		fileNameList.append(fileName);
		insertFile(fileName);
		//initFile();
		////setFileIcon(fileName);  //设置文件图标 
		//localFile = new QFile(fileName);
		//localFile->open(QFile::ReadOnly);

		//ui->sendStatusLabel->setText(QString::fromLocal8Bit("已打开文件 %1").arg(fileName));
	}
}

void UploadWindow::initFile()
{


	//tcpSocket = new QTcpSocket();
	//tcpSocket->abort();   //取消已有的连接
	//tcpSocket->connectToHost(ip, port);  //将这个socket连接到服务器

	//tcpSocket->write("UploadWindow");
	//qDebug() << globalUserName << " will send a file to server";
	//loadSize = 0;
	//byteToWrite = 0;
	//totalSize = 0;
	//sendtimes = 0;
	//ui->sendProgressBar->setValue(0);  //非第一次发送  
	//outBlock.clear();
}

//打开按钮
void UploadWindow::ClickOpenButton()  //打开文件并获取文件名（包括路径）  
{
	//ui->sendStatusLabel->setText(QString::fromLocal8Bit("正在打开文件..."));
	//告诉服务器，我要发送文件了
	//点击打开按钮的时候初始化数据

	//直接加入
	
	//fileDialog->open();
	//fileDialog->selectedFiles();
	
	fileNameList.append(QFileDialog::getOpenFileNames());
	for (int i = 0; i < fileNameList.size(); i++)
	{
		qDebug()<<"the file list:" << fileNameList.at(i);
	}
	//fileName = QFileDialog::getOpenFileName(this);
	if (!fileNameList.isEmpty())
	{
		for (int i = 0; i < fileNameList.size(); i++)
		{
			insertFile(fileNameList.at(i));
		}
		
		//setFileIcon(fileName);  //设置文件图标 
		//localFile = new QFile(fileName);
		//localFile->open(QFile::ReadOnly);
		//ui->sendStatusLabel->setText(QString::fromLocal8Bit("已打开文件 %1").arg(fileName));
	}
}

//void UploadWindow::send()  //发送文件头信息  
//{
//	if (!fileName.isNull())
//	{
//		//第一次发送的时候建立连接
//		connect(tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(goOnSend(qint64)));
//		byteToWrite = localFile->size();  //剩余数据的大小  
//		qDebug() << "the file bytetowrite: " << byteToWrite;
//		totalSize = localFile->size();
//
//		loadSize = 4 * 1024;  //每次发送数据的大小  
//
//		QDataStream out(&outBlock, QIODevice::WriteOnly);
//		//获取文件名字
//		QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);
//		//占位符,这里必须要先这样占位，然后后续读算出整体长度后在插入
//		//前面两个是文件大小和发送文件头的大小（为什么是qint64呢？），后面是文件名和用户名
//		out << qint64(0) << qint64(0) << currentFileName << globalUserName;
//
//		totalSize += outBlock.size();  //总大小为文件大小加上文件名等信息大小  
//		byteToWrite += outBlock.size();
//		qDebug() << "the total bytetowrite: " << byteToWrite;
//		out.device()->seek(0);  //回到字节流起点来写好前面连个qint64，分别为总大小和文件名等信息大小  
//		out << totalSize << qint64(outBlock.size());   //这个就是对应前面的qint64？
//		qDebug() << "the file head:" << outBlock;
//		tcpSocket->write(outBlock);  //将读到的文件信息发送到套接字  
//
//		sendTime.start();  //发送时间开始计时
//						   //UI信息
//						   //ui->progressLabel->show();
//		ui->sendProgressBar->setMaximum(totalSize);
//		ui->sendProgressBar->setValue(totalSize - byteToWrite);
//	}
//	else
//	{
//		//弹出请先添加文件提示！
//		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请先添加文件!"), MESSAGE_INFORMATION, BUTTON_OK, true);
//	}
//
//}


//继续发送
//void UploadWindow::goOnSend(qint64 numBytes)
//{
//	sendtimes++;
//	qDebug() << sendtimes << " get in goOnSend";
//	qDebug() << "the numBytes: " << numBytes << "the loadSize:" << loadSize
//		<< "the " << sendtimes << "  left byteTowrite: " << byteToWrite;
//
//	byteToWrite -= numBytes;  //剩余数据大小  
//	outBlock = localFile->read(qMin(byteToWrite, loadSize));   //如果剩余数据比每次发送的小则发送剩余的
//
//	tcpSocket->write(outBlock);    //将这个信息写入socket
//
//								   //qDebug() << "information:" <<outBlock;
//
//								   //这里是速度处理，显示速度和已下载
//	float useTime = sendTime.elapsed();
//	double speed = (totalSize - byteToWrite) / useTime;
//	ui->uploadSpeedLabel->show();
//	ui->uploadSpeedLabel->setText(QString::fromLocal8Bit("已发送 %1MB (%2MB/s) 共%3MB 已用时:%4秒\n估计剩余时间：%5秒")
//		.arg((totalSize - byteToWrite) / (1024 * 1024))//已接收
//		.arg(speed * 1000 / (1024 * 1024), 0, 'f', 2)//速度
//		.arg(totalSize / (1024 * 1024))//总大小
//		.arg(useTime / 1000, 0, 'f', 0)//用时
//		.arg(totalSize / speed / 1000 - useTime / 1000, 0, 'f', 0));//剩余时间
//
//
//																	//设置UI的进度条，这个可以考虑隐藏起来
//	ui->sendProgressBar->setMaximum(totalSize);
//	ui->sendProgressBar->setValue(totalSize - byteToWrite);
//
//	if (byteToWrite == 0)  //发送完毕  
//	{
//		//发送完毕且点击了点击了确定按钮。
//		if (!MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"),
//			QString::fromLocal8Bit("上传完成!"), MESSAGE_INFORMATION, BUTTON_OK, true))
//		{
//			ui->sendBtn->setEnabled(true);
//		}
//		//ui->sendStatusLabel->setText(QString::fromLocal8Bit("文件发送完毕!"));
//		//发送完毕就断开这个写字节的槽函数。
//		disconnect(tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(goOnSend(qint64)));
//		sendtimes = 0;
//
//		//发送完后取消连接，把线程退出？
//		uploadThread->quit();
//		tcpSocket->abort();
//		qDebug() << "the file had send";
//	}
//}


void UploadWindow::ClickSendButton()
{
	//发送文件信息
	emit sendFileSignal();
	ui->sendBtn->setEnabled(false); //按钮失效

	//connect(tcp->tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(goOnSend(qint64)));
	//ui->sendStatusLabel->setText(QString::fromLocal8Bit("正在发送文件 %1").arg(fileName));
}


void UploadWindow::setFileIcon(QString fileName)
{

	QString suffix = (fileName.right(fileName.size() - fileName.lastIndexOf('.') - 1)).left(3); //获取文件后缀前三个字符
	QString allName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1); //获取文件名字
	qDebug() << "the suffix :" << suffix << " and the allName:" << allName;
	// 获取图标、类型
	QIcon icon = fileIcon(suffix);
	QString strType = fileType(suffix);
	qDebug() << strType;
	QPixmap pixmap = icon.pixmap(icon.actualSize(QSize(30, 40)));
	//QPixmap fileIcon(icon.);  //用来放文件的图标
	//fileIcon = fileIcon.scaled(QSize(30, 40), Qt::KeepAspectRatio);
	mFileIcon->setPixmap(pixmap);
	mFileIcon->setAlignment(Qt::AlignCenter);
	
	mFileName->setText(allName);
	mFileIcon->show();
	mFileName->show();
	//放文件的时候重置速度和标签
	//ui->uploadSpeedLabel->hide();
	//ui->sendProgressBar->show();
}

void UploadWindow::receiveMainwindow()
{
	this->show();
}

QIcon UploadWindow::fileIcon(const QString &extension) const
{
	QFileIconProvider provider;
	QIcon icon;
	QString strTemplateName = QDir::tempPath() + QDir::separator() +
		QCoreApplication::applicationName() + "_XXXXXX." + extension;
	QTemporaryFile tmpFile(strTemplateName);
	tmpFile.setAutoRemove(false);

	if (tmpFile.open())
	{
		tmpFile.close();
		icon = provider.icon(QFileInfo(fileName));
		// tmpFile.remove();
	}
	else
	{
		qDebug() << QString("failed to write temporary file %1").arg(tmpFile.fileName());
	}

	return icon;
}

QString UploadWindow::fileType(const QString &extension) const
{
	QFileIconProvider provider;
	QString strType;
	QString strFileName = QDir::tempPath() + QDir::separator() +
		QCoreApplication::applicationName() + "_XXXXXX." + extension;
	QTemporaryFile tmpFile(strFileName);
	tmpFile.setAutoRemove(false);

	if (tmpFile.open())
	{
		tmpFile.close();
		strType = provider.type(QFileInfo(tmpFile.fileName()));
		// tmpFile.remove();
	}
	else
	{
		qCritical() << QString("failed to write temporary file %1").arg(tmpFile.fileName());
	}

	return strType;
}

