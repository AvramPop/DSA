#include <iostream>
#include "SortedDoublyLinkedList.h"
#include "SortedMap.h"

using namespace std;

bool increasing(TKey c1, TKey c2) {
    return c1 <= c2;
}

bool decreasing(TKey c1, TKey c2) {
    return c1 >= c2;
}

int main(){
//    SortedDoublyLinkedList list(increasing);
//    TElem e1;
//    e1.first = 0;
//    e1.second = 0;
//    TElem e2;
//    e2.first = 0;
//    e2.second = 100;
//    list.add(e1);
//    list.add(e2);
    SortedMap map(increasing);
    return 0;
}