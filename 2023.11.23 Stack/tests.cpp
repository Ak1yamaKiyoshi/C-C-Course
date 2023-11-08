#include "stack.cpp"
#include <iostream>

#ifndef STACK_TESTS_CPP
#define STACK_TESTS_CPP


void test_push() { 
    std::cout << " <Stack test push>"
    << "\n > Expected output:  Stack(1, 1, 1)"
    << "\n > Actual output:   ";

    Stack<int> *st = new Stack<int>(10);
    st->push(1);
    st->push(1);
    st->push(1);
    st->print();
    delete st;
}

void test_pop_from_empty_stack() {
    std::cout << " <Stack test pop_from_empty_stack>"
    << "\n > Expected output:  error,  You're trying to .pop() from empty Stack."
    << "\n > Actual output:   ";

    Stack<int> *st = new Stack<int>(10);
    st->pop();
    st->print();
    delete st;
}

void test_push_to_full_stack() {
    std::cout << " <Stack test push_to_full_stack>"
    << "\n > Expected output:  error,  You're trying to .push() to full Stack."
    << "\n > Actual output:   ";

    Stack<int> *st = new Stack<int>(1);
    st->push(1);
    st->push(1);
    st->push(1);
    st->push(1);
    st->print();
    delete st;
}

void test_print() {
    std::cout << " <Stack test push_to_full_stack>"
    << "\n > Expected output:  > Actual output:    Stack(1, 1, 1) \n is empty? yes"
    << "\n > Actual output:   ";

    Stack<int> *st = new Stack<int>(3);
    st->push(1);
    st->push(1);
    st->push(1);
    st->print();
    std::cout << " is empty? " << (st->empty() ? "yes" : "no") << "\n";

    delete st;
}


#endif