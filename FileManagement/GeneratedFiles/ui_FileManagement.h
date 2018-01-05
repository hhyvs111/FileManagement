/********************************************************************************
** Form generated from reading UI file 'FileManagement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEMANAGEMENT_H
#define UI_FILEMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileManagement
{
public:
    QWidget *centralWidget;
    QCalendarWidget *calendarWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FileManagement)
    {
        if (FileManagement->objectName().isEmpty())
            FileManagement->setObjectName(QStringLiteral("FileManagement"));
        FileManagement->resize(605, 272);
        centralWidget = new QWidget(FileManagement);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(160, 20, 248, 197));
        FileManagement->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(FileManagement);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FileManagement->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FileManagement);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FileManagement->setStatusBar(statusBar);

        retranslateUi(FileManagement);

        QMetaObject::connectSlotsByName(FileManagement);
    } // setupUi

    void retranslateUi(QMainWindow *FileManagement)
    {
        FileManagement->setWindowTitle(QApplication::translate("FileManagement", "FileManagement", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileManagement: public Ui_FileManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGEMENT_H
