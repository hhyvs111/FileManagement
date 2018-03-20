/********************************************************************************
** Form generated from reading UI file 'SetFilePath.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETFILEPATH_H
#define UI_SETFILEPATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetFilePath
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLineEdit *filePathLine;
    QPushButton *selectButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *SetFilePath)
    {
        if (SetFilePath->objectName().isEmpty())
            SetFilePath->setObjectName(QStringLiteral("SetFilePath"));
        SetFilePath->resize(337, 232);
        verticalLayout = new QVBoxLayout(SetFilePath);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(SetFilePath);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        filePathLine = new QLineEdit(SetFilePath);
        filePathLine->setObjectName(QStringLiteral("filePathLine"));

        horizontalLayout->addWidget(filePathLine);

        selectButton = new QPushButton(SetFilePath);
        selectButton->setObjectName(QStringLiteral("selectButton"));

        horizontalLayout->addWidget(selectButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        saveButton = new QPushButton(SetFilePath);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout_2->addWidget(saveButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(SetFilePath);
        QObject::connect(selectButton, SIGNAL(clicked()), SetFilePath, SLOT(selectFilePath()));
        QObject::connect(saveButton, SIGNAL(clicked()), SetFilePath, SLOT(ClickSaveButton()));

        QMetaObject::connectSlotsByName(SetFilePath);
    } // setupUi

    void retranslateUi(QWidget *SetFilePath)
    {
        SetFilePath->setWindowTitle(QApplication::translate("SetFilePath", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SetFilePath", "\344\270\213\350\275\275\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        selectButton->setText(QApplication::translate("SetFilePath", "\351\200\211\346\213\251\350\267\257\345\276\204", Q_NULLPTR));
        saveButton->setText(QApplication::translate("SetFilePath", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetFilePath: public Ui_SetFilePath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETFILEPATH_H
