#include "UploadFile.h"  
#include <QByteArray>
#include <QDataStream>
#include <QFileDialog>
#include <QHostAddress>
#include <QIODevice>
#include <QString>
#include <Qtime>
#include "MyMessageBox.h"

int sendtimes = 0;
UploadFile::UploadFile(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::UploadFile)
{
	ui->setupUi(this);
	//ui->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	ui->progressLabel->hide();
	ui->uploadSpeedLabel->hide();
	//connect(tcp, SIGNAL(connected()), this, SLOT(send()));  //当连接成功时，就开始传送文件 
}

UploadFile::~UploadFile()
{
	delete ui;
}
void UploadFile::ClickOpenButton()  //打开文件并获取文件名（包括路径）  
{
	ui->sendStatusLabel->setText(QString::fromLocal8Bit("正在打开文件..."));
	ui->sendProgressBar->setValue(0);  //非第一次发送  

									   //告诉服务器，我要发送文件了
	tcp->tcpSocket->write("uploadFile");
	qDebug() << globalUserName << " will send a file to server";
	//点击打开按钮的时候初始化数据
	loadSize = 0;
	byteToWrite = 0;
	totalSize = 0;
	sendtimes = 0;
	outBlock.clear();

	fileName = QFileDialog::getOpenFileName(this);
	localFile = new QFile(fileName);
	localFile->open(QFile::ReadOnly);

	ui->sendStatusLabel->setText(QString::fromLocal8Bit("已打开文件 %1").arg(fileName));
}

void UploadFile::send()  //发送文件头信息  
{
	//第一次发送的时候建立连接
	connect(tcp->tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(goOnSend(qint64)));
	byteToWrite = localFile->size();  //剩余数据的大小  
	qDebug() << "the file bytetowrite: " << byteToWrite;
	totalSize = localFile->size();

	loadSize = 4 * 1024;  //每次发送数据的大小  

	QDataStream out(&outBlock, QIODevice::WriteOnly);

	//获取文件名字
	QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);
	//占位符,这里必须要先这样占位，然后后续读算出整体长度后在插入
	//前面两个是文件大小和发送文件头的大小（为什么是qint64呢？），后面是文件名和用户名
	out << qint64(0) << qint64(0) << currentFileName <<globalUserName;

	totalSize += outBlock.size();  //总大小为文件大小加上文件名等信息大小  
	byteToWrite += outBlock.size();
	qDebug() << "the total bytetowrite: " << byteToWrite;
	out.device()->seek(0);  //回到字节流起点来写好前面连个qint64，分别为总大小和文件名等信息大小  
	out << totalSize << qint64(outBlock.size());   //这个就是对应前面的qint64？
	qDebug() << "the file head:" << outBlock;
	tcp->tcpSocket->write(outBlock);  //将读到的文件信息发送到套接字  

	sendTime.start();  //发送时间开始计时
	//UI信息
	ui->progressLabel->show();
	ui->sendProgressBar->setMaximum(totalSize);
	ui->sendProgressBar->setValue(totalSize - byteToWrite);
}


//继续发送
void UploadFile::goOnSend(qint64 numBytes)  
{
	sendtimes++;  
	qDebug() << sendtimes<<" get in goOnSend";
		qDebug() << "the numBytes: " << numBytes <<"the loadSize:" <<loadSize
			<< "the " << sendtimes << "  left byteTowrite: " << byteToWrite;

	byteToWrite -= numBytes;  //剩余数据大小  
	outBlock = localFile->read(qMin(byteToWrite, loadSize));   //如果剩余数据比每次发送的小则发送剩余的

	tcp->tcpSocket->write(outBlock);    //将这个信息写入socket
	
	//qDebug() << "information:" <<outBlock;

	//这里是速度处理，显示速度和已下载
	float useTime = sendTime.elapsed();
	double speed = (totalSize - byteToWrite) / useTime;
	ui->uploadSpeedLabel->show();
	ui->uploadSpeedLabel->setText(QString::fromLocal8Bit("已发送 %1MB (%2MB/s) 共%3MB 已用时:%4秒\n估计剩余时间：%5秒")
		.arg((totalSize - byteToWrite) / (1024 * 1024))//已接收
		.arg(speed * 1000 / (1024 * 1024), 0, 'f', 2)//速度
		.arg(totalSize / (1024 * 1024))//总大小
		.arg(useTime / 1000, 0, 'f', 0)//用时
		.arg(totalSize / speed / 1000 - useTime / 1000, 0, 'f', 0));//剩余时间


	//设置UI的进度条，这个可以考虑影藏起来
	ui->sendProgressBar->setMaximum(totalSize);
	ui->sendProgressBar->setValue(totalSize - byteToWrite);

	if (byteToWrite == 0)  //发送完毕  
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("上传完成!"), MESSAGE_INFORMATION, BUTTON_OK);
		ui->sendStatusLabel->setText(QString::fromLocal8Bit("文件发送完毕!"));
		//发送完毕就断开这个写字节的槽函数。
		disconnect(tcp->tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(goOnSend(qint64)));
		sendtimes = 0;
		qDebug() << "the file had send";
	}
}


void UploadFile::ClickSendButton()
{
	
	send();  //第一次发送的时候是由connectToHost出发connect信号才能调用send，第二次之后就需要调用send了  
	
	//connect(tcp->tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(goOnSend(qint64)));
	ui->sendStatusLabel->setText(QString::fromLocal8Bit("正在发送文件 %1").arg(fileName));
}



void UploadFile::receiveMainwindow()
{
	this->show();
}