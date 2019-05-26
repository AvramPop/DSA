////
//// Created by dani on 5/22/19.
////

#include <iosfwd>
#include "SortedBag.h"
#include <iostream>
#include "SortedBagIterator.h"

//theta(cap)
SortedBag::SortedBag(Relation r) : relation(r){
    buffer.capacity = 10;
    buffer.nodes = new Node[10];
    buffer.size = 0;
    buffer.root = 0;
    buffer.firstEmpty = 0;
    for(int i = 0; i < buffer.capacity; i++){
        buffer.nodes[i].info = DEFAULT_NULL;
        buffer.nodes[i].right = DEFAULT_NULL;
        buffer.nodes[i].left = DEFAULT_NULL;
    }
}

//O(n) - degenerated tree, average O(log n)
void SortedBag::add(TComp e){
    if(buffer.size == 0){
        buffer.nodes[0].info = e;
        buffer.firstEmpty = 1;
        buffer.size++;
        return;
    }
    if(buffer.size == buffer.capacity - 1){
        resize();
    }
    insertIntoTree(buffer.root, e);
    buffer.size++;
}

int SortedBag::insertIntoTree(int root, TComp e){
    if(root == DEFAULT_NULL){
        buffer.nodes[buffer.firstEmpty].info = e;
        int oldFirstEmpty = buffer.firstEmpty;
        updateFirstEmpty();
        return oldFirstEmpty;
    } else if(relation(buffer.nodes[root].info, e)){
        buffer.nodes[root].right = insertIntoTree(buffer.nodes[root].right, e);
        return root;
    } else {
        buffer.nodes[root].left = insertIntoTree(buffer.nodes[root].left, e);
        return root;
    }
}

//O(n) -- degenerated tree, average O(log n)
bool SortedBag::remove(TComp e){
    bool found = false, exists;
//    if(buffer.nodes[buffer.root].info == e){
//        found = true;
//        if(buffer.nodes[buffer.root].left == DEFAULT_NULL && buffer.nodes[buffer.root].right == DEFAULT_NULL){
//            buffer.root = 0;
//            buffer.firstEmpty = 0;
//        } else if(buffer.nodes[buffer.root].left == DEFAULT_NULL){
//            buffer.root = buffer.nodes[buffer.root].right;
//        } else if(buffer.nodes[buffer.root].right == DEFAULT_NULL){
//            buffer.root = buffer.nodes[buffer.root].left;
//        } else {
//            int mini = minimum(buffer.nodes[buffer.root].right);
//            buffer.nodes[buffer.root].info = buffer.nodes[mini].info;
//            buffer.nodes[buffer.root].right = removeUtil(buffer.nodes[buffer.root].right, buffer.nodes[mini].info, exists);
//        }
//    } else {
        removeUtil(buffer.root, e, found);
 //   }
    if(!found) return false;
    buffer.size--;
    return true;
}

//O(n) -- degenerated tree, average O(log n)
bool SortedBag::search(TComp e) const{
    if(size() == 0) return false;
    return searchUtil(buffer.root, e);

}

