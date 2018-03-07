#ifndef PAYOFFBRIDGE_H_
#define PAYOFFBRIDGE_H_

#include "payoff.h"

class payoffBridge
{
  public:
    payoffBridge(const payoffBridge &origin);
    payoffBridge(const payoff &inner);

    inline double operator()(double spot) const;
    ~payoffBridge();
    payoffBridge &operator=(const payoffBridge &origin);

  private:
    payoff *thePayOff;
};

inline double payoffBridge::operator()(double spot) const
{
    return (*thePayOff)(spot);
}

#endif