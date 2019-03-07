//
// Created by dani on 3/6/19.
//

#include "Bag.h"
#include "BagIterator.h"

Bag::Bag() {
    buffer = new TElem[1];
    buffer[0] = 0;
    bufferSize = 1;
    leastElement = 0;
}

void Bag::add(TElem e) {
    if(e >= 0) {
        if(e < bufferSize - leastElement) {
            buffer[bufferIndex(e)]++;
        } else {
            stretchBufferRight(bufferIndex(e - bufferSize + 1));
            bufferSize = bufferIndex(e) + 1;
            buffer[bufferIndex(e)]++;
        }
    } else {
        if(e * -1 <= leastElement) {
            buffer[bufferIndex(e)]++;
        } else {
            int difference = -1 * (e + leastElement);
            stretchBufferLeft(difference);
            bufferSize = bufferSize + difference;
            buffer[0] = 1;
            leastElement = e * -1;
        }
    }
}

bool Bag::remove(TElem e) {
    if(search(e)) {
        buffer[bufferIndex(e)]--;
        return true;
    } else {
        return false;
    }
}

bool Bag::search(TElem e) const {
    return buffer[bufferIndex(e)] > 0;
}

int Bag::nrOccurrences(TElem e) const {
    return buffer[bufferIndex(e)];
}

int Bag::size() const {
    return bufferSize;
}

BagIterator Bag::iterator() const {
    return BagIterator(*this);
}

bool Bag::isEmpty() const {
    return bufferSize == 1;
}

Bag::~Bag() {
    delete []buffer;
}

void Bag::stretchBufferRight(int difference) {
    TElem *newBuffer = new TElem[bufferSize + difference];
    for(int i = 0; i < bufferSize; i++) {
        newBuffer[i] = buffer[i];
    }
    for(int i = bufferSize; i < bufferSize + difference; i++) {
        newBuffer[i] = 0;
    }
    delete [] buffer;
    buffer = newBuffer;
}

void Bag::stretchBufferLeft(int difference) {
    TElem *newBuffer = new TElem[bufferSize + difference];
    for(int i = 0; i < bufferSize; i++) {
        newBuffer[i + difference] = buffer[i];
    }
    for(int i = 0; i < difference; i++) {
        newBuffer[i] = 0;
    }
    delete [] buffer;
    buffer = newBuffer;
}

int Bag::bufferIndex(int index) const {
    return index + leastElement;
}
