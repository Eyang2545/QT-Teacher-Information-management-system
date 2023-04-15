//
// Created by 90317 on 2022/11/25.
//
/**
 * 结果类的封装
 */
#ifndef QUESTION_BASERESPONSE_H
#define QUESTION_BASERESPONSE_H
#include "iostream"
using namespace std;
template<class T>
class BaseResponse {
public:
    T data;
    string message;
    bool success= false;
    BaseResponse(T data,bool success){
        this->data=data;
        this->success=success;
    }
    BaseResponse(string message,bool success){
        this->message=message;
        this->success=success;
    }
};


#endif //QUESTION_BASERESPONSE_H
