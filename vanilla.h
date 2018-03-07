#ifndef VANILLA_H_
#define VANILLA_H_

#include "payoff.h"
#include "payoffbridge.h"

class VanillaOption
{
  public:
    VanillaOption(const payoffBridge &_payoff, double _expiry);

    double getExpiry() const;
    double getPayoff(double spot) const;

  private:
    double expiry;
    payoffBridge thePayOff;
};

#endif