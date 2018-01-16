/********************************************************************************
** Form generated from reading UI file 'MyMessageBox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMESSAGEBOX_H
#define UI_MYMESSAGEBOX_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMessageBox
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *MessageContent;
    QLabel *MessageIcon;
    QLineEdit *inputContent;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pButtonOk;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pButtonCancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *MyMessageBox)
    {
        if (MyMessageBox->objectName().isEmpty())
            MyMessageBox->setObjectName(QStringLiteral("MyMessageBox"));
        MyMessageBox->resize(340, 184);
        horizontalLayoutWidget = new QWidget(MyMessageBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 50, 271, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MessageContent = new QLabel(horizontalLayoutWidget);
        MessageContent->setObjectName(QStringLiteral("MessageContent"));

        horizontalLayout->addWidget(MessageContent);

        MessageIcon = new QLabel(horizontalLayoutWidget);
        MessageIcon->setObjectName(QStringLiteral("MessageIcon"));

        horizontalLayout->addWidget(MessageIcon);

        inputContent = new QLineEdit(horizontalLayoutWidget);
        inputContent->setObjectName(QStringLiteral("inputContent"));

        horizontalLayout->addWidget(inputContent);

        horizontalLayoutWidget_2 = new QWidget(MyMessageBox);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(100, 120, 221, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pButtonOk = new QPushButton(horizontalLayoutWidget_2);
        pButtonOk->setObjectName(QStringLiteral("pButtonOk"));
        pButtonOk->setStyleSheet(QLatin1String("pButtonOk\n"
"{\n"
"    color:red;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}"));

        horizontalLayout_2->addWidget(pButtonOk);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pButtonCancel = new QPushButton(horizontalLayoutWidget_2);
        pButtonCancel->setObjectName(QStringLiteral("pButtonCancel"));
        pButtonCancel->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(pButtonCancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        retranslateUi(MyMessageBox);

        QMetaObject::connectSlotsByName(MyMessageBox);
    } // setupUi

    void retranslateUi(QWidget *MyMessageBox)
    {
        MyMessageBox->setWindowTitle(QApplication::translate("MyMessageBox", "Form", Q_NULLPTR));
        MessageContent->setText(QApplication::translate("MyMessageBox", "<html><head/><body><p>TextLabel</p></body></html>", Q_NULLPTR));
        MessageIcon->setText(QApplication::translate("MyMessageBox", "TextLabel", Q_NULLPTR));
        pButtonOk->setText(QApplication::translate("MyMessageBox", "PushButton", Q_NULLPTR));
        pButtonCancel->setText(QApplication::translate("MyMessageBox", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyMessageBox: public Ui_MyMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMESSAGEBOX_H
