/********************************************************************************
** Form generated from reading UI file 'Accounting.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTING_H
#define UI_ACCOUNTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Accounting
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *adas;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_13;
    QLabel *DateLabel_2;
    QSpacerItem *horizontalSpacer_14;
    QComboBox *TypeBox_2;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_15;
    QLabel *MoneyLabel_2;
    QLabel *BeizhuLabel_2;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *horizontalSpacer_18;
    QPlainTextEdit *remarks_2;
    QLabel *TypeLabel_2;
    QDateEdit *dateEdit_2;
    QLineEdit *oucomeNumber_2;
    QPushButton *SaveButton_2;
    QSpacerItem *verticalSpacer;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QLabel *DateLabel_3;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *horizontalSpacer_11;
    QLabel *TypeLabel_3;
    QSpacerItem *horizontalSpacer_12;
    QLabel *MoneyLabel_3;
    QLabel *BeizhuLabel_3;
    QComboBox *TypeBox_3;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *horizontalSpacer_23;
    QSpacerItem *horizontalSpacer_24;
    QDateEdit *incomeDate;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *horizontalSpacer_26;
    QPlainTextEdit *remarks_3;
    QLineEdit *incomeNumber;
    QPushButton *SaveButton_3;

    void setupUi(QWidget *Accounting)
    {
        if (Accounting->objectName().isEmpty())
            Accounting->setObjectName(QStringLiteral("Accounting"));
        Accounting->resize(641, 470);
        verticalLayout = new QVBoxLayout(Accounting);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(Accounting);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        adas = new QWidget();
        adas->setObjectName(QStringLiteral("adas"));
        verticalLayout_2 = new QVBoxLayout(adas);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_13, 3, 3, 1, 1);

        DateLabel_2 = new QLabel(adas);
        DateLabel_2->setObjectName(QStringLiteral("DateLabel_2"));
        DateLabel_2->setMinimumSize(QSize(0, 0));
        DateLabel_2->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(DateLabel_2, 2, 1, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_14, 1, 3, 1, 1);

        TypeBox_2 = new QComboBox(adas);
        TypeBox_2->setObjectName(QStringLiteral("TypeBox_2"));
        TypeBox_2->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(TypeBox_2, 0, 2, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_16, 3, 0, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_17, 2, 3, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_15, 1, 0, 1, 1);

        MoneyLabel_2 = new QLabel(adas);
        MoneyLabel_2->setObjectName(QStringLiteral("MoneyLabel_2"));
        MoneyLabel_2->setMinimumSize(QSize(0, 0));
        MoneyLabel_2->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(MoneyLabel_2, 1, 1, 1, 1);

        BeizhuLabel_2 = new QLabel(adas);
        BeizhuLabel_2->setObjectName(QStringLiteral("BeizhuLabel_2"));
        BeizhuLabel_2->setMinimumSize(QSize(0, 0));
        BeizhuLabel_2->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(BeizhuLabel_2, 3, 1, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(180, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_19, 0, 3, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_20, 2, 0, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_18, 0, 0, 1, 1);

        remarks_2 = new QPlainTextEdit(adas);
        remarks_2->setObjectName(QStringLiteral("remarks_2"));

        gridLayout_2->addWidget(remarks_2, 3, 2, 1, 1);

        TypeLabel_2 = new QLabel(adas);
        TypeLabel_2->setObjectName(QStringLiteral("TypeLabel_2"));
        TypeLabel_2->setMinimumSize(QSize(0, 0));
        TypeLabel_2->setMaximumSize(QSize(110, 16777215));

        gridLayout_2->addWidget(TypeLabel_2, 0, 1, 1, 1);

        dateEdit_2 = new QDateEdit(adas);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));

        gridLayout_2->addWidget(dateEdit_2, 2, 2, 1, 1);

        oucomeNumber_2 = new QLineEdit(adas);
        oucomeNumber_2->setObjectName(QStringLiteral("oucomeNumber_2"));

        gridLayout_2->addWidget(oucomeNumber_2, 1, 2, 1, 1);

        SaveButton_2 = new QPushButton(adas);
        SaveButton_2->setObjectName(QStringLiteral("SaveButton_2"));

        gridLayout_2->addWidget(SaveButton_2, 4, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(17, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(adas, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_3 = new QVBoxLayout(tab_4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        DateLabel_3 = new QLabel(tab_4);
        DateLabel_3->setObjectName(QStringLiteral("DateLabel_3"));
        DateLabel_3->setMinimumSize(QSize(0, 0));
        DateLabel_3->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(DateLabel_3, 2, 1, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(180, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_21, 0, 3, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_11, 3, 3, 1, 1);

        TypeLabel_3 = new QLabel(tab_4);
        TypeLabel_3->setObjectName(QStringLiteral("TypeLabel_3"));
        TypeLabel_3->setMinimumSize(QSize(0, 0));
        TypeLabel_3->setMaximumSize(QSize(110, 16777215));

        gridLayout_3->addWidget(TypeLabel_3, 0, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_12, 3, 0, 1, 1);

        MoneyLabel_3 = new QLabel(tab_4);
        MoneyLabel_3->setObjectName(QStringLiteral("MoneyLabel_3"));
        MoneyLabel_3->setMinimumSize(QSize(0, 0));
        MoneyLabel_3->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(MoneyLabel_3, 1, 1, 1, 1);

        BeizhuLabel_3 = new QLabel(tab_4);
        BeizhuLabel_3->setObjectName(QStringLiteral("BeizhuLabel_3"));
        BeizhuLabel_3->setMinimumSize(QSize(0, 0));
        BeizhuLabel_3->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(BeizhuLabel_3, 3, 1, 1, 1);

        TypeBox_3 = new QComboBox(tab_4);
        TypeBox_3->setObjectName(QStringLiteral("TypeBox_3"));
        TypeBox_3->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(TypeBox_3, 0, 2, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_22, 2, 0, 1, 1);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_23, 1, 3, 1, 1);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_24, 0, 0, 1, 1);

        incomeDate = new QDateEdit(tab_4);
        incomeDate->setObjectName(QStringLiteral("incomeDate"));

        gridLayout_3->addWidget(incomeDate, 2, 2, 1, 1);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_25, 1, 0, 1, 1);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_26, 2, 3, 1, 1);

        remarks_3 = new QPlainTextEdit(tab_4);
        remarks_3->setObjectName(QStringLiteral("remarks_3"));

        gridLayout_3->addWidget(remarks_3, 3, 2, 1, 1);

        incomeNumber = new QLineEdit(tab_4);
        incomeNumber->setObjectName(QStringLiteral("incomeNumber"));

        gridLayout_3->addWidget(incomeNumber, 1, 2, 1, 1);

        SaveButton_3 = new QPushButton(tab_4);
        SaveButton_3->setObjectName(QStringLiteral("SaveButton_3"));

        gridLayout_3->addWidget(SaveButton_3, 4, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(Accounting);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Accounting);
    } // setupUi

    void retranslateUi(QWidget *Accounting)
    {
        Accounting->setWindowTitle(QApplication::translate("Accounting", "Form", Q_NULLPTR));
        DateLabel_2->setText(QApplication::translate("Accounting", "   \346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        TypeBox_2->clear();
        TypeBox_2->insertItems(0, QStringList()
         << QApplication::translate("Accounting", "\346\227\245\345\270\270\347\224\250\345\223\201", Q_NULLPTR)
         << QApplication::translate("Accounting", "\345\212\236\345\205\254\347\224\250\345\223\201", Q_NULLPTR)
        );
        MoneyLabel_2->setText(QApplication::translate("Accounting", " \346\224\257\345\207\272\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        BeizhuLabel_2->setText(QApplication::translate("Accounting", "   \345\244\207\346\263\250\357\274\232", Q_NULLPTR));
        TypeLabel_2->setText(QApplication::translate("Accounting", " \346\224\257\345\207\272\347\261\273\345\210\253\357\274\232", Q_NULLPTR));
        SaveButton_2->setText(QApplication::translate("Accounting", "\344\277\235\345\255\230\350\256\260\345\275\225", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(adas), QApplication::translate("Accounting", "Tab 1", Q_NULLPTR));
        DateLabel_3->setText(QApplication::translate("Accounting", "   \346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        TypeLabel_3->setText(QApplication::translate("Accounting", " \346\224\266\345\205\245\347\261\273\345\210\253\357\274\232", Q_NULLPTR));
        MoneyLabel_3->setText(QApplication::translate("Accounting", " \346\224\266\345\205\245\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        BeizhuLabel_3->setText(QApplication::translate("Accounting", "   \345\244\207\346\263\250\357\274\232", Q_NULLPTR));
        TypeBox_3->clear();
        TypeBox_3->insertItems(0, QStringList()
         << QApplication::translate("Accounting", "\351\241\271\347\233\256\347\273\217\350\264\271", Q_NULLPTR)
         << QApplication::translate("Accounting", "\344\270\252\344\272\272\346\211\200\344\272\244", Q_NULLPTR)
        );
        SaveButton_3->setText(QApplication::translate("Accounting", "\344\277\235\345\255\230\350\256\260\345\275\225", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Accounting", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Accounting: public Ui_Accounting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTING_H
