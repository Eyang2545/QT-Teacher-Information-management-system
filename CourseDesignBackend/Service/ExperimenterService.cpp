//
// Created by 90317 on 2022/11/25.
//

#include "ExperimenterService.h"
#include "../mapper/ExperimenterMapper.h"
#include "../common/ResultUtils.h"
#include <fstream>
#include "string.h"
const char* EXPERIMENTER_DATABASE_PATH="experimenter.dat";

BaseResponse<long> ExperimenterService::add(Experimenter experimenter) {
    vector<Experimenter> experimenters = ExperimenterService::all().data;
    for (const auto &item: experimenters){
        if (item.id==experimenter.id){
            return ResultUtils<long>::error("have same id");
        }
    }
    experimenters.push_back(experimenter);
    ofstream os(EXPERIMENTER_DATABASE_PATH,ios::out | ios::binary);
    ExperimenterMapper::Serialize(os,experimenters);
    os.close();
    return ResultUtils<long>::success(experimenter.id);
}

BaseResponse<vector<Experimenter>> ExperimenterService::all() {
    vector<Experimenter> experimenters = {};
    ifstream is(EXPERIMENTER_DATABASE_PATH,ios::in | ios::binary);
    ExperimenterMapper::Deserialize(is,&experimenters);
    is.close();
    return ResultUtils<vector<Experimenter>>::success(experimenters);
}

BaseResponse<long> ExperimenterService::deleteById(long id) {
    vector<Experimenter> experimenters = all().data;
    int i;
    for (i = 0; i < experimenters.size(); i++) {
        if (experimenters[i].id==id){
            experimenters.erase(experimenters.begin()+i);
            break;
        }
    }
//    if (i==experimenters.size())return ResultUtils<long>::error("no such id");
    ofstream os(EXPERIMENTER_DATABASE_PATH,ios::out | ios::binary);
    ExperimenterMapper::Serialize(os,experimenters);
    os.close();
    return ResultUtils<long>::success(id);
}

BaseResponse<long> ExperimenterService::edit(Experimenter experimenter) {
    vector<Experimenter> experimenters = all().data;
    int i;
    for (i = 0; i < experimenters.size(); i++) {
        if (experimenters[i].id==experimenter.id){
            experimenters[i]=experimenter;
            break;
        }
    }
//    if (i==experimenters.size())return ResultUtils<long>::error("no such id");
    ofstream os(EXPERIMENTER_DATABASE_PATH,ios::out | ios::binary);
    ExperimenterMapper::Serialize(os,experimenters);
    os.close();
    return ResultUtils<long>::success(experimenter.id);
}

BaseResponse<vector<Experimenter>> ExperimenterService::query(Experimenter experimenter) {
    vector<Experimenter> experimenters = all().data;
    if (experimenter.id){
        for (int i = 0; i < experimenters.size(); i++){
            if (experimenter.id!=experimenters[i].id){
                experimenters.erase(experimenters.begin()+i);
                i--;
            }
        }
    }
    if (experimenter.name[0]){
        for (int i = 0; i < experimenters.size(); i++){
            if (strcmp(experimenter.name,experimenters[i].name) != 0){
                experimenters.erase(experimenters.begin()+i);
                i--;
            }
        }
    }
    if (experimenter.gender){
        for (int i = 0; i < experimenters.size(); i++){
            if (experimenter.gender!=experimenters[i].gender){
                experimenters.erase(experimenters.begin()+i);
                i--;
            }
        }
    }
    if (experimenter.age){
        for (int i = 0; i < experimenters.size(); i++){
            if (experimenter.age!=experimenters[i].age){
                experimenters.erase(experimenters.begin()+i);
                i--;
            }
        }
    }
    if (experimenter.laboratory[0]){
        for (int i = 0; i < experimenters.size(); i++){
            if (strcmp(experimenter.laboratory,experimenters[i].laboratory) != 0){
                experimenters.erase(experimenters.begin()+i);
                i--;
            }
        }
    }
    if (experimenter.duty[0]){
        for (int i = 0; i < experimenters.size(); i++){
            if (strcmp(experimenter.duty,experimenters[i].duty) != 0){
                experimenters.erase(experimenters.begin()+i);
                i--;
            }
        }
    }
    return ResultUtils<vector<Experimenter>>::success(experimenters);
}

BaseResponse<Experimenter> ExperimenterService::queryById(long id) {
    vector<Experimenter> experimenters = all().data;
    for (const auto &item: experimenters){
        if (item.id==id){
            return ResultUtils<Experimenter>::success(item);
        }
    }
    return ResultUtils<Experimenter>::error("no such id");
}
