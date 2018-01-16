/********************************************************************************
** Form generated from reading UI file 'UserInformation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFORMATION_H
#define UI_USERINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_UserInformation
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QLabel *picLabel;
    QPushButton *alterPassword;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout;
    QLineEdit *QQlineEdit;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *phoneLineEdit;
    QLabel *addressLabel;
    QLineEdit *nameLineEdit;
    QLineEdit *addressLineEdit;
    QLabel *phoneLabel;
    QLabel *nameLabel;
    QLineEdit *IDlineEdit;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *alterButton;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *UserInformation)
    {
        if (UserInformation->objectName().isEmpty())
            UserInformation->setObjectName(QStringLiteral("UserInformation"));
        UserInformation->resize(361, 370);
        verticalLayout = new QVBoxLayout(UserInformation);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_2 = new QLabel(UserInformation);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        picLabel = new QLabel(UserInformation);
        picLabel->setObjectName(QStringLiteral("picLabel"));

        horizontalLayout_3->addWidget(picLabel);

        alterPassword = new QPushButton(UserInformation);
        alterPassword->setObjectName(QStringLiteral("alterPassword"));
        alterPassword->setStyleSheet(QLatin1String("background-color: rgb(130, 130, 130);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(alterPassword);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        QQlineEdit = new QLineEdit(UserInformation);
        QQlineEdit->setObjectName(QStringLiteral("QQlineEdit"));

        gridLayout->addWidget(QQlineEdit, 4, 2, 1, 1);

        label_3 = new QLabel(UserInformation);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        label = new QLabel(UserInformation);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 4, 1, 1, 1);

        phoneLineEdit = new QLineEdit(UserInformation);
        phoneLineEdit->setObjectName(QStringLiteral("phoneLineEdit"));

        gridLayout->addWidget(phoneLineEdit, 3, 2, 1, 1);

        addressLabel = new QLabel(UserInformation);
        addressLabel->setObjectName(QStringLiteral("addressLabel"));
        addressLabel->setFont(font);
        addressLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(addressLabel, 5, 1, 1, 1);

        nameLineEdit = new QLineEdit(UserInformation);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 1, 2, 1, 1);

        addressLineEdit = new QLineEdit(UserInformation);
        addressLineEdit->setObjectName(QStringLiteral("addressLineEdit"));

        gridLayout->addWidget(addressLineEdit, 5, 2, 1, 1);

        phoneLabel = new QLabel(UserInformation);
        phoneLabel->setObjectName(QStringLiteral("phoneLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        phoneLabel->setFont(font1);
        phoneLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(phoneLabel, 3, 1, 1, 1);

        nameLabel = new QLabel(UserInformation);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setFont(font);
        nameLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nameLabel, 1, 1, 1, 1);

        IDlineEdit = new QLineEdit(UserInformation);
        IDlineEdit->setObjectName(QStringLiteral("IDlineEdit"));

        gridLayout->addWidget(IDlineEdit, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        alterButton = new QPushButton(UserInformation);
        alterButton->setObjectName(QStringLiteral("alterButton"));
        alterButton->setStyleSheet(QLatin1String("background-color: rgb(85, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_4->addWidget(alterButton);

        confirmButton = new QPushButton(UserInformation);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setStyleSheet(QLatin1String("background-color: rgb(85, 170, 255);\n"
"color: rgb(27, 27, 27);"));

        horizontalLayout_4->addWidget(confirmButton);

        cancelButton = new QPushButton(UserInformation);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setStyleSheet(QLatin1String("background-color: rgb(85, 170, 255);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(cancelButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        QWidget::setTabOrder(nameLineEdit, IDlineEdit);
        QWidget::setTabOrder(IDlineEdit, phoneLineEdit);
        QWidget::setTabOrder(phoneLineEdit, QQlineEdit);
        QWidget::setTabOrder(QQlineEdit, addressLineEdit);
        QWidget::setTabOrder(addressLineEdit, confirmButton);
        QWidget::setTabOrder(confirmButton, alterButton);
        QWidget::setTabOrder(alterButton, alterPassword);
        QWidget::setTabOrder(alterPassword, cancelButton);

        retranslateUi(UserInformation);

        QMetaObject::connectSlotsByName(UserInformation);
    } // setupUi

    void retranslateUi(QWidget *UserInformation)
    {
        UserInformation->setWindowTitle(QApplication::translate("UserInformation", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("UserInformation", "\344\270\252\344\272\272\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        picLabel->setText(QApplication::translate("UserInformation", "TextLabel", Q_NULLPTR));
        alterPassword->setText(QApplication::translate("UserInformation", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("UserInformation", "\345\255\246\345\217\267\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("UserInformation", "QQ\357\274\232", Q_NULLPTR));
        addressLabel->setText(QApplication::translate("UserInformation", "\351\202\256\347\256\261\357\274\232", Q_NULLPTR));
        phoneLabel->setText(QApplication::translate("UserInformation", "\346\211\213\346\234\272\345\217\267\357\274\232", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("UserInformation", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        alterButton->setText(QApplication::translate("UserInformation", "\344\277\256\346\224\271\344\277\241\346\201\257", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("UserInformation", "\344\277\235\345\255\230\344\277\241\346\201\257", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("UserInformation", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserInformation: public Ui_UserInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFORMATION_H
