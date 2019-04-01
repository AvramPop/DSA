//
// Created by dani on 4/1/19.
//

#include "LinkedListOnArray.h"

LinkedListOnArray::LinkedListOnArray(){
    dimension = 0;
    head = -1;
    for(int i = 0; i < CAPACITY; ++i){
        indexOfNext[i] = EMPTY_INDEX;
    }
    firstEmpty = 0;
}

bool LinkedListOnArray::search(TElem element){
    int current = head;
    while(current != -1 && buffer[current] != element){
        current = indexOfNext[current];
    }
    return current != -1;
}

void LinkedListOnArray::add(TElem newElement){
    if(head == -1){
        buffer[0] = newElement;
        indexOfNext[0] = -1;
        head = 0;
        firstEmpty = 1;
    } else{
        buffer[firstEmpty] = newElement;
        indexOfNext[indexOfLast()] = firstEmpty;
        indexOfNext[firstEmpty] = -1;
        updateFirstEmpty();
    }
    dimension++;
}

void LinkedListOnArray::remove(TElem elementToRemove){
    if(search(elementToRemove)){
        if(dimension == 1){
            indexOfNext[head] = EMPTY_INDEX;
            head = -1;
            firstEmpty = 0;
        } else {
            int current = head;
            int pre = -1;
            while(current != -1 && buffer[current] != elementToRemove){
                pre = current;
                current = indexOfNext[current];
            }
            if(pre != -1){
                indexOfNext[pre] = indexOfNext[current];
            }
            if(current == head){
                head = indexOfNext[head];
            }
            indexOfNext[current] = EMPTY_INDEX;
            updateFirstEmpty();
        }
        dimension--;
    }

}

int LinkedListOnArray::size() const{
    return dimension;
}

int LinkedListOnArray::indexOfLast(){
    if(dimension == 1){
        return head;
    }
    int current = head;
    while(current != -1 && indexOfNext[current] != -1){
        current = indexOfNext[current];
    }
    return current;
}

void LinkedListOnArray::updateFirstEmpty(){
    for(int i = 0; i <= dimension + 1; ){
        if(indexOfNext[i] == EMPTY_INDEX){
            firstEmpty = i;
            return;
        } else{
            ++i;
        }
    }
}

