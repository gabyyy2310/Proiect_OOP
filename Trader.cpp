#include "Trader.h"
#include <algorithm>
using namespace std;

Trader::Trader(int money) : money(money) {}

vector<Item> Trader::getInventory() const {
    return inventory;
}

void Trader::earn(int amount) {
    money += amount;
    cout << "[Earn] Trader gains " << amount << ". Total now: " << money << endl;
}

void Trader::lose(int amount) {
    money -= amount;
    if (money > 0)
        cout << "[Lose] Trader loses " << amount << ". Total now: " << money << endl;
    else {
        cout << "[Game Over] You have no money left!";
        exit(0);
    }
}

bool Trader::canAfford(int amount) const {
    return amount <= money;
}

void Trader::add_item(Item item) {
    inventory.push_back(item);
}

void Trader::showInventory() const {
    for (const auto& item : inventory) {
        cout << item.getName() << "\n";
    }
}

void Trader::removeByName(const string& name) {
    auto p = find_if(inventory.begin(), inventory.end(), [&](const Item& item) {
        return item.getName() == name;
    });
    if (p != inventory.end()) {
        inventory.erase(p);
    } else {
        cout << "[Inventory] Item \"" << name << "\" not found in inventory.\n";
    }
}