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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *SignUp;
    QSpacerItem *horizontalSpacer;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *userName;
    QLabel *userLogo;
    QLabel *userMessage;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *userPassword;
    QLabel *passLogo;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *userPassword2;
    QLabel *passLogo2;
    QLabel *passwordMessage;
    QLabel *passwordMessage2;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *clickRegister;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *clickCancel;
    QRadioButton *radioButton;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(336, 369);
        horizontalLayoutWidget = new QWidget(Register);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 50, 201, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        SignUp = new QLabel(horizontalLayoutWidget);
        SignUp->setObjectName(QStringLiteral("SignUp"));

        horizontalLayout->addWidget(SignUp);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayoutWidget_2 = new QWidget(Register);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(60, 110, 231, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        userName = new QLineEdit(horizontalLayoutWidget_2);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(userName);

        userLogo = new QLabel(horizontalLayoutWidget_2);
        userLogo->setObjectName(QStringLiteral("userLogo"));

        horizontalLayout_2->addWidget(userLogo);

        userMessage = new QLabel(Register);
        userMessage->setObjectName(QStringLiteral("userMessage"));
        userMessage->setGeometry(QRect(60, 150, 231, 21));
        horizontalLayoutWidget_3 = new QWidget(Register);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(60, 170, 231, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        userPassword = new QLineEdit(horizontalLayoutWidget_3);
        userPassword->setObjectName(QStringLiteral("userPassword"));
        userPassword->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(userPassword);

        passLogo = new QLabel(horizontalLayoutWidget_3);
        passLogo->setObjectName(QStringLiteral("passLogo"));

        horizontalLayout_3->addWidget(passLogo);

        horizontalLayoutWidget_4 = new QWidget(Register);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(60, 230, 231, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        userPassword2 = new QLineEdit(horizontalLayoutWidget_4);
        userPassword2->setObjectName(QStringLiteral("userPassword2"));
        userPassword2->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(userPassword2);

        passLogo2 = new QLabel(horizontalLayoutWidget_4);
        passLogo2->setObjectName(QStringLiteral("passLogo2"));

        horizontalLayout_4->addWidget(passLogo2);

        passwordMessage = new QLabel(Register);
        passwordMessage->setObjectName(QStringLiteral("passwordMessage"));
        passwordMessage->setGeometry(QRect(60, 210, 231, 21));
        passwordMessage2 = new QLabel(Register);
        passwordMessage2->setObjectName(QStringLiteral("passwordMessage2"));
        passwordMessage2->setGeometry(QRect(60, 270, 231, 21));
        horizontalLayoutWidget_5 = new QWidget(Register);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(70, 310, 201, 41));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        clickRegister = new QPushButton(horizontalLayoutWidget_5);
        clickRegister->setObjectName(QStringLiteral("clickRegister"));
        clickRegister->setMaximumSize(QSize(1000, 30));

        horizontalLayout_5->addWidget(clickRegister);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        clickCancel = new QPushButton(horizontalLayoutWidget_5);
        clickCancel->setObjectName(QStringLiteral("clickCancel"));
        clickCancel->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_5->addWidget(clickCancel);

        radioButton = new QRadioButton(Register);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(70, 290, 211, 16));
        QWidget::setTabOrder(userName, userPassword);
        QWidget::setTabOrder(userPassword, userPassword2);
        QWidget::setTabOrder(userPassword2, radioButton);
        QWidget::setTabOrder(radioButton, clickRegister);
        QWidget::setTabOrder(clickRegister, clickCancel);

        retranslateUi(Register);
        QObject::connect(clickRegister, SIGNAL(clicked()), Register, SLOT(Click_Register()));
        QObject::connect(clickCancel, SIGNAL(clicked()), Register, SLOT(Click_Cancel()));

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", Q_NULLPTR));
        SignUp->setText(QApplication::translate("Register", "\346\263\250\345\206\214", Q_NULLPTR));
        userLogo->setText(QApplication::translate("Register", "TextLabel", Q_NULLPTR));
        userMessage->setText(QApplication::translate("Register", "TextLabel", Q_NULLPTR));
        passLogo->setText(QApplication::translate("Register", "TextLabel", Q_NULLPTR));
        passLogo2->setText(QApplication::translate("Register", "TextLabel", Q_NULLPTR));
        passwordMessage->setText(QApplication::translate("Register", "TextLabel", Q_NULLPTR));
        passwordMessage2->setText(QApplication::translate("Register", "TextLabel", Q_NULLPTR));
        clickRegister->setText(QApplication::translate("Register", "\346\263\250\345\206\214", Q_NULLPTR));
        clickCancel->setText(QApplication::translate("Register", "\345\217\226\346\266\210", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Register", "\345\220\214\346\204\217\345\256\236\351\252\214\345\256\244\347\256\241\347\220\206\350\246\201\346\261\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
