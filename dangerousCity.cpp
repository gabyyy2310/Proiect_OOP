#include "dangerousCity.h"
#include <iostream>
using namespace std;

dangerousCity::dangerousCity(const string& name, int id, vector<Item> sell, vector<Item> demand,
                             float city_capital, int level)
    : City(name, id, sell, demand, city_capital), dangerLevel(level) {}

void dangerousCity::tradeWith(Trader& trader) {
    cout << "[DangerousCity] You are in a risky area. Be careful!\n";
    City::tradeWith(trader);
    if (dangerLevel > 0) {
        cout << "[DangerousCity] Thieves are lurking!\n";
        if (dangerLevel == 2 && !trader.getInventory().empty()) {
            trader.removeByName(trader.getInventory().front().getName());
            cout << "[Thief] One of your items was stolen!\n";
        } else {
            trader.lose(10 * dangerLevel);
            cout << "[Thief] You lost some money due to thievery!\n";
        }
    }
}