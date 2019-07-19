#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <winsock2.h>
#include <iostream>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_minus_sugar_clicked();

    void on_plus_sugar_clicked();

    void on_pushButton_3_clicked();

    void on_plus_milk_clicked();

    void on_minus_milk_clicked();

    void on_minus_choco_clicked();

    void on_plus_choco_clicked();

    void on_plus_tung_clicked();

    void on_minus_tung_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
