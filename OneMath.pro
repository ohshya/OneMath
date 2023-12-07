QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
ICON += qrc:/assets/icon.ico

SOURCES += \
    adduser.cpp \
    configuracion.cpp \
    conjuntos.cpp \
    credits.cpp \
    exportar.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    module1.cpp \
    module1test.cpp \
    module2.cpp \
    module2test.cpp \
    module3.cpp \
    module3test.cpp \
    module4.cpp \
    moduleselection.cpp \
    mybutton.cpp \
    profiles.cpp \
    sinewavewidget.cpp \
    slidingstackedwidget.cpp \
    switch.cpp

HEADERS += \
    ClickableFrame.h \
    SineWaveWidget.h \
    adduser.h \
    configuracion.h \
    conjuntos.h \
    credits.h \
    exportar.h \
    global.h \
    mainwindow.h \
    module1.h \
    module1test.h \
    module2.h \
    module2test.h \
    module3.h \
    module3test.h \
    module4.h \
    moduleselection.h \
    mybutton.h \
    profiles.h \
    slidingstackedwidget.h \
    style.h \
    switch.h

FORMS += \
    adduser.ui \
    configuracion.ui \
    conjuntos.ui \
    credits.ui \
    exportar.ui \
    mainwindow.ui \
    module1.ui \
    module1test.ui \
    module2.ui \
    module2test.ui \
    module3.ui \
    module3test.ui \
    module4.ui \
    moduleselection.ui \
    profiles.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
