//
// Created by dani on 4/4/19.
//

#include "BagIterator.h"


BagIterator::BagIterator(const Bag &b) : bag(b){
    index = 0;
    freq = 1;
    elems = bag.elems;
    frequencies = bag.frequencies;
}

TElem BagIterator::getCurrent(){
    if(valid()){
        return elems.at(index);
    } else {
        throw std::exception();
    }
}

bool BagIterator::valid(){
    return index < elems.size();
}

void BagIterator::next(){
    if(valid()){
        if(freq < frequencies.at(index)){
            freq++;
        } else {
            index++;
            freq = 1;
        }
    } else {
        throw std::exception();
    }
}

void BagIterator::first(){
    index = 0;
    freq = 1;
}

