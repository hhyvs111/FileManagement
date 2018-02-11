/********************************************************************************
** Form generated from reading UI file 'Register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QLabel *userMessage;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *userName;
    QLabel *userLogo;
    QSpacerItem *horizontalSpacer_10;
    QGridLayout *gridLayout_2;
    QLabel *passwordMessage;
    QSpacerItem *horizontalSpacer_11;
    QLineEdit *userPassword;
    QLabel *passLogo;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout_3;
    QLabel *passwordMessage2;
    QSpacerItem *horizontalSpacer_12;
    QLineEdit *userPassword2;
    QLabel *passLogo2;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_13;
    QLabel *trueNameLogo;
    QLineEdit *trueName;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_3;
    QLabel *teacherLogo;
    QLineEdit *teacher;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_4;
    QComboBox *level;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_5;
    QComboBox *term;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_18;
    QRadioButton *radioButton;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *clickCancel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *clickRegister;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(335, 491);
        verticalLayout = new QVBoxLayout(Register);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_20);

        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        userMessage = new QLabel(Register);
        userMessage->setObjectName(QStringLiteral("userMessage"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(userMessage->sizePolicy().hasHeightForWidth());
        userMessage->setSizePolicy(sizePolicy);
        userMessage->setMinimumSize(QSize(0, 15));

        gridLayout->addWidget(userMessage, 1, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 0, 0, 1, 1);

        userName = new QLineEdit(Register);
        userName->setObjectName(QStringLiteral("userName"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(userName->sizePolicy().hasHeightForWidth());
        userName->setSizePolicy(sizePolicy1);
        userName->setMinimumSize(QSize(220, 25));
        userName->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(userName, 0, 1, 1, 1);

        userLogo = new QLabel(Register);
        userLogo->setObjectName(QStringLiteral("userLogo"));

        gridLayout->addWidget(userLogo, 0, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        passwordMessage = new QLabel(Register);
        passwordMessage->setObjectName(QStringLiteral("passwordMessage"));
        sizePolicy.setHeightForWidth(passwordMessage->sizePolicy().hasHeightForWidth());
        passwordMessage->setSizePolicy(sizePolicy);
        passwordMessage->setMinimumSize(QSize(0, 15));

        gridLayout_2->addWidget(passwordMessage, 1, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_11, 0, 0, 1, 1);

        userPassword = new QLineEdit(Register);
        userPassword->setObjectName(QStringLiteral("userPassword"));
        sizePolicy1.setHeightForWidth(userPassword->sizePolicy().hasHeightForWidth());
        userPassword->setSizePolicy(sizePolicy1);
        userPassword->setMinimumSize(QSize(220, 25));
        userPassword->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(userPassword, 0, 1, 1, 1);

        passLogo = new QLabel(Register);
        passLogo->setObjectName(QStringLiteral("passLogo"));

        gridLayout_2->addWidget(passLogo, 0, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        passwordMessage2 = new QLabel(Register);
        passwordMessage2->setObjectName(QStringLiteral("passwordMessage2"));
        sizePolicy.setHeightForWidth(passwordMessage2->sizePolicy().hasHeightForWidth());
        passwordMessage2->setSizePolicy(sizePolicy);
        passwordMessage2->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(passwordMessage2, 1, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_12, 0, 0, 1, 1);

        userPassword2 = new QLineEdit(Register);
        userPassword2->setObjectName(QStringLiteral("userPassword2"));
        sizePolicy1.setHeightForWidth(userPassword2->sizePolicy().hasHeightForWidth());
        userPassword2->setSizePolicy(sizePolicy1);
        userPassword2->setMinimumSize(QSize(220, 25));
        userPassword2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(userPassword2, 0, 1, 1, 1);

        passLogo2 = new QLabel(Register);
        passLogo2->setObjectName(QStringLiteral("passLogo2"));

        gridLayout_3->addWidget(passLogo2, 0, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_13, 0, 0, 1, 1);

        trueNameLogo = new QLabel(Register);
        trueNameLogo->setObjectName(QStringLiteral("trueNameLogo"));

        gridLayout_4->addWidget(trueNameLogo, 0, 2, 1, 1);

        trueName = new QLineEdit(Register);
        trueName->setObjectName(QStringLiteral("trueName"));
        sizePolicy1.setHeightForWidth(trueName->sizePolicy().hasHeightForWidth());
        trueName->setSizePolicy(sizePolicy1);
        trueName->setMinimumSize(QSize(220, 25));

        gridLayout_4->addWidget(trueName, 0, 1, 1, 1);

        label_2 = new QLabel(Register);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 15));

        gridLayout_4->addWidget(label_2, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_14, 0, 0, 1, 1);

        label_3 = new QLabel(Register);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(0, 15));

        gridLayout_5->addWidget(label_3, 1, 1, 1, 1);

        teacherLogo = new QLabel(Register);
        teacherLogo->setObjectName(QStringLiteral("teacherLogo"));

        gridLayout_5->addWidget(teacherLogo, 0, 2, 1, 1);

        teacher = new QLineEdit(Register);
        teacher->setObjectName(QStringLiteral("teacher"));
        sizePolicy1.setHeightForWidth(teacher->sizePolicy().hasHeightForWidth());
        teacher->setSizePolicy(sizePolicy1);
        teacher->setMinimumSize(QSize(220, 25));

        gridLayout_5->addWidget(teacher, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_15);

        label_4 = new QLabel(Register);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_8->addWidget(label_4);

        level = new QComboBox(Register);
        level->setObjectName(QStringLiteral("level"));

        horizontalLayout_8->addWidget(level);

        horizontalSpacer_16 = new QSpacerItem(22, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_16);

        label_5 = new QLabel(Register);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5);

        term = new QComboBox(Register);
        term->setObjectName(QStringLiteral("term"));

        horizontalLayout_8->addWidget(term);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_17);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_18);

        radioButton = new QRadioButton(Register);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_2->addWidget(radioButton);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_19);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        clickCancel = new QPushButton(Register);
        clickCancel->setObjectName(QStringLiteral("clickCancel"));
        clickCancel->setMaximumSize(QSize(16777215, 30));
        clickCancel->setStyleSheet(QLatin1String("background-color: rgb(188, 188, 255);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(clickCancel);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        clickRegister = new QPushButton(Register);
        clickRegister->setObjectName(QStringLiteral("clickRegister"));
        clickRegister->setMaximumSize(QSize(1000, 30));
        clickRegister->setStyleSheet(QLatin1String("background-color: rgb(85, 170, 255);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(clickRegister);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_5);

        QWidget::setTabOrder(userName, userPassword);
        QWidget::setTabOrder(userPassword, userPassword2);
        QWidget::setTabOrder(userPassword2, trueName);
        QWidget::setTabOrder(trueName, teacher);
        QWidget::setTabOrder(teacher, level);
        QWidget::setTabOrder(level, term);
        QWidget::setTabOrder(term, radioButton);
        QWidget::setTabOrder(radioButton, clickRegister);
        QWidget::setTabOrder(clickRegister, clickCancel);

        retranslateUi(Register);
        QObject::connect(clickRegister, SIGNAL(clicked()), Register, SLOT(Click_Register()));
        QObject::connect(clickCancel, SIGNAL(clicked()), Register, SLOT(Click_Cancel()));
        QObject::connect(userPassword, SIGNAL(editingFinished()), Register, SLOT(checkIsokPassword()));

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\263\250\345\206\214\347\225\214\351\235\242</span></p></body></html>", Q_NULLPTR));
        userMessage->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:9pt;\">* \344\270\215\345\217\257\344\275\277\347\224\250\344\270\255\346\226\207\357\274\214\344\270\200\347\273\217\346\263\250\345\206\214\344\270\215\345\217\257\344\277\256\346\224\271\343\200\202</span></p></body></html>", Q_NULLPTR));
        userLogo->setText(QApplication::translate("Register", "1", Q_NULLPTR));
        passwordMessage->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:9pt;\">* \347\254\254\344\270\200\344\275\215\345\255\227\347\254\246\345\277\205\351\241\273\346\230\257\345\255\227\346\257\215\357\274\214\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231\343\200\202</span></p></body></html>", Q_NULLPTR));
        passLogo->setText(QApplication::translate("Register", "1", Q_NULLPTR));
        passwordMessage2->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:9pt;\">* \347\241\256\350\256\244\345\257\206\347\240\201\344\273\245\351\230\262\345\207\272\351\224\231\343\200\202</span></p></body></html>", Q_NULLPTR));
        passLogo2->setText(QApplication::translate("Register", "1", Q_NULLPTR));
        trueNameLogo->setText(QApplication::translate("Register", "1", Q_NULLPTR));
        label_2->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:9pt;\">* \345\256\236\345\220\215\345\210\266\347\256\241\347\220\206\357\274\214\344\270\200\347\273\217\346\263\250\345\206\214\344\270\215\345\217\257\344\277\256\346\224\271\343\200\202</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:9pt;\">* \345\275\223\345\211\215\345\257\274\345\270\210\345\247\223\345\220\215\357\274\214\344\270\200\347\273\217\346\263\250\345\206\214\344\270\215\345\217\257\344\277\256\346\224\271\343\200\202</span></p></body></html>", Q_NULLPTR));
        teacherLogo->setText(QApplication::translate("Register", "1", Q_NULLPTR));
        label_4->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:9pt;\">\345\271\264\347\272\247\357\274\232</span></p></body></html>", Q_NULLPTR));
        level->clear();
        level->insertItems(0, QStringList()
         << QApplication::translate("Register", "\347\240\224\344\270\200", Q_NULLPTR)
         << QApplication::translate("Register", "\347\240\224\344\272\214", Q_NULLPTR)
         << QApplication::translate("Register", "\347\240\224\344\270\211", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:9pt;\">\345\255\246\346\234\237\357\274\232</span></p></body></html>", Q_NULLPTR));
        term->clear();
        term->insertItems(0, QStringList()
         << QApplication::translate("Register", "\344\270\212\345\255\246\346\234\237", Q_NULLPTR)
         << QApplication::translate("Register", "\344\270\213\345\255\246\346\234\237", Q_NULLPTR)
        );
        radioButton->setText(QApplication::translate("Register", "\345\220\214\346\204\217\345\256\236\351\252\214\345\256\244\347\256\241\347\220\206\350\246\201\346\261\202", Q_NULLPTR));
        clickCancel->setText(QApplication::translate("Register", "\345\217\226\346\266\210", Q_NULLPTR));
        clickRegister->setText(QApplication::translate("Register", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
