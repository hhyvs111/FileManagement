/********************************************************************************
** Form generated from reading UI file 'UploadFile.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADFILE_H
#define UI_UPLOADFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadFile
{
public:
    QPushButton *openFileButton;
    QPushButton *sendFileButton;
    QProgressBar *sendProgressBar;
    QLabel *sendStatusLabel;
    QLabel *progressLabel;

    void setupUi(QWidget *UploadFile)
    {
        if (UploadFile->objectName().isEmpty())
            UploadFile->setObjectName(QStringLiteral("UploadFile"));
        UploadFile->resize(400, 300);
        openFileButton = new QPushButton(UploadFile);
        openFileButton->setObjectName(QStringLiteral("openFileButton"));
        openFileButton->setGeometry(QRect(80, 90, 75, 23));
        sendFileButton = new QPushButton(UploadFile);
        sendFileButton->setObjectName(QStringLiteral("sendFileButton"));
        sendFileButton->setGeometry(QRect(250, 90, 75, 23));
        sendProgressBar = new QProgressBar(UploadFile);
        sendProgressBar->setObjectName(QStringLiteral("sendProgressBar"));
        sendProgressBar->setGeometry(QRect(120, 170, 191, 23));
        sendProgressBar->setValue(24);
        sendStatusLabel = new QLabel(UploadFile);
        sendStatusLabel->setObjectName(QStringLiteral("sendStatusLabel"));
        sendStatusLabel->setGeometry(QRect(60, 260, 54, 12));
        progressLabel = new QLabel(UploadFile);
        progressLabel->setObjectName(QStringLiteral("progressLabel"));
        progressLabel->setGeometry(QRect(40, 180, 54, 12));

        retranslateUi(UploadFile);
        QObject::connect(openFileButton, SIGNAL(clicked()), UploadFile, SLOT(ClickOpenButton()));
        QObject::connect(sendFileButton, SIGNAL(clicked()), UploadFile, SLOT(ClickSendButton()));

        QMetaObject::connectSlotsByName(UploadFile);
    } // setupUi

    void retranslateUi(QWidget *UploadFile)
    {
        UploadFile->setWindowTitle(QApplication::translate("UploadFile", "Form", Q_NULLPTR));
        openFileButton->setText(QApplication::translate("UploadFile", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        sendFileButton->setText(QApplication::translate("UploadFile", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
        sendStatusLabel->setText(QApplication::translate("UploadFile", "sendStatusLabel", Q_NULLPTR));
        progressLabel->setText(QApplication::translate("UploadFile", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UploadFile: public Ui_UploadFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADFILE_H
