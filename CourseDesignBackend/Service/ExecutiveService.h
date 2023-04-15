//
// Created by 90317 on 2022/11/25.
//

#ifndef QUESTION_EXECUTIVESERVICE_H
#define QUESTION_EXECUTIVESERVICE_H
#include "../common/BaseResponse.h"
#include "iostream"
#include "vector"
#include "../model/dataobject/Executive.h"
using namespace std;
class ExecutiveService {
public:
    /**
     * 增加一名人员
     * @param executives 人员对象
     * @return 对象id
     */
    static BaseResponse<long> add(Executive executive);
    /**
     * 根据id进行逻辑删除
     * @param id 删除对象的id
     * @return 对象id
     */
    static BaseResponse<long> deleteById(long id);

    /**
     * 编辑人员数据
     * @param executives 对象
     * @return 对象id
     */
    static BaseResponse<long> edit(Executive executive);
    /**
     * 获取所有行政人员
     * @return 所有行政人员的集合
     */
    static BaseResponse<vector<Executive>> all();

    /**
     * 根据id查询人员
     * @param id id
     * @return 对象
     */
    static BaseResponse<vector<Executive>> query(Executive executive);
    /**
     * 根据id查询人员
     * @param id id
     * @return 对象
     */
    static BaseResponse<Executive> queryById(long id);

};


#endif //QUESTION_EXECUTIVESERVICE_H
