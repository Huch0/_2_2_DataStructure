// Array.h

#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
private:
    T* array_;       // Pointer to the dynamic array
    int size_;       // Size of the array

public:
    // Constructor to create an array of a given size
    explicit Array(int size) {
        size_ = size;
        array_ = new T[size_];  // Allocate memory for the array
    }

    // Destructor to release the memory when the object is destroyed
    ~Array() {
        delete[] array_;  // Deallocate the dynamically allocated memory
    }

    // Get the size of the array
    int getSize() {
        return size_;
    }

    // Set the value of an element at a specific index
    void set(int index, const T& element) {
        array_[index] = element;
    }

    // Get the value of an element at a specific index
    T get(int index) {
        return array_[index];
    }

    // Display the elements of the array
    void display() {
        std::cout << "[" << array_[0];
        for (int i = 1; i < size_; i++) {
            std::cout << ", " << array_[i];
        }
        std::cout << "]" << std::endl;
    }
};

#endif // ARRAY_H
