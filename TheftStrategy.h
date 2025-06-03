#ifndef THEFTSTRATEGY_H
#define THEFTSTRATEGY_H
#include "Trader.h"

class TheftStrategy {
public:
    virtual void attemptTheft(Trader& trader) const = 0;
    virtual ~TheftStrategy() = default;
};

#endif