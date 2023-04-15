//
// Created by 90317 on 2022/11/25.
//

#ifndef QUESTION_TEACHERMAPPER_H
#define QUESTION_TEACHERMAPPER_H
#include "iostream"
#include "vector"
#include "../model/dataobject/Teacher.h"
using namespace std;
class TeacherMapper {
public:
    static void Serialize(ostream & os,const Teacher & teacher);
    static void Serialize(ostream & os,const vector<Teacher> & teachers);

    static void Deserialize(istream & is,Teacher teacher);
    static void Deserialize(istream & is,vector<Teacher> * teachers);

};


#endif //QUESTION_TEACHERMAPPER_H
