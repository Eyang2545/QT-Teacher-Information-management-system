//
// Created by 90317 on 2022/11/25.
//

#ifndef QUESTION_EXECUTIVE_H
#define QUESTION_EXECUTIVE_H
#include "Shared.h"
#include "iostream"
using namespace std;
class Executive : public Shared{
public:
    //所在办公室
    char office[20];
    //职务
    char duty[20];

    Executive(long id,const string& name,int gender,bool isDelete,int age,const string& office,const string& duty);
    Executive();
};


#endif //QUESTION_EXECUTIVE_H
