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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileManagementClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FileManagementClass)
    {
        if (FileManagementClass->objectName().isEmpty())
            FileManagementClass->setObjectName(QStringLiteral("FileManagementClass"));
        FileManagementClass->resize(391, 238);
        centralWidget = new QWidget(FileManagementClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 30, 54, 21));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 60, 171, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 60, 54, 21));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 30, 171, 20));
        buttonBox = new QDialogButtonBox(centralWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-70, 100, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        FileManagementClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FileManagementClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 391, 23));
        FileManagementClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FileManagementClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FileManagementClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FileManagementClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FileManagementClass->setStatusBar(statusBar);

        retranslateUi(FileManagementClass);

        QMetaObject::connectSlotsByName(FileManagementClass);
    } // setupUi

    void retranslateUi(QMainWindow *FileManagementClass)
    {
        FileManagementClass->setWindowTitle(QApplication::translate("FileManagementClass", "FileManagement", Q_NULLPTR));
        label->setText(QApplication::translate("FileManagementClass", "\345\270\220\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("FileManagementClass", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileManagementClass: public Ui_FileManagementClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGEMENT_H
