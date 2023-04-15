//
// Created by 90317 on 2022/11/25.
//

#ifndef QUESTION_TEACHER_H
#define QUESTION_TEACHER_H
#include "Shared.h"
#include "iostream"
using namespace std;
class Teacher :public Shared{
public:
    //所在系部
    char department[20];
    //专业
    char specialized[20];
    //职称
    char jobTitle[20];

    Teacher(long id,const string& name,int gender,bool isDelete,int age,const string& department,const string& specialized,const string& jobTitle);
    Teacher();
};


#endif //QUESTION_TEACHER_H
