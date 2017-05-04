#ifndef AUDIOIOTEST_H
#define AUDIOIOTEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "../AudioAnalyzer/audioio.h"

class AudioIOTest: public QObject
{
    Q_OBJECT
public:
    explicit AudioIOTest(QObject *parent = 0);
    ~AudioIOTest(){}
private:
    AudioIO* audioIO;
private slots:
    void initTestCase();

    void test();
    void testLoadFile();
    void testPlay();

    void cleanupTestCase();
};

#endif // AUDIOIOTEST_H
