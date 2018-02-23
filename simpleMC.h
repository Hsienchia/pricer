#ifndef SIMPLEMC_H_
#define SIMPLEMC_H_
#include "payoff.h"

double simpleMC(const payoff &_payoff, double expiry, double spot,
                double vol, double r, unsigned long NumberOfPaths = 1000);

#endif 