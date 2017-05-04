#include <QtTest/QtTest>
#include "wavefiletest.h"
#include "audioiotest.h"

int main()
{
    WaveFileTest waveFileTest;
    QTest::qExec(&waveFileTest);

    AudioIOTest auidioIOTest;
    QTest::qExec(&auidioIOTest);

    return 0;
}
