#include <iostream>
#include "SortedType.h"
using namespace std;

int main() {

SortedType list1;
int value1=55;
int value2=77;
int value3=5;

list1.InsertItem(value1);
list1.InsertItem(value2);
list1.InsertItem(value3);
list1.Print();
    return 0;

}
