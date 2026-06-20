#include <iostream>
#include "StackType.h"
#include <cstdlib>
#include <ctime>
using namespace std;

bool  Identical(StackType stack1,StackType stack2){

if (stack1.IsEmpty()&&stack2.IsEmpty()){
    cout<<"stack1 and stack2 are identical"<<endl;}
if (stack1.IsFull()&&stack2.IsFull()){
cout<<"stack1 and stack2 are identical"<<endl;
}
for(int i=0; i,MAX_ITEMS;i++)
{
   if (stack1.Top().GetValue()!=stack2.Top().GetValue())
   {
       cout<<"stack1 and stack2 are not identical  "<<endl;

   }

    stack1.Pop();
    stack2.Pop();
}







}

int main() {

StackType stack1;
StackType stack2;
ItemType item;
srand(time(0));

    // Fill both stacks with identical values
    for (int i = 0; i < MAX_ITEMS; i++) {
        int randomValue = rand() % 100;  // Generate a random number (0-99)

        ItemType item1, item2;
        item1.Initialize(randomValue);
        item2.Initialize(randomValue);  // Same value for both stacks

        stack1.Push(item1);
        stack2.Push(item2);

    }

    stack1.Push(ItemType (57));
    // Test if stacks are identical
    if (Identical(stack1, stack2))
        cout << "Stacks are identical!" << endl;
    else
        cout << "Stacks are NOT identical!" << endl;

    return 0;
}


