QT -= gui
QT += xml concurrent

CONFIG += c++17 console
CONFIG -= app_bundle

LIBS += -L/usr/local/lib/ -lmatio
INCLUDEPATH += /usr/local/include

INCLUDEPATH += /home/operator/qt-projects/UtilitiesLibrary/src/ConfigurationParser/mat/headers/
LIBS += -L"/home/operator/qt-projects/UtilitiesLibrary/lib" \
        -lutilities

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config.mat \
    data-me.mat \
    data.mat

HEADERS +=
