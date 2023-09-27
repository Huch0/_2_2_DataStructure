#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList;

template <typename T>
class Node {
private:
    T data_;
    Node *next_;

    friend class LinkedList<T>;

public:
    explicit Node(const T& data) : data_(data), next_(nullptr) {};
    ~Node() = default;
};

template <typename T>
class LinkedList {
private:
    Node<T>* head_;

public:
    // Constructor
    explicit LinkedList() : head_(nullptr) {};

    // Destructor
    ~LinkedList() {
        while(!isEmpty())
            removeFront();
    }


    // Check is linked list empty
    bool isEmpty() const {
        return head_ == nullptr;
    }

    // Return data of first node of linked list
    const T& front() const {
        if (isEmpty())
            throw std::out_of_range("Index out of bounds in LinkedList::front()");
        return head_->data_;
    }

    // Add a new node to front
    void addFront(const T& data) {
        // Clang-Tidy: Use auto when initializing with new to avoid duplicating the type name
        auto* newNode = new Node<T>(data);
        newNode->next_ = head_;
        head_ = newNode;
    }

    // Remove a node from front
    void removeFront() {
        if (isEmpty())
            return;
        Node<T>* removing = head_;
        head_ = head_->next_;
        delete removing;
    }

    // Remove a node that has specific data.
    void remove(const T& data) {
        if (isEmpty())
            return;

        // Check if the first node matches the data
        if (head_->data_ == data)
            removeFront();

        Node<T>* cur = head_;
        Node<T>* prev = nullptr;

        while(cur != nullptr) {
            if (cur->data_ == data) {
                prev->next_ = cur->next_;
                delete cur;

                return;
            }

            prev = cur;
            cur = cur->next_;
        }
    }

    // Display the contents of the linked list
    void display() {
        Node<T>* tracer = head_;

        while (tracer != nullptr) {
            std::cout << tracer->data_ << " -> ";

            tracer = tracer->next_;
        }

        std::cout << "Null" << std::endl;
    }
};


#endif //LINKEDLIST_H
