//
// Created by 90317 on 2022/12/4.
//

#include "ExperimenterMapper.h"

void ExperimenterMapper::Serialize(ostream &os, const Experimenter &experimenter) {
    os.write((char*)&experimenter,sizeof experimenter);
}

void ExperimenterMapper::Serialize(ostream &os, const vector<Experimenter> &experimenters) {
    for(auto & experimenter:experimenters){
        Serialize(os,experimenter);
    }
}

void ExperimenterMapper::Deserialize(istream &is, Experimenter experimenter) {
    is.read((char*)&experimenter,sizeof experimenter);
}

void ExperimenterMapper::Deserialize(istream &is, vector<Experimenter> *experimenters) {
    Experimenter experimenter;
    while(is.read((char *)&experimenter, sizeof(experimenter))) { //一直读到文件结束
        experimenters->push_back(experimenter);
    }
}
