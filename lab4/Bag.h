//
// Created by dani on 4/4/19.
//

#ifndef LAB4_BAG_H
#define LAB4_BAG_H

#include "LinkedList.h"
class BagIterator;
class Bag {
    friend class BagIterator;

private:
    LinkedList elems;
    LinkedList frequencies;
    int indexOf(TElem e);

public:

    Bag();

    void add(TElem e);

    bool remove(TElem e);

    bool search(TElem e);

    int nrOccurrences(TElem e);

    int size();

    BagIterator iterator();

    bool isEmpty();

    ~Bag(){};

};

#endif //LAB4_BAG_H
