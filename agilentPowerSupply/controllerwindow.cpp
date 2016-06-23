#include "controllerwindow.h"
#include "ui_controllerwindow.h"

ControllerWindow::ControllerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControllerWindow)
{
    ui->setupUi(this);
}

ControllerWindow::~ControllerWindow()
{
    delete ui;
}
