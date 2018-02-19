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
#include <QtWidgets/QGridLayout>
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
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *rem_pw;
    QSpacerItem *horizontalSpacer_10;
    QCheckBox *auto_login;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *m_RegisterButton;
    QLineEdit *passwordLine;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *nameLine;
    QPushButton *m_LoginButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(482, 379);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(200, 200));

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        rem_pw = new QCheckBox(Login);
        rem_pw->setObjectName(QStringLiteral("rem_pw"));
        rem_pw->setMinimumSize(QSize(30, 0));
        rem_pw->setMaximumSize(QSize(126, 20));

        horizontalLayout_5->addWidget(rem_pw);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        auto_login = new QCheckBox(Login);
        auto_login->setObjectName(QStringLiteral("auto_login"));
        auto_login->setMinimumSize(QSize(50, 0));
        auto_login->setMaximumSize(QSize(94, 16777215));

        horizontalLayout_5->addWidget(auto_login);


        gridLayout->addLayout(horizontalLayout_5, 2, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(30, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(30, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 4, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 4, 1, 1);

        m_RegisterButton = new QPushButton(Login);
        m_RegisterButton->setObjectName(QStringLiteral("m_RegisterButton"));
        m_RegisterButton->setMinimumSize(QSize(59, 0));
        m_RegisterButton->setMaximumSize(QSize(80, 20));
        m_RegisterButton->setStyleSheet(QStringLiteral("QPushButton { border-radius: 3px; color: rgb(85, 85, 255); }"));

        gridLayout->addWidget(m_RegisterButton, 0, 3, 1, 1);

        passwordLine = new QLineEdit(Login);
        passwordLine->setObjectName(QStringLiteral("passwordLine"));
        sizePolicy.setHeightForWidth(passwordLine->sizePolicy().hasHeightForWidth());
        passwordLine->setSizePolicy(sizePolicy);
        passwordLine->setMinimumSize(QSize(180, 20));
        passwordLine->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(passwordLine, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(Login);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(59, 0));
        pushButton_2->setMaximumSize(QSize(80, 20));
        pushButton_2->setStyleSheet(QStringLiteral("QPushButton { border-radius: 3px; color: rgb(85, 85, 255); }"));

        gridLayout->addWidget(pushButton_2, 1, 3, 1, 1);

        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMaximumSize(QSize(200, 20));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(Login);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        nameLine = new QLineEdit(Login);
        nameLine->setObjectName(QStringLiteral("nameLine"));
        sizePolicy.setHeightForWidth(nameLine->sizePolicy().hasHeightForWidth());
        nameLine->setSizePolicy(sizePolicy);
        nameLine->setMinimumSize(QSize(180, 20));
        nameLine->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(nameLine, 0, 2, 1, 1);

        m_LoginButton = new QPushButton(Login);
        m_LoginButton->setObjectName(QStringLiteral("m_LoginButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_LoginButton->sizePolicy().hasHeightForWidth());
        m_LoginButton->setSizePolicy(sizePolicy2);
        m_LoginButton->setMinimumSize(QSize(180, 30));
        m_LoginButton->setMaximumSize(QSize(16777215, 16777215));
        m_LoginButton->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(m_LoginButton, 3, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 4, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


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
        rem_pw->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        auto_login->setText(QApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\345\275\225", Q_NULLPTR));
        m_RegisterButton->setText(QApplication::translate("Login", "\347\253\213\345\215\263\346\263\250\345\206\214", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Login", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Login", "\345\257\206  \347\240\201\357\274\232", Q_NULLPTR));
        m_LoginButton->setText(QApplication::translate("Login", "\347\231\273 \345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
