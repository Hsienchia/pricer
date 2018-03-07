#include "stats.h"
using namespace std;

statsMean::statsMean() : runningSum(0.0), pathsDone(0UL) {}

void statsMean::dumpOne(double result)
{
    runningSum += result;
    pathsDone++;
}

vector<vector<double>> statsMean::getResSoFar() const
{
    return vector<vector<double>>(1, vector<double>(1, runningSum / pathsDone));
}

stats* statsMean::clone() const
{
    return new statsMean(*this);
}