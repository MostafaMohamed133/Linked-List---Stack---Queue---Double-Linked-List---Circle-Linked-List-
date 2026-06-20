#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

struct NodeType {
    int data;
    NodeType* next;
    NodeType* prev;
};

class UnsortedType {
public:
    UnsortedType();
    ~UnsortedType();

    void MakeEmpty();
    bool IsFull() const;
    int LengthIs() const;
    void InsertItem(int item);
    void DeleteItem(int item);
    void RetrieveItem(int& item, bool& found);
    void ResetList();
    void GetNextItem(int& item);
    void Print() const;

private:
    NodeType* head;
    NodeType* tail;
    NodeType* currentPos;
    int length;
};

#endif
