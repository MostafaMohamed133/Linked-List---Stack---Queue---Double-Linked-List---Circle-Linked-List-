#include "StackType.h"
#include <iostream>
#include "ItemType.h"
using namespace std;

StackType::StackType( )
{
top = -1;
}
bool StackType::IsEmpty() const
{
return(top == -1);
}
bool StackType::IsFull() const
{
return (top == MAX_ITEMS-1);
}
void StackType::Push(ItemType newItem)
{
if( IsFull() )
throw FullStack();
top++;
items[top] = newItem;
}
void StackType::Pop()
{
if( IsEmpty() )
throw EmptyStack();
top--;
}
ItemType StackType::Top()
{
if (IsEmpty())
throw EmptyStack();
return items[top];
}
void StackType::print() const {
    if (IsEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack elements (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << items[i].GetValue() << " ";  // Print values using GetValue()
    }
    cout << endl;
}
