QT += testlib
QT += gui sql
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES += \
    ../App.cpp \
    ../choosedifficulty.cpp \
    ../gamehistory.cpp \
    ../gamemodewindow.cpp \
    ../gameplaywindow.cpp \
    ../loginpage.cpp \
    ../main.cpp \
    ../mainwindow.cpp \
    ../playerselection.cpp \
    ../signupform.cpp \
    ../userprofile.cpp\
    ../statisticswindow.cpp\
    tst_test1.cpp


HEADERS += \
    ../App.h \
    ../choosedifficulty.h \
    ../gamehistory.h \
    ../gamemodewindow.h \
    ../gameplaywindow.h \
    ../loginpage.h \
    ../mainwindow.h \
    ../playerselection.h \
    ../signupform.h \
    ../userprofile.h\
    ../statisticswindow.h\

FORMS += \
    ../choosedifficulty.ui \
    ../gamehistory.ui \
    ../gamemodewindow.ui \
    ../gameplaywindow.ui \
    ../loginpage.ui \
    ../mainwindow.ui \
    ../playerselection.ui \
    ../signupform.ui \
    ../userprofile.ui\
    ../statisticswindow.ui\

TARGET = test
