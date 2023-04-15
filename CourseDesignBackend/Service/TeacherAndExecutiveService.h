//
// Created by 90317 on 2022/11/25.
//

#ifndef QUESTION_TEACHERANDEXECUTIVESERVICE_H
#define QUESTION_TEACHERANDEXECUTIVESERVICE_H
#include "../common/BaseResponse.h"
#include "iostream"
#include "vector"
#include "../model/dataobject/TeacherAndExecutive.h"
using namespace std;

class TeacherAndExecutivesService {
public:
    /**
     * 增加一名人员
     * @param teacherAndExecutives 人员对象
     * @return 对象id
     */
    static BaseResponse<long> add(TeacherAndExecutive teacherAndExecutive);

    /**
     * 根据id进行逻辑删除
     * @param id 删除对象的id
     * @return 对象id
     */
    static BaseResponse<long> deleteById(long id);

    /**
     * 编辑人员数据
     * @param teacherAndExecutives 对象
     * @return 对象id
     */
    static BaseResponse<long> edit(TeacherAndExecutive teacherAndExecutive);

    /**
     * 获取所有老师兼行政人员
     * @return 所有老师兼行政人员的集合
     */
    static BaseResponse<vector<TeacherAndExecutive>> all();


    /**
     * 根据id查询人员
     * @param id id
     * @return 对象
     */
    static BaseResponse<vector<TeacherAndExecutive>> query(TeacherAndExecutive teacherAndExecutive);

    /**
     * 根据id查询人员
     * @param id id
     * @return 对象
     */
    static BaseResponse<TeacherAndExecutive> queryById(long id);
};


#endif //QUESTION_TEACHERANDEXECUTIVESERVICE_H
