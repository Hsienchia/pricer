#ifndef VANILLA_H_
#define VANILLA_H_

#include "payoff.h"

class VanillaOption
{
  public:
    VanillaOption(const payoff &_payoff, double _expiry);
    VanillaOption(const VanillaOption &origin);
    VanillaOption &operator=(const VanillaOption &origin);
    ~VanillaOption();

    double getExpiry() const;
    double getPayoff(double spot) const;

  private:
    double expiry;
    payoff *thePayOff;
};

#endif