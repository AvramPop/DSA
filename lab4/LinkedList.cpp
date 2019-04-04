//
// Created by dani on 4/4/19.
//

#include <bits/exception.h>
#include "LinkedList.h"

LinkedList::LinkedList(){
    dimension = 0;
    head = -1;
    for(int i = 0; i < CAPACITY; ++i){
        indexOfNext[i] = EMPTY_INDEX;
    }
    firstEmpty = 0;
}

bool LinkedList::search(TElem element){
    int current = head;
    while(current != -1 && buffer[current] != element){
        current = indexOfNext[current];
    }
    return current != -1;
}

void LinkedList::add(TElem newElement){
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

void LinkedList::removeFrom(unsigned int index){
    if(index < size()){
        if(dimension == 1 && head == 0){
            indexOfNext[head] = EMPTY_INDEX;
            head = -1;
            firstEmpty = 0;
            dimension--;
        } else {
            dimension--;
            int current = head;
            int pre = -1;
            for(int i = 0; i < index; i++){
                pre = current;
                current = indexOfNext[current];
            }
            if(index == 0){
                int temp = indexOfNext[head];
                indexOfNext[head] = EMPTY_INDEX;
                head = temp;
            } else {
                indexOfNext[pre] = indexOfNext[current];
                indexOfNext[current] = EMPTY_INDEX;
            }

        }
    } else {
        throw std::exception();
    }

}

int LinkedList::size(){
    return dimension;
}

int LinkedList::indexOfLast(){
    if(dimension == 1){
        return head;
    }
    int current = head;
    while(current != -1 && indexOfNext[current] != -1){
        current = indexOfNext[current];
    }
    return current;
}

void LinkedList::updateFirstEmpty(){
    for(int i = 0; i <= dimension + 1; ){
        if(indexOfNext[i] == EMPTY_INDEX){
            firstEmpty = i;
            return;
        } else{
            ++i;
        }
    }
}

TElem& LinkedList::operator[](unsigned int i){
    if(i < size()){
        int index = 0;
        int currentIndex = head;
        while(index < i){
            currentIndex = indexOfNext[currentIndex];
            index++;
        }
        return buffer[currentIndex];
    } else {
        throw std::exception();
    }
}