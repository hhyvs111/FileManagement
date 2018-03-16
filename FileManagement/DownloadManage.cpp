#include "DownloadManage.h"
#include "MyMessageBox.h"
#include <QFileDialog>
#include <QToolTip>
#include <QtWin>
#include <QToolButton>
#include <QFileIconProvider>

DownloadManage::DownloadManage(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::DownloadManage)
{
	ui->setupUi(this);
	initModel();
	initMap();
}

DownloadManage::~DownloadManage()
{
		
}

void DownloadManage::initModel()
{
	connect(ui->tableView, SIGNAL(entered(QModelIndex)),
		this, SLOT(showToolTip(QModelIndex)));
	ui->tableView->setMouseTracking(true);   //设置鼠标追踪
	model = new QStandardItemModel();  //初始化model
	model->setColumnCount(8);
	ui->tableView->setShowGrid(false);
	ui->tableView->verticalHeader()->setVisible(false);// 垂直不可见
														   //ui->tableView->horizontalHeader()->setVisible(false);// 水平不可见
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("文件名"));
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("文件大小"));
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("进度"));
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("速度"));
	model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("剩余时间"));
	model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("打开"));
	model->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("删除"));

	ui->tableView->setModel(model);
	ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui->tableView->setColumnWidth(0, 30);
	ui->tableView->setColumnWidth(1, 240);
	ui->tableView->setColumnWidth(2, 70);
	ui->tableView->setColumnWidth(3, 110);
	ui->tableView->setColumnWidth(4, 70);
	ui->tableView->setColumnWidth(5, 60);
	ui->tableView->setColumnWidth(6, 40);
	ui->tableView->setColumnWidth(7, 40);

	//设置列宽不可变 
	ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(7, QHeaderView::Fixed);
}
void DownloadManage::showToolTip(const QModelIndex &index) {
	if (!index.isValid()) {
		qDebug() << "Invalid index";
		return;
	}
	QToolTip::showText(QCursor::pos(), index.data().toString());
}

void DownloadManage::initMap()
{
	downloadThreadMap = new QMap<int, DownloadThread*>;
	downloadProgressBarMap = new QMap<int, QProgressBar*>;
	downloadSpeedMap = new QMap<int, QLabel*>;
	downloadLeftTimeMap = new QMap<int, QLabel*>;
	fileSizeMap = new QMap<int, QLabel*>;
	index = 0;
	
}

//当downloadWindow有下载请求的时候，插入一条下载记录到downloadManage，开启线程？
void DownloadManage::insertDownloadFile(QString m_FileName, QString m_FilePath)
{
	qDebug() << "insert download file" << m_FileName << m_FilePath;
	//插入界面到tableView

	//这个得放在前面，不然第一个不能直接插入，没有rowcount
	model->setItem(index, 1, new QStandardItem(m_FileName));

	mFileIcon = new QLabel();
	mFileName = new QLabel();
	mFileIcon->setMinimumSize(30, 35);
	setFileIcon(m_FileName);

	ui->tableView->setIndexWidget(model->index(model->rowCount() - 1, 0), mFileIcon);


	//实现图标和文件名在同一格放在第二列
	//IconName = new QWidget();
	//QHBoxLayout *fileInfoLayout = new QHBoxLayout();
	//IconName->setLayout(fileInfoLayout);
	//mFileIcon = new QLabel(IconName);
	//mFileName = new QLabel(IconName);
	//setFileIcon(m_FileName);
	//QHBoxLayout *fileInfoLayout = new QHBoxLayout();
	//fileInfoLayout->setMargin(0);
	//mFileIcon = new QLabel();
	//mFileIcon->setMinimumSize(30, 35);
	////mFileIcon->setMaximumSize(10, 10);
	//mFileName = new QLabel();
	////mFileName->setMinimumSize(20, 25);
	//setFileIcon(m_FileName);
	//fileInfoLayout->insertWidget(0, mFileIcon);
	//fileInfoLayout->insertWidget(1, mFileName);
	//IconName = new QWidget();
	//IconName->setLayout(fileInfoLayout);
	//fileInfoLayout->setAlignment(mFileIcon, Qt::AlignLeft);
	//fileInfoLayout->setAlignment(mFileName, Qt::AlignLeft);
	//ui->tableView->setIndexWidget(model->index(model->rowCount() - 1, 1), IconName);
	//ui->horizontalLayout->insertWidget(0, IconName);
	

	mFileSize = new QLabel();
	QWidget *sizeWidget = new QWidget();
	QHBoxLayout *SizeLayout = new QHBoxLayout();
	SizeLayout->addWidget(mFileSize);
	SizeLayout->setAlignment(mFileSize, Qt::AlignLeft);
	sizeWidget->setLayout(SizeLayout);
	fileSizeMap->insert(index, mFileSize);
	ui->tableView->setIndexWidget(model->index(model->rowCount()-1, 2), sizeWidget);


	//放进度条
	QProgressBar *downloadProgressBar = new QProgressBar(this);
	//downloadProgressBar->hide();
	//downloadProgressBar->setMaximumHeight(20);
	downloadProgressBar->setTextVisible(false);
	downloadProgressBarMap->insert(index, downloadProgressBar);  //将这个进度条放入map
	ui->tableView->setIndexWidget(model->index(model->rowCount()-1 , 3), downloadProgressBar);

	//放速度条
	mFileSpeed = new QLabel();
	QWidget *widgetSpeed = new QWidget();
	QHBoxLayout *SpeedLayout = new QHBoxLayout();
	SpeedLayout->addWidget(mFileSpeed);
	SpeedLayout->setAlignment(mFileSpeed, Qt::AlignLeft);
	widgetSpeed->setLayout(SpeedLayout);

	downloadSpeedMap->insert(index, mFileSpeed);
	ui->tableView->setIndexWidget(model->index(model->rowCount() -1, 4), widgetSpeed);
	//model->item(model->rowCount() - 1, 4)->setTextAlignment(Qt::AlignCenter);  //居中

	//放剩余时间
	mLeftTime = new QLabel();
	downloadLeftTimeMap->insert(index, mLeftTime);
	ui->tableView->setIndexWidget(model->index(model->rowCount() -1 , 5), mLeftTime);
	//model->item(model->rowCount() - 1, 5)->setTextAlignment(Qt::AlignCenter); //居中
	

	

	//model->setItem(index, 0, new QStandardItem(fileInfo.at(i).fileName));

	ui->tableView->setModel(model);
	//开启一个新的线程
	downloadThread = new DownloadThread(m_FileName, m_FilePath,index); //这里new了一个线程
	qDebug() << "new download , main ThreadId :" <<QThread::currentThreadId();
	downloadThreadMap->insert(index, downloadThread);
	connect(downloadThread, SIGNAL(finished()), downloadThread, SLOT(deleteLater()));
	connect(downloadThread, SIGNAL(downloadAvailable(int)), this, SLOT(beginToDownload(int)));
	//对了要发送一个下载请求到服务器！ 
	downloadThread->start();
	index++;
}

