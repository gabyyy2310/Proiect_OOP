#ifndef CITY_H
#define CITY_H
#include <string>
#include <vector>
#include "Item.h"
#include "Trader.h"

class City {
protected:
    std::string name;
    int id;
    std::vector<Item> item_to_sell;
    std::vector<Item> item_demanded;
    float city_capital;

public:
    City(std::string name, int id, std::vector<Item> sell, std::vector<Item> demand, float city_capital);
    virtual ~City() = default;

    virtual void tradeWith(Trader& trader);

    std::string getName() const;
    int getId() const;
};

#endif