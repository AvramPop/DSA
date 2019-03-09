//
// Created by dani on 3/6/19.
//

#ifndef LAB1_BAGITERATOR_H
#define LAB1_BAGITERATOR_H

#include "Bag.h"

class Bag;

class BagIterator{
    friend class Bag;

private:
    const Bag &bag;

    BagIterator(const Bag &b);

    //TElem *bagAsArray;

    int currentIterationIndex;

    int realIndex(int bufferIndex) const;

    int currentFrequency;
public:
    TElem getCurrent();

    bool valid();

    void next();

    void first();
};


#endif //LAB1_BAGITERATOR_H
