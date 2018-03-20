/********************************************************************************
** Form generated from reading UI file 'Echarts.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECHARTS_H
#define UI_ECHARTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Echarts
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *send;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *importexcel;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Echarts)
    {
        if (Echarts->objectName().isEmpty())
            Echarts->setObjectName(QStringLiteral("Echarts"));
        Echarts->resize(599, 465);
        verticalLayout_2 = new QVBoxLayout(Echarts);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        send = new QPushButton(Echarts);
        send->setObjectName(QStringLiteral("send"));

        horizontalLayout_3->addWidget(send);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        lineEdit = new QLineEdit(Echarts);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        pushButton = new QPushButton(Echarts);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        importexcel = new QPushButton(Echarts);
        importexcel->setObjectName(QStringLiteral("importexcel"));

        horizontalLayout_3->addWidget(importexcel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(Echarts);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Echarts);

        QMetaObject::connectSlotsByName(Echarts);
    } // setupUi

    void retranslateUi(QWidget *Echarts)
    {
        Echarts->setWindowTitle(QApplication::translate("Echarts", "Form", Q_NULLPTR));
        send->setText(QApplication::translate("Echarts", "\346\230\276\347\244\272\345\233\276\350\241\250", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Echarts", "\351\200\211\346\213\251excel\346\226\207\344\273\266", Q_NULLPTR));
        importexcel->setText(QApplication::translate("Echarts", "\345\257\274\345\205\245excel", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Echarts", "\345\257\274\345\207\272excel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Echarts: public Ui_Echarts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECHARTS_H
