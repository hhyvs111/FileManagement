/********************************************************************************
** Form generated from reading UI file 'ReportLook.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTLOOK_H
#define UI_REPORTLOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportLook
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *LookMyReport;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QHBoxLayout *comboboxLayout;
    QComboBox *selectcomboBox;
    QLineEdit *condition;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableView;

    void setupUi(QWidget *ReportLook)
    {
        if (ReportLook->objectName().isEmpty())
            ReportLook->setObjectName(QStringLiteral("ReportLook"));
        ReportLook->resize(626, 471);
        verticalLayout = new QVBoxLayout(ReportLook);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        LookMyReport = new QPushButton(ReportLook);
        LookMyReport->setObjectName(QStringLiteral("LookMyReport"));

        horizontalLayout->addWidget(LookMyReport);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(ReportLook);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboboxLayout = new QHBoxLayout();
        comboboxLayout->setObjectName(QStringLiteral("comboboxLayout"));
        selectcomboBox = new QComboBox(ReportLook);
        selectcomboBox->setObjectName(QStringLiteral("selectcomboBox"));

        comboboxLayout->addWidget(selectcomboBox);


        horizontalLayout->addLayout(comboboxLayout);

        condition = new QLineEdit(ReportLook);
        condition->setObjectName(QStringLiteral("condition"));

        horizontalLayout->addWidget(condition);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(ReportLook);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setMinimumSize(QSize(600, 400));
        tableView->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(tableView);


        retranslateUi(ReportLook);
        QObject::connect(LookMyReport, SIGNAL(clicked()), ReportLook, SLOT(ClickLookMyReportButton()));

        QMetaObject::connectSlotsByName(ReportLook);
    } // setupUi

    void retranslateUi(QWidget *ReportLook)
    {
        ReportLook->setWindowTitle(QApplication::translate("ReportLook", "Form", Q_NULLPTR));
        LookMyReport->setText(QApplication::translate("ReportLook", "\346\237\245\347\234\213\346\210\221\347\232\204\345\221\250\346\212\245", Q_NULLPTR));
        label->setText(QApplication::translate("ReportLook", "\346\214\211\346\235\241\344\273\266\346\237\245\346\211\276\357\274\232", Q_NULLPTR));
        selectcomboBox->clear();
        selectcomboBox->insertItems(0, QStringList()
         << QApplication::translate("ReportLook", "\346\211\200\346\234\211", Q_NULLPTR)
         << QApplication::translate("ReportLook", "\345\247\223\345\220\215", Q_NULLPTR)
         << QApplication::translate("ReportLook", "\345\255\246\346\234\237", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class ReportLook: public Ui_ReportLook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTLOOK_H
