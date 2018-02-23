#include "payoff.h"
#include <algorithm>

payoffCall::payoffCall(double _strike) : strike(_strike) {}
payoffPut::payoffPut(double _strike) : strike(_strike) {}

double payoffCall::operator()(double _spot) const
{
    return std::max(_spot - strike, 0.0);
}

double payoffPut::operator()(double _spot) const
{
    return std::max(strike - _spot, 0.0);
}
