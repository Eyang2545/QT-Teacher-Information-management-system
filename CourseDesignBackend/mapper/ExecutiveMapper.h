//
// Created by 90317 on 2022/12/4.
//

#ifndef QUESTION_EXECUTIVEMAPPER_H
#define QUESTION_EXECUTIVEMAPPER_H
#include "iostream"
#include "vector"
#include "../model/dataobject/Executive.h"
using namespace std;

class ExecutiveMapper {
public:
    static void Serialize(ostream & os,const Executive & executive);
    static void Serialize(ostream & os,const vector<Executive> & executives);

    static void Deserialize(istream & is,Executive executive);
    static void Deserialize(istream & is,vector<Executive> * executives);
};


#endif //QUESTION_EXECUTIVEMAPPER_H
