#ifndef SIGNALTEST_H
#define SIGNALTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include <utility>
#include <vector>
#include <iostream>
#include "../AudioAnalyzer/signal.h"

typedef std::pair<int, double> myPair;
typedef std::vector<myPair> myVector;

class SignalTest : public QObject
{
    Q_OBJECT
public:
    explicit SignalTest(QObject *parent = 0);
    ~SignalTest(){}
    myVector getSignalFromFile();
private:
    Signal* signal;
private slots:
    void initTestCase();

    void testInitSignal();
    void testSetTimeVariable();
    void testMakeTxtFile();
    void cleanUpTestCase();
};

#endif // SIGNALTEST_H
