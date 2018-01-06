/********************************************************************************
** Form generated from reading UI file 'Register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *pushButton;
    QLineEdit *userName;
    QLineEdit *userPassword;
    QLineEdit *userPassword2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(375, 279);
        pushButton = new QPushButton(Register);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 70, 75, 23));
        userName = new QLineEdit(Register);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setGeometry(QRect(130, 70, 113, 20));
        userPassword = new QLineEdit(Register);
        userPassword->setObjectName(QStringLiteral("userPassword"));
        userPassword->setGeometry(QRect(130, 110, 113, 20));
        userPassword2 = new QLineEdit(Register);
        userPassword2->setObjectName(QStringLiteral("userPassword2"));
        userPassword2->setGeometry(QRect(130, 160, 113, 20));
        pushButton_2 = new QPushButton(Register);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 210, 75, 23));
        pushButton_3 = new QPushButton(Register);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 210, 75, 23));
        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 72, 54, 20));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 112, 54, 20));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 160, 54, 21));

        retranslateUi(Register);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Register, SLOT(Click_Register()));
        QObject::connect(pushButton, SIGNAL(clicked()), Register, SLOT(Click_CheckUser()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), Register, SLOT(Click_Reset()));

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Register", "\346\243\200\346\237\245\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Register", "\346\263\250\345\206\214", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Register", "\351\207\215\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Register", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
