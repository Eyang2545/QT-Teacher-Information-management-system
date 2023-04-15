cmake_minimum_required(VERSION 3.23)
project(question)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "E:/qt/5.14.2/mingw73_64")

add_executable(question main.cpp model/dataobject/Teacher.cpp model/dataobject/Teacher.h model/dataobject/Shared.cpp model/dataobject/Shared.h model/dataobject/Experimenter.cpp model/dataobject/Experimenter.h model/dataobject/Executive.cpp model/dataobject/Executive.h model/dataobject/TeacherAndExecutive.cpp model/dataobject/TeacherAndExecutive.h Service/ExecutiveService.cpp Service/ExecutiveService.h Service/ExperimenterService.cpp Service/ExperimenterService.h Service/TeacherService.cpp Service/TeacherService.h Service/TeacherAndExecutiveService.cpp Service/TeacherAndExecutiveService.h common/BaseResponse.cpp common/BaseResponse.h common/ResultUtils.cpp common/ResultUtils.h mapper/TeacherMapper.cpp mapper/ExperimenterMapper.cpp mapper/ExperimenterMapper.h mapper/ExecutiveMapper.cpp mapper/ExecutiveMapper.h mapper/TeacherAndExecutiveMapper.cpp mapper/TeacherAndExecutiveMapper.h)