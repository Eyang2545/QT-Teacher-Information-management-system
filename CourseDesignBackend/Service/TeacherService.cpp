//
// Created by 90317 on 2022/11/25.
//

#include "TeacherService.h"
#include "../mapper/TeacherMapper.h"
#include "../common/ResultUtils.h"
#include <fstream>
#include "string.h"
const char* TEACHER_DATABASE_PATH="teacher.dat";

BaseResponse<long> TeacherService::add(Teacher teacher) {
    vector<Teacher> teachers = TeacherService::all().data;
    for (const auto &item: teachers){
        if (item.id==teacher.id){
            return ResultUtils<long>::error("have same id");
        }
    }
    teachers.push_back(teacher);
    ofstream os(TEACHER_DATABASE_PATH,ios::out | ios::binary);
    TeacherMapper::Serialize(os,teachers);
    os.close();
    return ResultUtils<long>::success(teacher.id);
}

BaseResponse<vector<Teacher>> TeacherService::all() {
    vector<Teacher> teachers = {};
    ifstream is(TEACHER_DATABASE_PATH,ios::in | ios::binary);
    TeacherMapper::Deserialize(is,&teachers);
    is.close();
    return ResultUtils<vector<Teacher>>::success(teachers);
}

BaseResponse<long> TeacherService::deleteById(long id) {
    vector<Teacher> teachers = all().data;
    int i;
    for (i = 0; i < teachers.size(); i++) {
        if (teachers[i].id==id){
            teachers.erase(teachers.begin()+i);
            break;
        }
    }
//    if (i==teachers.size())return ResultUtils<long>::error("no such id");
    ofstream os(TEACHER_DATABASE_PATH,ios::out | ios::binary);
    TeacherMapper::Serialize(os,teachers);
    os.close();
    return ResultUtils<long>::success(id);
}

BaseResponse<long> TeacherService::edit(Teacher teacher) {
    vector<Teacher> teachers = all().data;
    int i;
    for (i = 0; i < teachers.size(); i++) {
        if (teachers[i].id==teacher.id){
            teachers[i]=teacher;
            break;
        }
    }
    if (i==teachers.size())return ResultUtils<long>::error("no such id");
    ofstream os(TEACHER_DATABASE_PATH,ios::out | ios::binary);
    TeacherMapper::Serialize(os,teachers);
    os.close();
    return ResultUtils<long>::success(teacher.id);
}
//逻辑没想好
BaseResponse<vector<Teacher>> TeacherService::query(Teacher teacher) {
    vector<Teacher> teachers = all().data;
    if (teacher.id){
        for (int i = 0; i < teachers.size(); i++){
            if (teacher.id!=teachers[i].id){
                teachers.erase(teachers.begin()+i);
                i--;
            }
        }
    }
    if (teacher.name[0]){
        for (int i = 0; i < teachers.size(); i++){
            if (strcmp(teacher.name,teachers[i].name) != 0){
                teachers.erase(teachers.begin()+i);
                i--;
            }
        }
    }
    if (teacher.gender){
        for (int i = 0; i < teachers.size(); i++){
            if (teacher.gender!=teachers[i].gender){
                teachers.erase(teachers.begin()+i);
                i--;
            }
        }
    }
    if (teacher.age){
        for (int i = 0; i < teachers.size(); i++){
            if (teacher.age!=teachers[i].age){
                teachers.erase(teachers.begin()+i);
                i--;
            }
        }
    }
    if (teacher.department[0]){
        for (int i = 0; i < teachers.size(); i++){
            if (strcmp(teacher.department,teachers[i].department) != 0){
                teachers.erase(teachers.begin()+i);
                i--;
            }
        }
    }
    if (teacher.specialized[0]){
        for (int i = 0; i < teachers.size(); i++){
            if (strcmp(teacher.specialized,teachers[i].specialized) != 0){
                teachers.erase(teachers.begin()+i);
                i--;
            }
        }
    }
    if (teacher.jobTitle[0]){
        for (int i = 0; i < teachers.size(); i++){
            if (strcmp(teacher.jobTitle,teachers[i].jobTitle) != 0){
                teachers.erase(teachers.begin()+i);
                i--;
            }
        }
    }

    return ResultUtils<vector<Teacher>>::success(teachers);
}

BaseResponse<Teacher> TeacherService::queryById(long id) {
    vector<Teacher> teachers = all().data;
    for (const auto &item: teachers){
        if (item.id==id){
            return ResultUtils<Teacher>::success(item);
        }
    }
    return ResultUtils<Teacher>::error("no such id");
}

