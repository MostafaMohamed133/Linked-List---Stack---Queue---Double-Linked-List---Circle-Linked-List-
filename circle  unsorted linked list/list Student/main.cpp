#include <iostream>
#include <cstdlib>
#include <ctime>
#include "UnsortedType.h"
using namespace std;


int main() {
 UnsortedType list1;
 int value =99;
 int value2=55;
 int value3=5;

 list1.InsertItem(value2);
 list1.InsertItem(value3);
 list1.InsertItem(value);
 list1.Print();
return 0;
}
