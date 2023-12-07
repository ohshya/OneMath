QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    extendedWidgets/conjuntos.cpp \
    extendedWidgets/mybutton.cpp \
    extendedWidgets/sinewavewidget.cpp \
    extendedWidgets/slidingstackedwidget.cpp \
    extendedWidgets/switch.cpp \
    global.cpp \
    main.cpp \
    mainWidgets/configuracion.cpp \
    mainWidgets/moduleselection.cpp \
    mainWidgets/profiles.cpp \
    mainwindow.cpp \
    modulesWidgets/module1.cpp \
    modulesWidgets/module1test.cpp \
    modulesWidgets/module2.cpp \
    modulesWidgets/module2test.cpp \
    modulesWidgets/module3.cpp \
    modulesWidgets/module3test.cpp \
    modulesWidgets/module4.cpp \
    popupWidgets/adduser.cpp \
    popupWidgets/credits.cpp \
    popupWidgets/exportar.cpp

HEADERS += \
    extendedWidgets/ClickableFrame.h \
    extendedWidgets/SineWaveWidget.h \
    extendedWidgets/conjuntos.h \
    extendedWidgets/mybutton.h \
    extendedWidgets/slidingstackedwidget.h \
    extendedWidgets/style.h \
    extendedWidgets/switch.h \
    global.h \
    mainWidgets/configuracion.h \
    mainWidgets/moduleselection.h \
    mainWidgets/profiles.h \
    mainwindow.h \
    modulesWidgets/module1.h \
    modulesWidgets/module1test.h \
    modulesWidgets/module2.h \
    modulesWidgets/module2test.h \
    modulesWidgets/module3.h \
    modulesWidgets/module3test.h \
    modulesWidgets/module4.h \
    popupWidgets/adduser.h \
    popupWidgets/credits.h \
    popupWidgets/exportar.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    extendedWidgets/conjuntos.ui \
    mainWidgets/configuracion.ui \
    mainWidgets/moduleselection.ui \
    mainWidgets/profiles.ui \
    mainwindow.ui \
    modulesWidgets/module1.ui \
    modulesWidgets/module1test.ui \
    modulesWidgets/module2.ui \
    modulesWidgets/module2test.ui \
    modulesWidgets/module3.ui \
    modulesWidgets/module3test.ui \
    modulesWidgets/module4.ui \
    popupWidgets/adduser.ui \
    popupWidgets/credits.ui \
    popupWidgets/exportar.ui

RESOURCES += \
    qrc.qrc
