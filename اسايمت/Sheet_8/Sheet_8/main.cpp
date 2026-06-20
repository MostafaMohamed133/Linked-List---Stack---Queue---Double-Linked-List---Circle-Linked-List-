#include <iostream>
#include "ItemType.h"
#include "UnsortedType.h"
#include "SortedType.h"
#include "StackType.h"
#include "QueType.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    ItemType item;
    UnsortedType unsorted;
    SortedType sorted;
    StackType stack;
    QueType queue;
     srand(time(0));





    //unsorted insert
/*
    for(int i=1;i<=MAX_ITEMS;i++)
    {
        int random=rand()%100;
        item.Initialize(random);
        unsorted.InsertItem(item);
        cout<<"the value that inserted is   "<<item.GetValue()<<endl;
    }

cout<<"lenght is after insert items  "<<unsorted.LengthIs()<<endl;
cout<<"is list full = 1  or not = 0  "<<unsorted.IsFull()<<endl;

    for(int i=1;i<=2;i++)
    {
        unsorted.DeleteItem(item);
    }
cout<<"lenght is after delet items  "<<unsorted.LengthIs()<<endl;

*/

//sortde insert

/*
 for(int i=1;i<MAX_ITEMS;i++)
    {
        int random=rand()%100;
        item.Initialize(random);
        sorted.InsertItem(item);
        cout<<"the value that inserted is   "<<item.GetValue()<<endl;
    }

cout<<"lenght is after insert items  "<<sorted.LengthIs()<<endl;
cout<<"is list full = 1  or not = 0  "<<sorted.IsFull()<<endl;

    for(int i=1;i<=2;i++)
    {
        sorted.DeleteItem(item);
    }
cout<<"lenght is after delet items  "<<sorted.LengthIs()<<endl;


*/

//stack

/*

 for(int i=1;i<=MAX_ITEMS;i++)
    {
        int random=rand()%100;
        stack.Push(ItemType(random));
        cout<<"the value that pushed is   "<<stack.Top().GetValue()<<endl;
    }

cout<<"is stack Empty = 1 or not= 0  "<<stack.IsEmpty()<<endl;
cout<<"is list full = 1  or  not= 0  "<<stack.IsFull()<<endl;

    for(int i=1;i<=2;i++)
    {
      cout<<"the value that will be popped is "<<stack.Top().GetValue()<<endl;
        stack.Pop();
    }

cout<<"is stack Empty = 1 or not= 0  "<<stack.IsEmpty()<<endl;
cout<<"is list full = 1  or  not= 0  "<<stack.IsFull()<<endl;

*/



//queue


/*
 for(int i=1;i<MAX_ITEMS;i++)
    {
        int random=rand()%100;
        item.Initialize(random);
        queue.Enqueue(ItemType(random));
        cout<<"the value that Enqueued is   "<<item.GetValue()<<endl;
    }

cout<<"is queue Empty = 1 or not= 0  "<<queue.IsEmpty()<<endl;
cout<<"is queue full = 1  or  not= 0  "<<queue.IsFull()<<endl;

    for(int i=1;i<MAX_ITEMS;i++)
    {
      cout<<"the value that will be dequeue is "<<item.GetValue()<<endl;
        queue.Dequeue(item);
    }

cout<<"is queue Empty = 1 or not= 0  "<<queue.IsEmpty()<<endl;
cout<<"is queue full = 1  or  not= 0  "<<queue.IsFull()<<endl;


*/

// merge two un sorted list
  UnsortedType unsorted2;
  UnsortedType unsortedResult;

   for(int i=1;i<=3;i++)
    {
        int random=rand()%100;
        item.Initialize(random);
        unsorted.InsertItem(item);
        cout<<"the value that inserted is   "<<item.GetValue()<<endl;
    }
cout<<""<<endl;


   for(int i=1;i<=2;i++)
    {
        int random=rand()%100;
        item.Initialize(random);
        unsorted2.InsertItem(item);
        cout<<"the value that inserted is   "<<item.GetValue()<<endl;
    }


unsorted.MergeLists(unsorted2,unsortedResult);

for(int i=0; i<=unsortedResult.LengthIs();i++)
{
   cout<<item.GetValue()<<endl;
   unsortedResult.DeleteItem(item);

}



    return 0;
}
