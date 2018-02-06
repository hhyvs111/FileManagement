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
    QLabel *Drag;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_3;
    QLabel *mFileIcon;
    QLabel *mFileName;
    QHBoxLayout *horizontalLayout_2;
    QProgressBar *sendProgressBar;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_9;
    QLabel *uploadSpeedLabel;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *selectBtn;
    QPushButton *sendBtn;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *UploadFile)
    {
        if (UploadFile->objectName().isEmpty())
            UploadFile->setObjectName(QStringLiteral("UploadFile"));
        UploadFile->resize(529, 421);
        UploadFile->setMinimumSize(QSize(100, 100));
        verticalLayout = new QVBoxLayout(UploadFile);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Drag = new QLabel(UploadFile);
        Drag->setObjectName(QStringLiteral("Drag"));

        verticalLayout->addWidget(Drag);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        mFileIcon = new QLabel(UploadFile);
        mFileIcon->setObjectName(QStringLiteral("mFileIcon"));

        horizontalLayout_3->addWidget(mFileIcon);

        mFileName = new QLabel(UploadFile);
        mFileName->setObjectName(QStringLiteral("mFileName"));

        horizontalLayout_3->addWidget(mFileName);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        sendProgressBar = new QProgressBar(UploadFile);
        sendProgressBar->setObjectName(QStringLiteral("sendProgressBar"));
        sendProgressBar->setValue(0);

        horizontalLayout_2->addWidget(sendProgressBar);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_5);

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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        selectBtn = new QPushButton(UploadFile);
        selectBtn->setObjectName(QStringLiteral("selectBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectBtn->sizePolicy().hasHeightForWidth());
        selectBtn->setSizePolicy(sizePolicy);
        selectBtn->setMinimumSize(QSize(80, 30));
        selectBtn->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(selectBtn);

        sendBtn = new QPushButton(UploadFile);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sizePolicy.setHeightForWidth(sendBtn->sizePolicy().hasHeightForWidth());
        sendBtn->setSizePolicy(sizePolicy);
        sendBtn->setMinimumSize(QSize(80, 30));
        sendBtn->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(sendBtn);

        cancelBtn = new QPushButton(UploadFile);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(80, 30));
        cancelBtn->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(cancelBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UploadFile);
        QObject::connect(selectBtn, SIGNAL(clicked()), UploadFile, SLOT(ClickOpenButton()));
        QObject::connect(sendBtn, SIGNAL(clicked()), UploadFile, SLOT(ClickSendButton()));

        QMetaObject::connectSlotsByName(UploadFile);
    } // setupUi

    void retranslateUi(QWidget *UploadFile)
    {
        UploadFile->setWindowTitle(QApplication::translate("UploadFile", "Form", Q_NULLPTR));
        Drag->setText(QApplication::translate("UploadFile", "TextLabel", Q_NULLPTR));
        mFileIcon->setText(QApplication::translate("UploadFile", "TextLabel", Q_NULLPTR));
        mFileName->setText(QApplication::translate("UploadFile", "TextLabel", Q_NULLPTR));
        uploadSpeedLabel->setText(QApplication::translate("UploadFile", "TextLabel", Q_NULLPTR));
        selectBtn->setText(QApplication::translate("UploadFile", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("UploadFile", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
        cancelBtn->setText(QApplication::translate("UploadFile", "\345\217\226\346\266\210\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UploadFile: public Ui_UploadFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADFILE_H
