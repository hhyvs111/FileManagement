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
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *LTeacher;
    QLabel *LNumber;
    QLineEdit *reportTeacher;
    QComboBox *reportWeek;
    QLineEdit *reportName;
    QComboBox *reportTerm;
    QLabel *LName;
    QLabel *LWeek;
    QLabel *LLevel;
    QLineEdit *reportNumber;
    QLineEdit *reportLevel;
    QLabel *LTerm;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QLabel *LMain;
    QPlainTextEdit *reportMainPlainTextEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *LQuestionForSolve;
    QPlainTextEdit *reportQuestionForSolve;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *reportQuestionHasSolved;
    QPlainTextEdit *reportQuestionFromLastWeek;
    QLabel *LQuestionFromLastWeek;
    QLabel *LQuestionForSolved;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *LYourGet;
    QPlainTextEdit *reportYourGet;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *resetButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *submitButton;

    void setupUi(QWidget *ReportEdit)
    {
        if (ReportEdit->objectName().isEmpty())
            ReportEdit->setObjectName(QStringLiteral("ReportEdit"));
        ReportEdit->resize(639, 718);
        verticalLayout_4 = new QVBoxLayout(ReportEdit);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(13, 13, 13, 13);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        LTeacher = new QLabel(ReportEdit);
        LTeacher->setObjectName(QStringLiteral("LTeacher"));

        gridLayout_3->addWidget(LTeacher, 1, 3, 1, 1);

        LNumber = new QLabel(ReportEdit);
        LNumber->setObjectName(QStringLiteral("LNumber"));

        gridLayout_3->addWidget(LNumber, 0, 3, 1, 1);

        reportTeacher = new QLineEdit(ReportEdit);
        reportTeacher->setObjectName(QStringLiteral("reportTeacher"));

        gridLayout_3->addWidget(reportTeacher, 1, 6, 1, 1);

        reportWeek = new QComboBox(ReportEdit);
        reportWeek->setObjectName(QStringLiteral("reportWeek"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(reportWeek->sizePolicy().hasHeightForWidth());
        reportWeek->setSizePolicy(sizePolicy);
        reportWeek->setStyleSheet(QStringLiteral(""));
        reportWeek->setMaxVisibleItems(8);
        reportWeek->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        reportWeek->setMinimumContentsLength(15);
        reportWeek->setIconSize(QSize(70, 24));

        gridLayout_3->addWidget(reportWeek, 2, 6, 1, 1);

        reportName = new QLineEdit(ReportEdit);
        reportName->setObjectName(QStringLiteral("reportName"));
        reportName->setStyleSheet(QString::fromUtf8("background-color: rgba(255,240,255,120);\n"
"focus background-color: rgb(255,255,255)\357\274\233\n"
""));

        gridLayout_3->addWidget(reportName, 0, 1, 1, 1);

        reportTerm = new QComboBox(ReportEdit);
        reportTerm->setObjectName(QStringLiteral("reportTerm"));
        sizePolicy.setHeightForWidth(reportTerm->sizePolicy().hasHeightForWidth());
        reportTerm->setSizePolicy(sizePolicy);
        reportTerm->setCursor(QCursor(Qt::ArrowCursor));
        reportTerm->setStyleSheet(QLatin1String(" border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px; \n"
"    min-width: 10em; \n"
" subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 50px;\n"
" \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;"));
        reportTerm->setMaxVisibleItems(8);
        reportTerm->setIconSize(QSize(60, 30));

        gridLayout_3->addWidget(reportTerm, 2, 1, 1, 1);

        LName = new QLabel(ReportEdit);
        LName->setObjectName(QStringLiteral("LName"));

        gridLayout_3->addWidget(LName, 0, 0, 1, 1);

        LWeek = new QLabel(ReportEdit);
        LWeek->setObjectName(QStringLiteral("LWeek"));

        gridLayout_3->addWidget(LWeek, 2, 3, 1, 1);

        LLevel = new QLabel(ReportEdit);
        LLevel->setObjectName(QStringLiteral("LLevel"));

        gridLayout_3->addWidget(LLevel, 1, 0, 1, 1);

        reportNumber = new QLineEdit(ReportEdit);
        reportNumber->setObjectName(QStringLiteral("reportNumber"));
        reportNumber->setStyleSheet(QStringLiteral(""));

        gridLayout_3->addWidget(reportNumber, 0, 6, 1, 1);

        reportLevel = new QLineEdit(ReportEdit);
        reportLevel->setObjectName(QStringLiteral("reportLevel"));

        gridLayout_3->addWidget(reportLevel, 1, 1, 1, 1);

        LTerm = new QLabel(ReportEdit);
        LTerm->setObjectName(QStringLiteral("LTerm"));

        gridLayout_3->addWidget(LTerm, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 2, 2, 1, 1);


        verticalLayout_4->addLayout(gridLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        LMain = new QLabel(ReportEdit);
        LMain->setObjectName(QStringLiteral("LMain"));
        LMain->setStyleSheet(QStringLiteral("background-color: rgb(192,192, 192);"));

        verticalLayout->addWidget(LMain);

        reportMainPlainTextEdit = new QPlainTextEdit(ReportEdit);
        reportMainPlainTextEdit->setObjectName(QStringLiteral("reportMainPlainTextEdit"));

        verticalLayout->addWidget(reportMainPlainTextEdit);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        LQuestionForSolve = new QLabel(ReportEdit);
        LQuestionForSolve->setObjectName(QStringLiteral("LQuestionForSolve"));
        LQuestionForSolve->setStyleSheet(QStringLiteral("background-color: rgb(192,192, 192);"));

        verticalLayout_2->addWidget(LQuestionForSolve);

        reportQuestionForSolve = new QPlainTextEdit(ReportEdit);
        reportQuestionForSolve->setObjectName(QStringLiteral("reportQuestionForSolve"));

        verticalLayout_2->addWidget(reportQuestionForSolve);


        verticalLayout_4->addLayout(verticalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        reportQuestionHasSolved = new QPlainTextEdit(ReportEdit);
        reportQuestionHasSolved->setObjectName(QStringLiteral("reportQuestionHasSolved"));

        gridLayout_2->addWidget(reportQuestionHasSolved, 1, 2, 1, 1);

        reportQuestionFromLastWeek = new QPlainTextEdit(ReportEdit);
        reportQuestionFromLastWeek->setObjectName(QStringLiteral("reportQuestionFromLastWeek"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(reportQuestionFromLastWeek->sizePolicy().hasHeightForWidth());
        reportQuestionFromLastWeek->setSizePolicy(sizePolicy1);
        reportQuestionFromLastWeek->setMinimumSize(QSize(200, 0));

        gridLayout_2->addWidget(reportQuestionFromLastWeek, 1, 0, 1, 1);

        LQuestionFromLastWeek = new QLabel(ReportEdit);
        LQuestionFromLastWeek->setObjectName(QStringLiteral("LQuestionFromLastWeek"));
        LQuestionFromLastWeek->setStyleSheet(QStringLiteral("background-color: rgb(192,192, 192);"));

        gridLayout_2->addWidget(LQuestionFromLastWeek, 0, 0, 1, 1);

        LQuestionForSolved = new QLabel(ReportEdit);
        LQuestionForSolved->setObjectName(QStringLiteral("LQuestionForSolved"));
        LQuestionForSolved->setStyleSheet(QStringLiteral("background-color: rgb(192,192, 192);"));

        gridLayout_2->addWidget(LQuestionForSolved, 0, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(42, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        LYourGet = new QLabel(ReportEdit);
        LYourGet->setObjectName(QStringLiteral("LYourGet"));
        LYourGet->setStyleSheet(QLatin1String("background-color: rgb(85, 170, 255);\n"
""));

        verticalLayout_3->addWidget(LYourGet);

        reportYourGet = new QPlainTextEdit(ReportEdit);
        reportYourGet->setObjectName(QStringLiteral("reportYourGet"));

        verticalLayout_3->addWidget(reportYourGet);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        resetButton = new QPushButton(ReportEdit);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setStyleSheet(QLatin1String(" background:transparent;\n"
"border:1px solid rgb(89, 153, 48);\n"
"border-radius:10px;\n"
"padding:10px 12px;\n"
"color: blue;"));

        horizontalLayout_4->addWidget(resetButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        submitButton = new QPushButton(ReportEdit);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setStyleSheet(QLatin1String(" background:transparent;\n"
"border:1px solid rgb(89, 153, 48);\n"
"border-radius:10px;\n"
"padding:10px 12px;\n"
"color: blue;"));

        horizontalLayout_4->addWidget(submitButton);


        verticalLayout_4->addLayout(horizontalLayout_4);


        retranslateUi(ReportEdit);
        QObject::connect(submitButton, SIGNAL(clicked()), ReportEdit, SLOT(ClickSubmit()));

        QMetaObject::connectSlotsByName(ReportEdit);
    } // setupUi

    void retranslateUi(QWidget *ReportEdit)
    {
        ReportEdit->setWindowTitle(QApplication::translate("ReportEdit", "Form", Q_NULLPTR));
        LTeacher->setText(QApplication::translate("ReportEdit", "\345\257\274\345\270\210", Q_NULLPTR));
        LNumber->setText(QApplication::translate("ReportEdit", "\345\255\246\345\217\267", Q_NULLPTR));
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
        reportTerm->clear();
        reportTerm->insertItems(0, QStringList()
         << QApplication::translate("ReportEdit", "\347\240\224\344\270\200\344\270\212", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "\347\240\224\344\270\200\344\270\213", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "\347\240\224\344\272\214\344\270\212", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "\347\240\224\344\272\214\344\270\213", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "\347\240\224\344\270\211\344\270\212", Q_NULLPTR)
         << QApplication::translate("ReportEdit", "\347\240\224\344\270\211\344\270\213", Q_NULLPTR)
        );
        LName->setText(QApplication::translate("ReportEdit", "\345\247\223\345\220\215", Q_NULLPTR));
        LWeek->setText(QApplication::translate("ReportEdit", "\345\221\250\346\225\260", Q_NULLPTR));
        LLevel->setText(QApplication::translate("ReportEdit", "\345\271\264\347\272\247", Q_NULLPTR));
        LTerm->setText(QApplication::translate("ReportEdit", "\345\255\246\346\234\237", Q_NULLPTR));
        LMain->setText(QApplication::translate("ReportEdit", " \346\234\254\345\221\250\345\255\246\344\271\240\345\206\205\345\256\271", Q_NULLPTR));
        LQuestionForSolve->setText(QApplication::translate("ReportEdit", " \346\234\254\345\221\250\351\201\207\345\210\260\347\232\204\351\227\256\351\242\230", Q_NULLPTR));
        LQuestionFromLastWeek->setText(QApplication::translate("ReportEdit", " \344\270\212\345\221\250\347\232\204\351\227\256\351\242\230", Q_NULLPTR));
        LQuestionForSolved->setText(QApplication::translate("ReportEdit", " \350\247\243\345\206\263\346\226\271\346\263\225", Q_NULLPTR));
        LYourGet->setText(QApplication::translate("ReportEdit", " \345\255\246\344\271\240\345\277\203\345\276\227\344\270\216\344\275\223\344\274\232", Q_NULLPTR));
        resetButton->setText(QApplication::translate("ReportEdit", "\351\207\215\347\275\256", Q_NULLPTR));
        submitButton->setText(QApplication::translate("ReportEdit", "\346\217\220\344\272\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReportEdit: public Ui_ReportEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTEDIT_H
