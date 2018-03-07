#ifndef SIMPLEMC_H_
#define SIMPLEMC_H_
#include "vanilla.h"
#include "parameter.h"

double simpleMC(const VanillaOption& option, double spot,
                const parameter& vol, const parameter& r, unsigned long NumberOfPaths = 1000);

#endif 