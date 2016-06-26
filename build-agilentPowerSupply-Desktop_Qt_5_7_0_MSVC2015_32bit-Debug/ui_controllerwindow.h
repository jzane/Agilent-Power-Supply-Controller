/********************************************************************************
** Form generated from reading UI file 'controllerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLERWINDOW_H
#define UI_CONTROLLERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControllerWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QFrame *line;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_8;
    QLabel *label_4;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QGridLayout *gridLayout_2;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_11;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ControllerWindow)
    {
        if (ControllerWindow->objectName().isEmpty())
            ControllerWindow->setObjectName(QStringLiteral("ControllerWindow"));
        ControllerWindow->resize(558, 466);
        centralWidget = new QWidget(ControllerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 50, 131, 41));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 11, 61, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(261, 11, 53, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(49, 380, 331, 16));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 10, 21, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 10, 181, 20));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 90, 341, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(40, 110, 91, 17));
        QFont font1;
        font1.setPointSize(10);
        radioButton->setFont(font1);
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(160, 110, 82, 17));
        radioButton_2->setFont(font1);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 150, 71, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 380, 33, 16));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 179, 360, 163));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);


        gridLayout->addLayout(verticalLayout, 0, 1, 2, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 2);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout_2->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        verticalLayout_2->addWidget(lineEdit_5);


        gridLayout_2->addLayout(verticalLayout_2, 0, 1, 2, 1);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 2, 0, 1, 2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFont(font);

        gridLayout_3->addWidget(pushButton_3, 2, 2, 1, 1);

        ControllerWindow->setCentralWidget(centralWidget);
        pushButton->raise();
        label->raise();
        label_2->raise();
        label_4->raise();
        label_5->raise();
        lineEdit->raise();
        label_3->raise();
        label_4->raise();
        label_6->raise();
        line->raise();
        lineEdit_2->raise();
        label_7->raise();
        lineEdit_3->raise();
        pushButton_2->raise();
        radioButton->raise();
        radioButton_2->raise();
        label_8->raise();
        pushButton_3->raise();
        label_9->raise();
        menuBar = new QMenuBar(ControllerWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 558, 21));
        ControllerWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ControllerWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ControllerWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ControllerWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ControllerWindow->setStatusBar(statusBar);

        retranslateUi(ControllerWindow);

        QMetaObject::connectSlotsByName(ControllerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ControllerWindow)
    {
        ControllerWindow->setWindowTitle(QApplication::translate("ControllerWindow", "Agilent Power Supply Controller v0.0.0", 0));
        pushButton->setText(QApplication::translate("ControllerWindow", "connect!", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("ControllerWindow", "Device ID: ", 0));
        label_5->setText(QString());
        label_3->setText(QApplication::translate("ControllerWindow", "Connect to device through com port:", 0));
        radioButton->setText(QApplication::translate("ControllerWindow", "Output ON", 0));
        radioButton_2->setText(QApplication::translate("ControllerWindow", "Output Off", 0));
        label_8->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:12pt; text-decoration: underline;\">Output 1</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("ControllerWindow", "Errors:", 0));
        label_6->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:12pt; text-decoration: underline;\">Current Limit (</span><span style=\" font-size:12pt; font-weight:600; text-decoration: underline;\">A</span><span style=\" font-size:12pt; text-decoration: underline;\">)</span><span style=\" font-size:12pt; text-decoration: underline;\">:</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:12pt; text-decoration: underline;\">Voltage (</span><span style=\" font-size:12pt; font-weight:600; text-decoration: underline;\">V</span><span style=\" font-size:12pt; text-decoration: underline;\">):</span></p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("ControllerWindow", "\n"
"Set!\n"
"", 0));
        label_9->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:12pt; text-decoration: underline;\">Output 2</span></p></body></html>", 0));
        label_10->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:12pt; text-decoration: underline;\">Current Limit (</span><span style=\" font-size:12pt; font-weight:600; text-decoration: underline;\">A</span><span style=\" font-size:12pt; text-decoration: underline;\">)</span><span style=\" font-size:12pt; text-decoration: underline;\">:</span></p></body></html>", 0));
        label_11->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:12pt; text-decoration: underline;\">Voltage (</span><span style=\" font-size:12pt; font-weight:600; text-decoration: underline;\">V</span><span style=\" font-size:12pt; text-decoration: underline;\">):</span></p></body></html>", 0));
        pushButton_3->setText(QApplication::translate("ControllerWindow", "\n"
"Set!\n"
"", 0));
    } // retranslateUi

};

namespace Ui {
    class ControllerWindow: public Ui_ControllerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLERWINDOW_H
