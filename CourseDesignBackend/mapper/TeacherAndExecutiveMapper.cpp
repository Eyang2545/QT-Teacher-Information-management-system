//
// Created by 90317 on 2022/12/4.
//

#include "TeacherAndExecutiveMapper.h"

void TeacherAndExecutiveMapper::Serialize(ostream &os, const TeacherAndExecutive &teacherAndExecutive) {
    os.write((char*)&teacherAndExecutive,sizeof teacherAndExecutive);
}

void TeacherAndExecutiveMapper::Serialize(ostream &os, const vector<TeacherAndExecutive> &teacherAndExecutives) {
    for(auto & teacherAndExecutive:teacherAndExecutives){
        Serialize(os,teacherAndExecutive);
    }
}

void TeacherAndExecutiveMapper::Deserialize(istream &is, TeacherAndExecutive teacherAndExecutive) {
    is.read((char*)&teacherAndExecutive,sizeof teacherAndExecutive);
}

void TeacherAndExecutiveMapper::Deserialize(istream &is, vector<TeacherAndExecutive> *teacherAndExecutives) {
    TeacherAndExecutive teacherAndExecutive;
    while(is.read((char *)&teacherAndExecutive, sizeof(teacherAndExecutive))) { //一直读到文件结束
        teacherAndExecutives->push_back(teacherAndExecutive);
    }
}
