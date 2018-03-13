#include "DownloadFile.h"
#include <QFileDialog>
#include <QtWin>
#include "MyMessageBox.h"
DownloadFile::DownloadFile(QString mFileName, QString mFilePath,int num)
{
	fileName = mFileName;
	filePath = mFilePath;   //总文件就是 filePath + fileName；
	index = num;
	init();
	qDebug() << "new downloadFile :" <<QThread::currentThreadId();
}

DownloadFile::~DownloadFile()
{
	//delete ui;
}


//初始化界面
void DownloadFile::init()
{
	byteReceived = 0;
	receiveTime = 0;
	//initModel();

	tcpSocket = new QTcpSocket();  //新建一个socket
	tcpSocket->abort();   //取消已有的连接
	tcpSocket->connectToHost(ip, port);  //将这个socket连接到服务器

	QString bs = "downloadFile";
	QString data = bs + "#" + fileName;

	QByteArray datasend = data.toUtf8();  //发送UTF8过去
	if (tcpSocket->write(datasend))
	{
		qDebug() << "send data to server: " << data;
		connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveFile()));  //绑定信号槽
	}
	else
	{
		qDebug() << "send filed :" << data;
	}
}

void DownloadFile::receiveFile()
{
	if (byteReceived == 0)  //才刚开始接收数据，此数据为文件信息  
	{
		QTimer *timer = new QTimer(this);
		connect(timer, SIGNAL(timeout()), this, SLOT(updateSpeed())); // ***就是你所说的响应函数
		timer->start(1000); // 每隔1s更新速度标签
 
		qDebug() << "receive the file of head：";
		//ui->receivedProgressBar->setValue(0);
		QDataStream in(tcpSocket);
		//QString globalUserName;
		in >> RtotalSize >> byteReceived >> fileName;
		//user.queryUserByName(globalUserName);
		//qDebug() << "the user :" << user.getUserName();
		
		qDebug() << "the file of head: " << fileName;
		qDebug() << "totalSize: " << RtotalSize;
		qDebug() << " first byteReceived: " << byteReceived;
		saveFileName = filePath + fileName;
		qDebug() << "start saveFileName:" << saveFileName;

		//设计一个文件读写不重复的功能
		int i = 0;
		QString suffix = fileName.right(fileName.size() - fileName.lastIndexOf('.') - 1); //获取文件后缀;
		//这里和服务器的不一样
		QString fullName = saveFileName.left(saveFileName.size() - (saveFileName.size() - saveFileName.lastIndexOf('.'))); //获取文件名
		while (1)
		{
			QFile *existFile = new QFile(saveFileName);  //就是判断是否重复
			if (existFile->exists())   //如果文件存在
			{
				i++;
				saveFileName = fullName + "(" + QString::number(i, 10) + ")." + suffix;
				qDebug() << "the fileName :" << saveFileName;
			}
			else
				break;
		}

		newFile = new QFile(saveFileName);  //新建一个文件，写入
		newFile->open(QFile::WriteOnly);
		//开始计时！
		downloadTime.start();
	}
	else  //正式读取文件内容  
	{
		while (tcpSocket->bytesAvailable() > 0)
		{
			receiveTime++;
			qDebug()<< "ThreadId: " << QThread::currentThreadId() 
				<< fileName<< " the " << receiveTime << "recv block "<< inBlock.size()
				<< "current receive the byte is :" << byteReceived 
				<< " and the total " << RtotalSize;
			inBlock = tcpSocket->read(4 * 1024);
			//qDebug() << "the inBlock size is " << inBlock.size();   //你tm粘包了兄弟
			//qDebug() << "current received the byte is :" << byteReceived;
			//qDebug() << "the block: " << inBlock;
			byteReceived += inBlock.size();
			float useTime = downloadTime.elapsed();
			speed = (byteReceived) / useTime;
			//speed = (speed * 1000 / (1024 * 1024));

			//计算时间，传入一个float
			countLeftTime(RtotalSize / speed / 1000 - useTime / 1000); 
			emit updateProgress(index, byteReceived, RtotalSize);
			//ui->downloadSpeedLabel->show();
			//ui->downloadSpeedLabel->setText(QString::fromLocal8Bit("已下载 %1MB (%2MB/s) 共%3MB 已用时:%4秒\n估计剩余时间：%5秒")
			//	.arg((byteReceived) / (1024 * 1024))//已接收
			//	.arg(speed * 1000 / (1024 * 1024), 0, 'f', 2)//速度
			//	.arg(RtotalSize / (1024 * 1024))//总大小
			//	.arg(useTime / 1000, 0, 'f', 0)//用时
			//	.arg(RtotalSize / speed / 1000 - useTime / 1000, 0, 'f', 0));//剩余时间

			//ui->progressBar->setMaximum(RtotalSize);
			//ui->progressBar->setValue(byteReceived);
			//qDebug() << "begin to write";

			newFile->write(inBlock);
			newFile->flush();
		}
	}

	if (byteReceived == RtotalSize)
	{
		//MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("下载完成!"), MESSAGE_INFORMATION, BUTTON_OK);
		//ui->downloadSpeedLabel->setText(QString::fromLocal8Bit("下载完成！"));
		qDebug() << "receive is done, and the byteReceived is :" << byteReceived <<" the RtotalSize is :"<< RtotalSize;
		/*qDebug() << "the file name:" << file.getFileName();
		qDebug() << "the userid :" << user.getUserId();
		qDebug() << "the userid from file:" << file.getUserId();*/
		emit downloadOver(index);
		inBlock.clear();
		byteReceived = 0;
		RtotalSize = 0;
		receiveTime = 0;
		newFile->close();
		disconnect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveFile()));
		//connect(tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	}
}

void DownloadFile::updateSpeed()
{
	emit updateSpeedLabel(index, speed, leftTime);
}

void DownloadFile::countLeftTime(float mleftTime)
{
	int hour = 0, min = 0, second = mleftTime;
	hour = second / 3600;
	second %= 3600;
	min = second / 60;
	second %= 60;
	leftTime = QString::number(hour).sprintf("%02d", hour) + ":"
		+ QString::number(min).sprintf("%02d", min) + ":"
		+ QString::number(second).sprintf("%02d", second);
}