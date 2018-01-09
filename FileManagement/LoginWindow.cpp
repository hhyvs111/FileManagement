//#include "LoginWindow.h"
//#include "ui_LoginWindow.h"
//#include "accountitem.h"
//#include <QPainter>
//#include <QMovie>
//#include <QHBoxLayout>
//#include <QCursor>
//
//LoginWindow::LoginWindow(QWidget *parent)
//	: BaseWindow(parent)
//	, ui(new Ui::LoginWindow)
//{
//	ui->setupUi(this);
//	initWindow();
//	initMyTitle();
//	this->loadStyleSheet(":/Resources/LoginWindow/LoginWindow.css");
//}
//
//LoginWindow::~LoginWindow()
//{
//	delete ui;
//}
//
//void LoginWindow::initMyTitle()
//{
//	// 因为这里有控件层叠了，所以要注意控件raise()方法的调用顺序;
//	m_titleBar->move(0, 0);
//	m_titleBar->raise();
//	m_titleBar->setBackgroundColor(0, 0, 0, true);
//	m_titleBar->setButtonType(MIN_BUTTON);
//	m_titleBar->setTitleWidth(this->width());
//
//	ui->pButtonArrow->raise();
//}
//
//void LoginWindow::initWindow()
//{
//	//背景GIG图;
//	QLabel* pBack = new QLabel(this);
//	QMovie *movie = new QMovie();
//	movie->setFileName(":/Resources/LoginWindow/back.gif");
//	pBack->setMovie(movie);
//	movie->start();
//	pBack->move(0, 0);
//
//	//暗注释;
//	ui->accountComboBox->setEditable(true);
//	QLineEdit* lineEdit = ui->accountComboBox->lineEdit();
//	lineEdit->setPlaceholderText(QStringLiteral("QQ号码/手机/邮箱"));
//
//	ui->passwordEdit->setPlaceholderText(QStringLiteral("密码"));
//
//	// 密码框中的小键盘按钮;
//	m_keyboardButton = new QPushButton();
//	m_keyboardButton->setObjectName("pButtonKeyboard");
//	m_keyboardButton->setFixedSize(QSize(16, 16));
//	m_keyboardButton->setCursor(QCursor(Qt::PointingHandCursor));
//
//	QHBoxLayout* passwordEditLayout = new QHBoxLayout();
//	passwordEditLayout->addStretch();
//	passwordEditLayout->addWidget(m_keyboardButton);
//	passwordEditLayout->setSpacing(0);
//	passwordEditLayout->setContentsMargins(0, 0, 8, 0);
//
//	ui->passwordEdit->setLayout(passwordEditLayout);
//	ui->passwordEdit->setTextMargins(0, 0, m_keyboardButton->width() + 12, 0);
//
//	ui->userHead->setPixmap(QPixmap(":/Resources/LoginWindow/HeadImage.png"));
//	ui->loginState->setIcon(QIcon(":/Resources/LoginWindow/LoginState/state_online.png"));
//	ui->loginState->setIconSize(QSize(13, 13));
//}