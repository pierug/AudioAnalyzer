#include <QCoreApplication>
#include <iostream>
#include "audioio.h"
#include <QAudioOutput>
#include <QFile>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    AudioIO* audioIO=new AudioIO;

//    cout<<audioIO->loadFile("testFile.wav")<<endl;
//    cout<<audioIO->play("testFile.wav")<<endl;

    return a.exec();
}
