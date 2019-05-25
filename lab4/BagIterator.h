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
    //theta(1)
    TElem getCurrent();

    //theta(1)
    bool valid();

    //theta(1)
    void next();

    //theta(1)
    void first();

};



#endif //LAB4_BAGITERATOR_H
