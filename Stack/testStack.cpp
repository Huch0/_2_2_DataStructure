#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> myStack;

    // Check if the stack is empty
    std::cout << "Is the Stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;

    // Add nodes to the front of the list
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Display the top element
    std::cout << "Top element: " << myStack.top()<< std::endl;


    std::cout << "Original Stack:" << std::endl;
    myStack.display(); // Display the original list

    // Remove the front node
    myStack.pop();

    std::cout << "Stack after pop():" << std::endl;
    myStack.display(); // Display the list after removal


    return 0;
}
