//
// Created by dani on 4/4/19.
//

#include "Bag.h"
#include "BagIterator.h"


Bag::Bag(){
    elems = LinkedList();
    frequencies = LinkedList();
}

void Bag::add(TElem e){
    if(elems.search(e)){
        frequencies[indexOf(e)]++;
    } else {
        elems.add(e);
        frequencies.add(e);
    }
}

bool Bag::remove(TElem e){
    if(search(e)){
        frequencies[indexOf(e)]--;
        if(frequencies[indexOf(e)] == 0){
            frequencies.removeFrom(indexOf(e));
            elems.removeFrom(indexOf(e));
        }
    }
}

bool Bag::search(TElem e){
    return elems.search(e);
}

int Bag::nrOccurrences(TElem e){
    if(search(e)){
        return frequencies[indexOf(e)];
    } else {
        return 0;
    }
}

int Bag::size(){
    int numberOfElems = 0;
    for(int i = 0; i < elems.size(); i++){
        numberOfElems += frequencies[i];
    }
    return numberOfElems;
}

BagIterator Bag::iterator(){
    return BagIterator(*this);
}

bool Bag::isEmpty(){
    return size() == 0;
}

int Bag::indexOf(TElem e){
    int index = -1;
    for(int i = 0; i < elems.size(); i++){
        if(elems[i] == e){
            index = i;
        }
    }
    return index;
}
