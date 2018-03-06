#include "payoff.h"
#include <algorithm>

payoffCall::payoffCall(double _strike) : strike(_strike) {}
payoffPut::payoffPut(double _strike) : strike(_strike) {}
payoffDoubleDigital::payoffDoubleDigital(double _lower, double _upper) : lower(_lower), upper(_upper) {}

payoff *payoffCall::clone() const
{
    return new payoffCall(*this);
}

payoff *payoffPut::clone() const
{
    return new payoffPut(*this);
}

payoff *payoffDoubleDigital::clone() const
{
    return new payoffDoubleDigital(*this);
}

double payoffCall::operator()(double _spot) const
{
    return std::max(_spot - strike, 0.0);
}

double payoffPut::operator()(double _spot) const
{
    return std::max(strike - _spot, 0.0);
}

double payoffDoubleDigital::operator()(double _spot) const
{
    if (_spot < lower || _spot > upper)
        return 0.0;
    return 1.0;
}
