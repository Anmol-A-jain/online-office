#-------------------------------------------------
#
# Project created by QtCreator 2019-05-29T15:37:01
#
#-------------------------------------------------

QT       += core gui webengine webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MicrosoftOffice
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        excel.cpp \
        forms.cpp \
        home.cpp \
        main.cpp \
        office.cpp \
        onedrive.cpp \
        onenote.cpp \
        outlook.cpp \
        powerpoint.cpp \
        sway.cpp \
        word.cpp

HEADERS += \
        excel.h \
        forms.h \
        home.h \
        office.h \
        onedrive.h \
        onenote.h \
        outlook.h \
        powerpoint.h \
        sway.h \
        word.h

FORMS += \
        excel.ui \
        forms.ui \
        home.ui \
        office.ui \
        onedrive.ui \
        onenote.ui \
        outlook.ui \
        powerpoint.ui \
        sway.ui \
        word.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    officeresource.qrc
