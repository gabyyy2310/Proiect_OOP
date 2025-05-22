#ifndef DANGEROUSCITY_H
#define DANGEROUSCITY_H
#include "City.h"

class dangerousCity : virtual public City {
protected:
    int dangerLevel;

public:
    dangerousCity(const std::string& name, int id, std::vector<Item> sell, std::vector<Item> demand,
                  float city_capital, int level);
    void tradeWith(Trader& trader) override;
};

#endif