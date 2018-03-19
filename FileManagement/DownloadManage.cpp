#include "DownloadManage.h"
#include "MyMessageBox.h"
#include "Database.h"
#include <QFileDialog>
#include <QToolTip>
#include <QtWin>
#include <QToolButton>
#include<QActionGroup>
#include <QFileIconProvider>
#include <QDesktopServices>
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

	connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContextMenu(QPoint)));            //添加右键菜单
	ui->tableView->setMouseTracking(true);   //设置鼠标追踪
	model = new QStandardItemModel();  //初始化model
	model->setColumnCount(8);
	ui->tableView->setShowGrid(false);
	ui->tableView->verticalHeader()->setVisible(false);// 垂直不可见
	//ui->tableView->horizontalHeader()->setVisible(false);// 水平不可见
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);



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
	ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Fixed);
	ui->tableView->horizontalHeader()->setSectionResizeMode(7, QHeaderView::Fixed);
	//设置右键菜单
	setMenuEvent();
}
void DownloadManage::setMenuEvent()
{
	//右键菜单 
	actionWait = new QAction(this);
	actionWait->setText(QStringLiteral("暂停"));
	actionBegin = new QAction(this);
	actionBegin->setText(QStringLiteral("开始"));
	actionDelete = new QAction(this);
	actionDelete->setText(QStringLiteral("删除"));
	actionOpenFile = new QAction(this);
	actionOpenFile->setText(QStringLiteral("打开文件"));
	actionOpenFolder = new QAction(this);
	actionOpenFolder->setText(QStringLiteral("打开文件夹"));

	connect(actionWait, SIGNAL(triggered()), this, SLOT(CallWaitDownload()));
	connect(actionBegin, SIGNAL(triggered()), this, SLOT(CallKeepOnDownload()));
	connect(actionOpenFile, SIGNAL(triggered()), this, SLOT(CallOpenFile()));
	connect(actionOpenFile, SIGNAL(triggered()), this, SLOT(CallOpenFolder()));
	//QActionGroup *actionGroup = new QActionGroup(this);
	//actionGroup->addAction(actionBegin);
	//actionGroup->addAction(actionWait);
	//actionBegin->setChecked(true);
	//actionGroup->setExclusive(true);

	popMenu = new QMenu(ui->tableView);
	popMenu->addAction(actionBegin);
	popMenu->addAction(actionWait);
	popMenu->addSeparator();   //加一条横线
	popMenu->addAction(actionDelete);
	popMenu->addSeparator();   //加一条横线
	popMenu->addAction(actionOpenFile);
	popMenu->addAction(actionOpenFolder);

	//actionBegin->setEnabled(false);
}

void DownloadManage::addBreakFile(int num, qint64 recordId, int fileId,
	QString fileName, QString filePath,
	qint64 breakPoint)
{
	BreakFile breakFile;
	breakFile.recordId = recordId;
	breakFile.fileId = fileId;
	breakFile.fileName = fileName;
	breakFile.breakPoint = breakPoint;
	breakFile.filePath = filePath;
	breakFileMap->insert(num,breakFile);
}
void DownloadManage::CallWaitDownload()
{
	//当暂停按钮触发的时候，
	//actionBegin->setEnabled(true);
	QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
	QModelIndexList indexsSelected = selectionModel->selectedIndexes();
	QModelIndex indexSelected = indexsSelected.at(0);
	qDebug() << "waitRow" << indexSelected.row();

	QMap<int, int>::iterator it = fileStatusMap->find(indexSelected.row());
	it.value() = 2;
	downloadThreadMap->remove(indexSelected.row());
	

	//选中的行数发出暂停的操作
	
	emit stopDownload(indexSelected.row());
}

void DownloadManage::CallKeepOnDownload()
{
	QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
	QModelIndexList indexsSelected = selectionModel->selectedIndexes();
	QModelIndex indexSelected = indexsSelected.at(0);

	QMap<int, BreakFile>::iterator it = breakFileMap->find(indexSelected.row());

	downloadThread = new DownloadThread(it.value().fileId,it.value().fileName,it.value().filePath, it.value().breakPoint,it.value().recordId, indexSelected.row(),true); //这里new了一个线程
	qDebug() << "new download , main ThreadId :" << QThread::currentThreadId();
	downloadThreadMap->insert(indexSelected.row(), downloadThread);
	//fileStatusMap->insert(index, 0); //插入正在下载状态
	//insertDownloadRecord(m_FileName, m_FilePath, "-1", -1, -1);
	connect(downloadThread, SIGNAL(finished()), downloadThread, SLOT(deleteLater()));
	connect(downloadThread, SIGNAL(downloadAvailable(int)), this, SLOT(beginToDownload(int)));
	//对了要发送一个下载请求到服务器！ 
	downloadThread->start();

	//更改文件状态
	QMap<int, int>::iterator it1 = fileStatusMap->find(indexSelected.row());
	it1.value() = 1;

	
}

