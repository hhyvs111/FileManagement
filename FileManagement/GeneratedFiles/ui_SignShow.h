/********************************************************************************
** Form generated from reading UI file 'SignShow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNSHOW_H
#define UI_SIGNSHOW_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignShow
{
public:
    QVBoxLayout *verticalLayout;
    QWebEngineView *webEngineWidget;

    void setupUi(QWidget *SignShow)
    {
        if (SignShow->objectName().isEmpty())
            SignShow->setObjectName(QStringLiteral("SignShow"));
        SignShow->resize(400, 300);
        verticalLayout = new QVBoxLayout(SignShow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        webEngineWidget = new QWebEngineView(SignShow);
        webEngineWidget->setObjectName(QStringLiteral("webEngineWidget"));
        webEngineWidget->setUrl(QUrl(QStringLiteral("about:blank")));

        verticalLayout->addWidget(webEngineWidget);


        retranslateUi(SignShow);

        QMetaObject::connectSlotsByName(SignShow);
    } // setupUi

    void retranslateUi(QWidget *SignShow)
    {
        SignShow->setWindowTitle(QApplication::translate("SignShow", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SignShow: public Ui_SignShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNSHOW_H
