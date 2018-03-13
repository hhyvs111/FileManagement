/********************************************************************************
** Form generated from reading UI file 'DownloadWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADWINDOW_H
#define UI_DOWNLOADWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloadWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *condition;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *settingButton;
    QHBoxLayout *horizontalLayout_3;
    QTableView *downloadTable;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *progressBar;
    QLabel *downloadSpeedLabel;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *DownloadWindow)
    {
        if (DownloadWindow->objectName().isEmpty())
            DownloadWindow->setObjectName(QStringLiteral("DownloadWindow"));
        DownloadWindow->resize(811, 504);
        verticalLayout = new QVBoxLayout(DownloadWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(DownloadWindow);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        condition = new QLineEdit(DownloadWindow);
        condition->setObjectName(QStringLiteral("condition"));

        horizontalLayout->addWidget(condition);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        settingButton = new QToolButton(DownloadWindow);
        settingButton->setObjectName(QStringLiteral("settingButton"));

        horizontalLayout->addWidget(settingButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        downloadTable = new QTableView(DownloadWindow);
        downloadTable->setObjectName(QStringLiteral("downloadTable"));
        downloadTable->setMinimumSize(QSize(600, 400));

        horizontalLayout_3->addWidget(downloadTable);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        progressBar = new QProgressBar(DownloadWindow);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout_2->addWidget(progressBar);

        downloadSpeedLabel = new QLabel(DownloadWindow);
        downloadSpeedLabel->setObjectName(QStringLiteral("downloadSpeedLabel"));

        verticalLayout_2->addWidget(downloadSpeedLabel);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DownloadWindow);

        QMetaObject::connectSlotsByName(DownloadWindow);
    } // setupUi

    void retranslateUi(QWidget *DownloadWindow)
    {
        DownloadWindow->setWindowTitle(QApplication::translate("DownloadWindow", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("DownloadWindow", "\346\226\207\344\273\266\345\220\215\357\274\232", Q_NULLPTR));
        settingButton->setText(QApplication::translate("DownloadWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        downloadSpeedLabel->setText(QApplication::translate("DownloadWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DownloadWindow: public Ui_DownloadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADWINDOW_H
