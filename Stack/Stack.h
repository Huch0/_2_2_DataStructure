#ifndef STACK_H
#define STACK_H

#include "../LinkedList/LinkedList.h"

template <typename T>
class Stack {
private:
    LinkedList<T> linkedList_;
    int size_;
public:
    Stack() : size_(0) {};
    ~Stack() = default;

    // Insert element e at the top of the stack.
    void push(const T& e) {
        linkedList_.addFront(e);
        size_++;
    }
    // Remove the top element from the stack
    void pop() {
        if (isEmpty())
            throw std::out_of_range("Index out of bounds in Stack::pop()");
        linkedList_.removeFront();
        size_--;
    }

    // Return a reference to the top element on the stack without removing it
    T& top() {
        if (isEmpty())
            throw std::out_of_range("Index out of bounds in Stack::pop()");
        return linkedList_.front();
    }

    // Additional utility functions

    // Return the number of elements in the stack
    int size() {
        return size_;
    }

    // Return true if the stack is empty and false otherwise
    bool isEmpty() {
        return size_ == 0;
    }

    void display() {
        linkedList_.display();
    }
};


#endif // STACK_H
