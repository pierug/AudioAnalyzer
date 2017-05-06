QT       += testlib
QT += multimedia \
      multimediawidgets \


QT       -= gui

CONFIG += c++11

TARGET = AudioAnalyzerTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    wavefiletest.cpp \
    audioiotest.cpp \
    \
../AudioAnalyzer/wavefile.cpp \
../AudioAnalyzer/audioio.cpp \
    signaltest.cpp \
    ../AudioAnalyzer/signal.cpp


DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    wavefiletest.h \
    audioiotest.h \
    \
../AudioAnalyzer/audioio.h\
../AudioAnalyzer/wavefile.h \
    signaltest.h \
    ../AudioAnalyzer/signal.h

SUBDIRS += \
    ../AudioAnalyzer/AudioAnalyzer.pro


