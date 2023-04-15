#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include <iostream>
using namespace std;
namespace Ui {
class result;
}

class result : public QDialog
{
    Q_OBJECT

public:

    void setMessage(string message);

    explicit result(QWidget *parent = nullptr);
    ~result();

private slots:
    void on_pushButton_released();

private:
    Ui::result *ui;
};

#endif // RESULT_H
