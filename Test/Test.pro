QT += widgets testlib
QT -= gui



CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    ../Calculator/mylineedit.cpp \
    tst_calculator.cpp

HEADERS += \
    ../Calculator/calculator.h \
    ../Calculator/mylineedit.h

FORMS +=

