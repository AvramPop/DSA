#include <iostream>
#include "BagIterator.h"
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;
int main(){

//    cout << bag.nrOccurrences(-9) << endl;
//    BagIterator iter = bag.iterator();
//    while(iter.valid()){
//        //cout << iter.getCurrent() << endl;
//        iter.next();
//    }
//    bag.remove(-9);
//    cout << bag.nrOccurrences(-9) << endl;
//    iter.first();
//    cout << endl;
//    while(iter.valid()){
//       // cout << iter.getCurrent() << endl;
//        iter.next();
//    }
//
    ShortTest::testAll();
   // cout << "done1" << flush;
    ExtendedTest::testAllExtended();

    cout << "done\n";
        Bag bag;
    bag.add(5);
    bag.add(15);
    bag.add(3);
    bag.add(3);
    bag.add(3);
    bag.add(-9);
    cout << bag.size() << endl;
    cout << bag.nrOccurrences(3) << endl;
    bag.empty();
    cout << bag.size() << endl;
    cout << bag.nrOccurrences(3) << endl;
    return 0;
}