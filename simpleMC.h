#ifndef SIMPLEMC_H_
#define SIMPLEMC_H_
#include "vanilla.h"
#include "parameter.h"
#include "stats.h"

void simpleMC(const VanillaOption& option, double spot,
                const parameter& vol, const parameter& r, 
                stats& gatherer, unsigned long NumberOfPaths = 1000);

#endif 