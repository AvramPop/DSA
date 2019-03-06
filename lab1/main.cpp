#include <iostream>
#include "test/DynamicArray.h"
#include "test/DAIterator.h"
#include "Bag.h"

using namespace std;
int main() {
    Bag bag;
    bag.add(5);
    bag.add(5);
    bag.add(10);
    return 0;
}