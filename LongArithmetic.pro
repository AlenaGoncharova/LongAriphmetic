TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS_DEBUG += -gdwarf-3

SOURCES += main.cpp \
    verylargeint.cpp

HEADERS += \
    verylargeint.h
