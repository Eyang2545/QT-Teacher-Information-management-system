//
// Created by 90317 on 2022/11/25.
//

#ifndef QUESTION_TEACHERSERVICE_H
#define QUESTION_TEACHERSERVICE_H
#include "../common/BaseResponse.h"
#include "iostream"
#include "vector"
#include "../model/dataobject/Teacher.h"
#include <fstream>
using namespace std;

class TeacherService {
public:


    /**
     * 增加一名人员
     * @param teacher 人员对象
     * @return 对象id
     */
    static BaseResponse<long> add(Teacher teacher);

    /**
     * 根据id进行逻辑删除
     * @param id 删除对象的id
     * @return 对象id
     */
    static BaseResponse<long> deleteById(long id);

    /**
     * 编辑人员数据
     * @param teacher 对象
     * @return 对象id
     */
    static BaseResponse<long> edit(Teacher teacher);

    /**
     * 获取所有老师
     * @return 所有老师的集合
     */
    static BaseResponse<vector<Teacher>> all();

    /**
     * 查询人员
     * @param teacher 对象
     * @return 对象集合
     */
    static BaseResponse<vector<Teacher>> query(Teacher teacher);

    /**
     * 查询人员
     * @param teacher 对象
     * @return 对象集合
     */
    static BaseResponse<Teacher> queryById(long id);

};

#endif //QUESTION_TEACHERSERVICE_H
