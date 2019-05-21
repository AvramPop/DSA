//
// Created by dani on 5/22/19.
//

#ifndef LAB7_SORTEDBAG_H
#define LAB7_SORTEDBAG_H


#include "SortedBagIterator.h"

typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);
class SortedBagIterator;

class SortedBag {
    friend class SortedBagIterator;

private:
public:
    SortedBag(Relation r);
    void add(TComp e);
    bool remove(TComp e);
    bool search(TComp e) const;
    int nrOccurrences(TComp e) const;
    int size() const;
    SortedBagIterator iterator() const;
    bool isEmpty() const;
    ~SortedBag();

};


#endif //LAB7_SORTEDBAG_H
