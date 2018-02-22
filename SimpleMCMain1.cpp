#include <iostream>
#include <cmath>
#include "random.h"
using namespace std;

double SimpleMonteCarlo1(double expiry, double strike, double spot, double vol, double r, unsigned long NumberOfPaths = 1000)
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

int main()
{
    cout << "Assuming that the riskless rate of return is zero, " << endl;
    cout << "and the spot of the underlying is 100." << endl;
    cout << "The one-year vanilla option strikes at 100 is worth " << SimpleMonteCarlo1(1, 100, 100, 0.1, 0, 10000) << " now" << endl;
    return 0;
}