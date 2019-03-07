#include <iostream>
#include "test/DynamicArray.h"
#include "test/DAIterator.h"
#include "Bag.h"
#include "BagIterator.h"

using namespace std;
int main() {
    Bag bag;
    bag.add(5);
    bag.add(10);
    bag.add(-1);
    bag.add(2);
    bag.add(3);
    bag.add(10);
    bag.add(5);
    bag.add(5);
    bag.add(-5);
    BagIterator it = bag.iterator();
    while(it.valid()) {
        cout << it.getCurrent() << " ";
        it.next();
    }
    cout << endl;
    cout << it.valid();
    it.first();
    cout << endl;
    while(it.valid()) {
        cout << it.getCurrent() << " ";
        it.next();
    }
    return 0;
}