//
// Created by dani on 4/4/19.
//

#ifndef LAB4_BAGITERATOR_H
#define LAB4_BAGITERATOR_H

#include "Bag.h"

class Bag;

class BagIterator{
    friend class Bag;

private:
    const Bag &bag;
    int index;
    int freq;
    BagIterator(const Bag &b);
    LinkedList elems;
    LinkedList frequencies;

public:
    TElem getCurrent();

    bool valid();

    void next();

    void first();
};



#endif //LAB4_BAGITERATOR_H
