#include "dialog.h"
#include "ui_dialog.h"
#include "CourseDesignBackend/Service/ExecutiveService.h"
#include "CourseDesignBackend/Service/ExperimenterService.h"
#include "CourseDesignBackend/Service/TeacherAndExecutiveService.h"
#include "CourseDesignBackend/Service/TeacherService.h"
#include "iostream"
using namespace std;
TeacherAndExecutive teacherAndExecutive;
Executive executive;
Teacher teacher;
Experimenter experimenter;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent,Qt::FramelessWindowHint),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);



//    QPalette pal(this->palette());


//    pal.setColor(QPalette::Background,QColor(192, 192, 192));
//    this->setAutoFillBackground(true);
//    this->setPalette(pal);
}

void Dialog::showAll(){
    ui->typeBox->setEnabled(false);
    ui->idLineEdit->setEnabled(false);
    long id = ui->idLineEdit->text().toLong();
    int type = ui->typeBox->currentIndex();

    switch (type) {
    case 0:
        teacherAndExecutive =TeacherAndExecutivesService::queryById(id).data;
        ui->idLineEdit->setText(QString("%1").arg(teacherAndExecutive.id));
        ui->nameLineEdit->setText(QString("%1").arg(teacherAndExecutive.name));
        if(teacherAndExecutive.age){
            ui->ageLineEdit->setText(QString("%1").arg(teacherAndExecutive.age));
        }else{
            ui->ageLineEdit->setText(QString("%1").arg(""));
        }

        ui->genderBox->setCurrentIndex(teacherAndExecutive.gender);
        ui->lineEdit_2->setText(QString("%1").arg(teacherAndExecutive.department));
        ui->lineEdit_3->setText(QString("%1").arg(teacherAndExecutive.specialized));
        ui->lineEdit_4->setText(QString("%1").arg(teacherAndExecutive.jobTitle));
        ui->lineEdit_5->setText(QString("%1").arg(teacherAndExecutive.office));
        ui->lineEdit_6->setText(QString("%1").arg(teacherAndExecutive.duty));
        break;
    case 1:
        executive = ExecutiveService::queryById(id).data;
        ui->idLineEdit->setText(QString("%1").arg(executive.id));
        ui->nameLineEdit->setText(QString("%1").arg(executive.name));
        if(executive.age){
            ui->ageLineEdit->setText(QString("%1").arg(executive.age));
        }else{
            ui->ageLineEdit->setText(QString("%1").arg(""));
        }
        ui->genderBox->setCurrentIndex(executive.gender);
        ui->lineEdit_2->setText(QString("%1").arg(executive.office));
        ui->lineEdit_3->setText(QString("%1").arg(executive.duty));
        executive = ExecutiveService::queryById(id).data;
        break;
    case 2:
        teacher = TeacherService::queryById(id).data;
        ui->idLineEdit->setText(QString("%1").arg(teacher.id));
        ui->nameLineEdit->setText(QString("%1").arg(teacher.name));
        if(teacher.age){
            ui->ageLineEdit->setText(QString("%1").arg(teacher.age));
        }else{
            ui->ageLineEdit->setText(QString("%1").arg(""));
        }
        ui->genderBox->setCurrentIndex(teacher.gender);
        ui->lineEdit_2->setText(QString("%1").arg(teacher.department));
        ui->lineEdit_3->setText(QString("%1").arg(teacher.specialized));
        ui->lineEdit_4->setText(QString("%1").arg(teacher.jobTitle));
        break;
    case 3:
        experimenter = ExperimenterService::queryById(id).data;
        ui->idLineEdit->setText(QString("%1").arg(experimenter.id));
        ui->nameLineEdit->setText(QString("%1").arg(experimenter.name));
        if(experimenter.age){
            ui->ageLineEdit->setText(QString("%1").arg(experimenter.age));
        }else{
            ui->ageLineEdit->setText(QString("%1").arg(""));
        }
        ui->genderBox->setCurrentIndex(experimenter.gender);
        ui->lineEdit_2->setText(QString("%1").arg(experimenter.laboratory));
        ui->lineEdit_3->setText(QString("%1").arg(experimenter.duty));
        break;
    default:
        break;
    }
}

void Dialog::setMessage(long id,int type){
    ui->idLineEdit->setText(QString("%1").arg(id));
    ui->typeBox->setCurrentIndex(type);
    //查询id获取数据
}

void Dialog::getMessage(long &id,QString &name,int &age,bool &gender,int &type,QString &office,QString &duty,QString &laboratory,QString &department,QString &specialized,QString &jobTitle){
    id=ui->idLineEdit->text().toLong();
    name=ui->nameLineEdit->text();
    age=ui->ageLineEdit->text().toInt();
    gender=ui->genderBox->currentIndex();
    type=ui->typeBox->currentIndex();
    switch (type) {
    case 0:
        department=ui->lineEdit_2->text();
        specialized=ui->lineEdit_3->text();
        jobTitle=ui->lineEdit_4->text();
        office=ui->lineEdit_5->text();
        duty=ui->lineEdit_6->text();
        break;
    case 1:
        office=ui->lineEdit_2->text();
        duty=ui->lineEdit_3->text();
        break;
    case 2:
        department=ui->lineEdit_2->text();
        specialized=ui->lineEdit_3->text();
        jobTitle=ui->lineEdit_4->text();
        break;
    case 3:
        laboratory=ui->lineEdit_2->text();
        duty=ui->lineEdit_3->text();
        break;
    case 4:

        break;
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_typeBox_currentIndexChanged(int index)
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

}

void Dialog::on_accept_released()
{
    cout<<"accept"<<endl;
    int type = ui->typeBox->currentIndex();
    long id;
    string name;
    int age;
    int gender;

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
    switch (type) {
    case 0:
        department=ui->lineEdit_2->text().toStdString();
        specialized=ui->lineEdit_3->text().toStdString();
        jobTitle=ui->lineEdit_4->text().toStdString();
        office=ui->lineEdit_5->text().toStdString();
        duty=ui->lineEdit_6->text().toStdString();
        TeacherAndExecutivesService::edit(TeacherAndExecutive(id,name,gender,false,age,department,specialized,jobTitle,office,duty));
        break;
    case 1:
        office=ui->lineEdit_2->text().toStdString();
        duty=ui->lineEdit_3->text().toStdString();
        ExecutiveService::edit(Executive(id,name,gender,false,age,office,duty));
        break;
    case 2:
        department=ui->lineEdit_2->text().toStdString();
        specialized=ui->lineEdit_3->text().toStdString();
        jobTitle=ui->lineEdit_4->text().toStdString();
        TeacherService::edit(Teacher(id,name,gender,false,age,department,specialized,jobTitle));
        break;
    case 3:
        laboratory=ui->lineEdit_2->text().toStdString();
        duty=ui->lineEdit_3->text().toStdString();
        ExperimenterService::edit(Experimenter(id,name,gender,false,age,laboratory,duty));
        break;
    default:
        break;
    }
    accept();
}

void Dialog::on_reject_clicked()
{
    cout<<"reject"<<endl;
    reject();
}
