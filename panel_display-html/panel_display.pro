QT       += core gui
QT       += webenginewidgets
#QT       += webengine
#QT       += webchannel

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
    customqlabel.cpp \
    document.cpp \
    main.cpp \
    mainform.cpp \
    mainwindow.cpp \
    navigationform.cpp \
    startupform.cpp \
    webclass.cpp

HEADERS += \
    customqlabel.h \
    document.h \
    mainform.h \
    mainwindow.h \
    navigationform.h \
    startupform.h \
    webclass.h

FORMS += \
    mainform.ui \
    mainwindow.ui \
    navigationform.ui \
    startupform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../pic/audio/bimage.jpg \
    ../pic/navigation/batterynum/0.png \
    ../pic/navigation/batterynum/1.png \
    ../pic/navigation/batterynum/2.png \
    ../pic/navigation/batterynum/3.png \
    ../pic/navigation/batterynum/4.png \
    ../pic/navigation/batterynum/5.png \
    ../pic/navigation/batterynum/6.png \
    ../pic/navigation/batterynum/7.png \
    ../pic/navigation/batterynum/8.png \
    ../pic/navigation/batterynum/9.png \
    ../pic/navigation/batterynum/precent.png \
    ../pic/navigation/batterypic/green0.png \
    ../pic/navigation/batterypic/green1.png \
    ../pic/navigation/batterypic/green2.png \
    ../pic/navigation/batterypic/green3.png \
    ../pic/navigation/batterypic/green4.png \
    ../pic/navigation/batterypic/green5.png \
    ../pic/navigation/batterypic/read0.png \
    ../pic/navigation/batterypic/read1.png \
    ../pic/navigation/batterypic/read2.png \
    ../pic/navigation/batterypic/read3.png \
    ../pic/navigation/batterypic/read4.png \
    ../pic/navigation/batterypic/read5.png \
    ../pic/navigation/batterypic/yellow0.png \
    ../pic/navigation/batterypic/yellow1.png \
    ../pic/navigation/batterypic/yellow2.png \
    ../pic/navigation/batterypic/yellow3.png \
    ../pic/navigation/batterypic/yellow4.png \
    ../pic/navigation/batterypic/yellow5.png \
    ../pic/navigation/current.png \
    ../pic/navigation/dest.png \
    ../pic/navigation/etime.png \
    ../pic/navigation/fault_pic.png \
    ../pic/navigation/goto.png \
    ../pic/navigation/kmhpic.png \
    ../pic/navigation/leftlight_no.png \
    ../pic/navigation/leftlight_yes.png \
    ../pic/navigation/motorfault.png \
    ../pic/navigation/rail.png \
    ../pic/navigation/readypic.png \
    ../pic/navigation/return.png \
    ../pic/navigation/rightlight_no.png \
    ../pic/navigation/rightlight_yes.png \
    ../pic/navigation/speednum/0.png \
    ../pic/navigation/speednum/1.png \
    ../pic/navigation/speednum/2.png \
    ../pic/navigation/speednum/3.png \
    ../pic/navigation/speednum/4.png \
    ../pic/navigation/speednum/5.png \
    ../pic/navigation/speednum/6.png \
    ../pic/navigation/speednum/7.png \
    ../pic/navigation/speednum/8.png \
    ../pic/navigation/speednum/9.png \
    ../pic/navigation/speedpic.png \
    ../pic/running/bimage.png \
    ../pic/running/left_image.png \
    ../pic/running/odo.png \
    ../pic/running/right_image.png \
    ../pic/running/trip.png

RESOURCES +=
