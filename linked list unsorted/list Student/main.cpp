#include <iostream>
#include <cstdlib>
#include <ctime>
#include "UnsortedType.h"
using namespace std;

int main() {

UnsortedType list1;

int u=5;
int y=88;
int z=99;
list1.InsertItem(z);
list1.InsertItem(y);
list1.InsertItem(u);

list1.Print();
return 0;
}