void DownloadManage::CallOpenFile()
{
	QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
	QModelIndexList indexsSelected = selectionModel->selectedIndexes();
	QModelIndex indexSelected = indexsSelected.at(0);
	QMap<int, BreakFile>::iterator it = breakFileMap->find(indexSelected.row());

	//QFileInfo fi = QFileInfo(fileFull);
	//QString filePath;
	//filePath = fi.absolutePath();

	QDesktopServices::openUrl(QUrl(it.value().filePath + it.value().fileName, QUrl::TolerantMode));
}

void DownloadManage::CallOpenFolder()
{
	QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
	QModelIndexList indexsSelected = selectionModel->selectedIndexes();
	QModelIndex indexSelected = indexsSelected.at(0);
	QMap<int, BreakFile>::iterator it = breakFileMap->find(indexSelected.row());

	//QFileInfo fi = QFileInfo(fileFull);
	//QString filePath;
	//filePath = fi.absolutePath();

	QDesktopServices::openUrl(QUrl(it.value().filePath, QUrl::TolerantMode));
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
	fileStatusMap = new QMap<int, int>; 
	//fileIdMap = new QMap<int, int>;
	//fileNameMap = new QMap<int, QString>;
	breakFileMap = new QMap<int, BreakFile>;
	index = 0;
	queryLocalCache();
	
}



//-1代表还未下载
void DownloadManage::insertDownloadRecord(QString m_FileName, QString m_FilePath,QString m_FileSize,qint64 max,qint64 now)
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
	if (m_FileSize != "-1")
		mFileSize->setText(m_FileSize);
	ui->tableView->setIndexWidget(model->index(model->rowCount() - 1, 2), sizeWidget);


	//放进度条
	QProgressBar *downloadProgressBar = new QProgressBar(this);
	//downloadProgressBar->hide();
	//downloadProgressBar->setMaximumHeight(20);
	downloadProgressBar->setTextVisible(false);
	
	if (max == -1)
	{
		downloadProgressBarMap->insert(index, downloadProgressBar);  //将这个进度条放入map
	}
	else
	{
		qDebug() << "max :" << max << "now: " << now;
		downloadProgressBar->setMaximum(max);
		downloadProgressBar->setValue(now);
		downloadProgressBarMap->insert(index, downloadProgressBar);  //将这个进度条放入map
		downloadProgressBar->show();
	}
	ui->tableView->setIndexWidget(model->index(model->rowCount() - 1, 3), downloadProgressBar);

	//放速度条
	mFileSpeed = new QLabel();
	QWidget *widgetSpeed = new QWidget();
	QHBoxLayout *SpeedLayout = new QHBoxLayout();
	SpeedLayout->addWidget(mFileSpeed);
	SpeedLayout->setAlignment(mFileSpeed, Qt::AlignLeft);
	widgetSpeed->setLayout(SpeedLayout);

	downloadSpeedMap->insert(index, mFileSpeed);
	ui->tableView->setIndexWidget(model->index(model->rowCount() - 1, 4), widgetSpeed);
	//model->item(model->rowCount() - 1, 4)->setTextAlignment(Qt::AlignCenter);  //居中

	//放剩余时间
	mLeftTime = new QLabel();
	downloadLeftTimeMap->insert(index, mLeftTime);
	ui->tableView->setIndexWidget(model->index(model->rowCount() - 1, 5), mLeftTime);
	ui->tableView->setModel(model);
	index++;
	
}
//当downloadWindow有下载请求的时候，插入一条下载记录到downloadManage，开启线程？
void DownloadManage::insertDownloadFile(QString m_FileName, QString m_FilePath)
{
	
	//开启一个新的线程
	QString downloadName = checkRename(m_FileName, m_FilePath);
	downloadThread = new DownloadThread(m_FileName,m_FilePath,index,false); //这里new了一个线程
	qDebug() << "new download , main ThreadId :" <<QThread::currentThreadId();
	downloadThreadMap->insert(index, downloadThread);
	fileStatusMap->insert(index, 0); //插入正在下载状态
	qDebug() << "downloadName:" << downloadName;
	insertDownloadRecord(downloadName, m_FilePath,"-1", -1, -1);
	connect(downloadThread, SIGNAL(finished()), downloadThread, SLOT(deleteLater()));
	connect(downloadThread, SIGNAL(downloadAvailable(int)), this, SLOT(beginToDownload(int)));
	//对了要发送一个下载请求到服务器！ 
	downloadThread->start();
	
}

