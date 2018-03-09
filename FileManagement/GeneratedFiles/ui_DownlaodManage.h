/********************************************************************************
** Form generated from reading UI file 'DownlaodManage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLAODMANAGE_H
#define UI_DOWNLAODMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloadManage
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QWidget *DownloadManage)
    {
        if (DownloadManage->objectName().isEmpty())
            DownloadManage->setObjectName(QStringLiteral("DownloadManage"));
        DownloadManage->resize(400, 300);
        verticalLayout = new QVBoxLayout(DownloadManage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView = new QTableView(DownloadManage);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(DownloadManage);

        QMetaObject::connectSlotsByName(DownloadManage);
    } // setupUi

    void retranslateUi(QWidget *DownloadManage)
    {
        DownloadManage->setWindowTitle(QApplication::translate("DownloadManage", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DownloadManage: public Ui_DownloadManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLAODMANAGE_H
