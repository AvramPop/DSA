//
// Created by dani on 3/5/19.
//
#ifndef LAB1_BAG_H
#define LAB1_BAG_H


#include "BagIterator.h"

typedef int TElem;

class Bag {
    private:

    public:

        Bag();

        //adds an element to the bag
        void add(TElem e);

        //removes one occurrence of an element from a bag
        //returns true if an element was removed, false otherwise (if e was not part of the bag)
        bool remove(TElem e);

        //checks if an element appears is the bag
        bool search(TElem e) const;

        //returns the number of occurrences for an element in the bag
        int nrOccurrences(TElem e) const;

        //returns the number of elements from the bag
        int size() const;

        //returns an iterator for this bag
        BagIterator iterator() const;

        //checks if the bag is empty
        bool isEmpty() const;

        //destructor
        ~Bag();
};


#endif //LAB1_BAG_H
