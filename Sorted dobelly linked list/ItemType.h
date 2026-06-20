
#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <fstream>

const int MAX_ITEMS = 5;
enum RelationType { LESS, GREATER, EQUAL };
template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType<ItemType>* next;
    NodeType<ItemType>* prev;
};
class ItemType {
public:
    ItemType();
    ItemType(int number);
    RelationType ComparedTo(ItemType) const;
    void Print(std::ofstream&) const;
    void Initialize(int number);
    int GetValue() const { return value; }

private:
    int value;
};

#endif

