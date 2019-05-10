//
// Created by dani on 5/8/19.
//

#ifndef LAB6_BAGITERATOR_H
#define LAB6_BAGITERATOR_H

#include "Bag.h"
#include <vector>
class Bag;
class BagIterator {
    friend class Bag;

private:
    BagIterator(const Bag& b);
    const Bag& b;
    std::vector<TElem> tempList;
    int currentIndex;
    int bagSize;

public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;
};

#endif //LAB6_BAGITERATOR_H
