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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
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
    QLabel *label_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_2;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QWidget *tab_2;
    QPushButton *pushButton_3;
    QLabel *label_13;
    QLineEdit *lineEdit_7;
    QLabel *label_14;
    QPushButton *pushButton_4;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ControllerWindow)
    {
        if (ControllerWindow->objectName().isEmpty())
            ControllerWindow->setObjectName(QStringLiteral("ControllerWindow"));
        ControllerWindow->resize(700, 473);
        centralWidget = new QWidget(ControllerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 50, 131, 41));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 11, 61, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(261, 11, 53, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(59, 390, 331, 16));
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
        radioButton->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(160, 110, 82, 17));
        radioButton_2->setFont(font1);
        radioButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 390, 33, 16));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 160, 631, 201));
        tabWidget->setAutoFillBackground(true);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(24, 24));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(327, 70, 75, 51));
        pushButton_2->setFont(font);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 40, 71, 21));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(51, 71, 128, 19));
        label_6->setTextFormat(Qt::AutoText);
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(51, 98, 87, 19));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(186, 72, 133, 20));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(186, 98, 133, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(320, 20, 91, 41));
        pushButton_3->setFont(font);
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(410, 150, 201, 16));
        lineEdit_7 = new QLineEdit(tab_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(430, 50, 133, 20));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(430, 20, 128, 21));
        label_14->setTextFormat(Qt::AutoText);
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(320, 70, 91, 41));
        pushButton_4->setFont(font);
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setCheckable(false);
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 21, 116, 16));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 71, 111, 16));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 125, 80, 16));
        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(130, 130, 133, 20));
        lineEdit_5 = new QLineEdit(tab_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(130, 70, 133, 20));
        lineEdit_4 = new QLineEdit(tab_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(132, 21, 133, 20));
        tabWidget->addTab(tab_2, QString());
        ControllerWindow->setCentralWidget(centralWidget);
        pushButton->raise();
        label->raise();
        label_2->raise();
        label_5->raise();
        lineEdit->raise();
        label_3->raise();
        label_4->raise();
        line->raise();
        radioButton->raise();
        radioButton_2->raise();
        tabWidget->raise();
        menuBar = new QMenuBar(ControllerWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 21));
        ControllerWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ControllerWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ControllerWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ControllerWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ControllerWindow->setStatusBar(statusBar);

        retranslateUi(ControllerWindow);

        tabWidget->setCurrentIndex(1);


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
        label_4->setText(QApplication::translate("ControllerWindow", "Errors:", 0));
        pushButton_2->setText(QApplication::translate("ControllerWindow", "\n"
"Set!\n"
"", 0));
        label_8->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:12pt; text-decoration: underline;\">Output 1</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:12pt; text-decoration: underline;\">Current Limit (</span><span style=\" font-size:12pt; font-weight:600; text-decoration: underline;\">A</span><span style=\" font-size:12pt; text-decoration: underline;\">)</span><span style=\" font-size:12pt; text-decoration: underline;\">:</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:12pt; text-decoration: underline;\">Voltage (</span><span style=\" font-size:12pt; font-weight:600; text-decoration: underline;\">V</span><span style=\" font-size:12pt; text-decoration: underline;\">):</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ControllerWindow", "Manual Control", 0));
        pushButton_3->setText(QApplication::translate("ControllerWindow", "Start", 0));
        label_13->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:10pt; text-decoration: underline;\">Note</span><span style=\" font-size:10pt;\">: Maximum slope is 1.4 </span><span style=\" font-size:10pt; font-weight:600;\">V/S</span></p></body></html>", 0));
        label_14->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:12pt; text-decoration: underline;\">Current Limit (</span><span style=\" font-size:12pt; font-weight:600; text-decoration: underline;\">A</span><span style=\" font-size:12pt; text-decoration: underline;\">)</span><span style=\" font-size:12pt; text-decoration: underline;\">:</span></p></body></html>", 0));
        pushButton_4->setText(QApplication::translate("ControllerWindow", "Stop/Reset", 0));
        label_9->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">starting voltage (</span><span style=\" font-size:10pt; font-weight:600;\">V</span><span style=\" font-size:10pt;\">):</span></p></body></html>", 0));
        label_10->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Ending voltage (</span><span style=\" font-size:10pt; font-weight:600;\">V</span><span style=\" font-size:10pt;\">):</span></p></body></html>", 0));
        label_11->setText(QApplication::translate("ControllerWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Rise time (</span><span style=\" font-size:10pt; font-weight:600;\">S</span><span style=\" font-size:10pt;\">):</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ControllerWindow", "Voltage Ramp", 0));
    } // retranslateUi

};

namespace Ui {
    class ControllerWindow: public Ui_ControllerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLERWINDOW_H
