
#pragma once 

template <typename T>

class Stack {
private: 
    int *data;
    size_t capacity;
    size_t lenght; // size? 
public: 
    Stack();
    Stack(size_t capacity);
    ~Stack();
    

    void print();
    void push(T val);
    T pop(); 
    T top(); 
    bool empty(); 
};
