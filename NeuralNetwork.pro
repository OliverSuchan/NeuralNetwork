TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    neuron.cpp \
    inputneuron.cpp \
    outputneuron.cpp \
    neuralnetwork.cpp \
    connection.cpp

HEADERS += \
    neuron.h \
    inputneuron.h \
    outputneuron.h \
    neuralnetwork.h \
    connection.h

