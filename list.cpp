#include "list.h"
#include "ui_list.h"

list::list(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list)
{
    ui->setupUi(this);
}

list::~list()
{
    delete ui;
}
