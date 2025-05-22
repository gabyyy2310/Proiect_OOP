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

void Map::printMap() const {
    for (int i = 0; i < world_cities.size(); ++i) {
        cout << "City " << world_cities[i]->getName() << " (ID " << world_cities[i]->getId() << ") connects to:\n";
        for (const auto& road : roads_list[i]) {
            cout << "  -> " << world_cities[road.first]->getName() << " (cost " << road.second << ")\n";
        }
    }
}
