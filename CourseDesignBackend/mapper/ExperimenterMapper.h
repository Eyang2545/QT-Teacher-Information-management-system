//
// Created by 90317 on 2022/12/4.
//

#ifndef QUESTION_EXPERIMENTERMAPPER_H
#define QUESTION_EXPERIMENTERMAPPER_H
#include "iostream"
#include "vector"
#include "../model/dataobject/Experimenter.h"
using namespace std;

class ExperimenterMapper {
public:
    static void Serialize(ostream & os,const Experimenter & experimenter);
    static void Serialize(ostream & os,const vector<Experimenter> & experimenters);

    static void Deserialize(istream & is,Experimenter experimenter);
    static void Deserialize(istream & is,vector<Experimenter> * experimenters);
};


#endif //QUESTION_EXPERIMENTERMAPPER_H
