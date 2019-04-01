//
// Created by dani on 4/1/19.
//

#ifndef LAB4_BAGITERATOR_H
#define LAB4_BAGITERATOR_H

#include "Bag.h"
#include "LinkedListOnArray.h"

class Bag;

class BagIterator {
    friend class Bag;
private:
    const Bag &bag;

    BagIterator(const Bag &b);
public:
    TElem getCurrent();

    bool valid();

    void next();

    void first();
};

#endif //LAB4_BAGITERATOR_H
