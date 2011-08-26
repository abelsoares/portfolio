#-------------------------------------------------
#
# Project created by QtCreator 2010-11-25T22:29:45
#
#-------------------------------------------------

QT+= core gui declarative phonon opengl

TARGET = demo_01
TEMPLATE = app

DEPENDPATH += .
DEPENDPATH += dll
LIBS += "D:\OpenCV2.1\lib\cv210.lib"
LIBS += "D:\OpenCV2.1\lib\highgui210.lib"

INCLUDEPATH += "D:\OpenCV2.1\include"

SOURCES += main.cpp\
        mainwindow.cpp \
    QOpenCVWidget.cpp \
    navigationwidget.cpp \
    videowidget.cpp \
    glwidget.cpp \
    bookviewerwidget.cpp

HEADERS  += mainwindow.h \
    QOpenCVWidget.h \
    navigationwidget.h \
    videowidget.h \
    glwidget.h \
    bookviewerwidget.h

FORMS    += mainwindow.ui \
    videowidget.ui

OTHER_FILES += \
    qml/rec_book_layout.qml \
    qml/navigation.qml \
    qml/leiNewton.qml \
    qml/content_layout.qml \
    resources/qml/rec_book_layout.qml \
    resources/qml/navigation.qml \
    resources/qml/leiNewton.qml \
    resources/qml/content_layout.qml \
    resources/scripts/script.js \
    resources/qml/leiNewton2.qml

RESOURCES +=
