//
// Created by 90317 on 2022/11/25.
//

#include "ExecutiveService.h"
#include "../mapper/ExecutiveMapper.h"
#include "../common/ResultUtils.h"
#include <fstream>
#include "string.h"
const char* EXECUTIVE_DATABASE_PATH="executives.dat";

BaseResponse<long> ExecutiveService::add(Executive executive) {
    vector<Executive> executives = ExecutiveService::all().data;
    for (const auto &item: executives){
        if (item.id==executive.id){
            return ResultUtils<long>::error("have same id");
        }
    }
    executives.push_back(executive);
    ofstream os(EXECUTIVE_DATABASE_PATH,ios::out | ios::binary);
    ExecutiveMapper::Serialize(os,executives);
    os.close();
    return ResultUtils<long>::success(executive.id);
}

BaseResponse<vector<Executive>> ExecutiveService::all() {
    vector<Executive> executives = {};
    ifstream is(EXECUTIVE_DATABASE_PATH,ios::in | ios::binary);
    ExecutiveMapper::Deserialize(is,&executives);
    is.close();
    return ResultUtils<vector<Executive>>::success(executives);
}

BaseResponse<long> ExecutiveService::deleteById(long id) {
    vector<Executive> executives = all().data;
    int i;
    for (i = 0; i < executives.size(); i++) {
        if (executives[i].id==id){
            executives.erase(executives.begin()+i);
            break;
        }
    }
//    if (i==executives.size())return ResultUtils<long>::error("no such id");
    ofstream os(EXECUTIVE_DATABASE_PATH,ios::out | ios::binary);
    ExecutiveMapper::Serialize(os,executives);
    os.close();
    return ResultUtils<long>::success(id);
}

BaseResponse<long> ExecutiveService::edit(Executive executive) {
    vector<Executive> executives = all().data;
    int i;
    for (i = 0; i < executives.size(); i++) {
        if (executives[i].id==executive.id){
            executives[i]=executive;
            break;
        }
    }
//    if (i==executives.size())return ResultUtils<long>::error("no such id");
    ofstream os(EXECUTIVE_DATABASE_PATH,ios::out | ios::binary);
    ExecutiveMapper::Serialize(os,executives);
    os.close();
    return ResultUtils<long>::success(executive.id);
}

BaseResponse<vector<Executive>> ExecutiveService::query(Executive executive) {
    vector<Executive> executives = all().data;
    if (executive.id){
        for (int i = 0; i < executives.size(); i++){
            if (executive.id!=executives[i].id){
                executives.erase(executives.begin()+i);
                i--;
            }
        }
    }
    if (executive.name[0]){
        for (int i = 0; i < executives.size(); i++){
            if (strcmp(executive.name,executives[i].name) != 0){
                executives.erase(executives.begin()+i);
                i--;
            }
        }
    }
    if (executive.gender){
        for (int i = 0; i < executives.size(); i++){
            if (executive.gender!=executives[i].gender){
                executives.erase(executives.begin()+i);
                i--;
            }
        }
    }
    if (executive.age){
        for (int i = 0; i < executives.size(); i++){
            if (executive.age!=executives[i].age){
                executives.erase(executives.begin()+i);
                i--;
            }
        }
    }

    if (executive.office[0]){
        for (int i = 0; i < executives.size(); i++){
            if (strcmp(executive.office,executives[i].office) != 0){
                executives.erase(executives.begin()+i);
                i--;
            }
        }
    }

    if (executive.duty[0]){
        for (int i = 0; i < executives.size(); i++){
            if (strcmp(executive.duty,executives[i].duty) != 0){
                executives.erase(executives.begin()+i);
                i--;
            }
        }
    }

    return ResultUtils<vector<Executive>>::success(executives);
}

BaseResponse<Executive> ExecutiveService::queryById(long id) {
    vector<Executive> executives = all().data;
    for (const auto &item: executives){
        if (item.id==id){
            return ResultUtils<Executive>::success(item);
        }
    }
    return ResultUtils<Executive>::error("no such id");
}


