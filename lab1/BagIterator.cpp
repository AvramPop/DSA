//
// Created by dani on 3/6/19.
//

#include "BagIterator.h"

BagIterator::BagIterator(const Bag &b) : bag(b) {
    currentElement = bag.buffer;
    currentIterationIndex = 0;
}

TElem BagIterator::getCurrent() {
    if(valid()) {
        return *currentElement;
    } else {
        throw;
    }
}

bool BagIterator::valid() {
    return currentIterationIndex < bag.bufferSize;
}

void BagIterator::next() {
    if(valid()) {
        currentElement++; //TODO check this
        currentIterationIndex++;
    }
}

void BagIterator::first() {
    currentElement = bag.buffer;
    currentIterationIndex = 0;
}
