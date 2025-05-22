#ifndef SPECIALCITY_H
#define SPECIALCITY_H
#include "City.h"
#include "ChallengeManager.h"

class specialCity : virtual public City {
protected:
    std::string mayorName;
    ChallengeManager& challengeManager;

public:
    specialCity(const std::string& name, int id, std::vector<Item> sell, std::vector<Item> demand,
                float city_capital, const std::string& mayor, ChallengeManager& cm);
    void tradeWith(Trader& trader) override;
};

#endif