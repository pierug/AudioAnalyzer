#include "signal.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include "wavefile.h"

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
    long int fileSize=wavFile.size();//wavFile.size()/wavFile.fileFormat().sampleSize();
    char dat[fileSize];
    wavFile.read(dat,fileSize);
    const double sampleRateSec = 1.0/wavFile.fileFormat().sampleRate();
    for(long int i=0;i<fileSize;i++){
       myPair p((int)dat[i],i*sampleRateSec);
        data.push_back(p);
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
