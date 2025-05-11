#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <random>
#include <unordered_map>
#include <ctime>
#include <list>
using namespace std;

class Item {
private:
    string name;

public:
    Item(string name) {
        this->name = name;
    }

    friend ostream& operator<<(ostream& os, const Item& item) {
        os << item.name;
        return os;
    }

    friend istream& operator>>(istream& is, Item& item) {
        is >> item.name;
        return is;
    }
};

class City {
private:
    string name;
    int id;
    vector<Item> item_to_sell;
    vector<Item> item_demanded;
    float city_capital;

public:
    City(string name, int id, vector<Item> sell, vector<Item> demand, float city_capital) {
        this->name = name;
        this->id = id;
        this->item_to_sell = sell;
        this->item_demanded = demand;
        this->city_capital = city_capital;
    }

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    friend istream& operator>>(istream& is, City& city) {
        is >> city.name;
        is >> city.id;
        return is;
    }

    friend ostream& operator<<(ostream& os, const City& city) {
        os << city.name << " (ID: " << city.id << ")";
        return os;
    }
};

class Map {
private:
    vector<City> world_cities;
    vector<list<pair<int, int>>> roads_list;

public:
    void add_city(const City& city) {
        world_cities.push_back(city);
        roads_list.push_back(list<pair<int, int>>());
    }

    void add_road(int origin_id, int destination_id, int cost) {
        roads_list[origin_id].push_back({destination_id, cost});
        roads_list[destination_id].push_back({origin_id, cost});
    }

    void printMap() {
        for (int i = 0; i < world_cities.size(); ++i) {
            cout << "City " << world_cities[i].getName() << " (ID " << world_cities[i].getId() << ") connects to:\n";
            for (const auto& road : roads_list[i]) {
                cout << "  -> " << world_cities[road.first].getName() << " (cost " << road.second << ")\n";
            }
        }
    }
};

int main() {

    return 0;
}
