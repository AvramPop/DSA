#include <iostream>
#include "test/DynamicArray.h"
#include "test/DAIterator.h"

using namespace std;
int main() {
    DynamicArray array(5);
    array.addToEnd(0);
    cout << array.getElement(0);
    array.addToEnd(1);
    cout << array.getElement(1);
    array.addToEnd(2);
    cout << array.getElement(2);
    array.addToEnd(3);
    cout << array.getElement(3);
    array.addToEnd(4);
    cout << array.getElement(4);
    array.addToEnd(5);
    cout << array.getElement(5);
    array.setElement(5, 100);
    cout << array.getElement(5);
    cout << endl << array.size();
    array.remove(3);
    cout << endl;
    cout << array.getElement(0);
    cout << array.getElement(1);
    cout << array.getElement(2);
    cout << array.getElement(3);
    cout << array.getElement(4);
    cout << endl << array.size();
    cout << endl;
    DAIterator it = array.iterator();
    it.first();
    cout << it.getCurrent();
    it.next();
    cout << it.getCurrent();
    it.next();
    cout << it.getCurrent();
    it.next();
    cout << it.getCurrent();
    it.next();
    cout << it.getCurrent();
    it.next();
    return 0;
}