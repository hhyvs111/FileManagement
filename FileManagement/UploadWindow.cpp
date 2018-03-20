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
	ui->setupUi(this);
	
	initWindow();
	init();  //初始化
}

UploadWindow::~UploadWindow()
{
	delete ui;
}

void UploadWindow::initWindow()
{
	setAcceptDrops(true);
	QPixmap DragDrop(":/Resource/FunIcon/Drag-Drop.png");  //用来放文件的图标
														   //Drag = fil.scaled(QSize(50, 60), Qt::KeepAspectRatio);
	ui->Drag->setPixmap(DragDrop);
	//ui->Drag->setAlignment(Qt::AlignCenter);
	loadStyleSheet("UploadFile");  //
}
//主要是初始化界面
void UploadWindow::init()
{
	index = 0;
	fileProgressBarMap = new QMap<int, QProgressBar*>;   //需要初始化
	uploadFileMap = new QMap<int, UploadFile*>;
	uploadQThreadMap = new QMap<int, UploadThread*>;
	fileSpeedMap = new QMap<int, QLabel*>;
	fileStatusLayoutMap = new QMap<int, QHBoxLayout*>;
	//fileSizeMap = new QMap<int, QLabel*>;
	fileNameMap.clear();  //初始化这个，不是*不用NEW吧
	row = 0;
	column = 0;
	cnt = 0;
}



//重要操作，插入文件，新建线程
void UploadWindow::insertFile(QString m_fileName)
{
	//先定义第一层，总框架
	fileSumLayout = new QVBoxLayout(this);
	fileWindow = new QWidget(this);
	fileWindow->setObjectName("widgetMain");
	fileWindow->setStyleSheet("QWidget#widgetMain{border: 1px solid black; border-radius: 5px;};");
	
	fileWindow->setGeometry(0, 0, 250, 100);
	//第二层
	//文件名，大小，图标
	fileInfoLayout = new QHBoxLayout();
	fileSumLayout->insertLayout(0, fileInfoLayout);
	{
		mFileIcon = new QLabel();
		//mFileIcon->setGeometry(0, 0, 30, 40);
		mFileIcon->setMaximumSize(30, 40);
		fileNameSizeLayout = new QVBoxLayout();
		
		fileInfoLayout->insertWidget(0, mFileIcon);
		fileInfoLayout->insertLayout(1, fileNameSizeLayout);

		mFileName = new QLabel();
		mFileSize = new QLabel();
		localFile = new QFile(m_fileName);
		localFile->open(QFile::ReadOnly);
		mFileSize->setText(countFileSize(QString::number(localFile->size(), 10)));

		localFile->close();
		 //fileSizeMap->insert(index, mFileSize);
		setFileIcon(m_fileName);	//设置该文件的名字和图标
		 //fileInfoLayout->insertSpacerItem(2,Spacer);
		fileNameSizeLayout->addWidget(mFileName, Qt::AlignLeft);
		fileNameSizeLayout->addWidget(mFileSize, Qt::AlignLeft);
	}

	//进度条
	fileProgressBar = new QProgressBar(this);
	fileSumLayout->insertWidget(1, fileProgressBar);
	fileProgressBar->setMaximumHeight(10);
	fileProgressBar->setTextVisible(false);
	fileProgressBarMap->insert(index, fileProgressBar);  //将这个进度条放入map
	
	//文件状态界面
	fileStatusLayout = new QHBoxLayout();
	fileStatusLayoutMap->insert(index, fileStatusLayout);
	fileSumLayout->insertLayout(2, fileStatusLayout);
	{
		mFileSpeed = new QLabel();
		mButtonWait = new QPushButton();
		mButtonCancel = new QPushButton();

		fileSpeedMap->insert(index, mFileSpeed);
		mButtonWait->setText("wait");
		mButtonCancel->setText("cancel");

		fileStatusLayout->insertWidget(0, mFileSpeed);
		fileStatusLayout->insertWidget(1, mButtonWait);
		fileStatusLayout->insertWidget(2, mButtonCancel);

		/*mFileSpeed->setText("sudu");*/
	}

	fileWindow->setLayout(fileSumLayout);
	ui->UploadGridLayout->addWidget(fileWindow,row/2,column%2);
	//ui->FileListLayout->addWidget(fileWindow);

	//QProgressBar *fileProgressBar = new QProgressBar(this);
	//fileProgressBar->setTextVisible(false);   //不显示百分比
	//fileProgressBarMap->insert(index, fileProgressBar);  //将这个进度条放入map
	//stackLayout = new QStackedLayout();
	//fileWidget = new QWidget(this);
	// //fileWidget->setLayout(fileInfoLayout);  //设置水平layout
	// //插入文件和名字
	// fileInfoLayout = new QHBoxLayout(fileWidget);
	// mFileIcon = new QLabel(fileWidget);
	// mFileName = new QLabel(fileWidget);
	// fileInfoLayout->addWidget(mFileIcon);
	// fileInfoLayout->addWidget(mFileName);
	//
	// setFileIcon(m_fileName);	//设置该文件的名字和图标
	//
	// stackLayout->addWidget(fileWidget);
	// stackLayout->addWidget(fileProgressBar);
	// fileProgressBar->setTextVisible(false);
	// stackLayout->setStackingMode(QStackedLayout::StackAll);
	// ui->FileListLayout->addLayout(stackLayout);  //垂直的放置多个文件

	 //这个时候已经建立了套接字了，那就不行，因为是在主线程建立的。所以要先移动进线程？
	 //UploadFile *uploadFile = new UploadFile(m_fileName,index);
	 qDebug() << "the send id and name:" << index << " " << m_fileName;
	 fileThread = new UploadThread(m_fileName, index,this);
	 connect(fileThread, SIGNAL(finished()), fileThread, SLOT(deleteLater()));	
	 uploadQThreadMap->insert(index, fileThread);

	 qDebug() << " main Thread : " << QThread::currentThreadId();
	 connect(fileThread, SIGNAL(sendAvailable(int)), this, SLOT(beginToSend(int)));
	 fileThread->start();
	 
	 index++;
	 row++;
	 column++;
}


