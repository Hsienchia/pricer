#include "vanilla.h"

VanillaOption::VanillaOption(const payoff &_payoff, double _expiry)
{
    expiry = _expiry;
    thePayOff = _payoff.clone();
}

VanillaOption::VanillaOption(const VanillaOption &origin)
{
    expiry = origin.expiry;
    thePayOff = origin.thePayOff->clone();
}

VanillaOption &VanillaOption::operator=(const VanillaOption &origin)
{
    if (this != &origin)
    {
        expiry = origin.expiry;
        delete thePayOff;
        thePayOff = origin.thePayOff->clone();
    }
    return *this;
}

double VanillaOption::getExpiry() const
{
    return expiry;
}

double VanillaOption::getPayoff(double spot) const
{
    return (*thePayOff)(spot);
}
