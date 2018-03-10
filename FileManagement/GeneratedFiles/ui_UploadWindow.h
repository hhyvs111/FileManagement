/********************************************************************************
** Form generated from reading UI file 'UploadWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADWINDOW_H
#define UI_UPLOADWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadWindow
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *Drag;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_11;
    QVBoxLayout *FileListLayout;
    QSpacerItem *horizontalSpacer_12;
    QGridLayout *UploadGridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *selectBtn;
    QPushButton *sendBtn;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *UploadWindow)
    {
        if (UploadWindow->objectName().isEmpty())
            UploadWindow->setObjectName(QStringLiteral("UploadWindow"));
        UploadWindow->resize(580, 458);
        UploadWindow->setMinimumSize(QSize(100, 100));
        verticalLayout = new QVBoxLayout(UploadWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        Drag = new QLabel(UploadWindow);
        Drag->setObjectName(QStringLiteral("Drag"));

        horizontalLayout_6->addWidget(Drag);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        FileListLayout = new QVBoxLayout();
        FileListLayout->setObjectName(QStringLiteral("FileListLayout"));

        horizontalLayout_5->addLayout(FileListLayout);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_5);

        UploadGridLayout = new QGridLayout();
        UploadGridLayout->setObjectName(QStringLiteral("UploadGridLayout"));

        verticalLayout->addLayout(UploadGridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        selectBtn = new QPushButton(UploadWindow);
        selectBtn->setObjectName(QStringLiteral("selectBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectBtn->sizePolicy().hasHeightForWidth());
        selectBtn->setSizePolicy(sizePolicy);
        selectBtn->setMinimumSize(QSize(80, 30));
        selectBtn->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(selectBtn);

        sendBtn = new QPushButton(UploadWindow);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sizePolicy.setHeightForWidth(sendBtn->sizePolicy().hasHeightForWidth());
        sendBtn->setSizePolicy(sizePolicy);
        sendBtn->setMinimumSize(QSize(80, 30));
        sendBtn->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(sendBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(UploadWindow);
        QObject::connect(selectBtn, SIGNAL(clicked()), UploadWindow, SLOT(ClickOpenButton()));
        QObject::connect(sendBtn, SIGNAL(clicked()), UploadWindow, SLOT(ClickSendButton()));

        QMetaObject::connectSlotsByName(UploadWindow);
    } // setupUi

    void retranslateUi(QWidget *UploadWindow)
    {
        UploadWindow->setWindowTitle(QApplication::translate("UploadWindow", "Form", Q_NULLPTR));
        Drag->setText(QApplication::translate("UploadWindow", "TextLabel", Q_NULLPTR));
        selectBtn->setText(QApplication::translate("UploadWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("UploadWindow", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UploadWindow: public Ui_UploadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADWINDOW_H
