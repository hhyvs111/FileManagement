/********************************************************************************
** Form generated from reading UI file 'MoneyManage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONEYMANAGE_H
#define UI_MONEYMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MoneyManage
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *ShowLastLabel;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer;
    QPushButton *RecordButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MoneyManage)
    {
        if (MoneyManage->objectName().isEmpty())
            MoneyManage->setObjectName(QStringLiteral("MoneyManage"));
        MoneyManage->resize(727, 536);
        verticalLayout_2 = new QVBoxLayout(MoneyManage);
        verticalLayout_2->setSpacing(9);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ShowLastLabel = new QLabel(MoneyManage);
        ShowLastLabel->setObjectName(QStringLiteral("ShowLastLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ShowLastLabel->sizePolicy().hasHeightForWidth());
        ShowLastLabel->setSizePolicy(sizePolicy);
        ShowLastLabel->setMinimumSize(QSize(0, 30));
        ShowLastLabel->setMaximumSize(QSize(16777215, 30));
        ShowLastLabel->setStyleSheet(QLatin1String("border-color: rgb(0, 85, 255);\n"
"background-image: url(:/Resource/moneyBackground.jpg);\n"
"font: 14pt \"04b_21\";\n"
"color: rgb(255, 255, 255);\n"
""));
        ShowLastLabel->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(ShowLastLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        tableView = new QTableView(MoneyManage);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        tableView->setMinimumSize(QSize(500, 100));
        tableView->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(tableView);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        RecordButton = new QPushButton(MoneyManage);
        RecordButton->setObjectName(QStringLiteral("RecordButton"));
        RecordButton->setStyleSheet(QLatin1String("background:transparent;\n"
"border:1px solid rgb(89, 153, 48);\n"
"border-radius:10px;\n"
"padding:10px 12px;\n"
"color: green;"));
        RecordButton->setFlat(false);

        horizontalLayout->addWidget(RecordButton);

        pushButton_2 = new QPushButton(MoneyManage);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border:1px solid rgb(87, 118, 255);\n"
"border-radius:10px;\n"
"padding:10px 12px;\n"
"color: green;"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MoneyManage);
        QObject::connect(RecordButton, SIGNAL(clicked()), MoneyManage, SLOT(clickAccountingButton()));

        QMetaObject::connectSlotsByName(MoneyManage);
    } // setupUi

    void retranslateUi(QWidget *MoneyManage)
    {
        MoneyManage->setWindowTitle(QApplication::translate("MoneyManage", "Form", Q_NULLPTR));
        ShowLastLabel->setText(QApplication::translate("MoneyManage", "\346\234\200\350\277\221\346\224\266\346\224\257\346\203\205\345\206\265", Q_NULLPTR));
        RecordButton->setText(QApplication::translate("MoneyManage", "\350\256\260\350\264\246", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MoneyManage", "\346\237\245\347\234\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MoneyManage: public Ui_MoneyManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONEYMANAGE_H
