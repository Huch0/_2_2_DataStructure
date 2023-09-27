#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    // Create a DoublyLinkedList of integers
    DoublyLinkedList<int> myDoublyLinkedList;

    // Check if the list is empty
    std::cout << "Is the list empty? " << (myDoublyLinkedList.isEmpty() ? "Yes" : "No") << std::endl;

    // Add some elements to the front
    myDoublyLinkedList.addFront(3);
    myDoublyLinkedList.addFront(5);
    myDoublyLinkedList.addFront(7);

    // Display the contents of the list
    std::cout << "Contents of the list: " << std::endl;
    myDoublyLinkedList.display();

    // Check if the list is empty again
    std::cout << "Is the list empty? " << (myDoublyLinkedList.isEmpty() ? "Yes" : "No") << std::endl;

    // Add elements to the back
    myDoublyLinkedList.addBack(9);
    myDoublyLinkedList.addBack(11);

    // Display the contents of the list after adding to the back
    std::cout << "Contents of the list after adding to the back: " << std::endl;
    myDoublyLinkedList.display();

    // Remove elements from the front and back
    myDoublyLinkedList.removeFront();
    myDoublyLinkedList.removeBack();

    // Display the contents of the list after removal
    std::cout << "Contents of the list after removeFront() and removeBack(): " << std::endl;
    myDoublyLinkedList.display();

    // Add a new element before a specific value
    myDoublyLinkedList.addBefore(4, 3); // Add 4 before 5

    // Display the contents of the list after adding before a specific value
    std::cout << "Contents of the list after adding before a specific value: " << std::endl;
    myDoublyLinkedList.display();

    // Remove a specific value
    myDoublyLinkedList.removeByValue(3); // Remove the node with value 7

    // Display the contents of the list after removal by value
    std::cout << "Contents of the list after removal by value: " << std::endl;
    myDoublyLinkedList.display();

    return 0;
}
