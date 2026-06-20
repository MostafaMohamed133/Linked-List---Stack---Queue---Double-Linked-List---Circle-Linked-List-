#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <iostream>
const int MAX_ITEMS = 10;
class ItemType {
public:
    ItemType() : value(0) {}  // Default constructor
    ItemType(int number) : value(number) {}  // Constructor that accepts an int
    void Initialize(int number) { value = number; }
    int GetValue() const { return value; }
     // Overload << operator to print ItemType objects
    friend std::ostream& operator<<(std::ostream& os, const ItemType& item) {
        os << item.value;
        return os;
    }

private:
    int value;
};
#endif
