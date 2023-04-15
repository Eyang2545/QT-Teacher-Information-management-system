#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "CourseDesignBackend/model/dataobject/Shared.h"
#include "CourseDesignBackend/model/dataobject/Teacher.h"
#include "CourseDesignBackend/Service/ExecutiveService.h"
#include "CourseDesignBackend/Service/ExperimenterService.h"
#include "CourseDesignBackend/Service/TeacherService.h"
#include "CourseDesignBackend/Service/TeacherAndExecutiveService.h"
#include "dialog.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pDlg = new Dialog(this);
    pRst = new result(this);
    setTableList();

//    QPalette pal(this->palette());

//    pal.setColor(QPalette::Background,QColor(105,105,105));
//    this->setAutoFillBackground(true);
//    this->setPalette(pal);
}

void MainWindow::insertTableItems(vector<Teacher> shareds){
        QStringList header;
        ui->tableWidget->setColumnCount(8);
        header<<"id"<<"姓名"<<"性别"<<"年龄"<<"类型"<<"系部"<<"专业"<<"职称";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        ui->tableWidget->setColumnWidth(0,125);
        ui->tableWidget->setColumnWidth(1,125);
        ui->tableWidget->setColumnWidth(2,125);
        ui->tableWidget->setColumnWidth(3,125);
        ui->tableWidget->setColumnWidth(4,125);
        ui->tableWidget->setColumnWidth(5,125);
        ui->tableWidget->setColumnWidth(6,125);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(7,QHeaderView::Stretch);

    QTableWidgetItem *item[8];
    unsigned long long i;
    ui->tableWidget->setRowCount(0);
    for (i=0;i<shareds.size();i++) {
        ui->tableWidget->insertRow(i);
        item[0] = new QTableWidgetItem(QString("%1").arg(shareds[i].id));

        item[1] = new QTableWidgetItem(QString("%1").arg(shareds[i].name));



        switch (shareds[i].gender) {
        case 0:
            item[2] = new QTableWidgetItem("");
            break;
        case 1:
            item[2] = new QTableWidgetItem("男");
            break;
        case 2:
            item[2] = new QTableWidgetItem("女");
            break;
        default:
            break;
        }

        if(shareds[i].age){
            item[3] = new QTableWidgetItem(QString("%1").arg(shareds[i].age));
        }else{
            item[3] = new QTableWidgetItem("");
        }



        item[4] = new QTableWidgetItem(QString("%1").arg("教师"));

        item[5] = new QTableWidgetItem(QString("%1").arg(shareds[i].department));

        item[6] = new QTableWidgetItem(QString("%1").arg(shareds[i].specialized));

        item[7] = new QTableWidgetItem(QString("%1").arg(shareds[i].jobTitle));

        for (int j=0;j<8;j++) {
            ui->tableWidget->setItem(i,j,item[j]);
        }
    }
    ui->numLabel->setText("记录数："+QString::number(shareds.size())+"条");
}
void MainWindow::insertTableItems(vector<TeacherAndExecutive> shareds){

    QStringList header;
    ui->tableWidget->setColumnCount(10);
    header<<"id"<<"姓名"<<"性别"<<"年龄"<<"类型"<<"系部"<<"专业"<<"职称"<<"办公室"<<"职务";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setColumnWidth(0,100);
    ui->tableWidget->setColumnWidth(1,100);
    ui->tableWidget->setColumnWidth(2,125);
    ui->tableWidget->setColumnWidth(3,125);
    ui->tableWidget->setColumnWidth(4,125);
    ui->tableWidget->setColumnWidth(5,125);
    ui->tableWidget->setColumnWidth(6,125);
    ui->tableWidget->setColumnWidth(7,125);
    ui->tableWidget->setColumnWidth(8,125);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(9,QHeaderView::Stretch);


    QTableWidgetItem *item[10];
    unsigned long long i;
    ui->tableWidget->setRowCount(0);
    for (i=0;i<shareds.size();i++) {
        ui->tableWidget->insertRow(i);
        item[0] = new QTableWidgetItem(QString("%1").arg(shareds[i].id));

        item[1] = new QTableWidgetItem(QString("%1").arg(shareds[i].name));

        switch (shareds[i].gender) {
        case 0:
            item[2] = new QTableWidgetItem("");
            break;
        case 1:
            item[2] = new QTableWidgetItem("男");
            break;
        case 2:
            item[2] = new QTableWidgetItem("女");
            break;
        default:
            break;
        }

        if(shareds[i].age){
            item[3] = new QTableWidgetItem(QString("%1").arg(shareds[i].age));
        }else{
            item[3] = new QTableWidgetItem("");
        }
        item[4] = new QTableWidgetItem(QString("%1").arg("教师兼行政人员"));

        item[5] = new QTableWidgetItem(QString("%1").arg(shareds[i].department));

        item[6] = new QTableWidgetItem(QString("%1").arg(shareds[i].specialized));

        item[7] = new QTableWidgetItem(QString("%1").arg(shareds[i].jobTitle));

        item[8] = new QTableWidgetItem(QString("%1").arg(shareds[i].office));

        item[9] = new QTableWidgetItem(QString("%1").arg(shareds[i].duty));

        for (int j=0;j<10;j++) {
            ui->tableWidget->setItem(i,j,item[j]);
        }
    }
    ui->numLabel->setText("记录数："+QString::number(shareds.size())+"条");
}
void MainWindow::insertTableItems(vector<Executive> shareds){

    QStringList header;
    ui->tableWidget->setColumnCount(7);
    header<<"id"<<"姓名"<<"性别"<<"年龄"<<"类型"<<"办公室"<<"职称";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setColumnWidth(0,125);
    ui->tableWidget->setColumnWidth(1,125);
    ui->tableWidget->setColumnWidth(2,125);
    ui->tableWidget->setColumnWidth(3,125);
    ui->tableWidget->setColumnWidth(4,125);
    ui->tableWidget->setColumnWidth(5,125);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(6,QHeaderView::Stretch);

    QTableWidgetItem *item[7];
    unsigned long long i;
    ui->tableWidget->setRowCount(0);
    for (i=0;i<shareds.size();i++) {
        ui->tableWidget->insertRow(i);
        item[0] = new QTableWidgetItem(QString("%1").arg(shareds[i].id));

        item[1] = new QTableWidgetItem(QString("%1").arg(shareds[i].name));

        switch (shareds[i].gender) {
        case 0:
            item[2] = new QTableWidgetItem("");
            break;
        case 1:
            item[2] = new QTableWidgetItem("男");
            break;
        case 2:
            item[2] = new QTableWidgetItem("女");
            break;
        default:
            break;
        }
        if(shareds[i].age){
            item[3] = new QTableWidgetItem(QString("%1").arg(shareds[i].age));
        }else{
            item[3] = new QTableWidgetItem("");
        }

        item[4] = new QTableWidgetItem(QString("%1").arg("行政人员"));

        item[5] = new QTableWidgetItem(QString("%1").arg(shareds[i].office));

        item[6] = new QTableWidgetItem(QString("%1").arg(shareds[i].duty));

        for (int j=0;j<7;j++) {
            ui->tableWidget->setItem(i,j,item[j]);
        }
    }
        ui->numLabel->setText("记录数："+QString::number(shareds.size())+"条");
}
void MainWindow::insertTableItems(vector<Experimenter> shareds){

    QStringList header;
    ui->tableWidget->setColumnCount(7);
    header<<"id"<<"姓名"<<"性别"<<"年龄"<<"类型"<<"实验室"<<"职务";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setColumnWidth(0,125);
    ui->tableWidget->setColumnWidth(1,125);
    ui->tableWidget->setColumnWidth(2,125);
    ui->tableWidget->setColumnWidth(3,125);
    ui->tableWidget->setColumnWidth(4,125);
    ui->tableWidget->setColumnWidth(5,125);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(6,QHeaderView::Stretch);

    QTableWidgetItem *item[7];
    unsigned long long i;
    ui->tableWidget->setRowCount(0);
    for (i=0;i<shareds.size();i++) {
        ui->tableWidget->insertRow(i);
        item[0] = new QTableWidgetItem(QString("%1").arg(shareds[i].id));

        item[1] = new QTableWidgetItem(QString("%1").arg(shareds[i].name));

        switch (shareds[i].gender) {
        case 0:
            item[2] = new QTableWidgetItem("");
            break;
        case 1:
            item[2] = new QTableWidgetItem("男");
            break;
        case 2:
            item[2] = new QTableWidgetItem("女");
            break;
        default:
            break;
        }

        if(shareds[i].age){
            item[3] = new QTableWidgetItem(QString("%1").arg(shareds[i].age));
        }else{
            item[3] = new QTableWidgetItem("");
        }

        item[4] = new QTableWidgetItem(QString("%1").arg("实验员"));

        item[5] = new QTableWidgetItem(QString("%1").arg(shareds[i].laboratory));

        item[6] = new QTableWidgetItem(QString("%1").arg(shareds[i].duty));

        for (int j=0;j<7;j++) {
            ui->tableWidget->setItem(i,j,item[j]);
        }
    }
        ui->numLabel->setText("记录数："+QString::number(shareds.size())+"条");
}
void MainWindow::setTableList(){


    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setStyleSheet(\
                    "QHeaderView::section{"\
                    "padding:1px;"\
                    "border:none;"\
                    "border-bottom:1px solid rgb(75,120,154);"\
                    "border-right:1px solid rgb(75,120,154);"\

                    "}"\
                    );
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_set_released()
{
    long id;
    string name;
    int age;
    int gender;
    int type=0;

    //所在办公室
    string office;
    //职务
    string duty;
    //所在实验室
    string laboratory;
    //所在系部
    string department;
    //专业
    string specialized;
    //职称
    string jobTitle;

    id=ui->idLineEdit->text().toLong();
    name=ui->nameLineEdit->text().toStdString();
    age=ui->ageLineEdit->text().toInt();
    gender=ui->genderBox->currentIndex();
    type=ui->typeBox->currentIndex();
    if(id<=0){
        pRst->setMessage("请输入合法id");
        pRst->exec();
        return;
    }
    bool success;
    switch (type) {
    case 0:
        department=ui->lineEdit_2->text().toStdString();
        specialized=ui->lineEdit_3->text().toStdString();
        jobTitle=ui->lineEdit_4->text().toStdString();
        office=ui->lineEdit_5->text().toStdString();
        duty=ui->lineEdit_6->text().toStdString();
        success=TeacherAndExecutivesService::add(TeacherAndExecutive(id,name,gender,false,age,department,specialized,jobTitle,office,duty)).success;
        break;
    case 1:
        office=ui->lineEdit_2->text().toStdString();
        duty=ui->lineEdit_3->text().toStdString();
        success=ExecutiveService::add(Executive(id,name,gender,false,age,office,duty)).success;
        break;
    case 2:
        department=ui->lineEdit_2->text().toStdString();
        specialized=ui->lineEdit_3->text().toStdString();
        jobTitle=ui->lineEdit_4->text().toStdString();
        success=TeacherService::add(Teacher(id,name,gender,false,age,department,specialized,jobTitle)).success;
        break;
    case 3:
        laboratory=ui->lineEdit_2->text().toStdString();
        duty=ui->lineEdit_3->text().toStdString();
        success=ExperimenterService::add(Experimenter(id,name,gender,false,age,laboratory,duty)).success;
        break;
    case 4:

        break;
    }

    if(success){
        ui->idLineEdit->clear();
        ui->nameLineEdit->clear();
        ui->ageLineEdit->clear();
        ui->genderBox->setCurrentIndex(0);
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
    }else {
        pRst->setMessage("id已存在");
        pRst->exec();
    }

MainWindow::on_serch_released();
}

void MainWindow::on_serch_released()
{
    long id;
    string name;
    int age;
    int gender;
    int type=0;

    //所在办公室
    string office;
    //职务
    string duty;
    //所在实验室
    string laboratory;
    //所在系部
    string department;
    //专业
    string specialized;
    //职称
    string jobTitle;

    id=ui->idLineEdit->text().toLong();
    name=ui->nameLineEdit->text().toStdString();
    age=ui->ageLineEdit->text().toInt();
    gender=ui->genderBox->currentIndex();
    type=ui->typeBox->currentIndex();

    vector<TeacherAndExecutive> teacherAndExecutives;
    vector<Teacher> teachers;
    vector<Executive> executives;
    vector<Experimenter> experimenters;

    switch (type) {
    case 0:
        department=ui->lineEdit_2->text().toStdString();
        specialized=ui->lineEdit_3->text().toStdString();
        jobTitle=ui->lineEdit_4->text().toStdString();
        office=ui->lineEdit_5->text().toStdString();
        duty=ui->lineEdit_6->text().toStdString();
        teacherAndExecutives = TeacherAndExecutivesService::query(TeacherAndExecutive(id,name,gender,false,age,department,specialized,jobTitle,office,duty)).data;
        insertTableItems(teacherAndExecutives);
        break;
    case 1:
        office=ui->lineEdit_5->text().toStdString();
        duty=ui->lineEdit_6->text().toStdString();
        executives = ExecutiveService::query(Executive(id,name,gender,false,age,office,duty)).data;
        insertTableItems(executives);
        break;
    case 2:
        department=ui->lineEdit_2->text().toStdString();
        specialized=ui->lineEdit_3->text().toStdString();
        jobTitle=ui->lineEdit_4->text().toStdString();
        teachers = TeacherService::query(Teacher(id,name,gender,false,age,department,specialized,jobTitle)).data;
        insertTableItems(teachers);
        break;
    case 3:
        laboratory=ui->lineEdit_2->text().toStdString();
        duty=ui->lineEdit_3->text().toStdString();
        experimenters = ExperimenterService::query(Experimenter(id,name,gender,false,age,laboratory,duty)).data;
        insertTableItems(experimenters);
        break;
    case 4:

        break;
    }



}

void MainWindow::on_typeBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:

        ui->label_2->setText("系部");
        ui->label_2->setVisible(1);
        ui->lineEdit_2->setVisible(1);
        ui->label_3->setText("专业");
        ui->label_3->setVisible(1);
        ui->lineEdit_3->setVisible(1);
        ui->label_4->setText("职称");
        ui->label_4->setVisible(1);
        ui->lineEdit_4->setVisible(1);
        ui->label_5->setText("办公室");
        ui->label_5->setVisible(1);
        ui->lineEdit_5->setVisible(1);
        ui->label_6->setText("职务");
        ui->label_6->setVisible(1);
        ui->lineEdit_6->setVisible(1);

        break;
    case 1:
        ui->label_2->setText("办公室");
        ui->label_2->setVisible(1);
        ui->lineEdit_2->setVisible(1);
        ui->label_3->setText("职务");
        ui->label_3->setVisible(1);
        ui->lineEdit_3->setVisible(1);
        ui->label_4->setText("");
        ui->label_4->setVisible(0);
        ui->lineEdit_4->setVisible(0);
        ui->label_5->setText("");
        ui->label_5->setVisible(0);
        ui->lineEdit_5->setVisible(0);
        ui->label_6->setText("");
        ui->label_6->setVisible(0);
        ui->lineEdit_6->setVisible(0);
        break;
    case 2:
        ui->label_2->setText("系部");
        ui->label_2->setVisible(1);
        ui->lineEdit_2->setVisible(1);
        ui->label_3->setText("专业");
        ui->label_3->setVisible(1);
        ui->lineEdit_3->setVisible(1);
        ui->label_4->setText("职称");
        ui->label_4->setVisible(1);
        ui->lineEdit_4->setVisible(1);
        ui->label_5->setText("");
        ui->label_5->setVisible(0);
        ui->lineEdit_5->setVisible(0);
        ui->label_6->setText("");
        ui->label_6->setVisible(0);
        ui->lineEdit_6->setVisible(0);
        break;
    case 3:
        ui->label_2->setText("实验室");
        ui->label_2->setVisible(1);
        ui->lineEdit_2->setVisible(1);
        ui->label_3->setText("职务");
        ui->label_3->setVisible(1);
        ui->lineEdit_3->setVisible(1);
        ui->label_4->setText("");
        ui->label_4->setVisible(0);
        ui->lineEdit_4->setVisible(0);
        ui->label_5->setText("");
        ui->label_5->setVisible(0);
        ui->lineEdit_5->setVisible(0);
        ui->label_6->setText("");
        ui->label_6->setVisible(0);
        ui->lineEdit_6->setVisible(0);
        break;
    case 4:
        ui->label_2->setText("");
        ui->label_2->setVisible(0);
        ui->lineEdit_2->setVisible(0);
        ui->label_3->setText("");
        ui->label_3->setVisible(0);
        ui->lineEdit_3->setVisible(0);
        ui->label_4->setText("");
        ui->label_4->setVisible(0);
        ui->lineEdit_4->setVisible(0);
        ui->label_5->setText("");
        ui->label_5->setVisible(0);
        ui->lineEdit_5->setVisible(0);
        ui->label_6->setText("");
        ui->label_6->setVisible(0);
        ui->lineEdit_6->setVisible(0);
        break;
    }

    cout<<index<<endl;
}

