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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileManagement
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *TitleLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *FunctionLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_7;
    QPushButton *personButton;
    QSpacerItem *verticalSpacer_2;
    QToolButton *uploadButton;
    QSpacerItem *verticalSpacer_3;
    QToolButton *downloadButton;
    QSpacerItem *verticalSpacer_4;
    QToolButton *chatButton;
    QSpacerItem *verticalSpacer_5;
    QToolButton *deleteButton;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *SubLayout;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_9;
    QLabel *photoLabel;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FileManagement)
    {
        if (FileManagement->objectName().isEmpty())
            FileManagement->setObjectName(QStringLiteral("FileManagement"));
        FileManagement->resize(824, 576);
        centralWidget = new QWidget(FileManagement);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        TitleLayout = new QHBoxLayout();
        TitleLayout->setSpacing(0);
        TitleLayout->setObjectName(QStringLiteral("TitleLayout"));
        TitleLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        TitleLayout->addItem(horizontalSpacer_2);

        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font;
        font.setFamily(QStringLiteral("04b_21"));
        font.setPointSize(12);
        titleLabel->setFont(font);

        TitleLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TitleLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(TitleLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        FunctionLayout = new QHBoxLayout();
        FunctionLayout->setSpacing(6);
        FunctionLayout->setObjectName(QStringLiteral("FunctionLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        personButton = new QPushButton(centralWidget);
        personButton->setObjectName(QStringLiteral("personButton"));
        personButton->setMaximumSize(QSize(70, 55));
        personButton->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(personButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        uploadButton = new QToolButton(centralWidget);
        uploadButton->setObjectName(QStringLiteral("uploadButton"));
        uploadButton->setFocusPolicy(Qt::NoFocus);
        uploadButton->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(uploadButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        downloadButton = new QToolButton(centralWidget);
        downloadButton->setObjectName(QStringLiteral("downloadButton"));
        downloadButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(downloadButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        chatButton = new QToolButton(centralWidget);
        chatButton->setObjectName(QStringLiteral("chatButton"));

        verticalLayout->addWidget(chatButton);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        deleteButton = new QToolButton(centralWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        verticalLayout->addWidget(deleteButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);


        FunctionLayout->addLayout(verticalLayout);

        SubLayout = new QVBoxLayout();
        SubLayout->setSpacing(6);
        SubLayout->setObjectName(QStringLiteral("SubLayout"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SubLayout->addItem(verticalSpacer_8);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SubLayout->addItem(verticalSpacer_9);


        FunctionLayout->addLayout(SubLayout);

        photoLabel = new QLabel(centralWidget);
        photoLabel->setObjectName(QStringLiteral("photoLabel"));

        FunctionLayout->addWidget(photoLabel);


        verticalLayout_2->addLayout(FunctionLayout);

        FileManagement->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FileManagement);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FileManagement->setStatusBar(statusBar);

        retranslateUi(FileManagement);
        QObject::connect(uploadButton, SIGNAL(clicked()), FileManagement, SLOT(ClickUploadFile()));
        QObject::connect(downloadButton, SIGNAL(clicked()), FileManagement, SLOT(ClickDownloadFile()));

        QMetaObject::connectSlotsByName(FileManagement);
    } // setupUi

    void retranslateUi(QMainWindow *FileManagement)
    {
        FileManagement->setWindowTitle(QApplication::translate("FileManagement", "mainpage", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("FileManagement", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\254\242\350\277\216\346\235\245\345\210\260\345\256\236\351\252\214\345\256\244\346\226\207\346\241\243\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", Q_NULLPTR));
        personButton->setText(QString());
        uploadButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        downloadButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        chatButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        photoLabel->setText(QApplication::translate("FileManagement", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileManagement: public Ui_FileManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGEMENT_H
