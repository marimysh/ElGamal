#-------------------------------------------------
#
# Project created by QtCreator 2014-10-08T22:02:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ElGamal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    editkey.cpp \
    ElGamal2.cpp \
    editparam.cpp \
    enterkey.cpp \
    funcpasswd.cpp \
    vigenere.cpp

HEADERS  += mainwindow.h \
    editkey.h \
    elgamal2.h \
    editparam.h \
    enterkey.h \
    funcpasswd.h \
    vigenere.h

FORMS    += mainwindow.ui \
    editkey.ui \
    editparam.ui \
    enterkey.ui
