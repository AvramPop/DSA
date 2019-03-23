#include <iostream>
#include "SortedDoublyLinkedList.h"
#include "SortedMap.h"
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

int main(){
    testAll(); // todo am modificat in implementare null value pentru ca la un moment dat in test se adauga exact -1
    testAllExtended();
    return 0;
}