/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *MV_indicator;
    QPushButton *Ign_indicator;
    QPushButton *LV_indicator;
    QPushButton *FV_indicator;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLabel *label_2;
    QLabel *label_3;
    QLCDNumber *lcdNumber_3;
    QLabel *label_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QCheckBox *ventFuelBox;
    QCheckBox *ventLoxBox;
    QCheckBox *MVOpenBox;
    QCheckBox *MVCloseBox;
    QCheckBox *igniteBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(937, 647);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(767, 647));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background: black;\n"
"}\n"
"\n"
"QCheckBox:checked {\n"
"	color:#66ff00;\n"
"	border-color: #66ff00;\n"
";}\n"
"QCheckBox:unchecked {\n"
"	color:Red;\n"
"	border-color: red;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    image: null;\n"
"	width:0px;\n"
"	height:0px;\n"
"}\n"
"\n"
"QCheckBox {\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	alignment: center;\n"
"	padding: 15px;\n"
"}\n"
"\n"
"\n"
"QVBoxLayout {\n"
"	alignment: bottom;\n"
"	attachment: scroll;\n"
"}\n"
"\n"
"QPushButton {\n"
"color: black;\n"
"  border-width: 3px;        \n"
"  border-style: solid;\n"
"  border-radius: 25px;\n"
"	width:50;\n"
"	height:50;\n"
"\n"
"}\n"
"QPushButton:enabled {\n"
"	border-color: #66ff00;\n"
"	background: #66ff00\n"
"}\n"
"QPushButton:disabled {\n"
"	border-color: red;\n"
"	background: red\n"
"}\n"
"\n"
"QTextBrowser {\n"
"	image: url(:/images/Untitled.png)\n"
"}\n"
"\n"
"QLCDNumber {\n"
"color: red;\n"
"}\n"
"\n"
"QLabel {\n"
"color: red;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MV_indicator = new QPushButton(centralwidget);
        MV_indicator->setObjectName("MV_indicator");
        MV_indicator->setEnabled(false);
        MV_indicator->setGeometry(QRect(440, 470, 50, 50));
        QFont font;
        font.setPointSize(14);
        MV_indicator->setFont(font);
        Ign_indicator = new QPushButton(centralwidget);
        Ign_indicator->setObjectName("Ign_indicator");
        Ign_indicator->setEnabled(false);
        Ign_indicator->setGeometry(QRect(440, 540, 50, 50));
        Ign_indicator->setFont(font);
        LV_indicator = new QPushButton(centralwidget);
        LV_indicator->setObjectName("LV_indicator");
        LV_indicator->setEnabled(false);
        LV_indicator->setGeometry(QRect(380, 250, 50, 50));
        LV_indicator->setFont(font);
        FV_indicator = new QPushButton(centralwidget);
        FV_indicator->setObjectName("FV_indicator");
        FV_indicator->setEnabled(false);
        FV_indicator->setGeometry(QRect(500, 250, 50, 50));
        FV_indicator->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(660, 170, 258, 253));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(81, 20));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lcdNumber = new QLCDNumber(layoutWidget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setMinimumSize(QSize(171, 81));
        lcdNumber->setLineWidth(0);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(4);
        lcdNumber->setProperty("value", QVariant(11234.559999999999491));

        gridLayout->addWidget(lcdNumber, 0, 1, 1, 1);

        lcdNumber_2 = new QLCDNumber(layoutWidget);
        lcdNumber_2->setObjectName("lcdNumber_2");
        lcdNumber_2->setMinimumSize(QSize(171, 81));
        lcdNumber_2->setLineWidth(0);
        lcdNumber_2->setSmallDecimalPoint(false);
        lcdNumber_2->setDigitCount(4);
        lcdNumber_2->setProperty("value", QVariant(1234.559999999999945));

        gridLayout->addWidget(lcdNumber_2, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(37, 12));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(37, 12));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lcdNumber_3 = new QLCDNumber(layoutWidget);
        lcdNumber_3->setObjectName("lcdNumber_3");
        lcdNumber_3->setMinimumSize(QSize(171, 81));
        lcdNumber_3->setLineWidth(0);
        lcdNumber_3->setSmallDecimalPoint(false);
        lcdNumber_3->setDigitCount(4);
        lcdNumber_3->setProperty("value", QVariant(1234.559999999999945));

        gridLayout->addWidget(lcdNumber_3, 2, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(310, 30, 311, 561));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/images/Untitled.png);\n"
"color: red;"));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 171, 554));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ventFuelBox = new QCheckBox(layoutWidget1);
        ventFuelBox->setObjectName("ventFuelBox");
        QFont font1;
        font1.setPointSize(20);
        ventFuelBox->setFont(font1);

        verticalLayout->addWidget(ventFuelBox);

        ventLoxBox = new QCheckBox(layoutWidget1);
        ventLoxBox->setObjectName("ventLoxBox");
        ventLoxBox->setFont(font1);

        verticalLayout->addWidget(ventLoxBox);

        MVOpenBox = new QCheckBox(layoutWidget1);
        MVOpenBox->setObjectName("MVOpenBox");
        MVOpenBox->setFont(font1);
        MVOpenBox->setAutoExclusive(true);

        verticalLayout->addWidget(MVOpenBox);

        MVCloseBox = new QCheckBox(layoutWidget1);
        MVCloseBox->setObjectName("MVCloseBox");
        MVCloseBox->setEnabled(true);
        MVCloseBox->setFont(font1);
        MVCloseBox->setChecked(true);
        MVCloseBox->setAutoExclusive(true);

        verticalLayout->addWidget(MVCloseBox);

        igniteBox = new QCheckBox(layoutWidget1);
        igniteBox->setObjectName("igniteBox");
        igniteBox->setFont(font1);

        verticalLayout->addWidget(igniteBox);

        MainWindow->setCentralWidget(centralwidget);
        layoutWidget->raise();
        label_4->raise();
        MV_indicator->raise();
        Ign_indicator->raise();
        LV_indicator->raise();
        FV_indicator->raise();
        layoutWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 937, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        MV_indicator->setText(QCoreApplication::translate("MainWindow", "MV", nullptr));
        Ign_indicator->setText(QCoreApplication::translate("MainWindow", "Ign", nullptr));
        LV_indicator->setText(QCoreApplication::translate("MainWindow", "LV", nullptr));
        FV_indicator->setText(QCoreApplication::translate("MainWindow", "FV", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Fuel Pressure", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pneumatics", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Lox Pressure", nullptr));
        label_4->setText(QString());
        ventFuelBox->setText(QCoreApplication::translate("MainWindow", "Vent Fuel", nullptr));
        ventLoxBox->setText(QCoreApplication::translate("MainWindow", "Vent Lox", nullptr));
        MVOpenBox->setText(QCoreApplication::translate("MainWindow", "MV Open", nullptr));
        MVCloseBox->setText(QCoreApplication::translate("MainWindow", "MV Close", nullptr));
        igniteBox->setText(QCoreApplication::translate("MainWindow", "Ignite", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
