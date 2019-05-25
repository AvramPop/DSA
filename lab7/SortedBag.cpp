//
// Created by dani on 5/22/19.
//

#include <iosfwd>
#include "SortedBag.h"
#include <iostream>
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) : relation(r){
    buffer.capacity = 10;
    buffer.size = 0;
    buffer.nodes = new Node[buffer.capacity];
    buffer.firstEmpty = 0;
    buffer.root = buffer.firstEmpty;
    null.left = -1;
    null.right = -1;
    null.parent = -1;
    null.info = -1;
    for(int i = 0; i < buffer.capacity; i++){
        buffer.nodes[i] = null;
    }
}

void SortedBag::add(TComp e){
    if(buffer.size == buffer.capacity - 1){
        resize();
    }
    std::cout << "adding " << e << std::endl;
    if(buffer.size == 0){
        buffer.nodes[0].info = e;
        buffer.firstEmpty = 1;
    } else {
        insertIntoTree(buffer.root, e);
    }
    buffer.size++;
}

void SortedBag::insertIntoTree(int root, TComp e){
    if(!relation(buffer.nodes[root].info, e)){
        if(buffer.nodes[root].left == -1){
            buffer.nodes[buffer.firstEmpty].info = e;
            buffer.nodes[root].left = buffer.firstEmpty;
            updateFirstEmpty();

        } else {
            insertIntoTree(buffer.nodes[root].left, e);
        }
    } else {
        if(buffer.nodes[root].right == -1){
            buffer.nodes[buffer.firstEmpty].info = e;
            buffer.nodes[root].right = buffer.firstEmpty;
            updateFirstEmpty();
        } else {
            insertIntoTree(buffer.nodes[root].right, e);
        }
    }
}

bool SortedBag::remove(TComp e){
    if(size() == 0) return false;
    if(removeUtil(buffer.root, e) == -1) return false;
    buffer.size--;
    return true;
}

bool SortedBag::search(TComp e) const{
    if(size() == 0) return false;
    return searchUtil(buffer.root, e);
}

int SortedBag::nrOccurrences(TComp e) const{
    if(size() == 0) return 0;
    int count = 0;
    SortedBagIterator it = iterator();
    while(it.valid()){
        if(it.getCurrent() == e){
            count++;
        }
        it.next();
    }
    return count;

}

int SortedBag::size() const{
    return buffer.size;
}

SortedBagIterator SortedBag::iterator() const{
    return SortedBagIterator(*this);
}

bool SortedBag::isEmpty() const{
    return size() == 0;
}

SortedBag::~SortedBag(){
    delete [] this->buffer.nodes;
}

void SortedBag::resize(){
    Node* temp = new Node[buffer.capacity * 2];
    for(int i = 0; i < buffer.capacity; i++){
        temp[i] = buffer.nodes[i];
    }
    for(int i = buffer.capacity; i < 2 * buffer.capacity; i++){
        temp[i] = null;
    }
    buffer.capacity *= 2;
    delete [] buffer.nodes;
    buffer.nodes = temp;
    updateFirstEmpty();
}

void SortedBag::updateFirstEmpty(){
    while(buffer.nodes[buffer.firstEmpty] != null){
        buffer.firstEmpty++;
    }
}

bool SortedBag::searchUtil(int root, TComp e) const{
  //  std::cout << root << std::endl;
    if(root == -1 /*|| buffer.nodes[root] == null*/){
        return false;
    }
    if(buffer.nodes[root].info == e) return true;
    if(relation(buffer.nodes[root].info, e)){
        return searchUtil(buffer.nodes[root].right, e);
    } else {
        return searchUtil(buffer.nodes[root].left, e);
    }
}

int SortedBag::removeUtil(int root, TComp e){
   // std::cout << root << std::endl;
    if(root == -1){
        return false;
    } else if(buffer.nodes[root].info == e) {
        if(buffer.nodes[root].right == -1 && buffer.nodes[root].left == -1){
            return -1;
        } else if(buffer.nodes[root].right == -1) {
            return buffer.nodes[root].left;
        } else if(buffer.nodes[root].left == -1){
            return buffer.nodes[root].right;
        } else {
            int min = minimum(buffer.nodes[root].right);
            buffer.nodes[root].info = buffer.nodes[min].info;
            buffer.nodes[root].right = removeUtil(buffer.nodes[root].right, buffer.nodes[min].info);
            return root;
        }
    } else if(!relation(buffer.nodes[root].info, e)){
        buffer.nodes[root].left = removeUtil(buffer.nodes[root].left, e);
        return root;
    } else if (relation(buffer.nodes[root].info, e)){
        buffer.nodes[root].right = removeUtil(buffer.nodes[root].right, e);
        return root;
    }
}

int SortedBag::minimum(int root){
    if(root == -1){
        return -1;
    } else {
        int prev = -1;
        while(root != -1  /*buffer.nodes[root].left != -1*/){
            prev = root;
            root = buffer.nodes[root].left;

        }
        return prev;
    }
}

bool Node::operator==(const Node &rhs) const{
    return left == rhs.left &&
           right == rhs.right &&
           parent == rhs.parent &&
           info == rhs.info;
}

bool Node::operator!=(const Node &rhs) const{
    return !(rhs == *this);
}
