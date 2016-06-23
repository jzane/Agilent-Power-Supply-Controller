#ifndef CONTROLLERWINDOW_H
#define CONTROLLERWINDOW_H
#include <visa.h>

#include <QMainWindow>

namespace Ui {
class ControllerWindow;
}

class ControllerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControllerWindow(QWidget *parent = 0);
    ~ControllerWindow();

private:
    Ui::ControllerWindow *ui;
};

#endif // CONTROLLERWINDOW_H
