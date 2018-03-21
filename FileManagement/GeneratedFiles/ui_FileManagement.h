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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileManagement
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *TitleLayout;
    QLabel *titleLabel;
    QHBoxLayout *FunctionLayout;
    QWidget *ToolButtonWidget;
    QVBoxLayout *ToolButtonLayout;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_3;
    QToolButton *personButton;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_4;
    QToolButton *moneyButton;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_2;
    QToolButton *reportEditButton;
    QToolButton *reportLookButton;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QToolButton *showFileButton;
    QToolButton *uploadButton;
    QToolButton *downloadButton;
    QToolButton *deleteButton;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *SubLayout;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_9;

    void setupUi(QWidget *FileManagement)
    {
        if (FileManagement->objectName().isEmpty())
            FileManagement->setObjectName(QStringLiteral("FileManagement"));
        FileManagement->resize(831, 486);
        verticalLayout = new QVBoxLayout(FileManagement);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 35, 10, 10);
        TitleLayout = new QHBoxLayout();
        TitleLayout->setSpacing(0);
        TitleLayout->setObjectName(QStringLiteral("TitleLayout"));
        TitleLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        titleLabel = new QLabel(FileManagement);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font;
        font.setFamily(QStringLiteral("04b_21"));
        font.setPointSize(12);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QStringLiteral(""));

        TitleLayout->addWidget(titleLabel);


        verticalLayout->addLayout(TitleLayout);

        FunctionLayout = new QHBoxLayout();
        FunctionLayout->setSpacing(0);
        FunctionLayout->setObjectName(QStringLiteral("FunctionLayout"));
        ToolButtonWidget = new QWidget(FileManagement);
        ToolButtonWidget->setObjectName(QStringLiteral("ToolButtonWidget"));
        ToolButtonWidget->setStyleSheet(QStringLiteral(""));
        ToolButtonLayout = new QVBoxLayout(ToolButtonWidget);
        ToolButtonLayout->setSpacing(0);
        ToolButtonLayout->setObjectName(QStringLiteral("ToolButtonLayout"));
        ToolButtonLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        ToolButtonLayout->setContentsMargins(1, 1, 1, 1);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ToolButtonLayout->addItem(verticalSpacer_4);

        label_3 = new QLabel(ToolButtonWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        ToolButtonLayout->addWidget(label_3);

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

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ToolButtonLayout->addItem(verticalSpacer_6);

        label_4 = new QLabel(ToolButtonWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        ToolButtonLayout->addWidget(label_4);

        moneyButton = new QToolButton(ToolButtonWidget);
        moneyButton->setObjectName(QStringLiteral("moneyButton"));
        sizePolicy.setHeightForWidth(moneyButton->sizePolicy().hasHeightForWidth());
        moneyButton->setSizePolicy(sizePolicy);
        moneyButton->setMinimumSize(QSize(150, 30));

        ToolButtonLayout->addWidget(moneyButton);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ToolButtonLayout->addItem(verticalSpacer_5);

        label_2 = new QLabel(ToolButtonWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        ToolButtonLayout->addWidget(label_2);

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

        label = new QLabel(ToolButtonWidget);
        label->setObjectName(QStringLiteral("label"));

        ToolButtonLayout->addWidget(label);

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
        SubLayout->setSpacing(0);
        SubLayout->setObjectName(QStringLiteral("SubLayout"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SubLayout->addItem(verticalSpacer_8);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SubLayout->addItem(verticalSpacer_9);


        FunctionLayout->addLayout(SubLayout);


        verticalLayout->addLayout(FunctionLayout);


        retranslateUi(FileManagement);
        QObject::connect(personButton, SIGNAL(clicked()), FileManagement, SLOT(ClickUserInformation()));
        QObject::connect(reportEditButton, SIGNAL(clicked()), FileManagement, SLOT(ClickReportEdit()));
        QObject::connect(reportLookButton, SIGNAL(clicked()), FileManagement, SLOT(ClickReportLook()));
        QObject::connect(showFileButton, SIGNAL(clicked()), FileManagement, SLOT(ClickDownloadWindow()));
        QObject::connect(uploadButton, SIGNAL(clicked()), FileManagement, SLOT(ClickUploadWindow()));
        QObject::connect(downloadButton, SIGNAL(clicked()), FileManagement, SLOT(ClickDownloadManage()));
        QObject::connect(deleteButton, SIGNAL(clicked()), FileManagement, SLOT(ClickReturn()));
        QObject::connect(moneyButton, SIGNAL(clicked()), FileManagement, SLOT(ClickMoneyManage()));

        QMetaObject::connectSlotsByName(FileManagement);
    } // setupUi

    void retranslateUi(QWidget *FileManagement)
    {
        FileManagement->setWindowTitle(QApplication::translate("FileManagement", "Form", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("FileManagement", "<html><head/><body><p><span style=\" font-size:14pt;\"> \346\254\242\350\277\216\346\235\245\345\210\260\345\256\236\351\252\214\345\256\244\346\226\207\346\241\243\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("FileManagement", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\210\221\347\232\204</span></p></body></html>", Q_NULLPTR));
        personButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        label_4->setText(QApplication::translate("FileManagement", "<html><head/><body><p><span style=\" font-size:14pt;\">\350\264\242\345\212\241</span></p></body></html>", Q_NULLPTR));
        moneyButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("FileManagement", "<html><head/><body><p><span style=\" font-size:14pt;\">\345\221\250\346\212\245</span></p></body></html>", Q_NULLPTR));
        reportEditButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        reportLookButton->setText(QApplication::translate("FileManagement", "...", Q_NULLPTR));
        label->setText(QApplication::translate("FileManagement", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\226\207\346\241\243</span></p></body></html>", Q_NULLPTR));
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
