#include "signal.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include "wavefile.h"

#define HEADER_LENGHT 44

Signal::Signal()
{

}

Signal::Signal(myVector &vec)
{
    m_oscilographValues = vec;
}

void Signal::setOscilogramValues(const myVector &vec)
{
    m_oscilographValues = vec;
}

myVector Signal::getOscilogramValuesFromWav(WavFile& wavFile)
{
    myVector data;
    long int fileSize=wavFile.size();
    int sampleSize = wavFile.fileFormat().sampleSize();
    char dat[fileSize];
    wavFile.read(dat,fileSize);
    const double sampleRateSec = 1.0/wavFile.fileFormat().sampleRate();
    int bondedValue=0;
    int fileBytes = sampleSize/8;
    for(long int i=HEADER_LENGHT, sec=0;i<fileSize;i=i+fileBytes, sec++){
        bondedValue=0;
        for(int j=0; j<fileBytes;j++){
            bondedValue = bondedValue<<8;
            bondedValue |= dat[i+j];
        }
        myPair newValue(bondedValue,sec*sampleRateSec);
        data.push_back(newValue);
    }
    return data;
}

myVector Signal::oscilographValues() const
{
    return m_oscilographValues;
}

void Signal::clearOscilograph()
{
    m_oscilographValues.clear();
}

void Signal::toTxtFile(std::string dir)
{
    std::ofstream newfile(dir);
    if (newfile.is_open())
    {
        for (myPair p:m_oscilographValues) {
            newfile << p.first<<",\t"<<p.second<<"\n";
        }
        newfile.close();
    }
}
