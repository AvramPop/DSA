//
// Created by dani on 5/22/19.
//

#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r){

}

void SortedBag::add(TComp e){

}

bool SortedBag::remove(TComp e){
    return false;
}

bool SortedBag::search(TComp e) const{
    return false;
}

int SortedBag::nrOccurrences(TComp e) const{
    return 0;
}

int SortedBag::size() const{
    return 0;
}

SortedBagIterator SortedBag::iterator() const{
    return SortedBagIterator(*this);
}

bool SortedBag::isEmpty() const{
    return false;
}

SortedBag::~SortedBag(){

}