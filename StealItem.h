#ifndef STEALITEM_H
#define STEALITEM_H
#include "TheftStrategy.h"
#include <iostream>

class StealItem : public TheftStrategy {
public:
    void attemptTheft(Trader& trader) const override;
};

#endif