int SortedBag::nrOccurrences(TComp e) const{
    if(size() == 0) return 0;
    int count = 0;
    int current = buffer.root;
    while(current != DEFAULT_NULL){
        if(buffer.nodes[current].info == e) count++;
        if(relation(buffer.nodes[current].info, e)){
            current = buffer.nodes[current].right;
        } else {
            current = buffer.nodes[current].left;
        }
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
    Node *temp = new Node[buffer.capacity * 2];
    for(int i = 0; i < buffer.capacity; i++){
        temp[i] = buffer.nodes[i];
    }
    for(int i = buffer.capacity; i < 2 * buffer.capacity; i++){
        temp[i].info = DEFAULT_NULL;
        temp[i].right = DEFAULT_NULL;
        temp[i].left = DEFAULT_NULL;
    }
    updateFirstEmpty();
    buffer.capacity *= 2;
    delete [] buffer.nodes;
    buffer.nodes = temp;
}

void SortedBag::updateFirstEmpty(){
    while(buffer.nodes[buffer.firstEmpty].info != DEFAULT_NULL){
        buffer.firstEmpty++;
    }
}

bool SortedBag::searchUtil(int root, TComp e) const{
    if(root == DEFAULT_NULL){
        return false;
    }
    if(buffer.nodes[root].info == e) return true;
    if(relation(buffer.nodes[root].info, e)){
        return searchUtil(buffer.nodes[root].right, e);
    } else {
        return searchUtil(buffer.nodes[root].left, e);
    }
}

int SortedBag::removeUtil(int root, TComp e, bool &exists){
    if(root == DEFAULT_NULL){
        return DEFAULT_NULL;
    }
    if(buffer.nodes[root].info < e){
        buffer.nodes[root].right = removeUtil(buffer.nodes[root].right, e, exists);
        return root;
    } else if(buffer.nodes[root].info > e){
        buffer.nodes[root].left = removeUtil(buffer.nodes[root].left, e, exists);
        return root;
    } else {
        exists = true;
        if(buffer.nodes[root].left == DEFAULT_NULL && buffer.nodes[root].right == DEFAULT_NULL){
            return DEFAULT_NULL;
        } else if(buffer.nodes[root].left == DEFAULT_NULL){
        //    buffer.nodes[root] = buffer.nodes[root].right;
            return buffer.nodes[root].right;
        } else if(buffer.nodes[root].right == DEFAULT_NULL){
//            buffer.nodes[root] = buffer.nodes[root].left;
            return buffer.nodes[root].left;
        } else {
            int mini = minimum(buffer.nodes[root].right);
            buffer.nodes[root].info = buffer.nodes[mini].info;
            buffer.nodes[root].right = removeUtil(buffer.nodes[root].right, buffer.nodes[mini].info, exists);
            return root;
        }
    }
//    if(buffer.nodes[root].info == e){
//        exists = true;
//        if(buffer.nodes[root].left == DEFAULT_NULL && buffer.nodes[root].right == DEFAULT_NULL){
//            return DEFAULT_NULL;
//        } else if(buffer.nodes[root].left == DEFAULT_NULL){
//            return buffer.nodes[root].right;
//        } else if(buffer.nodes[root].right == DEFAULT_NULL){
//            return buffer.nodes[root].left;
//        } else {
//            int mini = minimum(buffer.nodes[root].right);
//            buffer.nodes[root].info = buffer.nodes[mini].info;
//            buffer.nodes[root].right = removeUtil(buffer.nodes[root].right, buffer.nodes[mini].info, exists);
//            return root;
//        }
//    } else if(!relation(buffer.nodes[root].info, e)){
//        buffer.nodes[root].left = removeUtil(buffer.nodes[root].left, e, exists);
//        return root;
//    } else if(relation(buffer.nodes[root].info, e)){
//        buffer.nodes[root].right = removeUtil(buffer.nodes[root].right, e, exists);
//        return root;
//    }
}

int SortedBag::minimum(int root){
    int current = root;
    while(buffer.nodes[current].left != DEFAULT_NULL){
        current = buffer.nodes[current].left;
    }
    return current;
}

bool Node::operator==(const Node &rhs) const{
    return left == rhs.left &&
           right == rhs.right &&
           info == rhs.info;
}

bool Node::operator!=(const Node &rhs) const{
    return !(rhs == *this);
}

//
//void SortedBag::resize()
//{
//    Node *aux = new Node[this->buffer.capacity * 2];
//    for (int i = 0; i < this->buffer.capacity; i++) {
//        aux[i] = this->buffer.nodes[i];
//    }
//    for (int i = this->buffer.capacity; i < this->buffer.capacity * 2; i++) {
//        aux[i].info = DEFAULT_NULL;
//        aux[i].left = DEFAULT_NULL;
//        aux[i].right = DEFAULT_NULL;
//    }
//    updateFirstEmpty();
//    this->buffer.capacity *= 2;
//    delete[]this->buffer.nodes;
//    this->buffer.nodes = aux;
//}
//
////theta(1)
//void SortedBag::updateFirstEmpty()
//{
//    while (this->buffer.nodes[this->buffer.firstEmpty].info != DEFAULT_NULL) {
//        this->buffer.firstEmpty++;
//    }
//}
//
//
//int SortedBag::insertIntoTree(int node, TElem e)
//{
//    if (node == DEFAULT_NULL)
//    {
//        this->buffer.nodes[this->buffer.firstEmpty].info = e;
//        int old = this->buffer.firstEmpty;
//        updateFirstEmpty();
//        return old;
//    }
//    else if (!relation(this->buffer.nodes[node].info, e)) {
//        this->buffer.nodes[node].left = insertIntoTree(this->buffer.nodes[node].left, e);
//        return node;
//    }
//    else {
//        this->buffer.nodes[node].right = insertIntoTree(this->buffer.nodes[node].right, e);
//        return node;
//    }
//}
//
////O(height_of_subtree) <==>O(n)
//int SortedBag::minimum(int node)
//{
//    int current = node;
//    while (this->buffer.nodes[current].left != DEFAULT_NULL)
//        current = this->buffer.nodes[current].left;
//    return current;
//}
//
//int SortedBag::removeUtil(int node, TElem e, bool &found)
//{
//    if (node == DEFAULT_NULL)
//        return DEFAULT_NULL;
//    if (this->buffer.nodes[node].info == e) {
//        found = true;
//        if (this->buffer.nodes[node].left == DEFAULT_NULL && this->buffer.nodes[node].right == DEFAULT_NULL) {
//            return DEFAULT_NULL;
//        }
//        else if (this->buffer.nodes[node].left == DEFAULT_NULL) {
//            return this->buffer.nodes[node].right;
//        }
//        else if (this->buffer.nodes[node].right == DEFAULT_NULL) {
//            return this->buffer.nodes[node].left;
//        }
//        else {
//            int min = minimum(this->buffer.nodes[node].right);
//            this->buffer.nodes[node].info = this->buffer.nodes[min].info;
//            this->buffer.nodes[node].right = removeUtil(this->buffer.nodes[node].right, this->buffer.nodes[min].info, found);
//            return node;
//        }
//    }
//    else if (!relation(this->buffer.nodes[node].info, e)) {
//        this->buffer.nodes[node].left = removeUtil(this->buffer.nodes[node].left, e, found);
//        return node;
//    }
//    else {
//        this->buffer.nodes[node].right = removeUtil(this->buffer.nodes[node].right, e, found);
//        return node;
//    }
//}
//
////theta(cap)
//SortedBag::SortedBag(Relation r) : relation(r)
//{
//    this->buffer.capacity = 10;
//    this->buffer.nodes = new Node[this->buffer.capacity];
//    this->buffer.size = 0;
//    this->buffer.root = 0;
//    this->buffer.firstEmpty = 0;
//    for (int i = 0; i < 10; i++) {
//        this->buffer.nodes[i].info = DEFAULT_NULL;
//        this->buffer.nodes[i].left = DEFAULT_NULL;
//        this->buffer.nodes[i].right = DEFAULT_NULL;
//    }
//}
//
////O(height) <==>O(n)
//void SortedBag::add(TElem  e)
//{
//    if (isEmpty()) {
//        this->buffer.nodes[0].info = e;
//        this->buffer.firstEmpty = 1;
//        this->buffer.size++;
//        return;
//    }
//    if (this->buffer.size == this->buffer.capacity - 1)
//        resize();
//    this->insertIntoTree(this->buffer.root, e);
//    this->buffer.size++;
//}
//
////O(height) <==>O(n)
//bool SortedBag::search(TElem c) const
//{
//    int current = this->buffer.root;
//    while (current != DEFAULT_NULL) {
//        if (relation(this->buffer.nodes[current].info, c)) {
//            if (c == this->buffer.nodes[current].info)
//                return true;
//            current = this->buffer.nodes[current].right;
//        }
//        else {
//            current = this->buffer.nodes[current].left;
//        }
//    }
//    return false;
//}
//
//int SortedBag::nrOccurrences(TElem c) const
//{
//    int count = 0;
//    int current = this->buffer.root;
//    while (current != DEFAULT_NULL) {
//        if (relation(this->buffer.nodes[current].info, c)) {
//            if (c == this->buffer.nodes[current].info)
//                count++;
//            current = this->buffer.nodes[current].right;
//        }
//        else {
//            current = this->buffer.nodes[current].left;
//        }
//    }
//    return count;
//}
//
////O(height) <==>O(n)
//bool SortedBag::remove(TElem c)
//{
//    bool found = false;
//    removeUtil(this->buffer.root, c, found);
//    if (!found)
//        return false;
//    this->buffer.size--;
//    return true;
//}
//
////theta(1)
//int SortedBag::size() const
//{
//    return this->buffer.size;
//}
//
////theta(1)
//bool SortedBag::isEmpty() const
//{
//    return this->buffer.size == 0;
//}
//
////O(n)
//SortedBagIterator SortedBag::iterator() const
//{
//    return SortedBagIterator(*this);
//}
//
////theta(1)
//SortedBag::~SortedBag()
//{
//    delete[] this->buffer.nodes;
//}