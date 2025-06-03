#include "StealItem.h"
#include <cstdlib>
using namespace std;

void StealItem::attemptTheft(Trader& trader) const {
    auto inventory = trader.getInventory();
    if (!inventory.empty()) {
        int index = rand() % inventory.size();
        string stolen = inventory[index].getName();
        trader.removeByName(stolen);
        cout << "[Thief] A thief stole your item: " << stolen << "!\n";
    } else {
        cout << "[Thief] The thief found nothing to steal!\n";
    }
}