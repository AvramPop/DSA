#include <iostream>
#include "SortedBag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
//#include "ExtendedTest.h"

using namespace std;
/*
 * ADT SortedBag – using a BST with linked representation on an array. If an element appears
multiple times, it will be stored multiple times in the BST.*/
bool rel(TComp r1, TComp r2) {
    return r1 <= r2;
}
int main(){
//    SortedBag bag(rel);
//    bag.add(1);
//    bag.add(2);
//   // cout << bag.nrOccurrences(1);
//    bag.remove(1);
  //  cout << bag.search(1);
    testAllExtended();
    cout << "well done!";
//    SortedBagIterator it = bag.iterator();
//    while(it.valid()){
//        cout << it.getCurrent() << " ";
//        it.next();
//    }
    return 0;
}