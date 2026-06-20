#include "UnsortedType.h"

UnsortedType::UnsortedType() {
    length = 0;
}

bool UnsortedType::IsFull() const {
    return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const {
    return length;
}

void UnsortedType::RetrieveItem(ItemType& item, bool& found) {
    int location = 0;
    found = false;
    while (location < length && !found) {
        if (item.ComparedTo(info[location]) == EQUAL) {
            found = true;
            item = info[location];
        }
        location++;
    }
}

void UnsortedType::InsertItem(ItemType item) {
    info[length] = item;
    length++;
}

void UnsortedType::DeleteItem(ItemType item) {
    int location = 0;
    while (item.ComparedTo(info[location]) != EQUAL)
        location++;
    for (int i = location + 1; i < length; i++)
        info[i - 1] = info[i];
    length--;
}

void UnsortedType::ResetList() {
    currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType& item) {
    currentPos++;
    item = info[currentPos];
}

void UnsortedType::MergeLists(UnsortedType& list, UnsortedType& result) {
    for (int i = 0; i < this->LengthIs(); i++) {
        result.InsertItem(info[i]);
    }
    for (int i = 0; i < list.LengthIs(); i++) {
        result.InsertItem(list.info[i]);
    }
}
/*
(un ,un , unresult merge)

void UnsortedType::MergeLists(UnsortedType& list, UnsortedType& result){

for(int i=0;i<this->LengthIs();i++)
{
    result.InsertItem(info[i]);
}
for(int i=0;i<list.LengthIs();i++)
{
    result.InsertItem(list.info{i})
}

}

*/

/*
(un ,un , sorted merge)


void UnsortedType::MergeLists(UnsortedType& list, UnsortedType& result) {
    int index1 = 0;
    int index2 = 0;

    while (index1 < this->LengthIs() && index2 < list.LengthIs()) {
        if (this->info[index1].ComparedTo(list.info[index2]) == LESS ||
            this->info[index1].ComparedTo(list.info[index2]) == EQUAL) {
            result.InsertItem(info[index1]);
            index1++;
        } else {
            result.InsertItem(list.info[index2]);
            index2++;
        }
    }

    while (index1 < this->LengthIs()) {
        result.InsertItem(info[index1]);
        index1++;
    }

    while (index2 < list.LengthIs()) {
        result.InsertItem(list.info[index2]);
        index2++;
    }
}

*/






void UnsortedType::SplitLists(UnsortedType& list1, UnsortedType& list2, ItemType item) {
    for (int i = 0; i < this->LengthIs(); i++) {
        if (info[i].ComparedTo(item) <= 0) {
            list1.InsertItem(info[i]);
        } else {
            list2.InsertItem(info[i]);
        }
    }
}



/*
void UnsortedType::unsortSplitLists(UnsortedType& list1, UnsortedType& list2, ItemType item) {
   int location=0;
    while(location<this->LengthIs()&&item.ComparedTo(info[location])!=EQUAL)
    {

        list1.InsertItem(info[location]);
        location++;
    }

    for(int i=location;i<this->LengthIs();i++)
    {
        list2.InsertItem(info[i]);

    }
}

*/
