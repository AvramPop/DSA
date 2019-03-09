//
// Created by dani on 3/6/19.
//

#ifndef LAB1_BAG_H
#define LAB1_BAG_H

typedef int TElem;

class BagIterator;

class Bag{

    friend class BagIterator;

private:
    TElem *buffer;
    int bufferSize;
    TElem leastElement;

    void stretchBufferRight(int newCapacity);

    void stretchBufferLeft(int newCapacity);

    int bufferIndex(int index) const;

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
};

#endif //LAB1_BAG_H
