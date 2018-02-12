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
    QHBoxLayout *FunctionLayout;
    QWidget *ToolButtonWidget;
    QVBoxLayout *ToolButtonLayout;
    QSpacerItem *verticalSpacer_4;
    QToolButton *personButton;
    QSpacerItem *verticalSpacer_3;
    QToolButton *reportEditButton;
    QToolButton *reportLookButton;
    QSpacerItem *verticalSpacer;
    QToolButton *showFileButton;
    QToolButton *uploadButton;
    QToolButton *downloadButton;
    QToolButton *deleteButton;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *SubLayout;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_9;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FileManagement)
    {
        if (FileManagement->objectName().isEmpty())
            FileManagement->setObjectName(QStringLiteral("FileManagement"));
        FileManagement->resize(843, 539);
        centralWidget = new QWidget(FileManagement);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 9, -1, -1);
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

        FunctionLayout = new QHBoxLayout();
        FunctionLayout->setSpacing(6);
        FunctionLayout->setObjectName(QStringLiteral("FunctionLayout"));
        ToolButtonWidget = new QWidget(centralWidget);
        ToolButtonWidget->setObjectName(QStringLiteral("ToolButtonWidget"));
        ToolButtonLayout = new QVBoxLayout(ToolButtonWidget);
        ToolButtonLayout->setSpacing(0);
        ToolButtonLayout->setContentsMargins(11, 11, 11, 11);
        ToolButtonLayout->setObjectName(QStringLiteral("ToolButtonLayout"));
        ToolButtonLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        ToolButtonLayout->setContentsMargins(1, 1, 1, 1);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ToolButtonLayout->addItem(verticalSpacer_4);

        personButton = new QToolButton(ToolButtonWidget);
        personButton->setObjectName(QStringLiteral("personButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(personButton->sizePolicy().hasHeightForWidth());
        personButton->setSizePolicy(sizePolicy);
        personButton->setMinimumSize(QSize(150, 30));
        personButton->setMaximumSize(QSize(16777215, 16777215));

        ToolButtonLayout->addWidget(personButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ToolButtonLayout->addItem(verticalSpacer_3);

        reportEditButton = new QToolButton(ToolButtonWidget);
        reportEditButton->setObjectName(QStringLiteral("reportEditButton"));
        sizePolicy.setHeightForWidth(reportEditButton->sizePolicy().hasHeightForWidth());
        reportEditButton->setSizePolicy(sizePolicy);
        reportEditButton->setMinimumSize(QSize(150, 30));

        ToolButtonLayout->addWidget(reportEditButton);

        reportLookButton = new QToolButton(ToolButtonWidget);
        reportLookButton->setObjectName(QStringLiteral("reportLookButton"));
        sizePolicy.setHeightForWidth(reportLookButton->sizePolicy().hasHeightForWidth());
        reportLookButton->setSizePolicy(sizePolicy);
        reportLookButton->setMinimumSize(QSize(150, 30));

        ToolButtonLayout->addWidget(reportLookButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ToolButtonLayout->addItem(verticalSpacer);

        showFileButton = new QToolButton(ToolButtonWidget);
        showFileButton->setObjectName(QStringLiteral("showFileButton"));
        sizePolicy.setHeightForWidth(showFileButton->sizePolicy().hasHeightForWidth());
        showFileButton->setSizePolicy(sizePolicy);
        showFileButton->setMinimumSize(QSize(150, 30));

        ToolButtonLayout->addWidget(showFileButton);

        uploadButton = new QToolButton(ToolButtonWidget);
        uploadButton->setObjectName(QStringLiteral("uploadButton"));
        sizePolicy.setHeightForWidth(uploadButton->sizePolicy().hasHeightForWidth());
        uploadButton->setSizePolicy(sizePolicy);
        uploadButton->setMinimumSize(QSize(150, 30));
        uploadButton->setFocusPolicy(Qt::NoFocus);
        uploadButton->setStyleSheet(QStringLiteral(""));

        ToolButtonLayout->addWidget(uploadButton);

        downloadButton = new QToolButton(ToolButtonWidget);
        downloadButton->setObjectName(QStringLiteral("downloadButton"));
        sizePolicy.setHeightForWidth(downloadButton->sizePolicy().hasHeightForWidth());
        downloadButton->setSizePolicy(sizePolicy);
        downloadButton->setMinimumSize(QSize(150, 30));
        downloadButton->setFocusPolicy(Qt::NoFocus);

        ToolButtonLayout->addWidget(downloadButton);

        deleteButton = new QToolButton(ToolButtonWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setMinimumSize(QSize(150, 30));

        ToolButtonLayout->addWidget(deleteButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ToolButtonLayout->addItem(verticalSpacer_2);


        FunctionLayout->addWidget(ToolButtonWidget);

        SubLayout = new QVBoxLayout();
        SubLayout->setSpacing(6);
        SubLayout->setObjectName(QStringLiteral("SubLayout"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SubLayout->addItem(verticalSpacer_8);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SubLayout->addItem(verticalSpacer_9);


        FunctionLayout->addLayout(SubLayout);


        verticalLayout_2->addLayout(FunctionLayout);

        FileManagement->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FileManagement);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FileManagement->setStatusBar(statusBar);

        retranslateUi(FileManagement);
        QObject::connect(personButton, SIGNAL(clicked()), FileManagement, SLOT(ClickUserInformation()));
        QObject::connect(showFileButton, SIGNAL(clicked()), FileManagement, SLOT(ClickDownloadFile()));
        QObject::connect(uploadButton, SIGNAL(clicked()), FileManagement, SLOT(ClickUploadFile()));
        QObject::connect(deleteButton, SIGNAL(clicked()), FileManagement, SLOT(ClickReturn()));
        QObject::connect(reportEditButton, SIGNAL(clicked()), FileManagement, SLOT(ClickReportEdit()));
        QObject::connect(reportLookButton, SIGNAL(clicked()), FileManagement, SLOT(ClickReportLook()));

        QMetaObject::connectSlotsByName(FileManagement);
    } // setupUi

    void retranslateUi(QMainWindow *FileManagement)
    {
        FileManagement->setWindowTitle(QApplication::translate("FileManagement", "mainpage", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("FileManagement", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\254\242\350\277\216\346\235\245\345\210\260\345\256\236\351\252\214\345\256\244\346\226\207\346\241\243\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", Q_NULLPTR));
        personButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        reportEditButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        reportLookButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        showFileButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        uploadButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        downloadButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileManagement: public Ui_FileManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGEMENT_H
