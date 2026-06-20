// The following declarations and definitions go into file ItemType.h.
#include <fstream>

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
