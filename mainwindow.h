#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <iostream>
#include "CourseDesignBackend/model/dataobject/Shared.h"
#include "CourseDesignBackend/model/dataobject/Teacher.h"
#include "CourseDesignBackend/Service/ExecutiveService.h"
#include "CourseDesignBackend/Service/ExperimenterService.h"
#include "CourseDesignBackend/Service/TeacherService.h"
#include "CourseDesignBackend/Service/TeacherAndExecutiveService.h"
#include "dialog.h"
#include "result.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setTableList();
    void insertTableItems(vector<Teacher> shareds);
    void insertTableItems(vector<TeacherAndExecutive> shareds);
    void insertTableItems(vector<Executive> shareds);
    void insertTableItems(vector<Experimenter> shareds);
private slots:

    void on_set_released();

    void on_serch_released();

    void on_typeBox_currentIndexChanged(int index);

    void on_delete_2_released();

    void on_edit_released();

private:
    Ui::MainWindow *ui;
    Dialog *pDlg;
    result *pRst;
};
#endif // MAINWINDOW_H
