#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <limits>
#include <list>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "Trader.h"
#include "City.h"
#include "specialCity.h"
#include "dangerousCity.h"
#include "Metropolis.h"
#include "ChallengeManager.h"
#include "StealItem.h"
#include "StealMoney.h"
#include "Map.h"

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void displayMenu(int currentCityId, const string& cityName) {
    cout << "\n========= MAIN MENU =========\n";
    cout << "Current location: " << cityName << " (ID " << currentCityId << ")\n";
    cout << "1. View current inventory\n";
    cout << "2. View map\n";
    cout << "3. Travel to city\n";
    cout << "4. Exit\n";
    cout << "5. View city details\n";
    cout << "6. Preview a specific city\n";
    cout << "Choose an option: ";
}

int main() {
    Trader player(100);
    ChallengeManager cm;
    cm.loadChallenges("C:/Users/laura/CLionProjects/ProiectOOP-Gabriela/challenges.txt");

    vector<Item> globalItems = {
        Item("Gold"), Item("Spices"), Item("Silk"), Item("Weapons"),
        Item("Herbs"), Item("Wine"), Item("Salt"), Item("Jewels")
    };

    Map worldMap;

    // Create cities
    for (int i = 0; i < 4; ++i) {
        auto city = make_shared<City>("City" + to_string(i + 1), i, vector<Item>{globalItems[i]}, vector<Item>{globalItems[(i+1)%globalItems.size()]}, 500.0);
        worldMap.add_city(city);
    }

    for (int i = 4; i < 8; ++i) {
        auto dcity = make_shared<dangerousCity>("DangerCity" + to_string(i - 3), i, vector<Item>{globalItems[i % globalItems.size()]}, vector<Item>{globalItems[(i+2)%globalItems.size()]}, 600.0, rand()%5+1);
        dcity->addThiefStrategy(make_shared<StealItem>());
        dcity->addThiefStrategy(make_shared<StealMoney>(cm));
        worldMap.add_city(dcity);
    }

    for (int i = 8; i < 10; ++i) {
        auto scity = make_shared<specialCity>("SpecialCity" + to_string(i - 7), i, vector<Item>{globalItems[i % globalItems.size()]}, vector<Item>{globalItems[(i+3)%globalItems.size()]}, 700.0, "Mayor" + to_string(i), cm);
        worldMap.add_city(scity);
    }

    for (int i = 10; i < 12; ++i) {
        auto metro = make_shared<Metropolis>("Metropolis" + to_string(i - 9), i, vector<Item>{globalItems[i % globalItems.size()]}, vector<Item>{globalItems[(i+4)%globalItems.size()]}, 1000.0, "MayorMetropolis" + to_string(i), cm, rand()%5+1);
        metro->addThiefStrategy(make_shared<StealItem>());
        worldMap.add_city(metro);
    }

    // Connect cities (simplified)
    for (int i = 0; i < 11; ++i) {
        worldMap.add_road(i, i + 1, rand()%50 + 10);
    }

    int currentCityId = 0;
    int choice;
    while (true) {
        clearScreen();
        displayMenu(currentCityId, worldMap.getCity(currentCityId)->getName());
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[Error] Invalid input. Try again.\n";
            pause();
            continue;
        }

        if (choice == 1) {
            cout << "\n[Inventory]\n";
            player.showInventory();
            pause();
        } else if (choice == 2) {
            worldMap.printMap();
            pause();
        } else if (choice == 3) {
            cout << "\nYou are currently in: City " << currentCityId << "\n";
            cout << "Where would you like to go? Available destinations:\n";

            for (const auto& [neighborId, cost] : worldMap.getNeighbors(currentCityId)) {
                cout << " - City ID " << neighborId << " (cost: " << cost << ")\n";
            }

            int cid;
            cin >> cid;

            bool validMove = false;
            for (const auto& [neighborId, _] : worldMap.getNeighbors(currentCityId)) {
                if (neighborId == cid) {
                    validMove = true;
                    break;
                }
            }

            if (validMove) {
                cout << "\n--- TRAVELING TO CITY " << cid << " ---\n";
                currentCityId = cid;
                worldMap.getCity(cid)->tradeWith(player);
            } else {
                cout << "[Error] You can't travel there directly!\n";
            }
            pause();
        } else if (choice == 4) {
            cout << "\nThank you for playing!\n";
            break;
        } else if (choice == 5) {
            worldMap.printCityDetails();
            pause();
        } else if (choice == 6) {
            cout << "\nEnter city ID to preview (0 to 11): ";
            int cid;
            cin >> cid;
            if (cid >= 0 && cid < 12) {
                auto city = worldMap.getCity(cid);
                cout << "\nCity Name: " << city->getName() << " (ID: " << city->getId() << ")\n";
                cout << "  Sells: ";
                for (const auto& item : city->getItemsToSell())
                    cout << item.getName() << " ";
                cout << "\n  Demands: ";
                for (const auto& item : city->getItemsDemanded())
                    cout << item.getName() << " ";
                cout << "\n";
            } else {
                cout << "[Error] Invalid city ID.\n";
            }
            pause();
        } else {
            cout << "[Error] Unknown choice. Try again.\n";
            pause();
        }
    }

    return 0;
}
