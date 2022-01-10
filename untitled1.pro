QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Rectangle.cpp \
    Scene.cpp \
    Shape.cpp \
    circle.cpp \
    commands.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    processes.cpp \
    triangle.cpp

HEADERS += \
    Rectangle.h \
    Scene.h \
    Shape.h \
    circle.h \
    commands.h \
    line.h \
    mainwindow.h \
    processes.h \
    triangle.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Icons/Save.ico \
    Icons/Undo-icon.png \
    Icons/circle.png \
    Icons/color.png \
    Icons/dense1.png \
    Icons/dense2.png \
    Icons/dense3.png \
    Icons/line.png \
    Icons/open.jpg \
    Icons/rectangle.jpg \
    Icons/redo-131964753186720817.png \
    Icons/solid.png \
    Icons/triangle.png \
    README.txt

RESOURCES += \
    icon.qrc
