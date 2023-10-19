#ifndef SINGLELINKEDLIST_CPP
#define SINGLELINKEDLIST_CPP

#include <stdarg.h>
#include <iostream>
#include "singleLinkedList.h"
#include "node/node.cpp"


/**
 * @brief allocates and returns new node with given paramenters
 * @param value value of node to be created
 * @param next pointer to new node
 * @return: nNode newNode */ 
Node* SingleLinkedList::newNode(int value, Node* next) {
    Node *node = new Node;
    node->value = value;
    node->next = next;
    return node;
}


Node* SingleLinkedList::findValue(int value) {}

/*** 
 * @brief finds node at given index
 * @return node at given index*/
Node* SingleLinkedList::findIndex(int index) {
    Node *current = this->tail;
    for (int k = 0; (current->next && k < index); current = current->next, k++) ;
    return current;
}


void SingleLinkedList::swap(Node *a, Node *b) {}

SingleLinkedList::SingleLinkedList() {
    this->tail = NULL;
}

/**
 * @brief adds new node to the end of the list
 * @param value to be added */ 
void SingleLinkedList::append(int value) {
    struct Node *node = newNode(value, NULL);
    if (!node) return; 

    // case 1: if list is not empty
    if (this->tail != NULL) { 
        Node *current = this->tail;
        for (;current->next; current = current->next);
        current->next = node;
    // case 2: if list is empty 
    } else  {
        tail = node; 
    }
}

/**
 * @brief adds new node to the end of the list
 * @param count number of values to add
 * @param ... values to add */ 
void SingleLinkedList::appendMultiple(int count, ...) {
    va_list args; 
    va_start(args, count); 
    for (int i = 0; i < count; i++) {
        int value = va_arg(args, int);
        this->append(value);
    }
    va_end(args);
}


/** @brief insert value into list at certain index 
 * @param value to be inserted
*/
void SingleLinkedList::insert(int value, int index) {
    Node *newnode = newNode(value, NULL);
    if (index == 0 || !this->tail) {
        newnode->next = this->tail;
        this->tail = newnode;
    } else {
        Node *current = findIndex(index-1);
        if (current) {
            newnode->next = current->next;
            current->next = newnode;
        }
    }
}


/** @brief prints list */
void SingleLinkedList::print() {
    std::cout << " SingleLinkedList(";
    for (Node* current = this->tail; current; current = current->next)
        if (current->next) 
            std::cout << current->value << ", ";
        else 
            std::cout << current->value;
    std::cout << ")\n";
}

/** @return lenght of list */
size_t SingleLinkedList::lenght() {
    size_t lenght = 0;
    for (Node* current = this->tail; current; current = current->next, lenght++);
    return lenght;
}


int SingleLinkedList::indexOf(int value) {
    int i = 0;
    Node *current = this->tail;
    for (;current; current = current->next, i++) {
        if (current->value == value) 
            return i;
    }
}

void SingleLinkedList::del(int index) {}
void SingleLinkedList::removeFirst(int value) {}
void SingleLinkedList::remove(int value) {}

void SingleLinkedList::bubbleSort() {}
void SingleLinkedList::merge(Node *list) {}

void SingleLinkedList::appendArray(int *arr, size_t len) {}
void SingleLinkedList::insertArray(int *arr, size_t len, int index) {}

std::ostream& operator<<(std::ostream& os, const Node *list) {
    std::cout << " SingleLinkedList(";
    for (; list; list = list->next)
        if (list->next) 
            std::cout << list->value << ", ";
        else 
            std::cout << list->value;
    std::cout << ")\n";
}


#endif
