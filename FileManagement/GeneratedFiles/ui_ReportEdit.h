/********************************************************************************
** Form generated from reading UI file 'ReportEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTEDIT_H
#define UI_REPORTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportEdit
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *LName;
    QLineEdit *reportName;
    QSpacerItem *horizontalSpacer_2;
    QLabel *LNumber;
    QLineEdit *reportNumber;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LLevel;
    QLineEdit *reportLevel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *LTeacher;
    QLineEdit *reportTeacher;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *LTerm;
    QComboBox *reportTerm;
    QLabel *LWeek;
    QComboBox *reportWeek;
    QSpacerItem *horizontalSpacer_9;
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
    QPushButton *resetButton;
    QPushButton *submitButton;

    void setupUi(QWidget *ReportEdit)
    {
        if (ReportEdit->objectName().isEmpty())
            ReportEdit->setObjectName(QStringLiteral("ReportEdit"));
        ReportEdit->resize(651, 511);
        verticalLayout_3 = new QVBoxLayout(ReportEdit);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        LName = new QLabel(ReportEdit);
        LName->setObjectName(QStringLiteral("LName"));

        horizontalLayout->addWidget(LName);

        reportName = new QLineEdit(ReportEdit);
        reportName->setObjectName(QStringLiteral("reportName"));

        horizontalLayout->addWidget(reportName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        LNumber = new QLabel(ReportEdit);
        LNumber->setObjectName(QStringLiteral("LNumber"));

        horizontalLayout->addWidget(LNumber);

        reportNumber = new QLineEdit(ReportEdit);
        reportNumber->setObjectName(QStringLiteral("reportNumber"));

        horizontalLayout->addWidget(reportNumber);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        LLevel = new QLabel(ReportEdit);
        LLevel->setObjectName(QStringLiteral("LLevel"));

        horizontalLayout_2->addWidget(LLevel);

        reportLevel = new QLineEdit(ReportEdit);
        reportLevel->setObjectName(QStringLiteral("reportLevel"));

        horizontalLayout_2->addWidget(reportLevel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        LTeacher = new QLabel(ReportEdit);
        LTeacher->setObjectName(QStringLiteral("LTeacher"));

        horizontalLayout_2->addWidget(LTeacher);

        reportTeacher = new QLineEdit(ReportEdit);
        reportTeacher->setObjectName(QStringLiteral("reportTeacher"));

        horizontalLayout_2->addWidget(reportTeacher);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        LTerm = new QLabel(ReportEdit);
        LTerm->setObjectName(QStringLiteral("LTerm"));

        horizontalLayout_3->addWidget(LTerm);

        reportTerm = new QComboBox(ReportEdit);
        reportTerm->setObjectName(QStringLiteral("reportTerm"));
        reportTerm->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout_3->addWidget(reportTerm);

        LWeek = new QLabel(ReportEdit);
        LWeek->setObjectName(QStringLiteral("LWeek"));

        horizontalLayout_3->addWidget(LWeek);

        reportWeek = new QComboBox(ReportEdit);
        reportWeek->setObjectName(QStringLiteral("reportWeek"));

        horizontalLayout_3->addWidget(reportWeek);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        LMain = new QLabel(ReportEdit);
        LMain->setObjectName(QStringLiteral("LMain"));

        verticalLayout->addWidget(LMain);

        reportMainPlainTextEdit = new QPlainTextEdit(ReportEdit);
        reportMainPlainTextEdit->setObjectName(QStringLiteral("reportMainPlainTextEdit"));

        verticalLayout->addWidget(reportMainPlainTextEdit);


        verticalLayout_3->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LQuestionForSolve = new QLabel(ReportEdit);
        LQuestionForSolve->setObjectName(QStringLiteral("LQuestionForSolve"));

        gridLayout->addWidget(LQuestionForSolve, 0, 0, 1, 1);

        reportQuestionForSolve = new QPlainTextEdit(ReportEdit);
        reportQuestionForSolve->setObjectName(QStringLiteral("reportQuestionForSolve"));

        gridLayout->addWidget(reportQuestionForSolve, 1, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        reportQuestionHasSolved = new QPlainTextEdit(ReportEdit);
        reportQuestionHasSolved->setObjectName(QStringLiteral("reportQuestionHasSolved"));

        gridLayout_2->addWidget(reportQuestionHasSolved, 1, 1, 1, 1);

        LQuestionForSolved = new QLabel(ReportEdit);
        LQuestionForSolved->setObjectName(QStringLiteral("LQuestionForSolved"));

        gridLayout_2->addWidget(LQuestionForSolved, 0, 1, 1, 1);

        LQuestionFromLastWeek = new QLabel(ReportEdit);
        LQuestionFromLastWeek->setObjectName(QStringLiteral("LQuestionFromLastWeek"));

        gridLayout_2->addWidget(LQuestionFromLastWeek, 0, 0, 1, 1);

        reportQuestionFromLastWeek = new QPlainTextEdit(ReportEdit);
        reportQuestionFromLastWeek->setObjectName(QStringLiteral("reportQuestionFromLastWeek"));

        gridLayout_2->addWidget(reportQuestionFromLastWeek, 1, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        LYourGet = new QLabel(ReportEdit);
        LYourGet->setObjectName(QStringLiteral("LYourGet"));

        verticalLayout_2->addWidget(LYourGet);

        reportYourGet = new QPlainTextEdit(ReportEdit);
        reportYourGet->setObjectName(QStringLiteral("reportYourGet"));

        verticalLayout_2->addWidget(reportYourGet);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        resetButton = new QPushButton(ReportEdit);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        horizontalLayout_4->addWidget(resetButton);

        submitButton = new QPushButton(ReportEdit);
        submitButton->setObjectName(QStringLiteral("submitButton"));

        horizontalLayout_4->addWidget(submitButton);


        verticalLayout_3->addLayout(horizontalLayout_4);


        retranslateUi(ReportEdit);
        QObject::connect(submitButton, SIGNAL(clicked()), ReportEdit, SLOT(ClickSubmit()));

        QMetaObject::connectSlotsByName(ReportEdit);
    } // setupUi

    void retranslateUi(QWidget *ReportEdit)
    {
        ReportEdit->setWindowTitle(QApplication::translate("ReportEdit", "Form", Q_NULLPTR));
        LName->setText(QApplication::translate("ReportEdit", "\345\247\223\345\220\215", Q_NULLPTR));
        LNumber->setText(QApplication::translate("ReportEdit", "\345\255\246\345\217\267", Q_NULLPTR));
        LLevel->setText(QApplication::translate("ReportEdit", "\345\271\264\347\272\247", Q_NULLPTR));
        LTeacher->setText(QApplication::translate("ReportEdit", "\345\257\274\345\270\210", Q_NULLPTR));
        LTerm->setText(QApplication::translate("ReportEdit", "\345\255\246\346\234\237", Q_NULLPTR));
        reportTerm->clear();
        reportTerm->insertItems(0, QStringList()
         << QApplication::translate("ReportEdit", "\347\240\224\344\270\200\344\270\212", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "\347\240\224\344\270\200\344\270\213", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "\347\240\224\344\272\214\344\270\212", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "\347\240\224\344\272\214\344\270\213", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "\347\240\224\344\270\211\344\270\212", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "\347\240\224\344\270\211\344\270\213", Q_NULLPTR)
        );
        LWeek->setText(QApplication::translate("ReportEdit", "\345\221\250\346\225\260", Q_NULLPTR));
        reportWeek->clear();
        reportWeek->insertItems(0, QStringList()
         << QApplication::translate("ReportEdit", "1", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "2", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "3", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "4", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "5", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "6", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "7", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "8", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "9", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "10", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "11", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "12", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "13", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "14", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "15", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "16", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "17", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "18", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "19", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "20", Q_NULLPTR)
        );
        LMain->setText(QApplication::translate("ReportEdit", "\346\234\254\345\221\250\345\255\246\344\271\240\345\206\205\345\256\271", Q_NULLPTR));
        LQuestionForSolve->setText(QApplication::translate("ReportEdit", "\346\234\254\345\221\250\351\201\207\345\210\260\347\232\204\351\227\256\351\242\230", Q_NULLPTR));
        LQuestionForSolved->setText(QApplication::translate("ReportEdit", "\350\247\243\345\206\263\346\226\271\346\263\225", Q_NULLPTR));
        LQuestionFromLastWeek->setText(QApplication::translate("ReportEdit", "\344\270\212\345\221\250\347\232\204\351\227\256\351\242\230", Q_NULLPTR));
        LYourGet->setText(QApplication::translate("ReportEdit", "\345\255\246\344\271\240\345\277\203\345\276\227\344\270\216\344\275\223\344\274\232", Q_NULLPTR));
        resetButton->setText(QApplication::translate("ReportEdit", "\351\207\215\347\275\256", Q_NULLPTR));
        submitButton->setText(QApplication::translate("ReportEdit", "\346\217\220\344\272\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportEdit: public Ui_ReportEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTEDIT_H
