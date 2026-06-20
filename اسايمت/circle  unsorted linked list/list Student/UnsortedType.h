#include "ItemType.h"

struct NodeType {
    int data;
    NodeType* next;
};
class UnsortedType {
public:
    UnsortedType();
    ~UnsortedType();
    void MakeEmpty();
    bool IsFull() const;
    int LengthIs() const;
    void RetrieveItem(int& item, bool& found);
    void InsertItem(int item);
    void DeleteItem(int item);
    void ResetList();
    void GetNextItem(int& item);
     void Print() const;

private:
    NodeType* head;
    int length;
   NodeType*CurrentPos;
    NodeType* tail;
};
