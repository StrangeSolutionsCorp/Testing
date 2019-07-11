#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "result.h"
#include "func.h"
#include "badres.h"
#include "fstream"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: on_minus_sugar_clicked()
{
    double count;
    QString label;
    count = (ui->sugar_count->text()).toDouble();
    if (count >= 1)
        count--;
    label = QString::number(count);
    ui->sugar_count->setText(label);
}

void MainWindow::on_plus_sugar_clicked()
{
    double count;
    QString label;
    count = (ui->sugar_count->text()).toDouble();
    if (count <= 9)
        count++;
    label = QString::number(count);
    ui->sugar_count->setText(label);
}

void MainWindow::on_pushButton_3_clicked()
{
    double sugar_count;
    bool sugar;
    double milk_count;
    bool milk;
    double choco_count;
    bool choco;
    double tung_count;
    double size;
    bool func_res;
    bool serv;
    QString type;
    QString result;
    sugar_count = (ui->sugar_count->text()).toDouble();
    if (sugar_count == 0)
            sugar = false;
            else
            sugar = true;
    milk_count = (ui->milk_count->text()).toDouble();
    if (milk_count == 0)
            milk = false;
            else
            milk = true;
    choco_count = (ui->choco_count->text()).toDouble();
    if (choco_count == 0)
            choco = false;
            else
            choco = true;
    tung_count = (ui->tung_count->text()).toDouble();

    if (ui->radioButton->isChecked())
        type = ui->radioButton->text();
    if (ui->radioButton_2->isChecked())
        type = ui->radioButton_2->text();
    if (ui->radioButton_3->isChecked())
        type = ui->radioButton_3->text();
    if (ui->radioButton_4->isChecked())
        type = ui->radioButton_4->text();
    if (ui->radioButton_5->isChecked())
        type = ui->radioButton_5->text();
    if (ui->radioButton_6->isChecked())
        size = 1;
    if (ui->radioButton_7->isChecked())
        size = 2;
    if (ui->radioButton_8->isChecked())
        size = 3;
    if (ui->checkBox->isChecked())
        serv=true;

    func_res = Func(type, tung_count,milk, milk_count, choco, choco_count, sugar, sugar_count, serv, size);
    if (func_res == false)
        result = "False";
    else
        result = "True";
    fstream log("serviceLog.txt", ios::in | ios::out | ios::app);
    log << type.toStdString() << ", " << tung_count<< ", " << milk << ", " << milk_count << ", " << choco << ", " << choco_count << ", " << sugar << ", " << sugar_count << ", " << serv << ", " << size << ": " << result.toStdString() << "\n\n";
    log.close();
    if (func_res == true)
        QMessageBox::information(this," ", "Cofee is ready");
    else
        QMessageBox::information(this," ", "Cofee is broken");


}

void MainWindow::on_plus_milk_clicked()
{
    double count;
    QString label;
    count = (ui->milk_count->text()).toDouble();
    if (count <= 9)
        count++;
    label = QString::number(count);
    ui->milk_count->setText(label);
}



void MainWindow::on_minus_milk_clicked()
{
    double count;
    QString label;
    count = (ui->milk_count->text()).toDouble();
    if (count >= 1)
      count--;
    label = QString::number(count);
    ui->milk_count->setText(label);

}

void MainWindow::on_minus_choco_clicked()
{
    double count;
    QString label;
    count = (ui->choco_count->text()).toDouble();
    if (count >= 1)
      count--;
    label = QString::number(count);
    ui->choco_count->setText(label);
}

void MainWindow::on_plus_choco_clicked()
{
    double count;
    QString label;
    count = (ui->choco_count->text()).toDouble();
    if (count <= 9)
      count++;
    label = QString::number(count);
    ui->choco_count->setText(label);
}

void MainWindow::on_plus_tung_clicked()
{
    double count;
    QString label;
    count = (ui->tung_count->text()).toDouble();
    if (count <= 9)
      count++;
    label = QString::number(count);
    ui->tung_count->setText(label);
}

void MainWindow::on_minus_tung_clicked()
{
    double count;
    QString label;
    count = (ui->tung_count->text()).toDouble();
    if (count >= 1)
      count--;
    label = QString::number(count);
    ui->tung_count->setText(label);
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}
