//
// Created by dani on 5/8/19.
//

#ifndef LAB6_BAG_H
#define LAB6_BAG_H

#include "BagIterator.h"

#define ABSENT_ELEMENT 2147483644
#define DELETED_ELEMENT 2147483641
/*
 * ADT Bag – using a hashtable with open addressing (double hashing) in which the elements
are stored. If an element appears multiple times, it will be stored multiple times in the
hashtable.*/
typedef int TElem;

class BagIterator;
class Bag {
    friend class BagIterator;
private:
    int dimension;
    int hash1(TElem elem) const;
    int hash2(TElem elem) const;
    int hash(TElem elem, int i) const;
    void rehash();
    TElem *hashTable;
//    TElem hashTable[DEFAULT_SIZE];
    int currentSize;

public:
    Bag();
    void add(TElem e);
    bool remove(TElem e);
    bool search(TElem e) const;
    int nrOccurrences(TElem e) const;
    int size() const;
    BagIterator iterator() const;
    bool isEmpty() const;
    ~Bag();
    int smallerPrimeBiggerThan(int number);
    void empty();
    bool isPrime(int number);
};




#endif //LAB6_BAG_H
