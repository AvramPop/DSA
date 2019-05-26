//
// Created by dani on 5/22/19.
//

#include "SortedBagIterator.h"


SortedBagIterator::SortedBagIterator(const SortedBag &b) : bag(b){
    if(bag.size() == 0){
        currentNode = DEFAULT_NULL;
        return;
    }
    int node = bag.buffer.root;
    while(node != DEFAULT_NULL){
        st.push(node);
        node = bag.buffer.nodes[node].left;
    }
    if(st.size() != 0){
        currentNode = st.top();
    } else {
        currentNode = DEFAULT_NULL;
    }
}

TElem SortedBagIterator::getCurrent(){
    if(valid()){
        return bag.buffer.nodes[currentNode].info;
    } else {
        throw std::exception();
    }
}

bool SortedBagIterator::valid(){
    return currentNode != DEFAULT_NULL;
}

void SortedBagIterator::next(){
    if(valid()){
        int node = st.top();
        st.pop();
        if(bag.buffer.nodes[node].right != DEFAULT_NULL){
            node = bag.buffer.nodes[node].right;
            while(node != DEFAULT_NULL){
                st.push(node);
                node = bag.buffer.nodes[node].left;
            }
        }
        if(st.size() != 0){
            currentNode = st.top();
        } else {
            currentNode = DEFAULT_NULL;
        }
    } else {
        throw std::exception();
    }
}

void SortedBagIterator::first(){
    while(st.size() != 0) st.pop();
    int node = bag.buffer.root;
    while(node != DEFAULT_NULL){
        st.push(node);
        node = bag.buffer.nodes[node].left;
    }
    if(st.size() != 0){
        currentNode = st.top();
    } else {
        currentNode = DEFAULT_NULL;
    }
}