#include "payoff.h"
#include <MinMax.h>

payoff::payoff(double _strike, OptionType _type) : strike(_strike), type(_type) {}

double payoff::operator()(double spot) const
{
    switch (type)
    {
    case call:
        return max(spot - strike, 0.0);
    case put:
        return max(strike - spot, 0.0);
    default:
        throw("Unknown option type found.");
    }
}
