#include <iostream>
#include "SortedBag.h"
#include "ExtendedTest.h"

using namespace std;
/*
 * ADT SortedBag – using a BST with linked representation on an array. If an element appears
multiple times, it will be stored multiple times in the BST.*/
bool rel(TComp r1, TComp r2) {
    return r1 <= r2;
}
int main(){
    SortedBag bag(rel);
    bag.add(13);
    bag.add(5);
    bag.add(17);
    bag.add(9);
    bag.add(9);
    bag.add(90);

    cout << bag.search(13);
    bag.remove(13);
    cout << endl << bag.search(13);
//    cout << endl << bag.search(15);
//    cout << endl << bag.search(9);
//    cout << endl << bag.search(91);
//    testAllExtended();
//    SortedBagIterator it = bag.iterator();
//    while(it.valid()){
//        cout << it.getCurrent() << " ";
//        it.next();
//    }
    return 0;
}