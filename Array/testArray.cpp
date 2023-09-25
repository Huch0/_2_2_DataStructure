#include <iostream>
#include "Array.h"

using namespace std;

int main() {
    Array<int> myArray = Array<int>(10);

    // Set values in the array
    for (int i = 0; i < myArray.getSize(); ++i) {
        myArray.set(i, i * 10);
    }

    myArray.display();

    int value = myArray.get(2);
    cout << "Element at index 2: " << value << endl;

    return 1;
}