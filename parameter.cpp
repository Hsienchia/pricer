#include "parameter.h"

parameter::parameter(const parameterInner &inner)
{
    para = inner.clone();
}

parameter::parameter(const parameter &origin)
{
    para = origin.para->clone();
}

parameter &parameter::operator=(const parameter &origin)
{
    if (this != &origin)
    {
        delete para;
        para = origin.para->clone();
    }
    return *this;
}

parameter::~parameter()
{
    delete para;
}

double parameter::mean(double init, double fin) const
{
    return integral(init, fin) / (fin - init);
}

double parameter::rms(double init, double fin) const
{
    return integralSqr(init, fin) / (fin - init);
}

constantPara::constantPara(double _constant)
{
    constant = _constant;
    constantSqr = _constant * _constant;
}

parameterInner *constantPara::clone() const
{
    return new constantPara(*this);
}

double constantPara::integral(double init, double fin) const
{
    return constant * (fin - init);
}

double constantPara::integral(double init, double fin) const
{
    return constantSqr * (fin - init);
}