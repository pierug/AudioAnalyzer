#include <QCoreApplication>
#include <iostream>
#include "audioio.h"
#include <QAudioOutput>
#include <QFile>
#include "signal.h"
#include "fastfouriertransformation.h"
#include <cmath>

#define WINDOW_SIZE 1024
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*
    AudioIO* audioIO=new AudioIO;
    cout<<audioIO->loadFile("DoubleSine.wav")<<endl;
    cout<<audioIO->play("DoubleSine.wav")<<endl;
    audioIO->file()->printFileInfo();
    Signal signal;
    signal.setOscilogramValues(signal.getOscilogramValuesFromWav(*audioIO->file()));
    signal.toTxtFile("DoubleSinetest.txt");

    FastFourierTransformation FFT;
    Complex test[WINDOW_SIZE];
    myVector tmp = signal.oscilographValues();
    for(int i=0;i<WINDOW_SIZE;i++){
        test[i]=(double)tmp.at(i).first;
    }
    ComplexArray data(test, WINDOW_SIZE);
    FFT.fft(data);
    FFT.toTxtFile("FFT1024test.txt",data);
    FFT.calculateSpectrum(data);
    FFT.spectrumToTxt("Spectrum1024.txt");
    */
    const int lenghtTestArray=500;
    double t=0;
    Complex test[lenghtTestArray];
    for(int i=0;i<lenghtTestArray;i++){
        if(i<lenghtTestArray/2)
            test[i]= 2*sin(2*PI*4*t) + sin(2*PI*5*t);
        else
            test[i]= 2*sin(2*PI*t) + sin(2*PI*2*t) + sin(2*PI*3*t);
        t=t+0.02;
    }
    FastFourierTransformation FFT;
    ComplexArray data(test, lenghtTestArray);
    ComplexArray tmp;
    vector<double> magnitude;
    vector<double> f = FFT.calculateFrequency(lenghtTestArray/2);
    for(int i=0;i<2;i++){
        tmp = FFT.shortTimeFFT(data,i*lenghtTestArray/2,lenghtTestArray/2);
        magnitude = FFT.calculateMagnitude(tmp);
        std::string str = std::to_string(i)+"Dupa.txt";
        std::ofstream newfile(str);
        if (newfile.is_open())
        {
            for (int j=0;j<lenghtTestArray/2;j++) {
                newfile << magnitude[j]<<"\t"<<f[j]<<"\n";
            }
            newfile.close();
        }
    }
    /*FFT.fft(data);
    double f[lenghtTestArray];
    for(int i=0;i<lenghtTestArray;i++){
        data[i]=abs(data[i]);
        f[i]=(double)((double)i*50.0)/lenghtTestArray;
    }
    std::ofstream newfile("Dupa.txt");
    if (newfile.is_open())
    {
        for (int i=0;i<lenghtTestArray;i++) {
            newfile << data[i].real()<<"\t"<<f[i]<<"\n";
        }
        newfile.close();
    }
*/
    return a.exec();
}
