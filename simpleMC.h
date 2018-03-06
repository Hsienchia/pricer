#ifndef SIMPLEMC_H_
#define SIMPLEMC_H_
#include "vanilla.h"

double simpleMC(const VanillaOption& option, double spot,
                double vol, double r, unsigned long NumberOfPaths = 1000);

#endif 