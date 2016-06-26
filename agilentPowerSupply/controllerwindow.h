#ifndef CONTROLLERWINDOW_H
#define CONTROLLERWINDOW_H
#include <visa.h>
#include <time.h>

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
    void OpenPort();
    void ClosePort();
    void  CheckError(char* pMessage);
    void delay(clock_t wait);
    void SendSCPI(char*);


private slots:
    void on_pushButton_clicked();

private:
    Ui::ControllerWindow *ui;
};

#endif // CONTROLLERWINDOW_H
