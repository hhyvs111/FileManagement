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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label_2;
    QPushButton *m_LoginButton;
    QLineEdit *nameLine;
    QLineEdit *passwordLine;
    QLabel *label;
    QPushButton *m_RegisterButton;
    QPushButton *close;
    QCheckBox *rem_pw;
    QCheckBox *auto_login;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(389, 250);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 130, 54, 21));
        m_LoginButton = new QPushButton(Login);
        m_LoginButton->setObjectName(QStringLiteral("m_LoginButton"));
        m_LoginButton->setGeometry(QRect(70, 200, 75, 23));
        nameLine = new QLineEdit(Login);
        nameLine->setObjectName(QStringLiteral("nameLine"));
        nameLine->setGeometry(QRect(110, 100, 171, 20));
        passwordLine = new QLineEdit(Login);
        passwordLine->setObjectName(QStringLiteral("passwordLine"));
        passwordLine->setGeometry(QRect(110, 130, 171, 20));
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 100, 54, 21));
        m_RegisterButton = new QPushButton(Login);
        m_RegisterButton->setObjectName(QStringLiteral("m_RegisterButton"));
        m_RegisterButton->setGeometry(QRect(290, 100, 75, 23));
        close = new QPushButton(Login);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(240, 200, 93, 28));
        rem_pw = new QCheckBox(Login);
        rem_pw->setObjectName(QStringLiteral("rem_pw"));
        rem_pw->setGeometry(QRect(120, 170, 83, 18));
        auto_login = new QCheckBox(Login);
        auto_login->setObjectName(QStringLiteral("auto_login"));
        auto_login->setGeometry(QRect(230, 170, 81, 20));

        retranslateUi(Login);
        QObject::connect(m_LoginButton, SIGNAL(clicked()), Login, SLOT(Click_Login()));
        QObject::connect(m_RegisterButton, SIGNAL(clicked()), Login, SLOT(Click_Register()));
        QObject::connect(rem_pw, SIGNAL(clicked()), Login, SLOT(raise()));
        QObject::connect(close, SIGNAL(clicked()), Login, SLOT(close()));
        QObject::connect(auto_login, SIGNAL(clicked()), Login, SLOT(lower()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        m_LoginButton->setText(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "\345\270\220\345\217\267\357\274\232", Q_NULLPTR));
        m_RegisterButton->setText(QApplication::translate("Login", "\346\263\250\345\206\214", Q_NULLPTR));
        close->setText(QApplication::translate("Login", "\345\217\226\346\266\210", Q_NULLPTR));
        rem_pw->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        auto_login->setText(QApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
