#include <iostream>
#include "SortedDoublyLinkedList.h"
#include "SortedMap.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SMIterator.h"

using namespace std;

bool increasing1(TKey c1, TKey c2) {
    if (c1 <= c2) {
        return true;
    } else {
        return false;
    }
}

int differenceBetweenMaxAndMinimumValue(SortedMap map){
    int maxValue = -10000000;
    int minValue = 10000000;
    SMIterator iter = map.iterator();
    iter.first();
    while (iter.valid()){
        TElem e = iter.getCurrent();
        if(e.second > maxValue){
            maxValue = e.second;
        }
        if(e.second < minValue){
            minValue = e.second;
        }
        iter.next();
    }
    return maxValue - minValue;
}

int main(){
    testAll(); // todo am modificat in implementare null value pentru ca la un moment dat in test se adauga exact -1
    testAllExtended();
    SortedMap sm(increasing1);
    sm.add(5, 100);
    sm.add(3, 200);
    sm.add(9, 25);
    cout << differenceBetweenMaxAndMinimumValue(sm);
    return 0;
}