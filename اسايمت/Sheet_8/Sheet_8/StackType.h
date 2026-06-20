#ifndef STACKTYPE_H
#define STACKTYPE_H

#include "ItemType.h"

class FullStack {};
class EmptyStack {};

class StackType {
public:
    StackType();        // Constructor
    bool IsFull() const; // Returns true if the stack is full
    bool IsEmpty() const; // Returns true if the stack is empty
    void Push(ItemType newItem); // Adds an item to the stack
    void Pop();           // Removes the top item from the stack
    ItemType Top();       // Returns the top item of the stack
    void print() const;   // Prints all items from top to bottom

private:
    int top;              // Points to the top of the stack
    ItemType items[MAX_ITEMS]; // Array to store stack elements
};

#endif

