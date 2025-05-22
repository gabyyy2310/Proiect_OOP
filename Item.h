#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

class Item {
private:
    std::string name;

public:
    Item(std::string name = "");
    std::string getName() const;

    friend std::ostream& operator<<(std::ostream& os, const Item& item);
    friend std::istream& operator>>(std::istream& is, Item& item);
};

#endif
