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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControllerWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ControllerWindow)
    {
        if (ControllerWindow->objectName().isEmpty())
            ControllerWindow->setObjectName(QStringLiteral("ControllerWindow"));
        ControllerWindow->resize(400, 300);
        menuBar = new QMenuBar(ControllerWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ControllerWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ControllerWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ControllerWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(ControllerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ControllerWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ControllerWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ControllerWindow->setStatusBar(statusBar);

        retranslateUi(ControllerWindow);

        QMetaObject::connectSlotsByName(ControllerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ControllerWindow)
    {
        ControllerWindow->setWindowTitle(QApplication::translate("ControllerWindow", "ControllerWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class ControllerWindow: public Ui_ControllerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLERWINDOW_H
