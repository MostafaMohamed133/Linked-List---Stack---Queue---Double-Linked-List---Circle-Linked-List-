#include "SortedType.h"
#include <iostream>
using namespace std;

SortedType::SortedType() {
    head = nullptr;
    tail = nullptr;
    currentPos = nullptr;
    length = 0;
}

SortedType::~SortedType() {
    MakeEmpty();
}

void SortedType::MakeEmpty() {
    NodeType* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    length = 0;
}

bool SortedType::IsFull() const {
    try {
        NodeType* temp = new NodeType;
        delete temp;
        return false;
    } catch (...) {
        return true;
    }
}

int SortedType::LengthIs() const {
    return length;
}

void SortedType::InsertItem(int item) {
    NodeType* newNode = new NodeType;
    newNode->data = item;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {

        head = tail = newNode;
    }
    else if (item < head->data) {

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {

        NodeType* current = head;

        while (current->next != nullptr && current->next->data < item) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;

        if (newNode->next != nullptr)
            newNode->next->prev = newNode;
        else
            tail = newNode;
    }

    length++;
}

void SortedType::DeleteItem(int item) {
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

void SortedType::RetrieveItem(int& item, bool& found) {
    NodeType* current = head;
    found = false;

    while (current != nullptr && current->data <= item) {
        if (current->data == item) {
            found = true;
            item = current->data;
            return;
        }
        current = current->next;
    }
}

void SortedType::ResetList() {
    currentPos = nullptr;
}

void SortedType::GetNextItem(int& item) {
    if (currentPos == nullptr)
        currentPos = head;
    else
        currentPos = currentPos->next;

    if (currentPos != nullptr)
        item = currentPos->data;
}

void SortedType::Print() const {
    NodeType* temp = head;
    cout << "List (forward): ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void SortedType::PrintReverse() const {
    NodeType* temp = tail;
    cout << "List (reverse): ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
