//
// Created by dani on 4/4/19.
//

#include "Bag.h"
#include "BagIterator.h"


Bag::Bag(){

}

void Bag::add(TElem e){

}

bool Bag::remove(TElem e){
    return false;
}

bool Bag::search(TElem e) const{
    return false;
}

int Bag::nrOccurrences(TElem e) const{
    return 0;
}

int Bag::size() const{
    return 0;
}

BagIterator Bag::iterator() const{
    return BagIterator(Bag());
}

bool Bag::isEmpty() const{
    return false;
}

Bag::~Bag(){

}