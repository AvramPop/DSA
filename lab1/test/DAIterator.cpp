//
// Created by dani on 3/6/19.
//

#include "DAIterator.h"

void DAIterator::first() {
    currentElement = c.array;
    currentIterationIndex = 0;
}

void DAIterator::next() {
    if(valid()) {
        currentElement++; //TODO check this
        currentIterationIndex++;
    }
}

bool DAIterator::valid() const {
    return currentIterationIndex < c.arrayLength;
}

TElem DAIterator::getCurrent() const {
    if(valid()) {
        return *currentElement;
    } else {
        throw;
    }
}

DAIterator::DAIterator(const DynamicArray &c) : c(c) {
    currentElement = c.array;
    currentIterationIndex = 0;
}