
#include "ItemType.h"

class FullStack {};
class EmptyStack {};

class StackType {
public:
    StackType();
    bool IsFull() const;
    bool IsEmpty() const;
    void Push(ItemType item);
    void Pop();
    ItemType Top();
    void print() const;
// Function: Prints all elements of the stack from top to bottom.


private:
    int top;
    ItemType items[MAX_ITEMS];
};


