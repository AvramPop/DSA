//
// Created by dani on 3/6/19.
//

#include <exception>
#include "BagIterator.h"

class my_exception : public std::exception {
    virtual const char *what() const throw() {
        return "Hello, world!";
    }
};

BagIterator::BagIterator(const Bag &b) : bag(b) {
    currentIterationIndex = -1;
    while(bag.buffer[++currentIterationIndex] == 0);
    currentFrequency = bag.buffer[currentIterationIndex];
}

TElem BagIterator::getCurrent() {
    if(valid()) {
        return realIndex(currentIterationIndex);
    } else {
        throw my_exception();
    }
}

bool BagIterator::valid() {
    return false;
}

void BagIterator::next() {
    if(valid()) {

    } else {
        throw my_exception();
    }

}

void BagIterator::first() {
    currentIterationIndex = -1;
    while(bag.buffer[++currentIterationIndex] == 0);
    currentFrequency = bag.buffer[currentIterationIndex];
}

int BagIterator::realIndex(int bufferIndex) const {
    return bufferIndex - bag.leastElement;
}
