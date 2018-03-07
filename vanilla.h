#ifndef VANILLA_H_
#define VANILLA_H_

#include "payoff.h"

class VanillaOption
{
  public:
    VanillaOption(const payoff &_payoff, double _expiry);

    double getExpiry() const;
    double getPayoff(double spot) const;

  private:
    double expiry;
    payoff thePayOff;
};

#endif