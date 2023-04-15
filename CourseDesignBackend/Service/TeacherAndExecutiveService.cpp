//
// Created by 90317 on 2022/11/25.
//

#include "TeacherAndExecutiveService.h"
#include "../mapper/TeacherAndExecutiveMapper.h"
#include "../common/ResultUtils.h"
#include <fstream>
#include "string.h"
const char* TEACHERANDEXECUTIVE_DATABASE_PATH="teacherandexecutive.dat";
BaseResponse<long> TeacherAndExecutivesService::add(TeacherAndExecutive teacherAndExecutive) {
    vector<TeacherAndExecutive> teacherAndExecutives = TeacherAndExecutivesService::all().data;
    for (const auto &item: teacherAndExecutives){
        if (item.id==teacherAndExecutive.id){
            return ResultUtils<long>::error("have same id");
        }
    }
    teacherAndExecutives.push_back(teacherAndExecutive);
    ofstream os(TEACHERANDEXECUTIVE_DATABASE_PATH,ios::out | ios::binary);
    TeacherAndExecutiveMapper::Serialize(os,teacherAndExecutives);
    os.close();
    return ResultUtils<long>::success(teacherAndExecutive.id);
}

BaseResponse<vector<TeacherAndExecutive>> TeacherAndExecutivesService::all() {
    vector<TeacherAndExecutive> teacherAndExecutives = {};
    ifstream is(TEACHERANDEXECUTIVE_DATABASE_PATH,ios::in | ios::binary);
    TeacherAndExecutiveMapper::Deserialize(is,&teacherAndExecutives);
    is.close();
    return ResultUtils<vector<TeacherAndExecutive>>::success(teacherAndExecutives);
}

BaseResponse<long> TeacherAndExecutivesService::deleteById(long id) {
    vector<TeacherAndExecutive> teacherAndExecutives = all().data;
    int i;
    for (i = 0; i < teacherAndExecutives.size(); i++) {
        if (teacherAndExecutives[i].id==id){
            teacherAndExecutives.erase(teacherAndExecutives.begin()+i);
            break;
        }
    }
//    if (i==teacherAndExecutives.size())return ResultUtils<long>::error("no such id");
    ofstream os(TEACHERANDEXECUTIVE_DATABASE_PATH,ios::out | ios::binary);
    TeacherAndExecutiveMapper::Serialize(os,teacherAndExecutives);

    os.close();
    return ResultUtils<long>::success(id);
}

BaseResponse<long> TeacherAndExecutivesService::edit(TeacherAndExecutive teacherAndExecutive) {
    vector<TeacherAndExecutive> teacherAndExecutives = all().data;
    int i;
    for (i = 0; i < teacherAndExecutives.size(); i++) {
        if (teacherAndExecutives[i].id==teacherAndExecutive.id){
            teacherAndExecutives[i]=teacherAndExecutive;
            break;
        }
    }
    if (i==teacherAndExecutives.size())return ResultUtils<long>::error("no such id");
    ofstream os(TEACHERANDEXECUTIVE_DATABASE_PATH,ios::out | ios::binary);
    TeacherAndExecutiveMapper::Serialize(os,teacherAndExecutives);
    os.close();
    return ResultUtils<long>::success(teacherAndExecutive.id);
}

BaseResponse<vector<TeacherAndExecutive>> TeacherAndExecutivesService::query(TeacherAndExecutive teacherAndExecutive) {
    vector<TeacherAndExecutive> teacherAndExecutives = all().data;
    if (teacherAndExecutive.id){
        for (int i = 0; i < teacherAndExecutives.size(); i++){
            if (teacherAndExecutive.id!=teacherAndExecutives[i].id){
                teacherAndExecutives.erase(teacherAndExecutives.begin()+i);
                i--;
            }
        }
    }
    if (teacherAndExecutive.name[0]){
        for (int i = 0; i < teacherAndExecutives.size(); i++){
            if (strcmp(teacherAndExecutive.name,teacherAndExecutives[i].name) != 0){
                teacherAndExecutives.erase(teacherAndExecutives.begin()+i);
                i--;
            }
        }
    }
    if (teacherAndExecutive.gender){
        for (int i = 0; i < teacherAndExecutives.size(); i++){
            if (teacherAndExecutive.gender!=teacherAndExecutives[i].gender){
                teacherAndExecutives.erase(teacherAndExecutives.begin()+i);
                i--;
            }
        }
    }
    if (teacherAndExecutive.age){
        for (int i = 0; i < teacherAndExecutives.size(); i++){
            if (teacherAndExecutive.age!=teacherAndExecutives[i].age){
                teacherAndExecutives.erase(teacherAndExecutives.begin()+i);
                i--;
            }
        }
    }
    if (teacherAndExecutive.department[0]){
        for (int i = 0; i < teacherAndExecutives.size(); i++){
            if (strcmp(teacherAndExecutive.department,teacherAndExecutives[i].department) != 0){
                teacherAndExecutives.erase(teacherAndExecutives.begin()+i);
                i--;
            }
        }
    }
    if (teacherAndExecutive.specialized[0]){
        for (int i = 0; i < teacherAndExecutives.size(); i++){
            if (strcmp(teacherAndExecutive.specialized,teacherAndExecutives[i].specialized) != 0){
                teacherAndExecutives.erase(teacherAndExecutives.begin()+i);
                i--;
            }
        }
    }
    if (teacherAndExecutive.jobTitle[0]){
        for (int i = 0; i < teacherAndExecutives.size(); i++){
            if (strcmp(teacherAndExecutive.jobTitle,teacherAndExecutives[i].jobTitle) != 0){
                teacherAndExecutives.erase(teacherAndExecutives.begin()+i);
                i--;
            }
        }
    }
    if (teacherAndExecutive.office[0]){
        for (int i = 0; i < teacherAndExecutives.size(); i++){
            if (strcmp(teacherAndExecutive.office,teacherAndExecutives[i].office) != 0){
                teacherAndExecutives.erase(teacherAndExecutives.begin()+i);
                i--;
            }
        }
    }
    if (teacherAndExecutive.duty[0]){
        for (int i = 0; i < teacherAndExecutives.size(); i++){
            if (strcmp(teacherAndExecutive.duty,teacherAndExecutives[i].duty) != 0){
                teacherAndExecutives.erase(teacherAndExecutives.begin()+i);
                i--;
            }
        }
    }
    return ResultUtils<vector<TeacherAndExecutive>>::success(teacherAndExecutives);
}

BaseResponse<TeacherAndExecutive> TeacherAndExecutivesService::queryById(long id) {
    vector<TeacherAndExecutive> teachersAndExecutives = all().data;
    for (const auto &item: teachersAndExecutives){
        if (item.id==id){
            return ResultUtils<TeacherAndExecutive>::success(item);
        }
    }
    return ResultUtils<TeacherAndExecutive>::error("no such id");
}
