/********************************************************************************
** Form generated from reading UI file 'Sign.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_H
#define UI_SIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sign
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QWidget *Sign)
    {
        if (Sign->objectName().isEmpty())
            Sign->setObjectName(QStringLiteral("Sign"));
        Sign->resize(400, 296);
        verticalLayout = new QVBoxLayout(Sign);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(30, 40, 30, 30);
        tableView = new QTableView(Sign);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(Sign);

        QMetaObject::connectSlotsByName(Sign);
    } // setupUi

    void retranslateUi(QWidget *Sign)
    {
        Sign->setWindowTitle(QApplication::translate("Sign", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Sign: public Ui_Sign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_H
