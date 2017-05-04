#ifndef WAVEFILETEST_H
#define WAVEFILETEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "../AudioAnalyzer/wavefile.h"


class WaveFileTest : public QObject
{
    Q_OBJECT
public:
    explicit WaveFileTest(QObject *parent = 0);
    ~WaveFileTest(){}
private:
    WavFile* wavFile;
private slots:
    void initTestCase();

    void testInit();
    void testOpenFile();
    void testHeaderLenght();
    void testFileFormat();

    void cleanUpTestCase();
};

#endif // WAVEFILETEST_H