//绑定信号槽
void DownloadManage::beginToDownload(int num)
{
	//依次绑定信号槽
	qDebug() << num << "bind signal ";
	QMap<int, DownloadThread*>::iterator it = downloadThreadMap->find(num);
	//这些就是更新UI，以及是否发送完毕
	connect(it.value()->downloadFile, SIGNAL(downloadOver(int)), this, SLOT(checkDownloadOver(int)), Qt::BlockingQueuedConnection);
	connect(it.value()->downloadFile, SIGNAL(updateProgress(int, qint64, qint64)),
		this, SLOT(updateProgressBar(int, qint64, qint64)), Qt::BlockingQueuedConnection);
	connect(it.value()->downloadFile, SIGNAL(updateSpeedLabel(int, double,QString)),
		this, SLOT(updateSpeedLabel(int, double,QString)), Qt::BlockingQueuedConnection);
	connect(this, SIGNAL(stopDownload(int)), it.value()->downloadFile, SLOT(stopReceive(int)));
	connect(it.value()->downloadFile, SIGNAL(addToBreakFile(int, qint64,int,QString,QString,qint64)), this, SLOT(addBreakFile(int, qint64, int, QString, QString, qint64)));
	//connect(this, SIGNAL(sendFileSignal()), it.value()->downloadFile, SLOT(receiveSendSignal()));

}
void DownloadManage::checkDownloadOver(int num)
{
	//下载完毕
	QMap<int, int>::iterator it = fileStatusMap->find(num);
	it.value() = 1;

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

//把文件路径和文件名发过来
QString DownloadManage::checkRename(QString mFileName,QString mFilePath)
{
	QString suffix = mFileName.right(mFileName.size() - mFileName.lastIndexOf('.') - 1); //获取文件后缀;
																					  //这里和服务器的不一样
	QString fullName = mFileName.left(mFileName.size() - (mFileName.size() - mFileName.lastIndexOf('.'))); //获取文件名
	
	int i = 0;																											   //查询文件名是否重复
	while (1)
	{
		QFile *existFile = new QFile(mFilePath + mFileName);  //就是判断是否重复
		qDebug() << "exitsFile" << mFilePath + mFileName;
		if (existFile->exists())   //如果文件存在
		{
			i++;
			mFileName = fullName + "(" + QString::number(i, 10) + ")." + suffix;

			qDebug() << "the fileName :" << mFileName;
		}
		else
			break;
	}
	return mFileName;
}

//查询本地的下载记录
void DownloadManage::queryLocalCache()
{
	QString sql = "select * from DownloadRecord;";
	QList<QStringList> record = Database::queryDB(sql, 7);
	//得到本地下载记录
	qDebug() << "cache size:" << record.size();

	for (int i = 0; i < record.size(); i++)
	{
		qDebug() << "cache :"<<record.at(i).at(1);
		qDebug() << "sum: " << record.at(i).at(4).toInt();
		qDebug() << "break: " << record.at(i).at(5).toInt();
		
		QString cFileName = record.at(i).at(1);
		QString cFilePath = record.at(i).at(2);
		QString cFileSize = countFileSize(record.at(i).at(3));

		qint64 cSumBlock = record.at(i).at(4).toInt() ;
		qint64 cbreakPoint = record.at(i).at(5).toInt() ;
		int cfileId = record.at(i).at(6).toInt();
		//插入界面
		//如果已经下载完毕
		if (cSumBlock == cbreakPoint)
		{
			fileStatusMap->insert(index, 1);
		}
		else
		{

			fileStatusMap->insert(index, 2);
		}
		BreakFile breakfile;
		breakfile.recordId = record.at(i).at(0).toInt();
		breakfile.fileId = cfileId;
		breakfile.fileName = cFileName;
		breakfile.filePath = cFilePath;
		breakfile.breakPoint = cbreakPoint;
		breakFileMap->insert(index, breakfile);
		insertDownloadRecord(cFileName, cFilePath, cFileSize, cSumBlock, cbreakPoint);
	}
}
void DownloadManage::slotContextMenu(QPoint pos) {

	QModelIndex current_index = ui->tableView->indexAt(pos);

	qDebug() << current_index;
	if (current_index.isValid())
	{
		//找到选中的文件状态
		QMap<int, int>::iterator it = fileStatusMap->find(current_index.row());
		//如果下载中
		if (it.value() == 0)
		{
			actionBegin->setEnabled(false);
			actionWait->setEnabled(true);
			actionOpenFile->setEnabled(false);
		}
		//下载完毕
		else if (it.value() == 1)
		{
			actionBegin->setEnabled(false);
			actionWait->setEnabled(false);
			actionOpenFile->setEnabled(true);
		}
		else if (it.value() == 2)
		{
			actionBegin->setEnabled(true);
			actionWait->setEnabled(false);
			actionOpenFile->setEnabled(false);
		}
		popMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
	}
}
