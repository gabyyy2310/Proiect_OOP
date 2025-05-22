#include "Item.h"
using namespace std;

Item::Item(string name) : name(name) {}

string Item::getName() const {
    return name;
}

ostream& operator<<(ostream& os, const Item& item) {
    os << item.name;
    return os;
}

istream& operator>>(istream& is, Item& item) {
    is >> item.name;
    return is;
}
