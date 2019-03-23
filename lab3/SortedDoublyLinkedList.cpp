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

void SortedDoublyLinkedList::add(TElem newElement){
    if(search(newElement.first) == NULL_TVALUE){
        if(length == 0){
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
            if(temp == head){
                nodeToAdd->next = head;
                nodeToAdd->previous = NULL;
                temp->previous = nodeToAdd;
                head = nodeToAdd;
            } else if(temp == NULL){
                nodeToAdd->previous = tail;
                nodeToAdd->next = NULL;
                tail->next = nodeToAdd;
                tail = nodeToAdd;
            } else {
                temp->previous->next = nodeToAdd;
                nodeToAdd->previous = temp->previous;
                temp->previous = nodeToAdd;
                nodeToAdd->next = temp;
            }
        }
        length++;
    } else {
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

void SortedDoublyLinkedList::remove(TKey elementToRemove){
    if(length != 0 && search(elementToRemove) != NULL_TVALUE){
        Node *temp = head;
        if(length == 1){
            length = 0;
            head = NULL;
            tail = NULL;
            return;
        }
        if(head->value.first == elementToRemove){
            head = head->next;
            head->previous = NULL;
            length--;
            return;
        }
        while(temp->value.first != elementToRemove && temp != tail){
            temp = temp->next;
        }
        if(temp == tail && tail->value.first == elementToRemove){
            tail = tail->previous;
            tail->next = NULL;
        } else {
            temp->next->previous = temp->previous;
            temp->previous->next = temp->next;
        }
        length--;
    }
}

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
