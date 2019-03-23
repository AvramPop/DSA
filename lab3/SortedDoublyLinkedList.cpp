//
// Created by dani on 3/23/19.
//

#include <cstdio>
#include "SortedDoublyLinkedList.h"

SortedDoublyLinkedList::SortedDoublyLinkedList(Relation relation) : relation(relation){
    head = NULL;
    tail = NULL;
    length = 0;
}

void SortedDoublyLinkedList::add(TElem newElement){
    if(search(newElement.first) == NULL_TVALUE){
        if(head == NULL){
            Node *temp = new Node;
            temp->next = NULL;
            temp->previous = NULL;
            temp->value = newElement;
            head = temp;
            tail = temp;
        } else {
            Node *temp = new Node;
            temp->value = newElement;
            temp->next = NULL;
            temp->previous = NULL;
            Node *actual = head;
            while(relation(actual->value.first, temp->value.first) && actual != tail){
                actual = actual->next;
            }
            if(head != tail){
                if(actual == head){
                    head->previous = temp;
                    temp->next = head;
                    temp->previous = NULL;
                    head = temp;
                } else if(actual == tail){
                    if(!relation(actual->value.first, temp->value.first)){
                        actual = actual->previous;
                        temp->next = actual->next;
                        temp->previous = actual;
                        actual->next->previous = temp;
                        actual->next = temp;
                    } else {
                        tail->next = temp;
                        temp->next = NULL;
                        temp->previous = tail;
                        tail = temp;
                    }
                } else {
                    actual = actual->previous;
                    temp->next = actual->next;
                    temp->previous = actual;
                    actual->next->previous = temp;
                    actual->next = temp;
                }
            } else {
                if(relation(actual->value.first, temp->value.first)){
                    tail->next = temp;
                    temp->next = NULL;
                    temp->previous = tail;
                    tail = temp;
                } else {
                    head->previous = temp;
                    temp->next = head;
                    temp->previous = NULL;
                    head = temp;
                }
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
        }
    }
}

void SortedDoublyLinkedList::remove(TKey elementToRemove){
    if(length != 0 && search(elementToRemove)){
        Node *temp = head;
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
    Node* temp = head;
    while(temp != NULL){
        if(temp->value.first == element) return temp->value.second;
        temp = temp->next;
    }
    return NULL_TVALUE;
}

int SortedDoublyLinkedList::size()const{
    return length;
}

void SortedDoublyLinkedList::setRelation(Relation r){
    relation = r;
}
