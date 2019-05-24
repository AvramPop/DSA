//
// Created by dani on 5/22/19.
//

#ifndef LAB7_SORTEDBAGITERATOR_H
#define LAB7_SORTEDBAGITERATOR_H


#include "SortedBag.h"
#include <stack>

class SortedBag;
typedef int TElem;
class SortedBagIterator{
    friend class SortedBag;

private:
    const SortedBag &bag;
    std::stack<int> st;
    int currentNode;
    SortedBagIterator(const SortedBag &b);
public:
    TElem getCurrent();
    bool valid();
    void next();
    void first();

};



#endif //LAB7_SORTEDBAGITERATOR_H
