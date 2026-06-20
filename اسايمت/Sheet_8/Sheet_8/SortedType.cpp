#include "SortedType.h"

SortedType::SortedType() {
    length = 0;
}

bool SortedType::IsFull() const {
    return (length == MAX_ITEMS);
}

int SortedType::LengthIs() const {
    return length;
}

void SortedType::RetrieveItem(ItemType& item, bool& found) {
    int first = 0;
    int last = length - 1;
    bool moreToSearch = first <= last;
    found = false;
    while (moreToSearch && !found) {
        int midPoint = (first + last) / 2;
        switch (item.ComparedTo(info[midPoint])) {
            case LESS: last = midPoint - 1; moreToSearch = first <= last; break;
            case GREATER: first = midPoint + 1; moreToSearch = first <= last; break;
            case EQUAL: found = true; item = info[midPoint]; break;
        }
    }
}

void SortedType::InsertItem(ItemType item) {
    int location = 0;
    bool moreToSearch = (location < length);
    while (moreToSearch) {
        switch (item.ComparedTo(info[location])) {
            case LESS: moreToSearch = false; break;
            case GREATER: location++; moreToSearch = (location < length); break;
        }
    }
    for (int i = length; i > location; i--)
        info[i] = info[i - 1];
    info[location] = item;
    length++;
}

void SortedType::DeleteItem(ItemType item) {
    int location = 0;
    while (item.ComparedTo(info[location]) != EQUAL)
        location++;
    for (int i = location + 1; i < length; i++)
        info[i - 1] = info[i];
    length--;
}

void SortedType::ResetList() {
    currentPos = -1;
}

void SortedType::GetNextItem(ItemType& item) {
    currentPos++;
    item = info[currentPos];
}

void SortedType::MergeLists(SortedType& list, SortedType& result) {
    int i = 0, j = 0;
    while (i < this->LengthIs() && j < list.LengthIs()) {
        if (this->info[i].ComparedTo(list.info[j]) == LESS) {
            result.InsertItem(this->info[i]);
            i++;
        } else {
            result.InsertItem(list.info[j]);
            j++;
        }
    }

    while (i < this->LengthIs()) {
        result.InsertItem(this->info[i]);
        i++;
    }

    while (j < list.LengthIs()) {
        result.InsertItem(list.info[j]);
        j++;
    }
}

/*

sorted , sorted , sorted result


void SortedType::MergeLists(SortedType& list, SortedType& result) {

    int index1=0;
    int index2=0;

    while(index1<this->LengthIs())
    {
        if(info[index1].ComparedTo(list.info[index2])==LESS)
        {
            result.InsertItem(info[index1]);
        }
        index1++;
    }
    while(index2<list.LengthIs()){
        result.InsertItem(list.info[index2]);
        index2++;
    }
}

*/
void SortedType::SplitLists(SortedType& list1, SortedType& list2, ItemType item) {
    int i = 0;
    while (i < this->LengthIs() && this->info[i].ComparedTo(item) <= 0) {
        list1.InsertItem(this->info[i]);
        i++;
    }
    while (i < this->LengthIs()) {
        list2.InsertItem(this->info[i]);
        i++;
    }
}
/*
 split sorted

void SortedType::SplitLists(SortedType& list1, SortedType& list2, ItemType item) {
   int location=0;
    for(int i=location;i<this->LengthIs();i++)
    if(item.ComparedTo(info[i])==GREATER)
    {
        list1.InsertItem(info[i]);
    }
    else
    {
        list2.InsertItem(info[i]);
    }

}
*/

/*
 sorted

void SortedType::SplitLists(SortedType& list1, SortedType& list2, ItemType item) {
    for (int i = 0; i < LengthIs(); i++) {
        if (item.ComparedTo(info[i]) == GREATER) {
            list1.InsertItem(info[i]);
        } else {
            list2.InsertItem(info[i]);
        }
    }
}

*/

/*
mostafa split sorted , unsorted

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


