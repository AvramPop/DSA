//
// Created by dani on 5/22/19.
//

#ifndef LAB7_SORTEDBAG_H
#define LAB7_SORTEDBAG_H
#define DEFAULT_NULL -999999

#include "SortedBagIterator.h"

typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);
class SortedBagIterator;

struct Node{
    int left, right;
    TComp info;

    bool operator==(const Node &rhs) const;

    bool operator!=(const Node &rhs) const;
};

struct BinarySearchTree{
    Node* nodes;
    int capacity, root, size, firstEmpty;
};

class SortedBag {
    friend class SortedBagIterator;

private:
    Relation relation;
    BinarySearchTree buffer;
    int insertIntoTree(int root, TComp e);

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

    void resize();

    void updateFirstEmpty();

    bool searchUtil(int root, TComp e) const;

    int removeUtil(int root, TComp e, bool& exists);

    int minimum(int root);
};


#endif //LAB7_SORTEDBAG_H
