#ifndef TRADER_H
#define TRADER_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

class Trader {
private:
    int money;
    std::vector<Item> inventory;

public:
    Trader(int money = 100);
    std::vector<Item> getInventory() const;
    void earn(int amount);
    void lose(int amount);
    bool canAfford(int amount) const;
    void add_item(Item item);
    void showInventory() const;
    void removeByName(const std::string& name);
};

#endif