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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMessageBox
{
public:
    QPushButton *pButtonCancel;
    QPushButton *pButtonOk;
    QLineEdit *inputContent;
    QLabel *MessageIcon;
    QLabel *MessageContent;

    void setupUi(QWidget *MyMessageBox)
    {
        if (MyMessageBox->objectName().isEmpty())
            MyMessageBox->setObjectName(QStringLiteral("MyMessageBox"));
        MyMessageBox->resize(431, 198);
        pButtonCancel = new QPushButton(MyMessageBox);
        pButtonCancel->setObjectName(QStringLiteral("pButtonCancel"));
        pButtonCancel->setGeometry(QRect(340, 140, 75, 31));
        pButtonCancel->setStyleSheet(QStringLiteral(""));
        pButtonOk = new QPushButton(MyMessageBox);
        pButtonOk->setObjectName(QStringLiteral("pButtonOk"));
        pButtonOk->setGeometry(QRect(250, 142, 75, 31));
        pButtonOk->setStyleSheet(QLatin1String("pButtonOk\n"
"{\n"
"    color:red;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}"));
        inputContent = new QLineEdit(MyMessageBox);
        inputContent->setObjectName(QStringLiteral("inputContent"));
        inputContent->setGeometry(QRect(230, 69, 181, 31));
        MessageIcon = new QLabel(MyMessageBox);
        MessageIcon->setObjectName(QStringLiteral("MessageIcon"));
        MessageIcon->setGeometry(QRect(60, 80, 54, 12));
        MessageContent = new QLabel(MyMessageBox);
        MessageContent->setObjectName(QStringLiteral("MessageContent"));
        MessageContent->setGeometry(QRect(130, 80, 51, 16));

        retranslateUi(MyMessageBox);

        QMetaObject::connectSlotsByName(MyMessageBox);
    } // setupUi

    void retranslateUi(QWidget *MyMessageBox)
    {
        MyMessageBox->setWindowTitle(QApplication::translate("MyMessageBox", "Form", Q_NULLPTR));
        pButtonCancel->setText(QApplication::translate("MyMessageBox", "PushButton", Q_NULLPTR));
        pButtonOk->setText(QApplication::translate("MyMessageBox", "PushButton", Q_NULLPTR));
        MessageIcon->setText(QApplication::translate("MyMessageBox", "TextLabel", Q_NULLPTR));
        MessageContent->setText(QApplication::translate("MyMessageBox", "<html><head/><body><p>TextLabel</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyMessageBox: public Ui_MyMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMESSAGEBOX_H
