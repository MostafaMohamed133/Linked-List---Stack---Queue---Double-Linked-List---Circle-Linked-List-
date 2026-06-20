#include "UnsortedType.h"
#include <iostream>
using namespace std;

UnsortedType::UnsortedType() {
    head = nullptr;
    tail = nullptr;
    currentPos = nullptr;
    length = 0;
}

UnsortedType::~UnsortedType() {
    MakeEmpty();
}

void UnsortedType::MakeEmpty() {
    NodeType* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    length = 0;
}

bool UnsortedType::IsFull() const {
    try {
        NodeType* temp = new NodeType;
        delete temp;
        return false;
    } catch (...) {
        return true;
    }
}

int UnsortedType::LengthIs() const {
    return length;
}

void UnsortedType::InsertItem(int item) {
    NodeType* newNode = new NodeType;
    newNode->data = item;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr)
        head->prev = newNode;
    else
        tail = newNode; // Ãæá ÚäÕÑ

    head = newNode;
    length++;
}

void UnsortedType::DeleteItem(int item) {
    NodeType* current = head;

    while (current != nullptr) {
        if (current->data == item) {
            if (current->prev != nullptr)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next != nullptr)
                current->next->prev = current->prev;
            else
                tail = current->prev;

            delete current;
            length--;
            return;
        }
        current = current->next;
    }
}

void UnsortedType::RetrieveItem(int& item, bool& found) {
    NodeType* current = head;
    found = false;

    while (current != nullptr) {
        if (current->data == item) {
            found = true;
            item = current->data;
            return;
        }
        current = current->next;
    }
}

void UnsortedType::ResetList() {
    currentPos = nullptr;
}

void UnsortedType::GetNextItem(int& item) {
    if (currentPos == nullptr)
        currentPos = head;
    else
        currentPos = currentPos->next;

    if (currentPos != nullptr)
        item = currentPos->data;
}

void UnsortedType::Print() const {
    NodeType* temp = head;
    cout << "List contents: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
