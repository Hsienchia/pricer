#include "payoffbridge.h"

payoffBridge::payoffBridge(const payoffBridge &origin)
{
    thePayOff = origin.thePayOff->clone();
}

payoffBridge::payoffBridge(const payoff &inner)
{
    thePayOff = inner.clone();
}

payoffBridge::~payoffBridge()
{
    delete thePayOff;
}

payoffBridge &payoffBridge::operator=(const payoffBridge &origin)
{
    if (this != &origin)
    {
        delete thePayOff;
        thePayOff = origin.thePayOff->clone();
    }
    return *this;
}