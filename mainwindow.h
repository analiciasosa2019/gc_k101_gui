#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ventLoxBox_clicked();

    void on_ventFuelBox_clicked();

    void on_igniteBox_clicked();

    void on_MVCloseBox_clicked();

    void on_MVOpenBox_clicked();

    void uart_read();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
