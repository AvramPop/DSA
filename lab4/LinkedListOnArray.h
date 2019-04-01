//
// Created by dani on 4/1/19.
//

#ifndef LAB4_LINKEDLISTONARRAY_H
#define LAB4_LINKEDLISTONARRAY_H


#include "Bag.h"

#define CAPACITY 1000
#define EMPTY_INDEX -5

class LinkedListOnArray {
private:
    TElem buffer[CAPACITY];
    int indexOfNext[CAPACITY];
    int dimension;
    int head;
    int firstEmpty;
public:
    LinkedListOnArray();
    bool search(TElem element);
    void add(TElem newElement);
    void remove(TElem elementToRemove);
    int size()const;

    int indexOfLast();

    void updateFirstEmpty();
};


#endif //LAB4_LINKEDLISTONARRAY_H
