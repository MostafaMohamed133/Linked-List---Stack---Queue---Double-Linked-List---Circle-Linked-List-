#ifndef QUETYPE_H
#define QUETYPE_H

#include "ItemType.h"

class FullQueue {};
class EmptyQueue {};

class QueType {
public:
    QueType(int max);   // Constructor with a parameter for max size
    QueType();          // Default constructor
    ~QueType();         // Destructor

    void MakeEmpty();   // Clears the queue
    bool IsEmpty() const;  // Returns true if the queue is empty
    bool IsFull() const;   // Returns true if the queue is full
    void Enqueue(ItemType newItem); // Adds an item to the queue
    void Dequeue(ItemType& item);  // Removes an item from the queue

private:
    int front;           // Points to the front of the queue
    int rear;            // Points to the rear of the queue
    int maxQue;          // Maximum size of the queue
    ItemType* items;     // Dynamically allocated array to hold the queue items
};

#endif
