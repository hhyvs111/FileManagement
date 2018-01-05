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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FileManagementClass)
    {
        if (FileManagementClass->objectName().isEmpty())
            FileManagementClass->setObjectName(QStringLiteral("FileManagementClass"));
        FileManagementClass->resize(490, 272);
        centralWidget = new QWidget(FileManagementClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 80, 54, 21));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 110, 171, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 110, 54, 21));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 80, 171, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 150, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 80, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(260, 150, 75, 23));
        FileManagementClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(FileManagementClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FileManagementClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FileManagementClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FileManagementClass->setStatusBar(statusBar);

        retranslateUi(FileManagementClass);
        QObject::connect(pushButton, SIGNAL(clicked()), FileManagementClass, SLOT(Btn_Click()));

        QMetaObject::connectSlotsByName(FileManagementClass);
    } // setupUi

    void retranslateUi(QMainWindow *FileManagementClass)
    {
        FileManagementClass->setWindowTitle(QApplication::translate("FileManagementClass", "FileManagement", Q_NULLPTR));
        label->setText(QApplication::translate("FileManagementClass", "\345\270\220\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("FileManagementClass", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FileManagementClass", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("FileManagementClass", "\346\263\250\345\206\214", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("FileManagementClass", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileManagementClass: public Ui_FileManagementClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGEMENT_H
