/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QLineEdit *nameLine;
    QPushButton *m_RegisterButton;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QLineEdit *passwordLine;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *rem_pw;
    QSpacerItem *horizontalSpacer_9;
    QCheckBox *auto_login;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_LoginButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(520, 419);
        verticalLayoutWidget = new QWidget(Login);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 420, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(200, 150));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_6 = new QSpacerItem(30, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMaximumSize(QSize(200, 20));

        horizontalLayout->addWidget(label_2);

        nameLine = new QLineEdit(verticalLayoutWidget);
        nameLine->setObjectName(QStringLiteral("nameLine"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(nameLine->sizePolicy().hasHeightForWidth());
        nameLine->setSizePolicy(sizePolicy2);
        nameLine->setMinimumSize(QSize(180, 20));
        nameLine->setMaximumSize(QSize(500, 25));

        horizontalLayout->addWidget(nameLine);

        m_RegisterButton = new QPushButton(verticalLayoutWidget);
        m_RegisterButton->setObjectName(QStringLiteral("m_RegisterButton"));
        m_RegisterButton->setMinimumSize(QSize(59, 0));
        m_RegisterButton->setMaximumSize(QSize(80, 20));
        m_RegisterButton->setStyleSheet(QStringLiteral("QPushButton { border-radius: 3px; color: rgb(85, 85, 255); }"));

        horizontalLayout->addWidget(m_RegisterButton);

        horizontalSpacer_7 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(30, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        passwordLine = new QLineEdit(verticalLayoutWidget);
        passwordLine->setObjectName(QStringLiteral("passwordLine"));
        sizePolicy2.setHeightForWidth(passwordLine->sizePolicy().hasHeightForWidth());
        passwordLine->setSizePolicy(sizePolicy2);
        passwordLine->setMinimumSize(QSize(180, 20));
        passwordLine->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(passwordLine);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(59, 0));
        pushButton_2->setMaximumSize(QSize(80, 20));
        pushButton_2->setStyleSheet(QStringLiteral("QPushButton { border-radius: 3px; color: rgb(85, 85, 255); }"));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer_5 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(110, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        rem_pw = new QCheckBox(verticalLayoutWidget);
        rem_pw->setObjectName(QStringLiteral("rem_pw"));
        rem_pw->setMinimumSize(QSize(30, 0));
        rem_pw->setMaximumSize(QSize(126, 20));

        horizontalLayout_3->addWidget(rem_pw);

        horizontalSpacer_9 = new QSpacerItem(30, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        auto_login = new QCheckBox(verticalLayoutWidget);
        auto_login->setObjectName(QStringLiteral("auto_login"));
        auto_login->setMinimumSize(QSize(50, 0));
        auto_login->setMaximumSize(QSize(94, 16777215));

        horizontalLayout_3->addWidget(auto_login);

        horizontalSpacer_8 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(115, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        m_LoginButton = new QPushButton(verticalLayoutWidget);
        m_LoginButton->setObjectName(QStringLiteral("m_LoginButton"));
        sizePolicy2.setHeightForWidth(m_LoginButton->sizePolicy().hasHeightForWidth());
        m_LoginButton->setSizePolicy(sizePolicy2);
        m_LoginButton->setMinimumSize(QSize(180, 30));
        m_LoginButton->setMaximumSize(QSize(50, 20));
        m_LoginButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:rgb(85,170,255);\n"
"border-radius: 3px; color: rgb(255, 255, 255); \n"
"}"));

        horizontalLayout_4->addWidget(m_LoginButton);

        horizontalSpacer_2 = new QSpacerItem(75, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        QWidget::setTabOrder(nameLine, passwordLine);
        QWidget::setTabOrder(passwordLine, m_LoginButton);
        QWidget::setTabOrder(m_LoginButton, rem_pw);
        QWidget::setTabOrder(rem_pw, auto_login);
        QWidget::setTabOrder(auto_login, m_RegisterButton);
        QWidget::setTabOrder(m_RegisterButton, pushButton_2);

        retranslateUi(Login);
        QObject::connect(m_LoginButton, SIGNAL(clicked()), Login, SLOT(Click_Login()));
        QObject::connect(m_RegisterButton, SIGNAL(clicked()), Login, SLOT(Click_Register()));
        QObject::connect(rem_pw, SIGNAL(clicked()), Login, SLOT(raise()));
        QObject::connect(auto_login, SIGNAL(clicked()), Login, SLOT(lower()));
        QObject::connect(nameLine, SIGNAL(textChanged(QString)), Login, SLOT(hide1()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        m_RegisterButton->setText(QApplication::translate("Login", "\347\253\213\345\215\263\346\263\250\345\206\214", Q_NULLPTR));
        label_3->setText(QApplication::translate("Login", "\345\257\206  \347\240\201\357\274\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Login", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
        rem_pw->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        auto_login->setText(QApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\345\275\225", Q_NULLPTR));
        m_LoginButton->setText(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
