//
// Created by dani on 4/1/19.
//

#ifndef LAB4_BAG_H
#define LAB4_BAG_H

#include "LinkedListOnArray.h"

typedef int TElem;
class BagIterator;
class Bag {
    friend class BagIterator;
private:
    LinkedListOnArray values;
    LinkedListOnArray frequencies;
public:

    //constructor

    Bag();



    //adds an element to the bag

    void add(TElem e);



    //removes one occurrence of an element from a bag

    //returns true if an element was removed, false otherwise (if e was not part of the bag)

    bool remove(TElem e);



    //checks if an element appearch is the bag

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


#endif //LAB4_BAG_H
