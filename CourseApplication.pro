QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CourseDesignBackend/Service/ExecutiveService.cpp \
    CourseDesignBackend/Service/ExperimenterService.cpp \
    CourseDesignBackend/Service/TeacherAndExecutiveService.cpp \
    CourseDesignBackend/Service/TeacherService.cpp \
    CourseDesignBackend/common/BaseResponse.cpp \
    CourseDesignBackend/common/ResultUtils.cpp \
    CourseDesignBackend/mapper/ExecutiveMapper.cpp \
    CourseDesignBackend/mapper/ExperimenterMapper.cpp \
    CourseDesignBackend/mapper/TeacherAndExecutiveMapper.cpp \
    CourseDesignBackend/mapper/TeacherMapper.cpp \
    CourseDesignBackend/model/dataobject/Executive.cpp \
    CourseDesignBackend/model/dataobject/Experimenter.cpp \
    CourseDesignBackend/model/dataobject/Teacher.cpp \
    CourseDesignBackend/model/dataobject/TeacherAndExecutive.cpp \
    dialog.cpp \
    list.cpp \
    main.cpp \
    mainwindow.cpp \
    result.cpp

HEADERS += \
    CourseDesignBackend/Service/ExecutiveService.h \
    CourseDesignBackend/Service/ExperimenterService.h \
    CourseDesignBackend/Service/TeacherAndExecutiveService.h \
    CourseDesignBackend/Service/TeacherService.h \
    CourseDesignBackend/common/BaseResponse.h \
    CourseDesignBackend/common/ResultUtils.h \
    CourseDesignBackend/mapper/ExecutiveMapper.h \
    CourseDesignBackend/mapper/ExperimenterMapper.h \
    CourseDesignBackend/mapper/TeacherAndExecutiveMapper.h \
    CourseDesignBackend/mapper/TeacherMapper.h \
    CourseDesignBackend/model/dataobject/Executive.h \
    CourseDesignBackend/model/dataobject/Experimenter.h \
    CourseDesignBackend/model/dataobject/Shared.h \
    CourseDesignBackend/model/dataobject/Teacher.h \
    CourseDesignBackend/model/dataobject/TeacherAndExecutive.h \
    dialog.h \
    list.h \
    mainwindow.h \
    result.h

FORMS += \
    dialog.ui \
    list.ui \
    mainwindow.ui \
    result.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
