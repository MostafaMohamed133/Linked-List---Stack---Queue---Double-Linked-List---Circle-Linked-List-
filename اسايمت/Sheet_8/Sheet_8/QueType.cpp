
#include "QueType.h"


QueType::QueType(int max) {
    maxQue = max + 1;    // +1 to differentiate between full and empty states in a circular array
    front = maxQue - 1;  // front points to the position before the first item
    rear = maxQue - 1;   // rear points to the last item in the queue
    items = new ItemType[maxQue];  // Dynamically allocate memory for the queue
}

QueType::QueType() {
    maxQue = 501;        // Default size of the queue
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
}

QueType::~QueType() {
    delete[] items;  // Free the dynamically allocated memory
}

void QueType::MakeEmpty() {
    front = maxQue - 1;
    rear = maxQue - 1;
}

bool QueType::IsEmpty() const {
    return (rear == front);  // Queue is empty if rear equals front
}

bool QueType::IsFull() const {
    return ((rear + 1) % maxQue == front);  // Queue is full if rear + 1 wraps around to front
}

void QueType::Enqueue(ItemType newItem) {
    if (IsFull()) {
        throw FullQueue();  // Throw exception if the queue is full
    } else {
        rear = (rear + 1) % maxQue;  // Move rear forward circularly
        items[rear] = newItem;       // Add the item to the queue
    }
}

void QueType::Dequeue(ItemType& item) {
    if (IsEmpty()) {
        throw EmptyQueue();  // Throw exception if the queue is empty
    } else {
        front = (front + 1) % maxQue;  // Move front forward circularly
        item = items[front];           // Remove the item from the queue
    }
}
