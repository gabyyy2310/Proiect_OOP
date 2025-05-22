#ifndef METROPOLIS_H
#define METROPOLIS_H
#include "specialCity.h"
#include "dangerousCity.h"

class Metropolis : public specialCity, public dangerousCity {
public:
    Metropolis(const std::string& name, int id, std::vector<Item> sell, std::vector<Item> demand,
               float city_capital, const std::string& mayor, ChallengeManager& cm, int dangerLevel);

    void tradeWith(Trader& trader) override;
};

#endif