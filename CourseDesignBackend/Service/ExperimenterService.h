//
// Created by 90317 on 2022/11/25.
//

#ifndef QUESTION_EXPERIMENTERSERVICE_H
#define QUESTION_EXPERIMENTERSERVICE_H
#include "../common/BaseResponse.h"
#include "iostream"
#include "vector"
#include "../model/dataobject/Experimenter.h"
using namespace std;

class ExperimenterService {
public:
    /**
     * 增加一名人员
     * @param experimenter 人员对象
     * @return 对象id
     */
    static BaseResponse<long> add(Experimenter experimenter);
    /**
     * 根据id进行逻辑删除
     * @param id 删除对象的id
     * @return 对象id
     */
    static BaseResponse<long> deleteById(long id);
    /**
     * 编辑人员数据
     * @param experimenter 对象
     * @return 对象id
     */
    static BaseResponse<long> edit(Experimenter experimenter);
    /**
     * 获取所有实验员
     * @return 所有实验员的集合
     */
    static BaseResponse<vector<Experimenter>> all();
    /**
     * 查询人员
     * @param id id
     * @return 对象
     */
    static BaseResponse<vector<Experimenter>> query(Experimenter experimenter);
    /**
     * 查询人员
     * @param id id
     * @return 对象
     */
    static BaseResponse<Experimenter> queryById(long id);

};


#endif //QUESTION_EXPERIMENTERSERVICE_H
