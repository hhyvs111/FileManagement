#include "DownloadFile.h"
#include <QFileDialog>
#include <QtWin>
#include "MyMessageBox.h"
#include "Database.h"
DownloadFile::DownloadFile(QString mFileName, QString mFilePath,int num)
{
	fileName = mFileName;
	filePath = mFilePath;   //总文件就是 filePath + fileName；
	index = num;
	keepOn = false;
	init();

	qDebug() << "new downloadFile :" <<QThread::currentThreadId()
		<< keepOn;
}
//fileId的名字可能和filename不一样
DownloadFile::DownloadFile(int mFileId,QString mFileName,QString mFilePath, qint64 mBreakPoint,qint64 mRecordId, int num)
{
	breakFileName = mFileName;
	breakFilePath = mFilePath;   //总文件就是 filePath + fileName；
	breakFileId = mFileId;
	cbreakPoint = mBreakPoint;
	recordId = mRecordId;
	index = num;
	keepOn = true;
	init();
}

DownloadFile::~DownloadFile()
{
	//delete ui;
}


//初始化界面  
void DownloadFile::init()
{
	QString bs;
	QString data;
	tcpSocket = new QTcpSocket();  //新建一个socket
	tcpSocket->abort();   //取消已有的连接
	tcpSocket->connectToHost(ip, port);  //将这个socket连接到服务器
	byteReceived = 0;
	receiveTime = 0;
	if (!keepOn)
	{
		 bs = "downloadFile";
		 data = bs + "#" + fileName + "#" + globalUserName;
	}
	else
	{

		 bs = "downloadBreakFile";
		 //cbreakPoint断点处，因为等于sumblock的值
		 data = bs + "#" + QString::number(breakFileId) + "#" + QString::number(cbreakPoint) + "#" + globalUserName ;
	}

	QByteArray datasend = data.toUtf8();  //发送UTF8过去
	if (tcpSocket->write(datasend))
	{
		qDebug() << "send data to server: " << data;
		
		connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveFile()),Qt::DirectConnection);  //绑定信号槽

	}
	else
	{
		qDebug() << "send filed :" << data;
	}
}

