#include <iostream>
#include "SortedType.h"
#include "SortedType.cpp"

using namespace std;

int main() {

SortedType list1;

int value1=77;
int value2=66;
int value3=7;

list1.InsertItem(value3);
list1.InsertItem(value1);
list1.InsertItem(value2);
list1.Print();

    return 0;

}
