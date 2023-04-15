cmake_minimum_required(VERSION 3.23)
project(CourseApplication)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CourseApplication
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui)