void DownloadFile::receiveFile()
{
	outBlock.clear();
	QDataStream out(&outBlock, QIODevice::WriteOnly);
	if (byteReceived == 0)  //才刚开始接收数据，此数据为文件信息  
	{
		timer = new QTimer(this);
		connect(timer, SIGNAL(timeout()), this, SLOT(updateSpeed())); // ***就是你所说的响应函数
		timer->start(1000); // 每隔1s更新速度标签
 
		QDataStream in(tcpSocket);
		in >> RtotalSize >> byteReceived >> fileName>> fileId;
		sumBlock = RtotalSize / (4 * 1024) + 1;   //文件块数等于总大小除以每块的数量
		qDebug() << "the file sumBlock :" << sumBlock;
		//filePath = "files/";
		saveFileName = filePath + fileName;
		qDebug() << "the file of head: " << fileName 
			<< "totalSize: " << RtotalSize 
			<< " first byteReceived: " << byteReceived
			<< "start saveFileName:" << saveFileName <<"fileId: "<<fileId;

		if(!keepOn)
		{
			qDebug() << "nimabi" << keepOn;
			//设计一个文件读写不重复的功能
			QString suffix = fileName.right(fileName.size() - fileName.lastIndexOf('.') - 1); //获取文件后缀;																	 //这里和服务器的不一样
			QString fullName = fileName.left(fileName.size() - (fileName.size() - fileName.lastIndexOf('.'))); //获取文件名

			int i = 0;																											   //查询文件名是否重复
			while (1)
			{
				QFile *existFile = new QFile(filePath + fileName);  //就是判断是否重复
																	//qDebug() << "exitsFile" << mFilePath + mFileName;
				if (existFile->exists())   //如果文件存在
				{
					i++;
					fileName = fullName + "(" + QString::number(i, 10) + ")." + suffix;

					//qDebug() << "the fileName :" << mFileName;
				}
				else
					break;
			}
			newFile = new QFile(filePath + fileName);  //新建一个文件，写入
			newFile->open(QFile::WriteOnly);
			//
			//qint64 fileWrited = newFile->size();

			breakPoint = receiveTime;
		}
		//如果是写断点，则直接打开不要新建
		else
		{
			qDebug() << "gogon!!!!!!!!!!!!!";
			newFile = new QFile(breakFilePath + breakFileName);  
			//append模式，在文件的后面
			newFile->open(QFile::WriteOnly| QFile::Append);
			newFile->atEnd();
			receiveTime = cbreakPoint - 1;
			byteReceived += (cbreakPoint-1) * 4 * 1024;
			breakPoint = cbreakPoint - 1;
		}

		
		//开始计时！
		downloadTime.start();
		outBlock.clear();
		//qDebug() << outBlock;
		qDebug() << "the status:" << receiveStatus << "the sumBlock:" << sumBlock << "the breakPoint:" << breakPoint;
		out << receiveStatus << sumBlock << breakPoint;
		//qDebug() << outBlock;
		tcpSocket->write(outBlock);
		//tcpSocket->waitForBytesWritten();

	}
	else  //正式读取文件内容  
	{
		while (tcpSocket->bytesAvailable() > 0)
		{
			receiveTime++;
			breakPoint = receiveTime;
			if (tcpSocket->bytesAvailable() < 4 * 1024)
				inBlock = tcpSocket->read(tcpSocket->bytesAvailable());
			else
				inBlock = tcpSocket->read(4 * 1024);
			byteReceived += inBlock.size();
			float useTime = downloadTime.elapsed();
			speed = (byteReceived) / useTime;
			//计算时间，传入一个float
			countLeftTime(RtotalSize / speed / 1000 - useTime / 1000);

			//要是信号大于0则代表停止传输，发送断点位置给服务器

			if (receiveStatus > 0)
			{
				qDebug() << "stop receive!";
				outBlock.clear();
				out << receiveStatus<<sumBlock<<breakPoint;
				if (insertRecord())
				{
					qDebug() << "insert downloadRecord success!";
				}
				else
				{
					qDebug() << "insert failed!";
				}
			}
			else
			{
				//如果写入完成向服务器发送一个标记,-1为继续发送
				if (newFile->write(inBlock))
				{
					qDebug() << "write sucess!";
					newFile->flush();
					emit updateProgress(index, byteReceived, RtotalSize);
					receiveStatus = -1;
					outBlock.clear();

					qDebug() << "the status:" << receiveStatus << "the sumBlock:" << sumBlock << "the breakPoint:" << breakPoint;
					out << receiveStatus << sumBlock << breakPoint;
					qDebug() << "ThreadId: " << QThread::currentThreadId()
						<< fileName << " the " << receiveTime << "recv block " << inBlock.size()
						<< "current receive the byte is :" << byteReceived
						<< " and the total " << RtotalSize;
				}
				else
				{
					qDebug() << "write fail!";
					receiveStatus = -2;
					outBlock.clear();
					qDebug() << "the status:" << receiveStatus << "the sumBlock:" << sumBlock << "the breakPoint:" << breakPoint;
					out << receiveStatus << sumBlock << breakPoint;
				}
			}
			//qDebug() << "outBlock" << outBlock;
			tcpSocket->write(outBlock);  //写数据给服务器
			tcpSocket->waitForBytesWritten();
		}
	}

	if (byteReceived == RtotalSize)
	{
		qDebug() << "receive is done, and the byteReceived is :" << byteReceived <<" the RtotalSize is :"<< RtotalSize;
		/*qDebug() << "the file name:" << file.getFileName();
		qDebug() << "the userid :" << user.getUserId();
		qDebug() << "the userid from file:" << file.getUserId();*/
		if (!keepOn)
		{
			if (insertRecord())
			{
				qDebug() << "insert downloadRecord success!";
			}
			else
			{
				qDebug() << "insert failed!";
			}
		}
		else
		{
			updateRecord();
		}


		inBlock.clear();
		byteReceived = 0;
		RtotalSize = 0;
		receiveTime = 0;
		newFile->close();
		timer->stop();
		disconnect(timer, SIGNAL(timeout()), this, SLOT(updateSpeed())); // ***就是你所说的响应函数
		//receiveStatus = -3;
		//out << receiveStatus << sumBlock << breakPoint;
		//tcpSocket->write(outBlock);  //写数据给服务器,说发送完毕
		disconnect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveFile()));
		//connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveBreak()));
		emit downloadOver(index);
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


//接收到停止发送的信号
void DownloadFile::stopReceive(int)
{
	receiveStatus = receiveTime;
}

bool DownloadFile::insertRecord()
{
	QString sql = "insert into DownloadRecord(r_fileName,r_filePath,r_fileSize,r_sumBlock,r_breakPoint,r_fileId)values('"
		+ fileName + "','" + filePath + "','" 
		+ QString::number(RtotalSize) + "'," + QString::number(sumBlock) + "," 
		+ QString::number(breakPoint)+"," + QString::number(fileId) +  ")";
	qDebug() << sql;
	QSqlQuery insert;
	insert.exec(sql);
	if (insert.isActive())
	{
		qDebug() << sql;
		//查询最新的downloadRecord记录
		QString sql1 = "select * from DownloadRecord order by r_Id desc limit 0,1";
		QSqlQuery query;
		query.exec(sql1);
		BreakFile breakFile;
		if (query.next())
		{
			breakFile.recordId = query.value(0).toInt();
		}
		
		breakFile.fileId = fileId;
		breakFile.fileName = fileName;
		breakFile.breakPoint = breakPoint;
		breakFile.filePath = filePath;
		////将这个breakFile传送过去
		//qint64 recordId, int fileId,
		//	QString fileName, QString filePath,
		//	qint64 breakPoint
		emit addToBreakFile(index, breakFile.recordId, breakFile.fileId,
			breakFile.fileName, breakFile.filePath, breakFile.breakPoint);

		return true;
	}

	return false;
}

bool DownloadFile::updateRecord()
{
	QString sql = "update DownloadRecord set r_breakPoint = " + QString::number(breakPoint) + " where r_Id = " + QString::number(recordId) + ";";
	qDebug() << sql;
	QSqlQuery insert;
	insert.exec(sql);
	if (insert.isActive())
	{
		qDebug() << sql;
		return true;
	}
	return false;
}

