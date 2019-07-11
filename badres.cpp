#include "badres.h"
#include "ui_badres.h"

badres::badres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::badres)
{
    ui->setupUi(this);
}

badres::~badres()
{
    delete ui;
}

void badres::on_pushButton_clicked()
{
    this->close();
}
