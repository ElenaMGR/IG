HEADERS += \
    ejes.h \
    escena.h

SOURCES += \
    ejes.cc \
    escena.cc \
    practica1.cc

win32{
LIBS += -L$$PWD/freeglut/lib/x64/ -lfreeglut
INCLUDEPATH += $$PWD/freeglut/include/
DEPENDPATH += $$PWD/freeglut/include/
}

unix{
LIBS += -lglut
}

CONFIG += console
