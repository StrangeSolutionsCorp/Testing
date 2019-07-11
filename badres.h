#ifndef BADRES_H
#define BADRES_H

#include <QDialog>

namespace Ui {
class badres;
}

class badres : public QDialog
{
    Q_OBJECT

public:
    explicit badres(QWidget *parent = nullptr);
    ~badres();

private slots:
    void on_pushButton_clicked();

private:
    Ui::badres *ui;
};

#endif // BADRES_H
