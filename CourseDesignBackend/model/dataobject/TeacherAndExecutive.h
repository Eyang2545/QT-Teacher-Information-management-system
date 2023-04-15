//
// Created by 90317 on 2022/11/25.
//

#ifndef QUESTION_TEACHERANDEXECUTIVE_H
#define QUESTION_TEACHERANDEXECUTIVE_H
#include "Shared.h"
#include "iostream"
using namespace std;
class TeacherAndExecutive : public Shared{
public:
    //所在系部
    char department[20];
    //专业
    char specialized[20];
    //职称
    char jobTitle[20];
    //所在办公室
    char office[20];
    //职务
    char duty[20];

    TeacherAndExecutive(long id,const string& name,int gender,bool isDelete,int age,const string& department,const string& specialized,const string& jobTitle,const string& office,const string& duty);
    TeacherAndExecutive();

};



#endif //QUESTION_TEACHERANDEXECUTIVE_H
