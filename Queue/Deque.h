#ifndef DEQUE_H
#define DEQUE_H

#include "../LinkedList/DoublyLinkedList.h"

#include <exception>
#include <string>

class DequeEmpty : public std::exception {
private:
    std::string message;

public:
    explicit DequeEmpty(const std::string& msg) : message(msg) {}

    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class Deque {
private:
    DoublyLinkedList<T> container_;
    int size_;
public:

    Deque() : size_(0) {};
    ~Deque() = default;
    // Insert a new element at the beginning of the deque
    void insertFront(const T& newElement) {
        container_.addFront(newElement);
        size_++;
    }

    // Insert a new element at the end of the deque.
    void insertBack(const T& newElement) {
        container_.addBack(newElement);
        size_++;
    }

    // Remove the element from the beginning of the deque
    void eraseFront() {
        if (size_ == 0)
            throw DequeEmpty("Deque is empty in Deque::eraseFront()");

        container_.removeFront();
        size_--;
    }

    // Remove the element from the end of the deque
    void eraseBack() {
        if (size_ == 0)
            throw DequeEmpty("Deque is empty in Deque::eraseBack()");

        container_.removeBack();
        size_--;
    }

    // Additional utility functions

    // Return the first element of the deque
    const T& front() const {
        if (size_ == 0)
            throw DequeEmpty("Deque is empty in Deque::front()");
        return container_.front();
    }

    // Return the last element of the deque
    const T& back() const {
        if (size_ == 0)
            throw DequeEmpty("Deque is empty in Deque::back()");
        return container_.back();
    }

    // Return the size of the deque
    [[nodiscard]] int size() const {
        return size_;
    }

    // Check is the deque empty
    [[nodiscard]] bool isEmpty() const {
        return size_ == 0;
    }

    // Display the contents of the deque
    void display() const {
        container_.display();
    }
};

#endif // DEQUE_H
