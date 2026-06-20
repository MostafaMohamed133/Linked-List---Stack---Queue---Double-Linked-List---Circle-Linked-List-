#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <fstream>
using namespace std;
const int MAX_ITEMS = 10;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ofstream&) const;
  void Initialize(int number);
    int GetValue()const {return value;}

private:
  int value;
};

#endif // ITEMTYPE_H

