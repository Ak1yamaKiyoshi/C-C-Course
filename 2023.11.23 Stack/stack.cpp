#include <iostream>
#include <stdexcept>
#include "stack.h"


#ifndef STACK_CPP
#define STACK_CPP

template <typename T>
Stack<T>::Stack() {
    this->capacity = 40;
    this->lenght = 0;
    this->data = new T[this->capacity];
}

template <typename T>
Stack<T>::Stack(size_t capacity) {
    this->capacity = capacity;
    this->lenght = 0;
    this->data = new T[this->capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] this->data;
}

template <typename T>
void Stack<T>::push(T val) {
    if (this->lenght >= this->capacity) 
        throw std::overflow_error("You're trying to .push() to full Stack.");
        //std::cerr << " You're trying to .push() to full Stack." << "\n";
    else 
        this->data[this->lenght++] = val; 
}

template <typename T>
bool Stack<T>::empty() {
    return this->lenght == 0;
}

template <typename T>
T Stack<T>::pop() {
    if (this->empty()) 
        throw std::out_of_range("You're trying to .pop() from empty Stack.");
        //std::cerr << " You're trying to .pop() from empty Stack." << "\n";
    return this->data[--this->lenght];
}

template <typename T>
T Stack<T>::top() {
    if (this->empty())
        std::cerr << " You're trying to use .top() from empty Stack. " << "\n"; 
    return this->data[--this->lenght];
}

template <typename T>
void Stack<T>::print() {
    std::cout << " Stack(";
    for (size_t i = 0, len = this->lenght; i < len ; i++) {
        T value = this->pop();
        if (i != len-1) 
            std::cout << value << ", ";
        else 
            std::cout << value;
    }
    std::cout << ")\n";
}


#endif




