#include "DownloadFile.h"
#include "ButtonDelegate.h"
#include "TableModel.h"
#include <QFileDialog>
#include<QToolTip>
#include <QtWin>
#include <QToolButton>
#include <QFileIconProvider>
#include "MyMessageBox.h"
DownloadFile::DownloadFile(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::DownloadFile)
{
	ui->setupUi(this);
	//StotalSize = 0;
	byteReceived = 0;

	initModel();
	init();

	ui->downloadTable->setMouseTracking(true);   //设置鼠标追踪

	connect(ui->downloadTable, SIGNAL(entered(QModelIndex)),
		this, SLOT(showToolTip(QModelIndex)));

	//从客户端处理得到的数据
	connect(tcp, SIGNAL(sendDataToDownload(QString)), this, SLOT(receiveDataFromClient(QString)));
}

DownloadFile::~DownloadFile()
{
	delete ui;
}
void  DownloadFile::initModel()
{
	model = new QStandardItemModel();
	model->setColumnCount(7);
	ui->downloadTable->setShowGrid(false);
	ui->downloadTable->verticalHeader()->setVisible(false);// 垂直不可见
	//ui->downloadTable->horizontalHeader()->setVisible(false);// 水平不可见
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("文件名"));
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("文件大小"));
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("上传时间"));
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("上传者"));
	model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("下载"));
	model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("删除"));
	
	ui->downloadTable->setModel(model);
	ui->downloadTable->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui->downloadTable->setColumnWidth(0, 30);
	ui->downloadTable->setColumnWidth(1, 240);
	ui->downloadTable->setColumnWidth(2, 70);
	ui->downloadTable->setColumnWidth(3, 110);
	ui->downloadTable->setColumnWidth(4, 70);
	ui->downloadTable->setColumnWidth(5, 40);
	ui->downloadTable->setColumnWidth(6, 40);
	
	//设置列宽不可变 
	ui->downloadTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
	ui->downloadTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
	ui->downloadTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
	ui->downloadTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
	ui->downloadTable->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
	ui->downloadTable->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
}

//初始化界面
void DownloadFile::init()
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
//提示文本追踪
void DownloadFile::showToolTip(const QModelIndex &index) {
	if (!index.isValid()) {
		qDebug() << "Invalid index";
		return;
	}
	QToolTip::showText(QCursor::pos(), index.data().toString());
}


