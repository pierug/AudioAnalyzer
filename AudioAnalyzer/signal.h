#ifndef SIGNAL_H
#define SIGNAL_H

#include <utility>
#include <vector>
#include <iostream>
#include "wavefile.h"

typedef std::pair<int, double> myPair;
typedef std::vector<myPair> myVector;

class Signal
{
public:
    Signal();
    Signal(myVector& vec);
    void setOscilogramValues(const myVector& vec);
    myVector getOscilogramValuesFromWav(WavFile &wavFile);
    myVector oscilographValues() const;
    void clearOscilograph();
    void toTxtFile(std::string dir);
private:
    myVector m_oscilographValues;
};

#endif // SIGNAL_H
