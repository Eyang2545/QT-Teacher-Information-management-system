//
// Created by 90317 on 2022/11/25.
//

#include "TeacherAndExecutive.h"
#include <cstring>
TeacherAndExecutive::TeacherAndExecutive(long id, const string& name, int gender, bool isDelete, int age, const string& department,
                                         const string& specialized, const string& jobTitle, const string& office, const string& duty) {
    this->id=id;
    strcpy(this->name,name.c_str());
    this->gender=gender;
    this->isDelete=isDelete;
    this->age=age;
    strcpy(this->department,department.c_str());
    strcpy(this->specialized,specialized.c_str());
    strcpy(this->jobTitle,jobTitle.c_str());
    strcpy(this->office,office.c_str());
    strcpy(this->duty,duty.c_str());
}

TeacherAndExecutive::TeacherAndExecutive() {

}
