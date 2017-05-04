#include "audioiotest.h"
#include <typeinfo>
using namespace std;

AudioIOTest::AudioIOTest(QObject *parent) :
    QObject(parent)
{

}

void AudioIOTest::initTestCase()
{
    audioIO = new AudioIO;
    QVERIFY2(audioIO!=NULL,"wavFile is NULL");
    QVERIFY2(typeid(audioIO)==typeid(new AudioIO),"wavFile worng typeid");
}

void AudioIOTest::test()
{
    QVERIFY2(true, "Failure");

}

void AudioIOTest::testLoadFile()
{
    QVERIFY2(audioIO->loadFile("")==false,"Error load file");
    QVERIFY2(audioIO->loadFile("error")==false,"Error load file");
    QVERIFY2(audioIO->loadFile("testFile.wav")==true,"Error load file");
}

void AudioIOTest::testPlay()
{
    QVERIFY2(true, "Failure");
    QVERIFY2(audioIO->play("testFile.wav")==true,"Error play method");

    QVERIFY2(audioIO->loadFile("testFile.wav")==true,"Error load file");
    QVERIFY2(audioIO->play()==true,"Error play method");
}

void AudioIOTest::cleanupTestCase()
{

}
