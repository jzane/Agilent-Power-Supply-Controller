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
    std::string ControllerWindow::to_string(double x); //convert double to string used in voltage ramping


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ControllerWindow *ui;
};

#endif // CONTROLLERWINDOW_H
