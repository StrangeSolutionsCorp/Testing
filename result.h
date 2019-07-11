#ifndef RESULT_H
#define RESULT_H

#include <QDialog>

namespace Ui {
class result;
}

class result : public QDialog
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = nullptr);
    ~result();

private slots:
    void on_pushButton_clicked();

private:
    Ui::result *ui;
};

#endif // RESULT_H
