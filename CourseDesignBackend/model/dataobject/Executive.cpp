//
// Created by 90317 on 2022/11/25.
//

#include "Executive.h"
#include <cstring>

Executive::Executive(long id, const string &name, int gender, bool isDelete, int age, const string& office, const string& duty) {
    this->id=id;
    strcpy(this->name,name.c_str());
    this->gender=gender;
    this->isDelete=isDelete;
    this->age=age;
    strcpy(this->office,office.c_str());
    strcpy(this->duty,duty.c_str());
}

Executive::Executive() {

}
