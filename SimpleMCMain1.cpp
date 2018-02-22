#include <iostream>
#include <cmath>
#include "random.h"
using namespace std;

double SimpleMonteCarlo1(double expiry, double strike, double spot, double vol, double r, unsigned long NumberOfPaths)
{
    double variance = vol * vol * expiry;
    double movedSpot = spot * exp(r * expiry - 0.5 * variance);
    double runningSum = 0;
    double curSpot = 0;

    for (unsigned int i = 0; i < NumberOfPaths; ++i)
    {
        double GaussianRV = randn();
        curSpot = movedSpot * exp(sqrt(variance) * GaussianRV);
        double curPayoff = (curSpot > strike) ? curSpot - strike : 0;
        runningSum += curPayoff;
    }

    double meanPayoff = runningSum / NumberOfPaths;
    meanPayoff *= exp(-r * expiry);
    return meanPayoff;
}