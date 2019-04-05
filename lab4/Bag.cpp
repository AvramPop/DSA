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
        const_cast<Bag*>(this)->frequencies.at(indexOf(e))++;
    } else {
        elems.add(e);
        frequencies.add(1);
    }
}

bool Bag::remove(TElem e){
    if(search(e)){
        frequencies.at(indexOf(e))--;
        if(const_cast<Bag*>(this)->frequencies.at(indexOf(e)) == 0){
            frequencies.removeFrom(indexOf(e));
            elems.removeFrom(indexOf(e));
        }
        return true;
    } else {
        return false;
    }
}

bool Bag::search(TElem e) const{
    return elems.search(e);
}

int Bag::nrOccurrences(TElem e) const{
    if(search(e)){
        return const_cast<Bag*>(this)->frequencies.at(indexOf(e));
    } else {
        return 0;
    }
}

int Bag::size() const{
    int numberOfElems = 0;
    for(int i = 0; i < elems.size(); i++){
        numberOfElems += const_cast<Bag*>(this)->frequencies.at(i);
    }
    return numberOfElems;
}

BagIterator Bag::iterator() const{
    return BagIterator(*this);
}

bool Bag::isEmpty() const{
    return size() == 0;
}

int Bag::indexOf(TElem e) const{
    int index = -1;
    for(int i = 0; i < elems.size(); i++){
        if(const_cast<Bag*>(this)->elems.at(i) == e){
            index = i;
        }
    }
    return index;
}
