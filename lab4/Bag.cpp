//
// Created by dani on 4/4/19.
//

#include <iostream>
#include "Bag.h"
#include "BagIterator.h"


Bag::Bag(){
    elems = LinkedList();
    frequencies = LinkedList();
}

//O(n)
void Bag::add(TElem e){
    if(elems.search(e)){
        const_cast<Bag*>(this)->frequencies.at(indexOf(e))++;
    } else {
        elems.add(e);
        frequencies.add(1);
    }
}

//O(n)
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

//O(n)
bool Bag::search(TElem e) const{
    return elems.search(e);
}

//O(n)
int Bag::nrOccurrences(TElem e) const{
    if(search(e)){
        return const_cast<Bag*>(this)->frequencies.at(indexOf(e));
    } else {
        return 0;
    }
}

//O(n)
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

Bag Bag::intersection(const Bag &b){
//    Bag newBag;
//    int dim = elems.size();
//    for(int i = 0; i < dim; i++){
//        if(b.search(elems[i])){
//            int freq = nrOccurrences(elems[i]) < b.nrOccurrences(elems[i]) ? nrOccurrences(elems[i]) : b.nrOccurrences(elems[i]);
//            while(freq > 0){
//                newBag.add(elems[i]);
//                freq--;
//            }
//        }
//    }
//    return newBag;
    int freq;
    int dim = elems.size();
    for(int i = 0; i < dim; i++){
        if(b.search(elems[i])){
            freq = nrOccurrences(elems[i]) < b.nrOccurrences(elems[i]) ? nrOccurrences(elems[i]) : b.nrOccurrences(elems[i]);
            if(freq != nrOccurrences(elems[i])){
                int diff = nrOccurrences(elems[i]) - freq;
                while(diff > 0){
                    remove(elems[i]);
                    diff--;
                }
            }
        } else {
            freq = nrOccurrences(elems[i]);
            while(freq > 0){
                remove(elems[i]);
                freq--;
            }
            i--;
        }
    }
}
