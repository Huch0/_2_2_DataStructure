// Array.h

#ifndef ARRAY_H
#define ARRAY_H

#include <initializer_list>

template <typename T>
class Array {
private:
    T* array_;       // Pointer to the dynamic array
    int size_;       // Size of the array
    int capacity_;   // Capacity of the array

public:
    // Constructor to create an array of a given size
    explicit Array() {
        size_ = 0;
        capacity_ = 10;
        array_ = new T[size_];  // Allocate memory for the array
    }

    // Constructor to create an array from an initializer list
    Array(std::initializer_list<T> elements) {
        size_ = elements.size();
        capacity_ = size_;
        array_ = new T[capacity_];

        // Copy elements from the initializer list to the array
        int i = 0;
        for (const T& element : elements) {
            array_[i] = element;
            i++;
        }
    }

    // Destructor to release the memory when the object is destroyed
    ~Array() {
        delete[] array_;  // Deallocate the dynamically allocated memory
    }

    // Get the size of the array
    int getSize() {
        return size_;
    }

    // Get the capacity of the array
    int getCapacity() {
        return capacity_;
    }

    // Set the value of an element at a specific index
    void set(const int index, const T& element) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of bounds in Array::set()");
        }

        array_[index] = element;
    }

    // Get the value of an element at a specific index
    const T& get(const int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of bounds in Array::get()\nindex = " + std::to_string(index));
        }

        return array_[index];
    }

    // Display the elements of the array
    void display() {
        std::cout << "size / capacity : " << size_ << " / " << capacity_ << std::endl;
        std::cout << "[" << array_[0];
        for (int i = 1; i < size_; i++) {
            std::cout << ", " << array_[i];
        }
        std::cout << "]" << std::endl;
    }

    // Additional methods ...

    // Check is array empty
    bool isEmpty() {
        return !size_;
    }

    // Check is array full
    bool isFull() {
        return size_ == capacity_;
    }

    // Resize the capacity of array
    void resize() {
        capacity_ *= 2; // Double the capacity
        T* newArray = new T[capacity_];

        // Copy elements of the old array to new one
        for (int i = 0; i < size_; i++) {
            newArray[i] = array_[i];
        }

        // Deallocate memory used by the old array
        delete[] array_;

        // Update the array pointer
        array_ = newArray;
    }

    // Insert an element at a specific index
    void add(const int index, const T &element) {
        if (isFull())
            // if the array is full, resize it.
            resize();

        // Shift elements to right to make space for the new element
        for (int i = size_; i > index; i--) {
            array_[i] = array_[i - 1];
        }

        // Insert the new element at a specific index
        array_[index] = element;

        // Update the size
        size_ += 1;
    }

    // Push an element at the back of the array
    void push(const T& element) {
        add(size_, element);
    }

    // Remove an element at a specific index
    T remove(const int index) {
        if (isEmpty()) {
            throw std::underflow_error("Array is empty in Array::remove()");
        }

        if (index < 0 || index >= size_)
            throw std::out_of_range("Index out of bounds in Array::remove()");

        // Store the element to be removed
        T removed = array_[index];

        // Shift elements to left to remove space for removing element
        for (int i = index; i < size_ - 1; i++) {
            array_[i] = array_[i + 1];
        }

        // Update the size of the array
        size_ -= 1;

        return removed;
    }

    // Sort the array in ascending order with Insertion Sort
    void sort() {
        for (int i = 1; i < size_; i++) {
            T current = array_[i];
            int j = i - 1;

            // Move elements to the right greater than the current element
            while (j >= 0 && current < array_[j]) {
                array_[j + 1] = array_[j];
                j--;
            }

            // Insert the current element in its correct position
            array_[j + 1] = current;
        }

    }
};

#endif // ARRAY_H
