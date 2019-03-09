//
// Created by dani on 3/6/19.
//

#include <exception>
#include "BagIterator.h"

class my_exception: public std::exception{
    virtual const char *what() const throw(){
        return "Hello, world!";
    }
};

BagIterator::BagIterator(const Bag &b) : bag(b){
    if(bag.isEmpty()){
        currentFrequency = -1;
        currentIterationIndex = bag.bufferSize + 5;
    } else {
        currentIterationIndex = -1;
        while(bag.buffer[++currentIterationIndex] == 0);
        currentFrequency = bag.buffer[currentIterationIndex];
    }
}

TElem BagIterator::getCurrent(){
    if(valid()){
        return realIndex(currentIterationIndex);
    } else {
        throw my_exception();
    }
}

bool BagIterator::valid(){
    if(bag.isEmpty()) return false;
    if(currentIterationIndex >= bag.bufferSize) return false;
    if(currentFrequency > 0) return true;
    else{
        int temp = currentIterationIndex + 1;
        while(temp < bag.bufferSize){
            if(bag.buffer[temp]) return true;
            temp++;
        }
        return false;
    }
}

void BagIterator::next(){
    if(valid()){
        currentFrequency--;
        if(currentFrequency <= 0){
            currentIterationIndex++;
            while(bag.buffer[currentIterationIndex] == 0 && currentIterationIndex < bag.bufferSize){
                currentIterationIndex++;
            }
            currentFrequency = bag.buffer[currentIterationIndex];
        }
    } else {
        throw my_exception();
    }
}

void BagIterator::first(){
    if(bag.isEmpty()){
        currentFrequency = -1;
        currentIterationIndex = bag.bufferSize + 5;
    } else {
        currentIterationIndex = -1;
        while(bag.buffer[++currentIterationIndex] == 0);
        currentFrequency = bag.buffer[currentIterationIndex];
    }
}

int BagIterator::realIndex(int bufferIndex) const{
    return bufferIndex - bag.leastElement;
}
