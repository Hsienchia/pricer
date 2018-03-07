#include "simpleMC.h"
#include "random.h"
#include <cmath>

double simpleMC(const VanillaOption &option, double spot,
                const parameter &vol, const parameter &r, unsigned long NumberOfPaths)
{
    double expiry = option.getExpiry();
    double variance = vol.integralSqr(0, expiry);
    double movedSpot = spot * exp(r.integral(0, expiry) - 0.5 * variance);
    double runningSum = 0;
    double curSpot = 0;

    for (unsigned int i = 0; i < NumberOfPaths; ++i)
    {
        double GaussianRV = randn();
        curSpot = movedSpot * exp(sqrt(variance) * GaussianRV);
        double curPayoff = option.getPayoff(curSpot);
        runningSum += curPayoff;
    }

    double meanPayoff = runningSum / NumberOfPaths;
    meanPayoff *= exp(-r.integral(0, expiry));
    return meanPayoff;
}
