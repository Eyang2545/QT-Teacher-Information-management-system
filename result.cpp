#include "result.h"
#include "ui_result.h"
#include "iostream"
result::result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
}


void result::setMessage(string message){
    ui->label->setText(QString::fromStdString(message));
}

result::~result()
{
    delete ui;
}

void result::on_pushButton_released()
{
    reject();
}
