//
// Created by 90317 on 2022/12/4.
//

#include "ExecutiveMapper.h"

void ExecutiveMapper::Serialize(ostream &os, const Executive &executive) {
    os.write((char*)&executive,sizeof executive);
}

void ExecutiveMapper::Serialize(ostream &os, const vector<Executive> &executives) {
    for(auto & executive:executives){
        Serialize(os,executive);
    }
}

void ExecutiveMapper::Deserialize(istream &is, Executive executive) {
    is.read((char*)&executive,sizeof executive);
}

void ExecutiveMapper::Deserialize(istream &is, vector<Executive> *executives) {
    Executive executive;
    while(is.read((char *)&executive, sizeof(executive))) { //一直读到文件结束
        executives->push_back(executive);
    }
}
