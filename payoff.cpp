#include "payoff.h"
#include <algorithm>

payoff::payoff(double _strike, OptionType _type) : strike(_strike), type(_type) {}

double payoff::operator()(double spot) const
{
    switch (type)
    {
    case call:
        return std::max(spot - strike, 0.0);
    case put:
        return std::max(strike - spot, 0.0);
    default:
        throw("Unknown option type found.");
    }
}
