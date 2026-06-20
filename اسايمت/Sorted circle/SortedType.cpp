#include "SortedType.h"
#include<iostream>
using namespace std;

SortedType::SortedType() {
    length = 0;
    head = nullptr;
    tail = nullptr;
}
SortedType::~SortedType() {
    MakeEmpty();
}

void SortedType::MakeEmpty() {
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

bool SortedType::IsFull() const {
    try {
        NodeType* node = new NodeType;
        delete node;
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

    // ÇáÍÇáÉ 1: ÇáŞÇÆãÉ İÇÖíÉ
    if (head == nullptr) {
        newNode->next = newNode;  // ÇáÚäÕÑ íÔíÑ áäİÓå
        head = newNode;
        tail = newNode;
    }
    // ÇáÍÇáÉ 2: ÇáÅÏÑÇÌ ŞÈá head (ÇáÚäÕÑ ÇáÌÏíÏ ÃÕÛÑ ãä ÇáÑÃÓ)
    else if (item < head->data) {
        newNode->next = head;
        tail->next = newNode;  // äÍÏË ÇáÑÈØ ãä ÇáĞíá Åáì ÇáÑÃÓ ÇáÌÏíÏ
        head = newNode;
    }
    // ÇáÍÇáÉ 3: ÅÏÑÇÌ İí ÇáæÓØ Ãæ ÇáäåÇíÉ
    else {
        NodeType* current = head;

        // äÈÍË Úä ÇáãßÇä ÇáÕÍíÍ
        while (current->next != head && current->next->data < item) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        // ÅĞÇ ÃÖİäÇå ÈÚÏ tail¡ äÍÏË tail
        if (current == tail) {
            tail = newNode;
        }
    }

    length++;
}

void SortedType::DeleteItem(int item) {
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

void SortedType::RetrieveItem(int& item, bool& found) {
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

void SortedType::ResetList() {
    CurrentPos = head;
}

void SortedType::GetNextItem(int& item) {
    if (CurrentPos == nullptr) return;
    CurrentPos = CurrentPos->next;
    item = CurrentPos->data;
}
void SortedType::Print() const {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    NodeType* temp = head;
    cout << "List contents: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
}


