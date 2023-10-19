#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include "node/node.cpp"
#include <iostream>

class SingleLinkedList {
private:
    Node *tail;
    
    Node* newNode(int value, Node* next);
    Node* findValue(int value);
    Node* findIndex(int index);
    void swap(Node *a, Node *b);

public: 
    SingleLinkedList();

    void append(int value);
    void appendMultiple(int count, ...); 
    void insert(int value, int index);
    void print();
    size_t lenght();
    int indexOf(int value);

    void del(int index);
    void removeFirst(int value);
    void remove(int value);

    void bubbleSort();
    void merge(Node *list);

    void appendArray(int *arr, size_t len);
    void insertArray(int *arr, size_t len, int index);
    
    friend std::ostream& operator<<(std::ostream& os, const Node *list);
};


#endif