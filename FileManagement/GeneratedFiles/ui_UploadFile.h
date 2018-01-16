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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadFile
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *selectBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *sendStatusLabel;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *progressLabel;
    QProgressBar *sendProgressBar;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_9;
    QLabel *uploadSpeedLabel;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QWidget *UploadFile)
    {
        if (UploadFile->objectName().isEmpty())
            UploadFile->setObjectName(QStringLiteral("UploadFile"));
        UploadFile->resize(529, 421);
        UploadFile->setMinimumSize(QSize(100, 100));
        verticalLayout = new QVBoxLayout(UploadFile);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        selectBtn = new QPushButton(UploadFile);
        selectBtn->setObjectName(QStringLiteral("selectBtn"));

        horizontalLayout->addWidget(selectBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sendBtn = new QPushButton(UploadFile);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));

        horizontalLayout->addWidget(sendBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cancelBtn = new QPushButton(UploadFile);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        sendStatusLabel = new QLabel(UploadFile);
        sendStatusLabel->setObjectName(QStringLiteral("sendStatusLabel"));

        horizontalLayout_3->addWidget(sendStatusLabel);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        progressLabel = new QLabel(UploadFile);
        progressLabel->setObjectName(QStringLiteral("progressLabel"));

        horizontalLayout_2->addWidget(progressLabel);

        sendProgressBar = new QProgressBar(UploadFile);
        sendProgressBar->setObjectName(QStringLiteral("sendProgressBar"));
        sendProgressBar->setValue(0);

        horizontalLayout_2->addWidget(sendProgressBar);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        uploadSpeedLabel = new QLabel(UploadFile);
        uploadSpeedLabel->setObjectName(QStringLiteral("uploadSpeedLabel"));

        horizontalLayout_4->addWidget(uploadSpeedLabel);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(UploadFile);
        QObject::connect(selectBtn, SIGNAL(clicked()), UploadFile, SLOT(ClickOpenButton()));
        QObject::connect(sendBtn, SIGNAL(clicked()), UploadFile, SLOT(ClickSendButton()));

        QMetaObject::connectSlotsByName(UploadFile);
    } // setupUi

    void retranslateUi(QWidget *UploadFile)
    {
        UploadFile->setWindowTitle(QApplication::translate("UploadFile", "Form", Q_NULLPTR));
        selectBtn->setText(QApplication::translate("UploadFile", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("UploadFile", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
        cancelBtn->setText(QApplication::translate("UploadFile", "\345\217\226\346\266\210\345\217\221\351\200\201", Q_NULLPTR));
        sendStatusLabel->setText(QApplication::translate("UploadFile", "sendStatusLabel", Q_NULLPTR));
        progressLabel->setText(QApplication::translate("UploadFile", "TextLabel", Q_NULLPTR));
        uploadSpeedLabel->setText(QApplication::translate("UploadFile", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UploadFile: public Ui_UploadFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADFILE_H
