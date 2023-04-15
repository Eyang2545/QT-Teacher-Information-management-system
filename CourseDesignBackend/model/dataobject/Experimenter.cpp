//
// Created by 90317 on 2022/11/25.
//

#include "Experimenter.h"
#include <cstring>
Experimenter::Experimenter(long id, const string& name, int gender, bool isDelete, int age, const string& laboratory, const string& duty) {
    this->id=id;
    strcpy(this->name,name.c_str());
    this->gender=gender;
    this->isDelete=isDelete;
    this->age=age;
    strcpy(this->laboratory,laboratory.c_str());
    strcpy(this->duty,duty.c_str());
}

Experimenter::Experimenter() {

}
