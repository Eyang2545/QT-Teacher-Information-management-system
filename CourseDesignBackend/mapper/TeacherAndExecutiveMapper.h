//
// Created by 90317 on 2022/12/4.
//

#ifndef QUESTION_TEACHERANDEXECUTIVEMAPPER_H
#define QUESTION_TEACHERANDEXECUTIVEMAPPER_H
#include "iostream"
#include "vector"
#include "../model/dataobject/TeacherAndExecutive.h"
using namespace std;

class TeacherAndExecutiveMapper {
public:
    static void Serialize(ostream & os,const TeacherAndExecutive & teacherAndExecutive);
    static void Serialize(ostream & os,const vector<TeacherAndExecutive> & teacherAndExecutives);

    static void Deserialize(istream & is,TeacherAndExecutive teacherAndExecutive);
    static void Deserialize(istream & is,vector<TeacherAndExecutive> * teacherAndExecutives);
};


#endif //QUESTION_TEACHERANDEXECUTIVEMAPPER_H
