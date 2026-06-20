#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

struct NodeType {
    int data;
    NodeType* next;
    NodeType* prev;
};

class SortedType {
public:
    SortedType();
    ~SortedType();

    void MakeEmpty();
    bool IsFull() const;
    int LengthIs() const;
    void InsertItem(int item);
    void DeleteItem(int item);
    void RetrieveItem(int& item, bool& found);
    void ResetList();
    void GetNextItem(int& item);
    void Print() const;
    void PrintReverse() const;

private:
    NodeType* head;
    NodeType* tail;
    NodeType* currentPos;
    int length;
};

#endif
