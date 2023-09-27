#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> myList;

    // Check if the list is empty
    std::cout << "Is the list empty? " << (myList.isEmpty() ? "Yes" : "No") << std::endl;

    // Add nodes to the front of the list
    myList.addFront(1);
    myList.addFront(2);
    myList.addFront(3);

    // Display the front node
    std::cout << "Front element: " << myList.front()<< std::endl;

    // Populate the list with some nodes
    myList.addFront(10);
    myList.addFront(20);
    myList.addFront(30);
    myList.addFront(40);
    myList.addFront(50);

    std::cout << "Original list:" << std::endl;
    myList.display(); // Display the original list

    // Remove the front node
    myList.removeFront();

    std::cout << "List after removing front:" << std::endl;
    myList.display(); // Display the list after removal

    // Remove the specific node
    int dataToRemove = 30; // Data to remove
    myList.remove(dataToRemove);

    std::cout << "List after removing " << dataToRemove << ":" << std::endl;
    myList.display(); // Display the list after removal

    // Test remove() is removing first node.
    dataToRemove = 40; // Data to remove
    myList.remove(dataToRemove);

    std::cout << "List after removing " << dataToRemove << ":" << std::endl;
    myList.display(); // Display the list after removal

    return 0;
}
