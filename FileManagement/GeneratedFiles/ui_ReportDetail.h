/********************************************************************************
** Form generated from reading UI file 'ReportDetail.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTDETAIL_H
#define UI_REPORTDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportDetail
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *reporterDetail;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *reportTime;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *reportMainPlainTextEdit;
    QLabel *LMain;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout;
    QLabel *LQuestionForSolve;
    QPlainTextEdit *reportQuestionForSolve;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *reportQuestionFromLastWeek;
    QLabel *LQuestionFromLastWeek;
    QSpacerItem *horizontalSpacer_7;
    QGridLayout *gridLayout_3;
    QLabel *LQuestionForSolved;
    QPlainTextEdit *reportQuestionHasSolved;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout_5;
    QLabel *LYourGet;
    QPlainTextEdit *reportYourGet;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *ReportDetail)
    {
        if (ReportDetail->objectName().isEmpty())
            ReportDetail->setObjectName(QStringLiteral("ReportDetail"));
        ReportDetail->resize(820, 682);
        verticalLayout = new QVBoxLayout(ReportDetail);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        reporterDetail = new QLabel(ReportDetail);
        reporterDetail->setObjectName(QStringLiteral("reporterDetail"));

        horizontalLayout_3->addWidget(reporterDetail);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        reportTime = new QLabel(ReportDetail);
        reportTime->setObjectName(QStringLiteral("reportTime"));

        horizontalLayout_2->addWidget(reportTime);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ReportDetail);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        reportMainPlainTextEdit = new QPlainTextEdit(ReportDetail);
        reportMainPlainTextEdit->setObjectName(QStringLiteral("reportMainPlainTextEdit"));

        gridLayout_4->addWidget(reportMainPlainTextEdit, 1, 1, 1, 1);

        LMain = new QLabel(ReportDetail);
        LMain->setObjectName(QStringLiteral("LMain"));

        gridLayout_4->addWidget(LMain, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LQuestionForSolve = new QLabel(ReportDetail);
        LQuestionForSolve->setObjectName(QStringLiteral("LQuestionForSolve"));

        gridLayout->addWidget(LQuestionForSolve, 0, 1, 1, 1);

        reportQuestionForSolve = new QPlainTextEdit(ReportDetail);
        reportQuestionForSolve->setObjectName(QStringLiteral("reportQuestionForSolve"));

        gridLayout->addWidget(reportQuestionForSolve, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        reportQuestionFromLastWeek = new QPlainTextEdit(ReportDetail);
        reportQuestionFromLastWeek->setObjectName(QStringLiteral("reportQuestionFromLastWeek"));

        gridLayout_2->addWidget(reportQuestionFromLastWeek, 1, 1, 1, 1);

        LQuestionFromLastWeek = new QLabel(ReportDetail);
        LQuestionFromLastWeek->setObjectName(QStringLiteral("LQuestionFromLastWeek"));

        gridLayout_2->addWidget(LQuestionFromLastWeek, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        LQuestionForSolved = new QLabel(ReportDetail);
        LQuestionForSolved->setObjectName(QStringLiteral("LQuestionForSolved"));

        gridLayout_3->addWidget(LQuestionForSolved, 0, 1, 1, 1);

        reportQuestionHasSolved = new QPlainTextEdit(ReportDetail);
        reportQuestionHasSolved->setObjectName(QStringLiteral("reportQuestionHasSolved"));

        gridLayout_3->addWidget(reportQuestionHasSolved, 1, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        LYourGet = new QLabel(ReportDetail);
        LYourGet->setObjectName(QStringLiteral("LYourGet"));

        gridLayout_5->addWidget(LYourGet, 0, 1, 1, 1);

        reportYourGet = new QPlainTextEdit(ReportDetail);
        reportYourGet->setObjectName(QStringLiteral("reportYourGet"));

        gridLayout_5->addWidget(reportYourGet, 1, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_9, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        updateButton = new QPushButton(ReportDetail);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        horizontalLayout_4->addWidget(updateButton);

        deleteButton = new QPushButton(ReportDetail);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout_4->addWidget(deleteButton);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(ReportDetail);

        QMetaObject::connectSlotsByName(ReportDetail);
    } // setupUi

    void retranslateUi(QWidget *ReportDetail)
    {
        ReportDetail->setWindowTitle(QApplication::translate("ReportDetail", "Form", Q_NULLPTR));
        reporterDetail->setText(QApplication::translate("ReportDetail", "TextLabel", Q_NULLPTR));
        reportTime->setText(QApplication::translate("ReportDetail", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("ReportDetail", "-------------------------------------------------------------------------------------------------------------------------------------", Q_NULLPTR));
        LMain->setText(QApplication::translate("ReportDetail", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\234\254\345\221\250\345\255\246\344\271\240\345\206\205\345\256\271</span></p></body></html>", Q_NULLPTR));
        LQuestionForSolve->setText(QApplication::translate("ReportDetail", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\234\254\345\221\250\351\201\207\345\210\260\347\232\204\351\227\256\351\242\230</span></p></body></html>", Q_NULLPTR));
        LQuestionFromLastWeek->setText(QApplication::translate("ReportDetail", "<html><head/><body><p><span style=\" font-size:14pt;\">\344\270\212\345\221\250\347\232\204\351\227\256\351\242\230</span></p></body></html>", Q_NULLPTR));
        LQuestionForSolved->setText(QApplication::translate("ReportDetail", "<html><head/><body><p><span style=\" font-size:14pt;\">\350\247\243\345\206\263\346\226\271\346\263\225</span></p></body></html>", Q_NULLPTR));
        LYourGet->setText(QApplication::translate("ReportDetail", "<html><head/><body><p><span style=\" font-size:14pt;\">\345\255\246\344\271\240\345\277\203\345\276\227\344\270\216\344\275\223\344\274\232</span></p></body></html>", Q_NULLPTR));
        updateButton->setText(QApplication::translate("ReportDetail", "\344\277\256\346\224\271", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("ReportDetail", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportDetail: public Ui_ReportDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTDETAIL_H
