//
// Created by dani on 3/23/19.
//

#include <cstdio>
#include "SortedDoublyLinkedList.h"
#include <iostream>

SortedDoublyLinkedList::SortedDoublyLinkedList(Relation relation) : relation(relation){
    head = NULL;
    tail = NULL;
    length = 0;
}
// O(n)
void SortedDoublyLinkedList::add(TElem newElement){
    if(search(newElement.first) == NULL_TVALUE){
        if(length == 0){ // list is empty
            Node* temp = new Node;
            temp->value = newElement;
            temp->previous = NULL;
            temp->next = NULL;
            head = temp;
            tail = temp;
        } else {
            Node* temp = head;
            while(temp && relation(temp->value.first, newElement.first)){
                temp = temp->next;
            }
            Node* nodeToAdd = new Node;
            nodeToAdd->value = newElement;
            if(temp == head){ // element is added on first position
                nodeToAdd->next = head;
                nodeToAdd->previous = NULL;
                temp->previous = nodeToAdd;
                head = nodeToAdd;
            } else if(temp == NULL){ // element on last position
                nodeToAdd->previous = tail;
                nodeToAdd->next = NULL;
                tail->next = nodeToAdd;
                tail = nodeToAdd;
            } else { // element somewhere in the middle
                temp->previous->next = nodeToAdd;
                nodeToAdd->previous = temp->previous;
                temp->previous = nodeToAdd;
                nodeToAdd->next = temp;
            }
        }
        length++;
    } else { // element already here
        Node* temp = head;
        while(temp != NULL){
            if(temp->value.first == newElement.first) {
                temp->value.second = newElement.second;
                return;
            }
            temp = temp->next;
        }
    }
}

// O(n)
void SortedDoublyLinkedList::remove(TKey elementToRemove){
    if(length != 0 && search(elementToRemove) != NULL_TVALUE){
        Node *temp = head;
        if(length == 1){ // only the sought element
            length = 0;
            head = NULL;
            tail = NULL;
            return;
        }
        if(head->value.first == elementToRemove){ // element is first
            head = head->next;
            head->previous = NULL;
            length--;
            return;
        }
        while(temp->value.first != elementToRemove && temp != tail){
            temp = temp->next;
        }
        if(temp == tail && tail->value.first == elementToRemove){ // element is last
            tail = tail->previous;
            tail->next = NULL;
        } else { // else
            temp->next->previous = temp->previous;
            temp->previous->next = temp->next;
        }
        length--;
    }
}

//O(n)
TValue SortedDoublyLinkedList::search(TKey element)const{
    if(length != 0){
        if(length == 1){
            return head->value.first == element ? head->value.second : NULL_TVALUE;
        }
        Node *temp = head;
        while(temp != NULL){
            if(temp->value.first == element) return temp->value.second;
            temp = temp->next;
        }
        return NULL_TVALUE;
    } else return NULL_TVALUE;
}

//theta(1)
int SortedDoublyLinkedList::size()const{
    return length;
}

void SortedDoublyLinkedList::setRelation(Relation r){
    relation = r;
}

SortedDoublyLinkedList::SortedDoublyLinkedList(){
    head = NULL;
    tail = NULL;
    length = 0;
}

SortedDoublyLinkedList::~SortedDoublyLinkedList(){}
