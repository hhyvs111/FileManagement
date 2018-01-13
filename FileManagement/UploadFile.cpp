#include "UploadFile.h"  
#include <QHostAddress>  
#include <QTextCodec>  
#include <QFileDialog>  

UploadFile::UploadFile(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::UploadFile)
{
	ui->setupUi(this);

	ui->progressLabel->hide();

	//QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

	//tcpClient = new QTcpSocket(this);
	sendTimes = 0;

	//connect(tcp, SIGNAL(connected()), this, SLOT(send()));  //当连接成功时，就开始传送文件  
	//connect(tcp->tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(goOnSend(qint64)));


}

void UploadFile::send()  //发送文件头信息  
{
	byteToWrite = localFile->size();  //剩余数据的大小  
	totalSize = localFile->size();

	loadSize = 4 * 1024;  //每次发送数据的大小  

	QDataStream out(&outBlock, QIODevice::WriteOnly);
	QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);

	out << qint64(0) << qint64(0) << currentFileName;

	totalSize += outBlock.size();  //总大小为文件大小加上文件名等信息大小  
	byteToWrite += outBlock.size();

	out.device()->seek(0);  //回到字节流起点来写好前面连个qint64，分别为总大小和文件名等信息大小  
	out << totalSize << qint64(outBlock.size());

	tcp->tcpSocket->write(outBlock);  //将读到的文件发送到套接字  

	ui->progressLabel->show();
	ui->sendProgressBar->setMaximum(totalSize);
	ui->sendProgressBar->setValue(totalSize - byteToWrite);
}

void UploadFile::goOnSend(qint64 numBytes)  //开始发送文件内容  
{
	byteToWrite -= numBytes;  //剩余数据大小  
	outBlock = localFile->read(qMin(byteToWrite, loadSize));

	tcp->tcpSocket->write(outBlock);

	ui->sendProgressBar->setMaximum(totalSize);
	ui->sendProgressBar->setValue(totalSize - byteToWrite);

	if (byteToWrite == 0)  //发送完毕  
		ui->sendStatusLabel->setText(tr("文件发送完毕!"));
}

UploadFile::~UploadFile()
{
	delete ui;
}

void UploadFile::ClickOpenButton()  //打开文件并获取文件名（包括路径）  
{
	ui->sendStatusLabel->setText(tr("正在打开文件..."));
	ui->sendProgressBar->setValue(0);  //非第一次发送  

	loadSize = 0;
	byteToWrite = 0;
	totalSize = 0;
	outBlock.clear();

	fileName = QFileDialog::getOpenFileName(this);
	localFile = new QFile(fileName);
	localFile->open(QFile::ReadOnly);

	ui->sendStatusLabel->setText(tr("已打开文件 %1").arg(fileName));
}

void UploadFile::ClickSendButton()
{

		send();  //第一次发送的时候是由connectToHost出发connect信号才能调用send，第二次之后就需要调用send了  
		connect(tcp->tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(goOnSend(qint64)));
		ui->sendStatusLabel->setText(tr("正在发送文件 %1").arg(fileName));
}

void UploadFile::receiveMainwindow()
{
	this->show();
}