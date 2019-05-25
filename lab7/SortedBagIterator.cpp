//
// Created by dani on 5/22/19.
//

#include "SortedBagIterator.h"


SortedBagIterator::SortedBagIterator(const SortedBag &b) : bag(b){
    if(bag.size() == 0){
        currentNode = -1;
        return;
    }
    int node = bag.buffer.root;
    while(node != -1){
        st.push(node);
        node = bag.buffer.nodes[node].left;
    }
    if(st.size() != 0){
        currentNode = st.top();
    } else {
        currentNode = -1;
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
    return currentNode != -1;
}

void SortedBagIterator::next(){
    if(valid()){
        int node = st.top();
        st.pop();
        if(bag.buffer.nodes[node].right != -1){
            node = bag.buffer.nodes[node].right;
            while(node != -1){
                st.push(node);
                node = bag.buffer.nodes[node].left;
            }
        }
        if(st.size() != 0){
            currentNode = st.top();
        } else {
            currentNode = -1;
        }
    } else {
        throw std::exception();
    }
}

void SortedBagIterator::first(){
    while(st.size() != 0) st.pop();
    int node = bag.buffer.root;
    while(node != -1){
        st.push(node);
        node = bag.buffer.nodes[node].left;
    }
    if(st.size() != 0){
        currentNode = st.top();
    } else {
        currentNode = -1;
    }
}