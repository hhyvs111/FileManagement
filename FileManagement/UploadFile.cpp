#include "UploadFile.h"  
#include <QByteArray>
#include <QDataStream>
#include <QFileDialog>
#include <QHostAddress>
#include <QIODevice>
#include <QString>


int sendtimes = 0;
UploadFile::UploadFile(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::UploadFile)
{
	ui->setupUi(this);

	ui->progressLabel->hide();

	//connect(tcp, SIGNAL(connected()), this, SLOT(send()));  //当连接成功时，就开始传送文件  
	


}

void UploadFile::send()  //发送文件头信息  
{
	connect(tcp->tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(goOnSend(qint64)));
	byteToWrite = localFile->size();  //剩余数据的大小  
	qDebug() << "the file bytetowrite: " << byteToWrite;
	totalSize = localFile->size();

	loadSize = 2 * 1024;  //每次发送数据的大小  

	QDataStream out(&outBlock, QIODevice::WriteOnly);

	//获取文件名字
	QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);
	
	//前面两个是文件大小和发送文件头的大小，后面是文件名和用户名
	out << qint64(0) << qint64(0) << currentFileName <<globalUserName;

	totalSize += outBlock.size();  //总大小为文件大小加上文件名等信息大小  
	byteToWrite += outBlock.size();
	qDebug() << "the total bytetowrite: " << byteToWrite;
	out.device()->seek(0);  //回到字节流起点来写好前面连个qint64，分别为总大小和文件名等信息大小  
	out << totalSize << qint64(outBlock.size());
	qDebug() << "the file head:" << outBlock;
	tcp->tcpSocket->write(outBlock);  //将读到的文件信息发送到套接字  


	//UI信息
	ui->progressLabel->show();
	ui->sendProgressBar->setMaximum(totalSize);
	ui->sendProgressBar->setValue(totalSize - byteToWrite);
}

void UploadFile::goOnSend(qint64 numBytes)  //开始发送文件内容  
{
	sendtimes++;  
	qDebug() << sendtimes<<" get in goOnSend";
		qDebug() << "the numBytes: " << numBytes <<"the loadSize:" <<loadSize
			<< "the " << sendtimes << "  left byteTowrite: " << byteToWrite;

	byteToWrite -= numBytes;  //剩余数据大小  
	outBlock = localFile->read(qMin(byteToWrite, loadSize));   //如果剩余数据比每次发送的小则发送剩余的

	tcp->tcpSocket->write(outBlock);    //将这个信息写入socket

	//qDebug() << "information:" <<outBlock;
	ui->sendProgressBar->setMaximum(totalSize);
	ui->sendProgressBar->setValue(totalSize - byteToWrite);

	if (byteToWrite == 0)  //发送完毕  
	{
		ui->sendStatusLabel->setText(QString::fromLocal8Bit("文件发送完毕!"));
		disconnect(tcp->tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(goOnSend(qint64)));
		sendtimes = 0;
		qDebug() << "the file had send";
	}
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
	qDebug() << globalUserName<<" will send a file to server";
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