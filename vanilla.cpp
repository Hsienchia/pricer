#include "vanilla.h"

VanillaOption::VanillaOption(const payoff &_payoff, double _expiry) : thePayOff(_payoff), expiry(_expiry) {}

double VanillaOption::getExpiry() const
{
    return expiry;
}

double VanillaOption::getPayoff(double spot) const
{
    return thePayOff(spot);
}