void DownloadFile::receiveFile()
{
	qDebug() << "get in receiveFile!!!";
	qDebug() << "the byte has received :" << byteReceived;

	if (byteReceived == 0)  //才刚开始接收数据，此数据为文件信息  
	{
 
		qDebug() << "receive the file of head";
		//ui->receivedProgressBar->setValue(0);
		QDataStream in(tcp->tcpSocket);
		//QString globalUserName;
		in >> RtotalSize >> byteReceived >> fileName;
		//user.queryUserByName(globalUserName);
		//qDebug() << "the user :" << user.getUserName();
		
		qDebug() << "the file of head: " << fileName;
		qDebug() << "totalSize: " << RtotalSize;
		qDebug() << " first byteReceived: " << byteReceived;
		qDebug() << "start saveFileName:" << saveFileName;
		newFile = new QFile(saveFileName);
		newFile->open(QFile::WriteOnly);
		//开始计时！
		downloadTime.start();
	}
	else  //正式读取文件内容  
	{
		while (tcp->tcpSocket->bytesAvailable() > 0)
		{
			receiveTime++;
			qDebug() << "the " << receiveTime << " receive the file ";
			inBlock = tcp->tcpSocket->read(4 * 1024);
			qDebug() << "the inBlock size is " << inBlock.size();   //你tm粘包了兄弟
			qDebug() << "current received the byte is :" << byteReceived;
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
			//qDebug() << "begin to write";

			newFile->write(inBlock);
			newFile->flush();
		}
	}

	if (byteReceived == RtotalSize)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("下载完成!"), MESSAGE_INFORMATION, BUTTON_OK);
		ui->downloadSpeedLabel->setText(QString::fromLocal8Bit("下载完成！"));
		qDebug() << "receive is done, and the byteReceived is :" << byteReceived <<" the RtotalSize is :"<< RtotalSize;
		/*qDebug() << "the file name:" << file.getFileName();
		qDebug() << "the userid :" << user.getUserId();
		qDebug() << "the userid from file:" << file.getUserId();*/
		inBlock.clear();
		byteReceived = 0;
		RtotalSize = 0;
		receiveTime = 0;
		newFile->close();
		disconnect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveFile()));
		connect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	}
}
void DownloadFile::ClickDownloadButton()
{
	QPushButton *btn = (QPushButton *)sender();   //产生事件的对象，按的谁就取谁
	QString row = btn->property("row").toString();  //取得按钮的row属性
	qDebug() << "the row is: "<<row;

	receiveTime = 0;
	//获取ui输入的信息
	//openFileName = ui->downloadFileName->text();   
	openFileName = btn->property("fileName").toString();
	QString bs = "downloadFile";
	QString data = bs + "#" + openFileName;
	if (saveFilePath(openFileName))  //调用一下获取路径函数，其实就是直接获取文件名,如果返回了真才下一步
	//发送中文需要
	{
		QByteArray datasend = data.toUtf8();  //发送UTF8过去
		if (tcp->tcpSocket->write(datasend))
		{
			qDebug() << "send data to server: " << data;
			disconnect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));  //取消TCP的正常读信息
			connect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveFile()));
		}
		else
		{
			qDebug() << "send filed :" << data;
		}
	}
}
void DownloadFile::ClickDeleteButton()
{
	QPushButton *btn = (QPushButton *)sender();   //产生事件的对象，按的谁就取谁
	QString row = btn->property("row").toString();  //取得按钮的row属性

	
	QString deleteFileName = btn->property("deleteFileName").toString();
	QString deleteFileId = btn->property("deleteFileId").toString();
	if (!MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("确定要删除%1吗？").arg(deleteFileName),
		MESSAGE_QUESTION, BUTTON_OK_AND_CANCEL, true))
	{
		QString bs = "deleteFile";
		QString data = bs + "#" + deleteFileName + "#" + deleteFileId;

		QByteArray datasend = data.toUtf8();
		if (tcp->tcpSocket->write(datasend))
		{
			qDebug() << "send data to server: " << data;

		}
		else
			qDebug() << "send failed!";
	}

}

void DownloadFile::sendFileInfo(QString condition)
{
	//每次打开该页面则发查询信息发过去
	//QString data = "findFileByName#" + globalUserName;   //查询该用户的文件？
	QString data = "findFile#";   //查询文件，默认为all
	data += condition;

	QByteArray datasend = data.toUtf8();
	qDebug() << datasend;
	tcp->tcpSocket->write(datasend);

	//暂时取消TCP原本的验证消息
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	connect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(showFileInfo()));
}

