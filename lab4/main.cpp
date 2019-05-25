#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "BagIterator.h"

using namespace std;
int main(){

    testAll();
    testAllExtended();
//cout << "Fds";
//    Bag bag1;
//    bag1.add(1);
//    bag1.add(2);
//    bag1.add(2);
//    bag1.add(2);
//    bag1.add(3);
//    bag1.add(3);
//    bag1.add(4);
//
//    BagIterator iter = bag1.iterator();
//    while(iter.valid()){
//        cout << iter.getCurrent() << " ";
//        iter.next();
//    }
//    cout << endl;
//
//    Bag bag2;
//    bag2.add(1);
//    bag2.add(1);
//    bag2.add(2);
//    bag2.add(2);
//
//    BagIterator iter2 = bag2.iterator();
//    while(iter2.valid()){
//        cout << iter2.getCurrent() << " ";
//        iter2.next();
//    }
////
////    cout << endl;
////    BagIterator iter3 = bag1.intersection(bag2).iterator();
////
////    while(iter3.valid()){
////        cout << iter3.getCurrent() << " ";
////        iter3.next();
////    }
    return 0;
}