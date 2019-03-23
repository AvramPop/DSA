//
// Created by dani on 3/23/19.
//

#ifndef LAB3_SORTEDDOUBLYLINKEDLIST_H
#define LAB3_SORTEDDOUBLYLINKEDLIST_H

#include <utility>

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -10000000
typedef bool(*Relation)(TKey, TKey);

struct Node {
    TElem value;
    Node* previous;
    Node* next;
};

class SortedDoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;
    Relation relation;
    friend class SMIterator;
public:
    void setRelation(Relation r);
    SortedDoublyLinkedList(Relation relation);
    SortedDoublyLinkedList();
    void add(TElem newElement);
    void remove(TKey elementToRemove);
    TValue search(TKey element) const;
    int size()const;
};


#endif //LAB3_SORTEDDOUBLYLINKEDLIST_H