void DownloadFile::receiveDataFromClient(QString data)
{
	if (QString::compare(data, "delete_T") == 0)
	{
		//ui->downloadTable->clearn

		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("删除文件成功！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
		//实现实时更新
		initModel();  //删除后在这里初始化
		sendFileInfo();  //然后发信息给服务器查询当前文件情况
		//model.
	}
	else if (QString::compare(data, "delete_F") == 0)
	{
		MyMessageBox::showMyMessageBox(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("删除文件失败！"), MESSAGE_INFORMATION, BUTTON_OK_AND_CANCEL);
	}
}

void DownloadFile::showFileInfo()
{
	initModel();
	QByteArray dataread = tcp->tcpSocket->readAll();
	//QDataStream in(tcp->tcpSocket);

	qDebug() << dataread;

	QBuffer buf(&dataread);
	buf.open(QIODevice::ReadOnly);
	QDataStream in(&buf);
	int FileListSize;
	in >> FileListSize;  //读入文件个数

	//设置一个fileInfo的Qlist
	QList<FileInfo> fileInfo;
	//讲二进制流依次写入
	for (int i = 0;i < FileListSize;i++)
	{
		FileInfo f1;
		in >> f1;
		fileInfo.append(f1);
		qDebug() << f1.fileId << " " << f1.fileName << " " <<
			f1.fileSize << " " << f1.fileType << " " 
			<< f1.fileTime << " " << f1.fileUser << " " << f1.userId;
	}
	buf.close();
	//FileInfo f2;


	////QString data = QString::fromUtf8(dataread);
	////qDebug() << "the data from client: " << dataread;
	////QStringList listNumber = data.split("$");

	//QList<FileInfo> fileInfo;
	////在这里就要加入到表里去
	////把数据都放到QList里去！
	////listNumber[0] 是文件个数
	//for (int i = 1;i <= listNumber[0].toInt();i++)
	//{
	//	FileInfo littleFile;
	//	QStringList fileList = listNumber[i].split("^");
	//	littleFile.fileId = fileList[0].toInt();
	//	littleFile.fileName = fileList[1];
	//	littleFile.fileSize = fileList[2];
	//	littleFile.fileType = fileList[3];
	//	littleFile.fileTime = fileList[4];
	//	littleFile.fileUser = fileList[5];
	//	littleFile.userId = fileList[6].toInt();
	//	qDebug() << littleFile.fileId<<" " << littleFile.fileName << " " <<
	//		littleFile.fileSize << " " << littleFile.fileType << " " 
	//		<< littleFile.fileTime << " " << littleFile.fileUser << " " << littleFile.userId;
	//	fileInfo.append(littleFile);
	//}
	ui->downloadTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	for (int i = 0; i < fileInfo.size(); i++)
	{
		//设置前四列的数据
		model->setItem(i, 1, new QStandardItem(fileInfo.at(i).fileName));
		model->setItem(i, 2, new QStandardItem(countFileSize(fileInfo.at(i).fileSize)));  //countFileSize根据大小显示KB还是MB
		model->setItem(i, 3, new QStandardItem(fileInfo.at(i).fileTime));
		model->setItem(i, 4, new QStandardItem(fileInfo.at(i).fileUser));

		//为这个第五列添加按钮
		m_download = new QToolButton();
		QIcon downloadFile(":/Resource/icon/downloadFile.png"); //创建QIcon对象
		m_download->setIcon(downloadFile); //将图片设置到按钮上
		m_download->setIconSize(QSize(20, 20));//根据实际调整图片大小
		m_download->setStyleSheet("border:none");
		m_download->setCursor(Qt::PointingHandCursor);
		m_delete = new QToolButton(); 
		QIcon deleteFile(":/Resource/icon/deleteFile.png"); //创建QIcon对象
		m_delete->setIcon(deleteFile); //将图片设置到按钮上
		m_delete->setIconSize(QSize(20, 20));//根据实际调整图片大小
		m_delete->setStyleSheet("border:none");
		m_delete->setCursor(Qt::PointingHandCursor);
		//触发下载按钮的槽函数
		connect(m_download, SIGNAL(clicked(bool)), this, SLOT(ClickDownloadButton()));
		connect(m_delete, SIGNAL(clicked(bool)), this, SLOT(ClickDeleteButton()));
		//直接把文件名发给row得了！

		m_download->setProperty("row", i);  //为按钮设置row属性
		m_download->setProperty("fileName", fileInfo.at(i).fileName);  //为按钮设置filename属性

		m_delete->setProperty("row", i);
		m_delete->setProperty("deleteFileId", fileInfo.at(i).fileId);
		m_delete->setProperty("deleteFileName", fileInfo.at(i).fileName);

		
		ui->downloadTable->setIndexWidget(model->index(model->rowCount() - 1, 5), m_download);
		ui->downloadTable->setIndexWidget(model->index(model->rowCount() - 1, 6), m_delete);

		//这里设置一下图标？
		QIcon icon = fileIcon(fileInfo.at(i).fileType);
		QPixmap pixmap = icon.pixmap(icon.actualSize(QSize(20, 30)));
		QLabel *fIcon = new QLabel();
		fIcon->setPixmap(pixmap);
		ui->downloadTable->setIndexWidget(model->index(model->rowCount() - 1, 0), fIcon);
		
		//设置数据居中
		for(int j = 2;j < 5;j++)
		model->item(i, j)->setTextAlignment(Qt::AlignCenter);
	}
	//m_model->setData(data);
	//用完后断开
	disconnect(tcp->tcpSocket, SIGNAL(readyRead()), this, SLOT(showFileInfo()));
	connect(tcp->tcpSocket, SIGNAL(readyRead()), tcp, SLOT(readMessages()));
	
}

QString DownloadFile::countFileSize(QString fileSize)
{
	float floatSize;
	floatSize = fileSize.toFloat() / 1024;   //先是计算KB？
	//如果floatSize大于1024KB则输出MB,且保留2位小数
	if (floatSize > 1024)
	{
		return QString::fromLocal8Bit("%1MB").arg(QString::number(fileSize.toFloat() / (1024 * 1024), 'f', 2)); //返回一个QString
	}
	else
	{
		return QString::fromLocal8Bit("%1KB").arg(QString::number(fileSize.toFloat() / (1024), 'f', 2)); //返回一个QString
	}

	//QString::number(fileSize.toFloat() / (1024 * 1024), 'f', 2);  //先转换为浮点数。
}
bool DownloadFile::saveFilePath(QString openFileName)
{
	QFileDialog m_QFileDialog;   //新建一个对话

	//!-- 得到原文件的后缀名  
	QString suffix_save = QFileInfo(openFileName).suffix();
	//!--- 设置过滤匹配文件格式  
	QString setFilter = "office(*.doc *.docx *.xls *.xlsx *.ppt *.pptx);;image(*.jpg *.bmp);;txt(*.xml *.txt *.pdf);;(*.*);;";
	//!--- selectFilter为弹出对话框中的文件格式，dirString为文件路径，这里显示文件名  
	QString selectFilter, dirString;

	if (openFileName.isEmpty()) return false;
	else dirString = QFileInfo(openFileName).fileName();

	//!--- 判断文件后缀名以及文件格式，看是否匹配，没有做出相应操作  
	if (!suffix_save.isEmpty() && setFilter.contains(selectFilter)) selectFilter = suffix_save.insert(0, "*.");
	if (!suffix_save.isEmpty() && !setFilter.contains(selectFilter)) selectFilter = "*.*";

	 saveFileName = m_QFileDialog.getSaveFileName(this, "保存文件", dirString, setFilter, &selectFilter,
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	
	 //qDebug() << " saveFileName :"<< saveFileName;  //没问题啊尼玛
	if (saveFileName.isEmpty()) return false;

	return true;
	//QFile file(saveFileName);

	//if (selectFilter.compare("*.*")) saveFileName = saveFileName + selectFilter.remove(0, 1);
	//qDebug() << " saveFileName1 :" << saveFileName;  //看看这里
}

void DownloadFile::loadStyleSheet(const QString &sheetName)
{
	QFile file(":/Resource/qss/" + sheetName + ".qss");
	file.open(QFile::ReadOnly);
	if (file.isOpen())
	{
		//qDebug() << "is qss";
		QString styleSheet = this->styleSheet();
		styleSheet += QLatin1String(file.readAll());
		this->setStyleSheet(styleSheet);
	}
}

QIcon DownloadFile::fileIcon(const QString &extension) const
{
	QFileIconProvider provider;
	QIcon icon;
	QString strTemplateName = QDir::tempPath() + QDir::separator() +
		QCoreApplication::applicationName() + "_XXXXXX." + extension;
	QTemporaryFile tmpFile(strTemplateName);
	tmpFile.setAutoRemove(false);

	if (tmpFile.open())
	{
		QString file_name = tmpFile.fileName();
		tmpFile.close();
		icon = provider.icon(QFileInfo(file_name));
		tmpFile.remove();
	}
	else
	{
		qDebug() << QString("failed to write temporary file %1").arg(tmpFile.fileName());
	}

	return icon;
}

QString DownloadFile::fileType(const QString &extension) const
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

//条件查询，若输入为空则默认为all，主要是查询文件名字
void DownloadFile::ClickFindButton()
{
	//这个是输入框的值
	QString condition = ui->condition->text();
	if (condition.isEmpty())
	{
		sendFileInfo();
	}
	else
	{
		sendFileInfo(condition);
	}
}

