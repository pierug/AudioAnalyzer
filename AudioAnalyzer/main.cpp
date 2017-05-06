#include <QCoreApplication>
#include <iostream>
#include "audioio.h"
#include <QAudioOutput>
#include <QFile>
#include "signal.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AudioIO* audioIO=new AudioIO;

    cout<<audioIO->loadFile("testFile.wav")<<endl;
//    cout<<audioIO->play("testFile.wav")<<endl;

    Signal signal;
    signal.setOscilogramValues(signal.getOscilogramValuesFromWav(*audioIO->file()));
    signal.toTxtFile("test.txt");
    return a.exec();
}
