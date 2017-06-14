#ifndef FASTFOURIERTRANSFORMATION_H
#define FASTFOURIERTRANSFORMATION_H
#include <complex>
#include <iostream>
#include <valarray>
#include <fstream>
#include <cmath>

const double PI = 3.141592653589793238460;

using namespace std;

typedef complex<double> Complex;
typedef valarray<Complex> ComplexArray;

class FastFourierTransformation
{
public:
    FastFourierTransformation();
    void setFftWindowSize(int value);
    void fft(ComplexArray& x)
    {
        const size_t N = x.size();
        if (N <= 1)
            return;
        ComplexArray even = x[std::slice(0, N/2, 2)];
        ComplexArray  odd = x[std::slice(1, N/2, 2)];

        fft(even);
        fft(odd);
        for (size_t k = 0; k < N/2; ++k)
        {
            Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
            x[k] = even[k] + t;
            x[k+N/2] = even[k] - t;
        }
    }

    void calculateRecursiveCooleyTukeyFFT(ComplexArray& x)
    {
        const size_t N = x.size();
        if (N <= 1)
            return;
        ComplexArray even = x[slice(0, N/2, 2)];
        ComplexArray  odd = x[slice(1, N/2, 2)];

        calculateRecursiveCooleyTukeyFFT(even);
        calculateRecursiveCooleyTukeyFFT(odd);
        for (size_t k = 0; k < N/2; ++k)
        {
            Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
            x[k] = even[k] + t;
            x[k+N/2] = even[k] - t;
        }
    }

    void toTxtFile(string dir, ComplexArray& x)
    {
        ofstream newfile(dir);
        if (newfile.is_open())
        {
            const size_t N = x.size();

            for (size_t i=0; i<N; i++) {
                newfile << x[i].real()<<"\t"<<x[i].imag()<<"\n";
            }
            newfile.close();
        }
    }

    void calculateSpectrum(ComplexArray& x){
        const size_t N = x.size();
        spectrum.clear();
        for (size_t i=0; i<N; i++) {
            spectrum.push_back(abs(sqrt(pow(x[i].real(),2)+pow(x[i].imag(),2))));
        }
    }

    vector<double> calculateMagnitude(ComplexArray& x){
        vector<double> magnitude;
        ComplexArray absoluteComplex = x;
        for(int i=0;i<absoluteComplex.size();i++){
            absoluteComplex[i]=abs(x[i]);
            magnitude.push_back(absoluteComplex[i].real());
        }
        return magnitude;
    }

    vector<double> calculateFrequency(int samples){
        vector<double> frequency;
        for(int i=0;i<samples;i++){
            frequency.push_back(((double)i/(double)samples));
        }
        return frequency;
    }

    ComplexArray shortTimeFFT(ComplexArray& x, int start, int windowLenght)
    {
        const unsigned long int N = x.size();
        if(N<start+windowLenght){
            ComplexArray nothing;
            return nothing;
        }
        Complex windowedInput[windowLenght];
        for(int i=0;i<windowLenght;i++){
            windowedInput[i] = x[i+start];
        }
        ComplexArray result(windowedInput,windowLenght);
        calculateRecursiveCooleyTukeyFFT(result);
        return result;
    }

    void spectrumToTxt(string dir)
    {
        ofstream newfile(dir);
        if (newfile.is_open())
        {
            for (size_t i=0; i<spectrum.size(); i++) {
                newfile << spectrum.at(i)<<"\t"<<i<<"\n";
            }
            newfile.close();
        }
    }
private:
    int fftWindowSize;
    vector<double> spectrum;
};

#endif // FASTFOURIERTRANSFORMATION_H
