#include "StackType.h"
#include <iostream>

StackType::StackType() {
    top = -1;  // Stack starts empty
}

bool StackType::IsFull() const {
    return (top == MAX_ITEMS - 1);  // Stack is full if top is at MAX_ITEMS - 1
}

bool StackType::IsEmpty() const {
    return (top == -1);  // Stack is empty if top is -1
}

void StackType::Push(ItemType newItem) {
    if (IsFull()) {
        throw FullStack();  // Throw an exception if the stack is full
    } else {
        top++;  // Move the top pointer
        items[top] = newItem;  // Add the item to the stack
    }
}

void StackType::Pop() {
    if (IsEmpty()) {
        throw EmptyStack();  // Throw an exception if the stack is empty
    } else {
        top--;  // Move the top pointer to remove the item
    }
}

ItemType StackType::Top() {
    if (IsEmpty()) {
        throw EmptyStack();  // Throw an exception if the stack is empty
    } else {
        return items[top];  // Return the top item
    }
}

void StackType::print() const {
    if (IsEmpty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack contents (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            std::cout << items[i].GetValue() << " ";
        }
        std::cout << std::endl;
    }
}

