//
// Created by 90317 on 2022/11/25.
//

#ifndef QUESTION_EXPERIMENTER_H
#define QUESTION_EXPERIMENTER_H
#include "Shared.h"
#include "iostream"
using namespace std;
class Experimenter: public Shared{
public:
    //所在实验室
    char laboratory[20];
    //职务
    char duty[20];

    Experimenter(long id,const string& name,int gender,bool isDelete,int age,const string& laboratory,const string& duty);
    Experimenter();
};


#endif //QUESTION_EXPERIMENTER_H
