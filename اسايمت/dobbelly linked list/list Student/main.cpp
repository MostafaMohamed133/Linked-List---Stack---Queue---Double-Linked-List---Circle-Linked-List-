/*(1)
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "UnsortedType.h"
using namespace std;

int main() {
 UnsortedType list;
 int item;
 srand(time(0));

 for(int i=0; i< 10; i++)
 {
     int random=rand()%1000;
     list.InsertItem(random);
     cout<<"the number is   "<<random<<endl;


 }

 cout<<"are list is full or not  "<<list.IsFull() <<endl;
 cout<<" length of the list is   "<<list.LengthIs()<<endl;
 list.Print();

list.DeleteItem(item);
list.MakeEmpty();
 cout<<"are list is full or not  "<<list.IsFull() <<endl;



return 0;
}

*/

/*

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "UnsortedType.h"
using namespace std;

int main() {
 UnsortedType list;
 srand(time(0));

 for(int i=0; i< 10; i++)
 {
     int random=rand()%1000;
     list.InsertItem(random);
     cout<<"the number is   "<<random<<endl;


 }

 cout<<"are list is full or not  "<<list.IsFull() <<endl;
 cout<<" length of the list is   "<<list.LengthIs()<<endl;




return 0;
}

*/

/*(3)

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "UnsortedType.h"
using namespace std;
double CalcAvg(int item,UnsortedType list)
{
    int sum=0;
    int num=list.LengthIs();

    list.ResetList();

    for(int i=0; i<list.LengthIs();i++)
    {
       cout<<"the value of item is  "<< item<<endl;
        list.GetNextItem(item);
        sum+=item;

    }

    return sum/num;

}

int main() {
 UnsortedType list;
srand(time(0));


for(int i =0; i<= 10;i++)
 {
     int random=rand()%1000;
     list.InsertItem(random);

 }

int item;

cout<<"the average is"<< CalcAvg(item,list)<<endl;

return 0;
}

*/

/*(4)

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "UnsortedType.h"
using namespace std;

int CalcMax(int item,UnsortedType list){

int MaxValue=0;
list.ResetList();

for(int i=0;i<list.LengthIs();i++)
{

    cout<<item<<endl;
    if(item>MaxValue)
    {
        MaxValue=item;


    }
    list.GetNextItem(item);
}
cout<<"the max value is   "<<MaxValue<<endl;

}


int main() {
 UnsortedType list;
 int item;
srand(time(0));


for(int i =0; i<= 10;i++)
 {
     int random=rand()%1000;
     list.InsertItem(random);

 }

 CalcMax(item,list);

return 0;
}
*/

/*(5)

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "UnsortedType.h"
using namespace std;

int CalcMini(int item,UnsortedType list){

int MiniValue=item;
list.ResetList();

for(int i=0;i<list.LengthIs();i++)
{

    cout<<item<<endl;
    if(item<MiniValue)
    {
        MiniValue=item;


    }
    list.GetNextItem(item);
}
cout<<"the minimam value is   "<<MiniValue<<endl;

}


int main() {
 UnsortedType list;
 int item;
srand(time(0));


for(int i =0; i<= 20;i++)
 {
     int random=rand()%1000;
     list.InsertItem(random);

 }

 CalcMini(item,list);

return 0;
}
*/


