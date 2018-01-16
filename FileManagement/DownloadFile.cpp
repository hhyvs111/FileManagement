#include "DownloadFile.h"
DownloadFile::DownloadFile(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::DownloadFile)
{
	ui->setupUi(this);
	//StotalSize = 0;
	byteReceived = 0;
	//ui->progressLabel->hide();
	
	//connect(tcp, SIGNAL(connected()), this, SLOT(send()));  //当连接成功时，就开始传送文件 
}

DownloadFile::~DownloadFile()
{
	delete ui;
}

void DownloadFile::receiveFile()
{
	qDebug() << "get in receiveFile!!!";
	qDebug() << byteReceived;

	if (byteReceived == 0)  //才刚开始接收数据，此数据为文件信息  
	{
		qDebug() << "receive the file of head";
		//ui->receivedProgressBar->setValue(0);
		QDataStream in(tcp->tcpSocket);
		//QString globalUserName;
		in >> RtotalSize >> byteReceived >> fileName;
		//user.queryUserByName(globalUserName);
		//qDebug() << "the user :" << user.getUserName();

		fileName = "files/" + fileName;
		qDebug() << "the file of head: " << fileName;
		qDebug() << "totalSize: " << RtotalSize;
		qDebug() << " first byteReceived: " << byteReceived;
		newFile = new QFile(fileName);
		newFile->open(QFile::WriteOnly);

		//开始计时！
		downloadTime.start();

	}
	else  //正式读取文件内容  
	{
		receiveTime++;
		qDebug() << "the " << receiveTime << " receive the file ";
		inBlock = tcp->tcpSocket->readAll();
		qDebug() << "current receive the byte is :" << byteReceived;
		//qDebug() << "the block: " << inBlock;
		byteReceived += inBlock.size();

		float useTime = downloadTime.elapsed();
		double speed = (byteReceived) / useTime;
		ui->downloadSpeedLabel->show();
		ui->downloadSpeedLabel->setText(QString::fromLocal8Bit("已下载 %1MB (%2MB/s) 共%3MB 已用时:%4秒\n估计剩余时间：%5秒")
			.arg((byteReceived) / (1024 * 1024))//已接收
			.arg(speed * 1000 / (1024 * 1024), 0, 'f', 2)//速度
			.arg(RtotalSize / (1024 * 1024))//总大小
			.arg(useTime / 1000, 0, 'f', 0)//用时
			.arg(RtotalSize / speed / 1000 - useTime / 1000, 0, 'f', 0));//剩余时间
		
		ui->progressBar->setMaximum(RtotalSize);
		ui->progressBar->setValue(byteReceived);
		qDebug() << "begin to write";
		newFile->write(inBlock);
		newFile->flush();
	}

	if (byteReceived == RtotalSize)
	{
		ui->downloadSpeedLabel->setText(QString::fromLocal8Bit("下载完成！ %1MB (%2MB/s) 共%3MB 已用时:%4秒\n估计剩余时间：%5秒"));
		qDebug() << "receive is done";
		/*qDebug() << "the file name:" << file.getFileName();
		qDebug() << "the userid :" << user.getUserId();
		qDebug() << "the userid from file:" << file.getUserId();*/
		inBlock.clear();
		byteReceived = 0;
		RtotalSize = 0;
		receiveTime = 0;
		
		disconnect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveFile()));
		connect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	}
}
void DownloadFile::ClickDownloadButton()
{
	receiveTime = 0;
	QString openFileName;
	//获取ui输入的信息
	openFileName = ui->downloadFileName->text();

	QString bs = "downloadFile";
	QString data = bs + "#" + openFileName;

	//发送中文需要
	QByteArray datasend = data.toLocal8Bit();
	if (tcp->tcpSocket->write(datasend))
	{
		
		qDebug() << data;
		connect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveFile()));
		disconnect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	}
	else
	{
		qDebug() << "send filed :" << data;
	}
}

void DownloadFile::sendFileInfo()
{
	//每次打开该页面则发查询信息发过去
	QString data = "findFileByName#" + globalUserName;
	QByteArray datasend = data.toLocal8Bit();
	qDebug() << datasend;
	tcp->tcpSocket->write(datasend);

	//暂时取消TCP原本的验证消息
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	connect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(showFileInfo()));
}

void DownloadFile::showFileInfo()
{
	QByteArray dataread = tcp->tcpSocket->readAll();
	QString data = QString::fromLocal8Bit(dataread);
	qDebug() << "the data from client: " << data;

}