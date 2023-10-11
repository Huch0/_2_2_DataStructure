#include <iostream>
#include <cassert>
#include "Deque.h"

int main() {
    Deque<int> myDeque;

    // Test empty deque
    assert(myDeque.isEmpty());
    assert(myDeque.size() == 0);

    // Test inserting elements at the front and back
    myDeque.insertFront(1);
    myDeque.insertBack(2);
    myDeque.insertFront(0);
    myDeque.display();

    assert(!myDeque.isEmpty());
    assert(myDeque.size() == 3);
    assert(myDeque.front() == 0);
    assert(myDeque.back() == 2);

    // Test erasing elements from the front and back
    myDeque.eraseFront();
    myDeque.eraseBack();

    assert(!myDeque.isEmpty());
    assert(myDeque.size() == 1);
    assert(myDeque.front() == 1);
    assert(myDeque.back() == 1);

    myDeque.eraseBack();

    // Test exception handling
    try {
        myDeque.eraseFront();
    } catch (const DequeEmpty& ex) {
        // Expected exception
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    // Test clear and empty deque
    assert(myDeque.isEmpty());
    assert(myDeque.size() == 0);

    return 0;
}
