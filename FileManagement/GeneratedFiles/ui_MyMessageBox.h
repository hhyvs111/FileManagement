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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMessageBox
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *MessageIcon;
    QLabel *MessageContent;
    QLineEdit *inputContent;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pButtonOk;
    QPushButton *pButtonCancel;

    void setupUi(QWidget *MyMessageBox)
    {
        if (MyMessageBox->objectName().isEmpty())
            MyMessageBox->setObjectName(QStringLiteral("MyMessageBox"));
        MyMessageBox->resize(340, 184);
        verticalLayout = new QVBoxLayout(MyMessageBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        MessageIcon = new QLabel(MyMessageBox);
        MessageIcon->setObjectName(QStringLiteral("MessageIcon"));

        horizontalLayout->addWidget(MessageIcon);

        MessageContent = new QLabel(MyMessageBox);
        MessageContent->setObjectName(QStringLiteral("MessageContent"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MessageContent->sizePolicy().hasHeightForWidth());
        MessageContent->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(MessageContent);

        inputContent = new QLineEdit(MyMessageBox);
        inputContent->setObjectName(QStringLiteral("inputContent"));

        horizontalLayout->addWidget(inputContent);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pButtonOk = new QPushButton(MyMessageBox);
        pButtonOk->setObjectName(QStringLiteral("pButtonOk"));
        pButtonOk->setStyleSheet(QLatin1String("pButtonOk\n"
"{\n"
"    color:red;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}"));

        horizontalLayout_2->addWidget(pButtonOk);

        pButtonCancel = new QPushButton(MyMessageBox);
        pButtonCancel->setObjectName(QStringLiteral("pButtonCancel"));
        pButtonCancel->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(pButtonCancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(MyMessageBox);

        QMetaObject::connectSlotsByName(MyMessageBox);
    } // setupUi

    void retranslateUi(QWidget *MyMessageBox)
    {
        MyMessageBox->setWindowTitle(QApplication::translate("MyMessageBox", "Form", Q_NULLPTR));
        MessageIcon->setText(QApplication::translate("MyMessageBox", "TextLabel", Q_NULLPTR));
        MessageContent->setText(QApplication::translate("MyMessageBox", "<html><head/><body><p>TextLabel</p></body></html>", Q_NULLPTR));
        pButtonOk->setText(QApplication::translate("MyMessageBox", "PushButton", Q_NULLPTR));
        pButtonCancel->setText(QApplication::translate("MyMessageBox", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyMessageBox: public Ui_MyMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMESSAGEBOX_H
