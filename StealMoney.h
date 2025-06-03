#ifndef STEALMONEY_H
#define STEALMONEY_H
#include "TheftStrategy.h"
#include "ChallengeManager.h"

class StealMoney : public TheftStrategy {
private:
    ChallengeManager& challengeManager;

public:
    StealMoney(ChallengeManager& cm);
    void attemptTheft(Trader& trader) const override;
};

#endif