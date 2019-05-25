//
// Created by dani on 5/8/19.
//

#include <bits/exception.h>
#include "BagIterator.h"
#include <iostream>
//BagIterator::BagIterator(const Bag &b) : b(b){
//    int k = 0;
//    for(int i = 0; i < b.dimension; i++){
//        if(b.hashTable[i] != ABSENT_ELEMENT && b.hashTable[i] != DELETED_ELEMENT){
//            tempList.push_back(b.hashTable[i]);
//            k++;
//        }
//    }
//    bagSize = b.size();
//    currentIndex = 0;
//}
//
//void BagIterator::first(){
//    currentIndex = 0;
//}
//
//void BagIterator::next(){
//    if(valid()){
//        currentIndex++;
//    } else {
//        throw std::exception();
//    }
//}
//
//bool BagIterator::valid() const{
//    if(tempList.size() == 0) return false;
//    return currentIndex < tempList.size();
//}
//
//TElem BagIterator::getCurrent() const{
//    if(valid()){
//        return tempList[currentIndex];
//    } else {
//        throw std::exception();
//    }
//}
//O(m)
BagIterator::BagIterator(const Bag &b) : b(b){
    if(b.isEmpty()) currentIndex = b.dimension + 5;
    else{
        currentIndex = 0;
        while(b.hashTable[currentIndex] == ABSENT_ELEMENT || b.hashTable[currentIndex] == DELETED_ELEMENT){
            currentIndex++;
        }
    }
}
//O(m)
void BagIterator::first(){
    if(b.isEmpty()) currentIndex = b.dimension + 5;
    else{
        currentIndex = 0;
        while(b.hashTable[currentIndex] == ABSENT_ELEMENT || b.hashTable[currentIndex] == DELETED_ELEMENT){
            currentIndex++;
        }
    }
}
//O(m)
void BagIterator::next(){
    if(valid()){
        currentIndex++;
        while(b.hashTable[currentIndex] == ABSENT_ELEMENT || b.hashTable[currentIndex] == DELETED_ELEMENT){
            currentIndex++;
        }
    } else {
        throw std::exception();
    }
}
//theta(1)
bool BagIterator::valid() const{
    return currentIndex < b.dimension;
}
//theta(1)
TElem BagIterator::getCurrent() const{
    if(valid()){
        return b.hashTable[currentIndex];
    } else {
        throw std::exception();
    }
}