void MainWindow::on_delete_2_released()
{
    int i = ui->tableWidget->currentRow();
    if(i==-1)return;
    long id = ui->tableWidget->item(i,0)->text().toLong();
    QString str = ui->tableWidget->item(i,4)->text();
    ui->tableWidget->removeRow(i);

    if(str=="教师兼行政人员"){TeacherAndExecutivesService::deleteById(id);}
    if(str=="行政人员"){ExecutiveService::deleteById(id);}
    if(str=="教师"){TeacherService::deleteById(id);}

    if(str=="实验员"){ExperimenterService::deleteById(id);}

    //cout<<i<<endl;
    cout<<id<<endl;
    ui->tableWidget->setCurrentCell(-1,0);
}

void MainWindow::on_edit_released()
{
    int i = ui->tableWidget->currentRow();
    if(i==-1)return;
    QString str = ui->tableWidget->item(i,4)->text();
    long id = ui->tableWidget->item(i,0)->text().toLong();

    if(str=="教师兼行政人员"){pDlg->setMessage(id,0);}
    if(str=="行政人员"){pDlg->setMessage(id,1);}
    if(str=="教师"){pDlg->setMessage(id,2);}

    if(str=="实验员"){pDlg->setMessage(id,3);}
    pDlg->showAll();

    pDlg->exec();



//    cout<<i<<endl;
    cout<<id<<endl;
    ui->tableWidget->setCurrentCell(-1,0);
    MainWindow::on_serch_released();
}
