//
// Created by dani on 4/4/19.
//

#ifndef LAB4_LINKEDLIST_H
#define LAB4_LINKEDLIST_H

#include <ostream>

#define CAPACITY 100000
#define EMPTY_INDEX -5
typedef int TElem;

class LinkedList {
private:
    TElem buffer[CAPACITY];
    int indexOfNext[CAPACITY];
    int dimension;
    int head;
    int firstEmpty;
    int indexOfLast();
    void updateFirstEmpty();

public:
    LinkedList();
    bool search(TElem element);
    void add(TElem newElement);
    void removeFrom(unsigned int index);
    int size();
    TElem& operator[](unsigned i);

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list);

};


#endif //LAB4_LINKEDLIST_H
