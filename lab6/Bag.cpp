//
// Created by dani on 5/8/19.
//

#include <cmath>
#include "Bag.h"
#include "BagIterator.h"
#include <cmath>
#include <iostream>

Bag::Bag(){
    dimension = 2999;
    currentSize = 0;
    hashTable = new TElem[dimension];
    for(int i = 0; i < dimension; i++){
        hashTable[i] = ABSENT_ELEMENT;
    }
}

void Bag::add(TElem e){
    if(this->currentSize == dimension){
        rehash();
    }int i = 0;
    int pos = hash(e, i);
    while(i < dimension && hashTable[pos] != ABSENT_ELEMENT && hashTable[pos] != DELETED_ELEMENT){
        i++;
        pos = hash(e, i);
    }
    hashTable[pos] = e;
    currentSize++;
}

bool Bag::remove(TElem e){

    int i = 0;
    int pos = hash(e, i);
    while(i < dimension && hashTable[pos] != e && hashTable[pos] != ABSENT_ELEMENT){
        i++;
        pos = hash(e, i);
    }
    if(i == dimension || hashTable[pos] == ABSENT_ELEMENT){
        return false;
    } else {
        hashTable[pos] = DELETED_ELEMENT;
        currentSize--;
        return true;
    }
}

int Bag::nrOccurrences(TElem e) const{
    int i = 0;
    int count = 0;
    int pos = hash(e, i);
    while(i < dimension && hashTable[pos] != ABSENT_ELEMENT){
        if(hashTable[pos] == e){
            count++;
        }
        i++;
        pos = hash(e, i);
    }
    return count;
}

bool Bag::search(TElem e) const{
    int i = 0;
    int pos = hash(e, i);
    while(i < dimension && hashTable[pos] != e && hashTable[pos] != ABSENT_ELEMENT){
        i++;
        pos = hash(e, i);
    }
    if(i == dimension || hashTable[pos] == ABSENT_ELEMENT){
        return false;
    }
    return true;
}

int Bag::size() const{
    return currentSize;
}

BagIterator Bag::iterator() const{
    return BagIterator(*this);
}

bool Bag::isEmpty() const{
    return size() == 0;
}

Bag::~Bag(){
    delete [] hashTable;
}

int Bag::hash1(TElem elem) const{
    elem = std::abs(elem);
    return elem % dimension;
}

int Bag::hash2(TElem elem) const{
    elem = std::abs(elem);
    return 1 + (elem % (dimension - 1));
}

int Bag::hash(TElem elem, int i) const{
    return (hash1(elem) + i * hash2(elem)) % dimension;
}

void Bag::rehash(){
    int prime = smallerPrimeBiggerThan(2 * dimension);
    TElem *temp = new TElem[prime];
    int oldDimension = dimension;
    dimension = prime;
    for(int i = 0; i < prime; i++){
        temp[i] = ABSENT_ELEMENT;
    }
    for(int i = 0; i < oldDimension; i++){
        TElem e = hashTable[i];
        int j = 0;
        int pos = hash(e, j);
        while(j < dimension && temp[pos] != ABSENT_ELEMENT){
            j++;
            pos = hash(e, j);
        }
        temp[pos] = e;
    }
    delete [] hashTable;
    this->hashTable = temp;
}

int Bag::smallerPrimeBiggerThan(int number){
    number++;
    if(number % 2 == 0) number++;
    while(!isPrime(number)){
        number += 2;
    }
    return number;
}

bool Bag::isPrime(int number){
    if(number == 1 || number == 0) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int d = 3; d <= std::sqrt(number) + 1; d += 2){
        if(number % d == 0) return false;
    }
    return true;
}
