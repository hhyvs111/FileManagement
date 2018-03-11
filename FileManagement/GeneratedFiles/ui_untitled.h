/********************************************************************************
** Form generated from reading UI file 'untitled.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNTITLED_H
#define UI_UNTITLED_H

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

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *fileSumLayout;
    QHBoxLayout *fileInfoLayout;
    QLabel *label;
    QVBoxLayout *fileNameSize;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QProgressBar *progressBar;
    QHBoxLayout *fileSatusLayout;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(277, 102);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        fileSumLayout = new QVBoxLayout();
        fileSumLayout->setObjectName(QStringLiteral("fileSumLayout"));
        fileInfoLayout = new QHBoxLayout();
        fileInfoLayout->setObjectName(QStringLiteral("fileInfoLayout"));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));

        fileInfoLayout->addWidget(label);

        fileNameSize = new QVBoxLayout();
        fileNameSize->setObjectName(QStringLiteral("fileNameSize"));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));

        fileNameSize->addWidget(label_2);

        label_3 = new QLabel(Form);
        label_3->setObjectName(QStringLiteral("label_3"));

        fileNameSize->addWidget(label_3);


        fileInfoLayout->addLayout(fileNameSize);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        fileInfoLayout->addItem(horizontalSpacer_2);


        fileSumLayout->addLayout(fileInfoLayout);

        progressBar = new QProgressBar(Form);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximumSize(QSize(300, 10));
        progressBar->setValue(24);

        fileSumLayout->addWidget(progressBar);

        fileSatusLayout = new QHBoxLayout();
        fileSatusLayout->setObjectName(QStringLiteral("fileSatusLayout"));
        label_4 = new QLabel(Form);
        label_4->setObjectName(QStringLiteral("label_4"));

        fileSatusLayout->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        fileSatusLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        fileSatusLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        fileSatusLayout->addWidget(pushButton_2);


        fileSumLayout->addLayout(fileSatusLayout);


        verticalLayout->addLayout(fileSumLayout);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Form", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Form", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNTITLED_H
