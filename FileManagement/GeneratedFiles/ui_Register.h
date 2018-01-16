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
    QLabel *userMessage;
    QLabel *passwordMessage;
    QLabel *passwordMessage2;
    QRadioButton *radioButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *userLabel;
    QLineEdit *userName;
    QLabel *userLogo;
    QSpacerItem *horizontalSpacer_10;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *passLabel;
    QLineEdit *userPassword;
    QLabel *passLogo;
    QSpacerItem *horizontalSpacer_8;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *confirmLabel;
    QLineEdit *userPassword2;
    QLabel *passLogo2;
    QSpacerItem *horizontalSpacer_6;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *clickRegister;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *clickCancel;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(376, 377);
        Register->setAutoFillBackground(false);
        userMessage = new QLabel(Register);
        userMessage->setObjectName(QStringLiteral("userMessage"));
        userMessage->setGeometry(QRect(30, 112, 251, 16));
        passwordMessage = new QLabel(Register);
        passwordMessage->setObjectName(QStringLiteral("passwordMessage"));
        passwordMessage->setGeometry(QRect(30, 168, 271, 16));
        passwordMessage2 = new QLabel(Register);
        passwordMessage2->setObjectName(QStringLiteral("passwordMessage2"));
        passwordMessage2->setGeometry(QRect(30, 224, 271, 16));
        radioButton = new QRadioButton(Register);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 274, 131, 16));
        layoutWidget = new QWidget(Register);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 44, 88, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        layoutWidget1 = new QWidget(Register);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 74, 324, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        userLabel = new QLabel(layoutWidget1);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setMinimumSize(QSize(30, 30));
        userLabel->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(userLabel);

        userName = new QLineEdit(layoutWidget1);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setMinimumSize(QSize(180, 20));
        userName->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(userName);

        userLogo = new QLabel(layoutWidget1);
        userLogo->setObjectName(QStringLiteral("userLogo"));

        horizontalLayout_2->addWidget(userLogo);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        layoutWidget2 = new QWidget(Register);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 130, 324, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        passLabel = new QLabel(layoutWidget2);
        passLabel->setObjectName(QStringLiteral("passLabel"));
        passLabel->setMinimumSize(QSize(30, 30));
        passLabel->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_3->addWidget(passLabel);

        userPassword = new QLineEdit(layoutWidget2);
        userPassword->setObjectName(QStringLiteral("userPassword"));
        userPassword->setMinimumSize(QSize(180, 20));
        userPassword->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(userPassword);

        passLogo = new QLabel(layoutWidget2);
        passLogo->setObjectName(QStringLiteral("passLogo"));

        horizontalLayout_3->addWidget(passLogo);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        layoutWidget3 = new QWidget(Register);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 186, 324, 32));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        confirmLabel = new QLabel(layoutWidget3);
        confirmLabel->setObjectName(QStringLiteral("confirmLabel"));
        confirmLabel->setMinimumSize(QSize(30, 30));
        confirmLabel->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_4->addWidget(confirmLabel);

        userPassword2 = new QLineEdit(layoutWidget3);
        userPassword2->setObjectName(QStringLiteral("userPassword2"));
        userPassword2->setMinimumSize(QSize(180, 20));
        userPassword2->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(userPassword2);

        passLogo2 = new QLabel(layoutWidget3);
        passLogo2->setObjectName(QStringLiteral("passLogo2"));

        horizontalLayout_4->addWidget(passLogo2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        layoutWidget4 = new QWidget(Register);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 296, 296, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        clickRegister = new QPushButton(layoutWidget4);
        clickRegister->setObjectName(QStringLiteral("clickRegister"));
        clickRegister->setMaximumSize(QSize(1000, 30));
        clickRegister->setStyleSheet(QLatin1String("background-color: rgb(85, 170, 255);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(clickRegister);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        clickCancel = new QPushButton(layoutWidget4);
        clickCancel->setObjectName(QStringLiteral("clickCancel"));
        clickCancel->setMaximumSize(QSize(16777215, 30));
        clickCancel->setStyleSheet(QLatin1String("background-color: rgb(188, 188, 255);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(clickCancel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

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
        userMessage->setText(QApplication::translate("Register", "TextLabel", Q_NULLPTR));
        passwordMessage->setText(QApplication::translate("Register", "TextLabel", Q_NULLPTR));
        passwordMessage2->setText(QApplication::translate("Register", "TextLabel", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Register", "\345\220\214\346\204\217\345\256\236\351\252\214\345\256\244\347\256\241\347\220\206\350\246\201\346\261\202", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\263\250\345\206\214</span></p></body></html>", Q_NULLPTR));
        userLabel->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        userLogo->setText(QApplication::translate("Register", "TextLabel", Q_NULLPTR));
        passLabel->setText(QApplication::translate("Register", "\345\257\206\347\240\201", Q_NULLPTR));
        passLogo->setText(QApplication::translate("Register", "TextLabel", Q_NULLPTR));
        confirmLabel->setText(QApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        passLogo2->setText(QApplication::translate("Register", "TextLabel", Q_NULLPTR));
        clickRegister->setText(QApplication::translate("Register", "\346\263\250\345\206\214", Q_NULLPTR));
        clickCancel->setText(QApplication::translate("Register", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
