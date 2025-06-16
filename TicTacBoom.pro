QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    App.cpp \
    choosedifficulty.cpp \
    gamehistory.cpp \
    gamemodewindow.cpp \
    gameplaywindow.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    playerselection.cpp \
    signupform.cpp \
    statisticswindow.cpp \
    userprofile.cpp

HEADERS += \
    App.h \
    choosedifficulty.h \
    gamehistory.h \
    gamemodewindow.h \
    gameplaywindow.h \
    loginpage.h \
    mainwindow.h \
    playerselection.h \
    signupform.h \
    statisticswindow.h \
    userprofile.h

FORMS += \
    choosedifficulty.ui \
    gamehistory.ui \
    gamemodewindow.ui \
    gameplaywindow.ui \
    loginpage.ui \
    mainwindow.ui \
    playerselection.ui \
    signupform.ui \
    statisticswindow.ui \
    userprofile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
