#include "payoff.h"
#include <algorithm>

payoff::payoff(const payoff &origin)
{
    thePayOff = origin.thePayOff->clone();
}

payoff::payoff(const payoffInner &inner)
{
    thePayOff = inner.clone();
}

payoff::~payoff()
{
    delete thePayOff;
}

payoff &payoff::operator=(const payoff &origin)
{
    if (this != &origin)
    {
        delete thePayOff;
        thePayOff = origin.thePayOff->clone();
    }
    return *this;
}

payoffCall::payoffCall(double _strike) : strike(_strike) {}
payoffPut::payoffPut(double _strike) : strike(_strike) {}
payoffDoubleDigital::payoffDoubleDigital(double _lower, double _upper) : lower(_lower), upper(_upper) {}

payoffInner *payoffCall::clone() const
{
    return new payoffCall(*this);
}

payoffInner *payoffPut::clone() const
{
    return new payoffPut(*this);
}

payoffInner *payoffDoubleDigital::clone() const
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
