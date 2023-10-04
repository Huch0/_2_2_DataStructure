#ifndef QUEUE_H
#define QUEUE_H

#include "../Array/Array.h"

template <typename T>
class Queue {
private:
    Array<T> items_;
    int size_;

    int front_;
    int rear_;
public:
    Queue() : size_(0), front_(0), rear_(0) {};
    ~Queue() = default;

    // Insert element to back
    void push(const T& e) {

        std::cout << "front : " << front_ << " , rear : " << rear_ << " , size : " <<  size_ << std::endl;
        items_.add(rear_, e);

        rear_++;
        size_++;
    }
    // Remove element from front
    void pop() {
        if (isEmpty())
            throw std::out_of_range("Index out of bounds in Queue::pop()");
        items_.set(front_, T());
        front_++;
        size_--;
    }
    // Return a reference of the front element
    const T& front() const {
        if (isEmpty())
            throw std::out_of_range("Index out of bounds in Queue::front()");
        return items_.get(front_);
    }

    // Return a reference of the rear element
    const T& back() const {
        if (isEmpty())
            throw std::out_of_range("Index out of bounds in Queue::back()");
        return items_.get(rear_ - 1);

    }

    // Additional utility functions

    // Return size of the Queue
    int size() const {
        return size_;
    }

    // Return Queue is Empty
    bool isEmpty() const {
        return size_ == 0;
    }

    void display() const {
        std::cout << "front : " << front_ << " , rear : " << rear_ << std::endl;
        std::cout << "[";
        if (!isEmpty()) {
            std::cout << items_.get(front_);

            for (int i = front_ + 1; i < rear_; i++)
                std::cout <<  ", " << items_.get(i);
        }

        std::cout << "]" << std::endl;
    }
};
#endif // QUEUE_H