//绑定信号槽
void DownloadManage::beginToDownload(int num)
{
	//依次绑定信号槽
	qDebug() << num << "bind signal ";
	QMap<int, DownloadThread*>::iterator it = downloadThreadMap->find(num);;
	//这些就是更新UI，以及是否发送完毕
	connect(it.value()->downloadFile, SIGNAL(downloadOver(int)), this, SLOT(checkDownloadOver(int)), Qt::BlockingQueuedConnection);
	connect(it.value()->downloadFile, SIGNAL(updateProgress(int, qint64, qint64)),
		this, SLOT(updateProgressBar(int, qint64, qint64)), Qt::BlockingQueuedConnection);
	connect(it.value()->downloadFile, SIGNAL(updateSpeedLabel(int, double,QString)),
		this, SLOT(updateSpeedLabel(int, double,QString)), Qt::BlockingQueuedConnection);
	//connect(this, SIGNAL(sendFileSignal()), it.value()->downloadFile, SLOT(receiveSendSignal()));

}
void DownloadManage::checkDownloadOver(int num)
{

	//QMap<int, DownloadThread*>::iterator it = downloadQThreadMap->find(num);
	//设置一下图片
	//qDebug() << num << "is send over";
	//if (it.value()->downloadFile->isOver == true)
	//{
	//	qDebug() << num << "is download over";
	//	QMap<int, QHBoxLayout*>::iterator it1 = fileStatusLayoutMap->find(num);
	//	QLabel *successLogo = new QLabel();
	//	successLogo->setPixmap(QPixmap(":/Resource/icon/correct.png"));
	//	QLabel *successMessage = new QLabel(QString::fromLocal8Bit("上传成功"));

	//	it1.value()->insertWidget(0, successLogo);
	//	it1.value()->insertWidget(1, successMessage);
	//	QMap<int, QLabel*>::iterator it2 = fileSpeedMap->find(num);
	//	it2.value()->hide();
	//}
}

void DownloadManage::updateProgressBar(int num, qint64 byteToWrite, qint64 totalSize)
{
	QMap<int, QProgressBar*>::iterator itP = downloadProgressBarMap->find(num);
	itP.value()->setMaximum(totalSize);// 取出该值设置大小
	itP.value()->setValue(byteToWrite);  //设置当前值

	QMap<int, QLabel*>::iterator it1 = fileSizeMap->find(num);
	it1.value()->setText(countFileSize(QString::number(totalSize, 10)));
}

//更新速度，这个QString是downloadFile传过来的 00::00::00格式。
void DownloadManage::updateSpeedLabel(int num, double speed, QString leftTime)
{
	QMap<int, QLabel*>::iterator it1 = downloadSpeedMap->find(num);
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

	QMap<int, QLabel*>::iterator it2 = downloadLeftTimeMap->find(num);
	it2.value()->setText(leftTime);
}
void DownloadManage::setFileIcon(QString fileName)
{

	QString suffix = (fileName.right(fileName.size() - fileName.lastIndexOf('.') - 1)).left(3); //获取文件后缀前三个字符
	QString allName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1); //获取文件名字
	qDebug() << "the suffix :" << suffix << " and the allName:" << allName;
	// 获取图标、类型
	QIcon icon = fileIcon(suffix);
	QString strType = fileType(suffix);
	qDebug() << strType;
	QPixmap pixmap = icon.pixmap(icon.actualSize(QSize(30, 35)));
	//QPixmap fileIcon(icon.);  //用来放文件的图标
	//fileIcon = fileIcon.scaled(QSize(30, 40), Qt::KeepAspectRatio);
	mFileIcon->setPixmap(pixmap);
	mFileIcon->setAlignment(Qt::AlignCenter);
	mFileName->setText(allName);

	//mFileIcon->show();
	//mFileName->show();
}
QIcon DownloadManage::fileIcon(const QString &extension) const
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

QString DownloadManage::fileType(const QString &extension) const
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
QString DownloadManage::countFileSize(QString fileSize)
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
}