#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> myQueue;

    // Check if the stack is empty
    std::cout << "Is the Stack empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;

    // Add nodes to the front of the list
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    myQueue.push(40);
    myQueue.push(50);
    myQueue.push(60);

    myQueue.push(70);
    myQueue.push(80);
    myQueue.push(90);


    myQueue.push(100);
    myQueue.push(110);
    myQueue.push(120);

    // Display the front element
    std::cout << "Front element: " << myQueue.front()<< std::endl;

    // Display the Back element
    std::cout << "Back element: " << myQueue.back()<< std::endl;


    std::cout << "Original Queue:" << std::endl;
    myQueue.display(); // Display the original list

    // Remove the front node
    myQueue.pop();

    std::cout << "Queue after pop():" << std::endl;
    myQueue.display(); // Display the list after removal


    return 0;
}
