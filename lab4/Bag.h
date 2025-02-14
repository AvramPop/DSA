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
    int indexOf(TElem e) const;

public:

    Bag();

    void add(TElem e);

    bool remove(TElem e);

    bool search(TElem e) const;

    int nrOccurrences(TElem e) const;

    int size() const;

    BagIterator iterator() const;

    bool isEmpty() const;
    Bag intersection(const Bag& b);

    ~Bag(){};

};

#endif //LAB4_BAG_H
