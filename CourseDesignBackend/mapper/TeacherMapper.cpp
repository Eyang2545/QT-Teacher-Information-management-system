//
// Created by 90317 on 2022/11/25.
//

#include "TeacherMapper.h"
#include "iostream"
#include "fstream"


void TeacherMapper::Serialize(ostream &os, const Teacher &teacher) {
    os.write((char*)&teacher,sizeof teacher);
}

void TeacherMapper::Serialize(ostream &os, const vector<Teacher> &teachers) {
    for(auto & teacher:teachers){
        Serialize(os,teacher);
    }
}

void TeacherMapper::Deserialize(istream &is,Teacher teacher) {
    is.read((char*)&teacher,sizeof teacher);
}

void TeacherMapper::Deserialize(istream &is,vector<Teacher> * teachers) {
    Teacher teacher;
    while(is.read((char *)&teacher, sizeof(teacher))) { //一直读到文件结束
        teachers->push_back(teacher);
    }
}


