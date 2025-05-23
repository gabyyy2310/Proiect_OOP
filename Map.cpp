#include "Map.h"
#include <iostream>
using namespace std;

void Map::add_city(shared_ptr<City> city) {
    world_cities.push_back(city);
    roads_list.push_back({});
}

void Map::add_road(int origin_id, int destination_id, int cost) {
    roads_list[origin_id].push_back({destination_id, cost});
    roads_list[destination_id].push_back({origin_id, cost});
}

std::shared_ptr<City> Map::getCity(int id) const {
    if (id >= 0 && id < world_cities.size()) {
        return world_cities[id];
    }
    return nullptr;
}

const std::list<std::pair<int, int>>& Map::getNeighbors(int cityId) const {
    return roads_list[cityId];
}

void Map::printMap() const {
    for (int i = 0; i < world_cities.size(); ++i) {
        cout << "City " << world_cities[i]->getName() << " (ID " << world_cities[i]->getId() << ") connects to:\n";
        for (const auto& road : roads_list[i]) {
            cout << "  -> " << world_cities[road.first]->getName() << " (cost " << road.second << ")\n";
        }
    }
}

void Map::printCityDetails() const {
    for (const auto& city : world_cities) {
        cout << "City \"" << city->getName() << "\" (ID: " << city->getId() << ")\n";

        if (dynamic_cast<const Metropolis*>(city.get())) {
            cout << "  Type: Metropolis\n";
        } else if (dynamic_cast<const specialCity*>(city.get())) {
            cout << "  Type: Special City\n";
        } else if (dynamic_cast<const dangerousCity*>(city.get())) {
            cout << "  Type: Dangerous City\n";
        } else {
            cout << "  Type: Normal City\n";
        }

        cout << "  Sells: ";
        for (const auto& item : city->getItemsToSell())
            cout << item.getName() << " ";
        cout << "\n  Demands: ";
        for (const auto& item : city->getItemsDemanded())
            cout << item.getName() << " ";
        cout << "\n\n";
    }
}


