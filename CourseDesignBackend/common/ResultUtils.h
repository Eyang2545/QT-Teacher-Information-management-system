//
// Created by 90317 on 2022/11/25.
//
/**
 * 结果类实例化工具
 */
#ifndef QUESTION_RESULTUTILS_H
#define QUESTION_RESULTUTILS_H
#include "BaseResponse.h"

template<class T>
class ResultUtils {
public:
    static BaseResponse<T> success(T data){return BaseResponse<T>(data,true);}
    static BaseResponse<T> error(string message){return BaseResponse<T>(message, false);}
};


#endif //QUESTION_RESULTUTILS_H
