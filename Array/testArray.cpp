#include <iostream>
#include "Array.h"

int main() {
    // Create an instance of the Array class
    Array<int> myArray1;

    // Test isEmpty() method
    std::cout << "Is array empty? " << (myArray1.isEmpty() ? "Yes" : "No") << std::endl;

    // Test getSize() method
    std::cout << "Initial size: " << myArray1.getSize() << std::endl;

    // Test getCapacity() method
    std::cout << "Initial capacity: " << myArray1.getCapacity() << std::endl;

    // Test add() method
    for (int i = 0; i < 15; i++) {
        myArray1.add(i, i * 10);
    }

    // Test isFull() method
    std::cout << "Is array full? " << (myArray1.isFull() ? "Yes" : "No") << std::endl;

    // Test resize() method
    std::cout << "New capacity after resizing: " << myArray1.getCapacity() << std::endl;

    // Test set() and get() methods
    myArray1.set(3, 100); // Set element at index 3
    std::cout << "Element at index 3: " << myArray1.get(3) << std::endl;

    // Test display() method
    myArray1.display();

    // Test remove() method
    std::cout << "Removed element at index 3: " << myArray1.remove(3) << std::endl;
    std::cout << "Array after removing" << std::endl;
    myArray1.display();

    // Test sort() method
    Array<int> myArray2 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::cout << "Before sorting" << std::endl;
    myArray2.display();

    myArray2.sort();
    std::cout << "After sorting" << std::endl;
    myArray2.display();

    return 0;
}