//根据index的值来绑定信号槽
void UploadWindow::beginToSend(int num)
{
	//依次绑定信号槽
	QMap<int, UploadThread*>::iterator it = uploadQThreadMap->find(num);;
	//这些就是更新UI，以及是否发送完毕
	connect(it.value()->uploadFile, SIGNAL(sendOver(int)), this, SLOT(checkSendOver(int)), Qt::BlockingQueuedConnection);
	connect(it.value()->uploadFile, SIGNAL(updateProgress(int, qint64, qint64)),
		this, SLOT(updataProgressBar(int, qint64, qint64)),Qt::BlockingQueuedConnection);
	connect(it.value()->uploadFile, SIGNAL(updateSpeedLabel(int, double)), 
		this, SLOT(updateSpeedLabel(int, double)), Qt::BlockingQueuedConnection);
	connect(this, SIGNAL(sendFileSignal()), it.value()->uploadFile, SLOT(receiveSendSignal()));
	
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
	}
}

void UploadWindow::initFile()
{

}

//打开按钮
void UploadWindow::ClickOpenButton()  //打开文件并获取文件名（包括路径）  
{
	//直接加入
	QStringList List = QFileDialog::getOpenFileNames();
	
	//fileName = QFileDialog::getOpenFileName(this);
	if (!List.isEmpty())
	{
		for (int i = 0; i < List.size(); i++)
		{
			fileName = List.at(i);
			qDebug() << "the file list:" << List.at(i);
			insertFile(List.at(i));
		}
		fileNameList.append(List);
	}
}



void UploadWindow::ClickSendButton()
{
	emit sendFileSignal();
	//QTcpSocket *tcp = new QTcpSocket();
	//tcp->connectToHost(ip, port);  //将这个socket连接到服务器
	ui->sendBtn->setEnabled(false); //按钮失效
}
void UploadWindow::checkSendOver(int num)
{

	QMap<int, UploadThread*>::iterator it = uploadQThreadMap->find(num);
	//设置一下图片
	//qDebug() << num << "is send over";
	if (it.value()->uploadFile->isOver == true)
	{
		qDebug() << num << "is send over";
		QMap<int, QHBoxLayout*>::iterator it1 = fileStatusLayoutMap->find(num);
		QLabel *successLogo = new QLabel();
		successLogo->setPixmap(QPixmap(":/Resource/icon/correct.png"));
		QLabel *successMessage = new QLabel(QString::fromLocal8Bit("上传成功"));

		it1.value()->insertWidget(0,successLogo);
		it1.value()->insertWidget(1,successMessage);
		QMap<int, QLabel*>::iterator it2 = fileSpeedMap->find(num);
		it2.value()->hide();
		//it.value()->~UploadThread();  //直接析构吧
		cnt++;
	}
	if (cnt == index)
	{
		ui->sendBtn->setEnabled(true);
	}
	//直接初始化这些map
	//init();
	//ui->retranslateUi(this);
}

//更新进度条
void UploadWindow::updataProgressBar(int num,qint64 byteToWrite,qint64 totalSize)
{
	QMap<int, QProgressBar*>::iterator itP = fileProgressBarMap->find(num);
	
	//mFileSize->setText(countFileSize(QString::number(totalSize, 10)));  //计算文件大小，显示在界面上 
	//qDebug() <<"index "<<num <<" value"<< byteToWrite << " " << totalSize;
	
	//为什么会崩溃啊尼玛
	itP.value()->setMaximum(totalSize);// 取出该值设置大小
	itP.value()->setValue(totalSize - byteToWrite);  //设置当前值

	
}
void UploadWindow::updateSpeedLabel(int num, double speed)
{
	QMap<int, QLabel*>::iterator it1 = fileSpeedMap->find(num);
	speed = (speed) / 1024 * 1024;
	//如果速度大于MB则显示MB否则显示KB
	if (speed > 1024)
	{
		speed /= 1024;
		it1.value()->setText(QString::fromLocal8Bit("%1M/S").arg(speed, 0, 'f', 2));
	}
	else
	{
		it1.value()->setText(QString::fromLocal8Bit("%1KB/S").arg(speed, 0, 'f', 2));
	}
}
QString UploadWindow::countFileSize(QString fileSize)
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
		
		icon = provider.icon(QFileInfo(strTemplateName));
		tmpFile.close();
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

