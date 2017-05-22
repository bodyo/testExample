QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

include(../../gtest_dependency.pri)

TEMPLATE = app

SOURCES += tst_learningtest.cpp \
    main.cpp \
    quadratic.cpp

HEADERS += \
    quadratic.h

