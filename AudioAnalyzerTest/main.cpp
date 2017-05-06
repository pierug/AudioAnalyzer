#include <QtTest/QtTest>
#include "wavefiletest.h"
#include "audioiotest.h"
#include "signaltest.h"
int main()
{

    //WaveFileTest waveFileTest;
    //QTest::qExec(&waveFileTest);

    //AudioIOTest auidioIOTest;
    //QTest::qExec(&auidioIOTest);

    SignalTest signalTest;
    QTest::qExec(&signalTest);

    return 0;
}
