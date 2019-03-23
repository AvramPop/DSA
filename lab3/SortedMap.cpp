//
// Created by dani on 3/23/19.
//

#include "SortedMap.h"
#include "SMIterator.h"
#include <iostream>

TValue SortedMap::add(TKey c, TValue v){
    TElem newElem;
    newElem.first = c;
    newElem.second = v;
    if(buffer.search(c) == NULL_TVALUE){
        buffer.add(newElem);
        return NULL_TVALUE;
    } else {
        TValue oldValue = buffer.search(c);
        buffer.add(newElem);
        return oldValue;
    }
}

TValue SortedMap::search(TKey c) const{
    return buffer.search(c);
}

TValue SortedMap::remove(TKey c){
    if(buffer.search(c) != NULL_TVALUE){
        TValue value = buffer.search(c);
        buffer.remove(c);
        return value;
    } else {
        return NULL_TVALUE;
    }
}

int SortedMap::size() const{
    return buffer.size();
}

bool SortedMap::isEmpty() const{
    return buffer.size() == 0;
}

SortedMap::~SortedMap(){}

SortedMap::SortedMap(Relation r){
    buffer.setRelation(r);
}

std::ostream &operator<<(std::ostream &os, const SortedMap &map){
    os << "Sorted Map:\n";
    return os;
}

SMIterator SortedMap::iterator() const{

}
