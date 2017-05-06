#include "wavefiletest.h"
#include <QtTest/QtTest>
#include <typeinfo>
#include <QDebug>

using namespace std;
WaveFileTest::WaveFileTest(QObject *parent) :
    QObject(parent)
{

}

void WaveFileTest::initTestCase()
{
    QVERIFY2(true, "Failure");
    wavFile = new WavFile();
}

void WaveFileTest::testInit()
{
    QVERIFY2(wavFile!=NULL,"wavFile is NULL");
    QVERIFY2(typeid(wavFile)==typeid(new WavFile),"wavFile worng typeid");
}

void WaveFileTest::testOpenFile()
{
    QVERIFY2(wavFile->open("testFile.wav")==true,"File didn't open");
}

void WaveFileTest::testHeaderLenght()
{
    QVERIFY2(wavFile->headerLength()!=20,"Wrong header lenght");
    QVERIFY2(wavFile->headerLength()==44,"Wrong header lenght");
}

void WaveFileTest::testFileFormat()
{
    const QAudioFormat testAudioFormat;
    QVERIFY2(typeid(wavFile->fileFormat())==typeid(testAudioFormat),"Fileformat worng typeid");
    QVERIFY2(wavFile->fileFormat().sampleType()==QAudioFormat::UnSignedInt,"Wrong sample type");
    QVERIFY2(wavFile->fileFormat().sampleSize()==8,"Wrong sample size");
    QVERIFY2(wavFile->fileFormat().sampleRate()==11025,"Wrong sample rate");
    QVERIFY2(wavFile->fileFormat().channelCount()==1,"Wrong channel count");
}

void WaveFileTest::testFileSize()
{
    QVERIFY2(wavFile->size()==96300,"Wrong bytes number");
    QVERIFY2(wavFile->size()/1024==94,"Wrong kilo bytes number");
}


void WaveFileTest::cleanUpTestCase()
{
    delete wavFile;
}

