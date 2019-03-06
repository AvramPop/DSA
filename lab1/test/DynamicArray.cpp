//
// Created by dani on 3/6/19.
//

#include "DynamicArray.h"
#include "DAIterator.h"
#include <algorithm>

DynamicArray::DynamicArray(int capacity) {
    arrayLength = 0;
    arrayCapacity = capacity;
    array = new TElem[capacity];
}

int DynamicArray::size() const {
    return arrayLength;
}

TElem DynamicArray::getElement(int pos) const {
    return array[pos];
}

TElem DynamicArray::setElement(int pos, TElem newElem) {
    array[pos] = newElem;
}

void DynamicArray::addToEnd(TElem newElem) {
    if(arrayLength >= arrayCapacity) {
        stretchArray(arrayCapacity + 10);
    }
    array[arrayLength] = newElem;
    arrayLength++;
}

void DynamicArray::stretchArray(int newCapacity) {
    TElem *newArray = new TElem[newCapacity];
    for(int i = 0; i < arrayLength; i++) {
        newArray[i] = array[i];
    }
    arrayCapacity = newCapacity;
    delete [] array;
    array = newArray;
}

void DynamicArray::addToPosition(int pos, TElem newElem) {
    std::copy(array + pos, array + arrayLength, array + pos + 1);
    array[pos] = newElem;
}

TElem DynamicArray::remove(int pos) {
    for(int i = pos; i < arrayLength; i++) {
        array[i] = array[i + 1];
    }
    arrayLength--;
}

DAIterator DynamicArray::iterator() const {
    return DAIterator(*this);
}

DynamicArray::~DynamicArray() {
    delete []array;
}
