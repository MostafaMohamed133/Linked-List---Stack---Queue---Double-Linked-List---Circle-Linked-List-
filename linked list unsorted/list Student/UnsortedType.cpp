#include "UnsortedType.h"
#include<iostream>
using namespace std;

UnsortedType::UnsortedType() {
    length = 0;
    head = nullptr;
    tail = nullptr;
}
UnsortedType::~UnsortedType() {
    MakeEmpty();
}

void UnsortedType::MakeEmpty() {
    if (head == nullptr) return;

    NodeType* tempPtr = head->next;
    NodeType* toDelete;

    while (tempPtr != head) {
        toDelete = tempPtr;
        tempPtr = tempPtr->next;
        delete toDelete;
    }

    delete head;
    head = nullptr;
    length = 0;
}

bool UnsortedType::IsFull() const {
    try {
        NodeType* node = new NodeType;
        delete node;
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

    if (head == nullptr) {
        head = newNode;
        newNode->next = newNode;  // points to itself

    } else {
        newNode->next = head->next;
        head->next = newNode;
    }

    head = newNode;
    length++;
}

void UnsortedType::DeleteItem(int item) {
    if (head == nullptr) return;

    NodeType* location = head->next;
    NodeType* prev = head   ;

    do {
        if (location->data == item) {
            if (location == head) {
                if (head == head->next) { // one node only
                    delete head;
                    head = nullptr;
                } else {
                    prev->next = location->next;
                    delete location;
                    head = prev;
                }
            } else {
                prev->next = location->next;
                delete location;
            }
            length--;
            return;
        }
        prev = location;
        location = location->next;
    } while (location != head->next);
}

void UnsortedType::RetrieveItem(int& item, bool& found) {
    if (head == nullptr) {
        found = false;
        return;
    }

    NodeType* temp = head->next;
    found = false;

    do {
        if (temp->data == item) {
            found = true;
            item = temp->data;
            return;
        }
        temp = temp->next;
    } while (temp != head->next);
}

void UnsortedType::ResetList() {
    CurrentPos = head;
}

void UnsortedType::GetNextItem(int& item) {
    if (CurrentPos == nullptr) return;
    CurrentPos = CurrentPos->next;
    item = CurrentPos->data;
}

void UnsortedType::Print() const {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    NodeType* temp = head->next;
    cout << "List contents: ";

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head->next);

    cout << endl;
}

/*
//circle
void UnsortedType::InsertItem(int item) {
    NodeType* newNode ;
    newNode->data = item;

    if (head == nullptr) {
        head = newNode;
        tail= newNode;
        tail->next=newNode;
    } else {
        newNode->next = head;
        head = newNode;
        newNode->next = newNode;    }
}
*/
/*
void UnsortedType::InsertItem(int item) {
    NodeType* newNode = new NodeType;
    newNode->data = item;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}


//circle
void UnsortedType::DeleteItem(int item) {
    if (head == nullptr) return;

    NodeType* location = head;
    NodeType* prev = tail;

    do {
        if (location->data == item) {
            if (location == head && location == tail) {

                delete location;
                head = nullptr;
                tail = nullptr;
            } else {
                prev->next = location->next;
                if (location == head)
                    head = head->next;
                if (location == tail)
                    tail = prev;
                delete location;
            }
            length--;
            return;
        }

        prev = location;
        location = location->next;
    } while (location != head);
}
*/
