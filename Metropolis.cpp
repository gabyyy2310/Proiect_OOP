#include "Metropolis.h"
#include <cstdlib>

Metropolis::Metropolis(const std::string& name, int id, std::vector<Item> sell, std::vector<Item> demand,
                       float city_capital, const std::string& mayor, ChallengeManager& cm, int dangerLevel)
    : City(name, id, sell, demand, city_capital),
      specialCity(name, id, sell, demand, city_capital, mayor, cm),
      dangerousCity(name, id, sell, demand, city_capital, dangerLevel) {}

void Metropolis::tradeWith(Trader& trader) {
    if (rand() % 2 == 0) {
        specialCity::tradeWith(trader);
    } else {
        dangerousCity::tradeWith(trader);
    }
}
