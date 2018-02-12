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
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *reporterDetail;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *reportTime;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *LMain;
    QPlainTextEdit *reportMainPlainTextEdit;
    QGridLayout *gridLayout;
    QLabel *LQuestionForSolve;
    QPlainTextEdit *reportQuestionForSolve;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *reportQuestionHasSolved;
    QLabel *LQuestionForSolved;
    QLabel *LQuestionFromLastWeek;
    QPlainTextEdit *reportQuestionFromLastWeek;
    QVBoxLayout *verticalLayout_2;
    QLabel *LYourGet;
    QPlainTextEdit *reportYourGet;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *updateButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *ReportDetail)
    {
        if (ReportDetail->objectName().isEmpty())
            ReportDetail->setObjectName(QStringLiteral("ReportDetail"));
        ReportDetail->resize(554, 521);
        verticalLayout_3 = new QVBoxLayout(ReportDetail);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        reporterDetail = new QLabel(ReportDetail);
        reporterDetail->setObjectName(QStringLiteral("reporterDetail"));

        horizontalLayout_3->addWidget(reporterDetail);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        reportTime = new QLabel(ReportDetail);
        reportTime->setObjectName(QStringLiteral("reportTime"));

        horizontalLayout_2->addWidget(reportTime);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ReportDetail);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        LMain = new QLabel(ReportDetail);
        LMain->setObjectName(QStringLiteral("LMain"));

        verticalLayout->addWidget(LMain);

        reportMainPlainTextEdit = new QPlainTextEdit(ReportDetail);
        reportMainPlainTextEdit->setObjectName(QStringLiteral("reportMainPlainTextEdit"));

        verticalLayout->addWidget(reportMainPlainTextEdit);


        verticalLayout_3->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LQuestionForSolve = new QLabel(ReportDetail);
        LQuestionForSolve->setObjectName(QStringLiteral("LQuestionForSolve"));

        gridLayout->addWidget(LQuestionForSolve, 0, 0, 1, 1);

        reportQuestionForSolve = new QPlainTextEdit(ReportDetail);
        reportQuestionForSolve->setObjectName(QStringLiteral("reportQuestionForSolve"));

        gridLayout->addWidget(reportQuestionForSolve, 1, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        reportQuestionHasSolved = new QPlainTextEdit(ReportDetail);
        reportQuestionHasSolved->setObjectName(QStringLiteral("reportQuestionHasSolved"));

        gridLayout_2->addWidget(reportQuestionHasSolved, 1, 1, 1, 1);

        LQuestionForSolved = new QLabel(ReportDetail);
        LQuestionForSolved->setObjectName(QStringLiteral("LQuestionForSolved"));

        gridLayout_2->addWidget(LQuestionForSolved, 0, 1, 1, 1);

        LQuestionFromLastWeek = new QLabel(ReportDetail);
        LQuestionFromLastWeek->setObjectName(QStringLiteral("LQuestionFromLastWeek"));

        gridLayout_2->addWidget(LQuestionFromLastWeek, 0, 0, 1, 1);

        reportQuestionFromLastWeek = new QPlainTextEdit(ReportDetail);
        reportQuestionFromLastWeek->setObjectName(QStringLiteral("reportQuestionFromLastWeek"));

        gridLayout_2->addWidget(reportQuestionFromLastWeek, 1, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        LYourGet = new QLabel(ReportDetail);
        LYourGet->setObjectName(QStringLiteral("LYourGet"));

        verticalLayout_2->addWidget(LYourGet);

        reportYourGet = new QPlainTextEdit(ReportDetail);
        reportYourGet->setObjectName(QStringLiteral("reportYourGet"));

        verticalLayout_2->addWidget(reportYourGet);


        verticalLayout_3->addLayout(verticalLayout_2);

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


        verticalLayout_3->addLayout(horizontalLayout_4);


        retranslateUi(ReportDetail);

        QMetaObject::connectSlotsByName(ReportDetail);
    } // setupUi

    void retranslateUi(QWidget *ReportDetail)
    {
        ReportDetail->setWindowTitle(QApplication::translate("ReportDetail", "Form", Q_NULLPTR));
        reporterDetail->setText(QApplication::translate("ReportDetail", "TextLabel", Q_NULLPTR));
        reportTime->setText(QApplication::translate("ReportDetail", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("ReportDetail", "-----------------------------------------------------------------------------------------", Q_NULLPTR));
        LMain->setText(QApplication::translate("ReportDetail", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\234\254\345\221\250\345\255\246\344\271\240\345\206\205\345\256\271</span></p></body></html>", Q_NULLPTR));
        LQuestionForSolve->setText(QApplication::translate("ReportDetail", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\234\254\345\221\250\351\201\207\345\210\260\347\232\204\351\227\256\351\242\230</span></p></body></html>", Q_NULLPTR));
        LQuestionForSolved->setText(QApplication::translate("ReportDetail", "<html><head/><body><p><span style=\" font-size:12pt;\">\350\247\243\345\206\263\346\226\271\346\263\225</span></p></body></html>", Q_NULLPTR));
        LQuestionFromLastWeek->setText(QApplication::translate("ReportDetail", "<html><head/><body><p><span style=\" font-size:12pt;\">\344\270\212\345\221\250\347\232\204\351\227\256\351\242\230</span></p></body></html>", Q_NULLPTR));
        LYourGet->setText(QApplication::translate("ReportDetail", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\255\246\344\271\240\345\277\203\345\276\227\344\270\216\344\275\223\344\274\232</span></p></body></html>", Q_NULLPTR));
        updateButton->setText(QApplication::translate("ReportDetail", "\344\277\256\346\224\271", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("ReportDetail", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportDetail: public Ui_ReportDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTDETAIL_H
