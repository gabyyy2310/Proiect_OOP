#include "City.h"
#include <iostream>
#include <algorithm>
#include "Randomised.h"
using namespace std;

City::City(string name, int id, vector<Item> sell, vector<Item> demand, float city_capital)
    : name(name), id(id), item_to_sell(sell), item_demanded(demand), city_capital(city_capital) {}

string City::getName() const {
    return name;
}

int City::getId() const {
    return id;
}

void City::tradeWith(Trader& trader) {
    cout << "\n[Banker] Welcome to " << name << "!\n";
    cout << "[Banker] Are you looking for a specific item from our land?\n";
    string requested_item;
    cin >> requested_item;

    if (requested_item != "-") {
        auto p = find_if(item_to_sell.begin(), item_to_sell.end(), [&](const Item& item) {
            return item.getName() == requested_item;
        });

        if (p != item_to_sell.end()) {
            int price = randomPrice();
            cout << "\n[Banker] Yes, we have " << requested_item << "! The price we demand is: " << price << ". Accept?\n";
            char choice;
            cin >> choice;
            if (choice == 'y') {
                if (trader.canAfford(price)) {
                    trader.lose(price);
                    trader.add_item(*p);
                } else {
                    cout << "[Banker] Are you sure you want to make this transaction?\n";
                    char answer;
                    cin >> answer;
                    if (answer == 'y') {
                        trader.lose(price);
                    }
                }
            } else {
                cout << "[Banker] Offer declined by the client!\n";
            }
        } else {
            cout << "[Banker] We don't have " << requested_item << "!\n";
        }
    }

    cout << "[Banker] Do you want to offer something from your inventory to sell?\n";
    char response;
    cin >> response;
    if (response == 'y') {
        trader.showInventory();
        string offered_item;
        cout << "[Banker] What do you choose to offer?\n";
        cin >> offered_item;
        const auto& inventory = trader.getInventory();
        auto q = find_if(inventory.begin(), inventory.end(), [&](const Item& item) {
            return item.getName() == offered_item;
        });
        if (q != inventory.end()) {
            bool cityWants = any_of(item_demanded.begin(), item_demanded.end(), [&](const Item& d) {
                return d.getName() == q->getName();
            });
            if (cityWants) {
                int offered_price = randomPrice();
                cout << "[Banker] Yes, we need that! We will offer you the following price: " << offered_price << ".\n";
                trader.earn(offered_price);
                trader.removeByName(offered_item);
            } else {
                cout << "[Banker] We don't need this Item!\n";
            }
        } else {
            cout << "[System] You don't have this Item...\n";
        }
    }
    cout << "[Banker] That's all for now! Good luck!\n";
}
