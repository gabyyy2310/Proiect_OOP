#ifndef MAP_H
#define MAP_H
#include <vector>
#include <list>
#include <memory>
#include "City.h"

class Map {
private:
    std::vector<std::shared_ptr<City>> world_cities;
    std::vector<std::list<std::pair<int, int>>> roads_list;

public:
    void add_city(std::shared_ptr<City> city);
    void add_road(int origin_id, int destination_id, int cost);
    void printMap() const;
};

#endif
