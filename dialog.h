#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <iostream>
using namespace std;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:

    void getMessage(long &id,QString &name,int &age,bool &gender,int &type,QString &office,QString &duty,QString &laboratory,QString &department,QString &specialized,QString &jobTitle);
    void setMessage(long id,int type);
    void showAll();

    explicit Dialog(QWidget *parent = nullptr);


    ~Dialog();

private slots:
    void on_typeBox_currentIndexChanged(int index);

    void on_accept_released();

    void on_reject_clicked();

private:

    Ui::Dialog *ui;
};

#endif // DIALOG_H
