//
// Created by dani on 3/23/19.
//

#include "SMIterator.h"

class my_exception: public std::exception{
    virtual const char *what() const throw(){
        return "IteratorException";
    }
};

SMIterator::SMIterator(const SortedMap &c) : c(c){
    if(c.isEmpty()){
        currentNode = NULL;
    } else {
        currentNode = c.buffer.head;
    }
}

void SMIterator::first(){
    if(c.isEmpty()){
        currentNode = NULL;
    } else {
        currentNode = c.buffer.head;
    }
}

void SMIterator::next(){
    if(valid()){
        currentNode = currentNode->next;
    } else {
        throw my_exception();
    }
}

bool SMIterator::valid() const{
    if(c.isEmpty()) return false;
    if(c.size() == 1 && currentNode == c.buffer.tail) return true;
    return currentNode != NULL;
}

TElem SMIterator::getCurrent() const{
    if(valid()){
        return currentNode->value;
    } else {
        throw my_exception();
    }
}
