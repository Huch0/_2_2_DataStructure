cmake_minimum_required(VERSION 3.26)
project(_2_2_DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(Pa_01_1
        "[PA 01] C++ Practice - Classes, Templates, and Operator Overloading/using_friend.cpp")

add_executable(Pa_01_2
        "[PA 01] C++ Practice - Classes, Templates, and Operator Overloading/using_getter_setter.cpp")

add_executable(PA_02
        "[PA 02] String Decoder/StackStringDecoder.cpp")

add_executable(PA03
        "[PA 03] Common Ancestors in a Binary Search Tree/BinarySearchTree.cpp")


add_executable(PA04
        "[PA 04] MAT-ZIP/array.cpp"
        "[PA 04] MAT-ZIP/priorityQueue.cpp")

add_executable(PA05
        "[PA 05] My Hash Table/myHashTable.cpp"
)

add_executable(ValidatePA05
        "[PA 05] My Hash Table/validateTestCase.cpp"
)

add_executable(Array
        Array/testArray.cpp)

add_executable(LinkedList
        LinkedList/LinkedList.h
        LinkedList/testLinkedList.cpp)

add_executable(DoublyLinkedList
        LinkedList/DoublyLinkedList.h
        LinkedList/testDoublyLinkedList.cpp)

add_executable(Stack
        Stack/Stack.h
        Stack/testStack.cpp)

add_executable(Queue
        Queue/Queue.h
        Queue/testQueue.cpp)
add_executable(Deque
        Queue/Deque.h
        Queue/testDeque.cpp)

add_executable(Tree
        Tree/Tree.h
        Tree/testTree.cpp)
