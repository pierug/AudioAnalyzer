#include "signaltest.h"
#include <QtTest/QtTest>
#include <typeinfo>
#include <QDebug>
#include "../AudioAnalyzer/wavefile.h"
#include <utility>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

typedef std::pair<int, double> myPair;
typedef std::vector<myPair> myVector;

SignalTest::SignalTest(QObject *parent) : QObject(parent)
{

}

myVector SignalTest::getSignalFromFile()
{
    WavFile wavFile;
    myVector data;

    wavFile.open("testFile.wav");
    long int fileSize=wavFile.size();//wavFile.fileFormat().sampleSize();
    char dat[fileSize];
    wavFile.read(dat,fileSize);
    const double sampleRateSec = 1.0/wavFile.fileFormat().sampleRate();
    for(long int i=0;i<fileSize;i++){
       myPair p((int)dat[i],i*sampleRateSec);
        data.push_back(p);
    }
    return data;
}

void SignalTest::initTestCase()
{
    signal = new Signal();
    QVERIFY2(signal!=NULL,"signal is NULL");
    QVERIFY2(typeid(signal)==typeid(new Signal()),"signal worng typeid");
}

void SignalTest::testInitSignal()
{
    if(signal==NULL){
        delete signal;
    }
    myVector data = getSignalFromFile();
    signal = new Signal(data);
    QVERIFY2(signal!=NULL,"signal is NULL");
    QVERIFY2(typeid(signal)==typeid(new Signal()),"signal worng typeid");
    QVERIFY2(signal->oscilographValues().empty()==false,"Empty vector");
}

void SignalTest::testSetTimeVariable()
{
    signal->clearOscilograph();
    QVERIFY2(signal->oscilographValues().empty()==true,"Not empty vector");
    myVector data = getSignalFromFile();
    signal->setOscilogramValues(data);
    QVERIFY2(signal->oscilographValues().empty()!=true,"Empty vector");
}

void SignalTest::testMakeTxtFile()
{
    signal->toTxtFile("test.txt");
    const char* const FileName = "test.txt";
    std::ifstream fin(FileName);
    QVERIFY2(fin.good()==true,"File didn't find");
    fin.close();
}

void SignalTest::cleanUpTestCase()
{
    delete signal;
}
