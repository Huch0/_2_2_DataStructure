#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class DoublyLinkedList;

template <typename T>
class Node {
private:
    T data_;
    Node<T>* prev_;
    Node<T>* next_;

    friend class DoublyLinkedList<T>;

public:
    explicit Node(const T& data) : data_(data), prev_(nullptr), next_(nullptr) {};
    ~Node() = default;
};

template <typename T>
class DoublyLinkedList {
private:
    // Sentinel nodes
    // - A specifically designated node as a traversal path terminator for convenience
    Node<T>* header_;
    Node<T>* trailer_;

public:
    DoublyLinkedList() {
        header_ = new Node<T>(T()); // Create header with default-constructed data
        trailer_ = new Node<T>(T()); // Create trailer with default-constructed data

        header_->next_ = trailer_;
        trailer_->prev_ = header_;
    };
    ~DoublyLinkedList() {
        while (isEmpty()) {
            removeFront();
        }

        delete header_;
        delete trailer_;
    }

    // Check is the doubly linked list empty
    // O(1)
    [[nodiscard]] bool isEmpty() const {
        return header_->next_ == trailer_;
    }

    // Add a new node before a specific node.
    // O(1)
    void add(const T& newData, Node<T>* position) {
        auto* newNode = new Node<T>(newData);
        Node<T>* prevNode = position->prev_;

        // before : <-> prevNode <-> position <->
        // after : <-> prevNode <-> newNode <-> position <->
        prevNode->next_ = newNode;
        newNode->prev_ = prevNode;
        newNode->next_ = position;
        position->prev_ = newNode;
    }

    // Add a Node to front
    // O(1)
    void addFront(const T& newData) {
        add(newData, header_->next_);
    }

    // Add a Node to back
    // O(1)
    void addBack(const T& newData) {
        add(newData, trailer_);
    }

    // Remove a Node from the specific position
    // O(1)
    void remove(Node<T>* removing) {
        if (isEmpty())
            return;

        Node<T>* prevNode = removing->prev_;
        Node<T>* nextNode = removing->next_;

        // before : prevNode <-> removing <-> nextNode
        // after : prevNode <-> nextNode
        prevNode->next_ = nextNode;
        nextNode->prev_ = prevNode;

        delete removing;
    }

    // Remove a Node from the front
    // O(1)
    void removeFront() {
        remove(header_->next_);
    }

    // Remove a Node from the back
    // O(1)
    void removeBack() {
        remove(trailer_->prev_);
    }

    // Search for a Node by value
    // O(n)
    Node<T>* searchNode(const T& data) const {
        Node<T>* tracer = header_->next_;

        while(tracer != trailer_) {
            if (tracer->data_ == data)
                break;

            tracer = tracer->next_;
        }

        if (tracer == trailer_)
            throw std::runtime_error("Value not found in the DoublyLinkedList");

        return tracer;
    }

    // Add a Node before a specific Node (search by value)
    // O(n)
    void addBefore(const T& newData, const T& valueOfPosition) {
        add(newData, searchNode(valueOfPosition));
    }

    // Remove a specific Node by value
    // O(n)
    void removeByValue(const T& data) {
        remove(searchNode(data));
    }

    // Return the first element of the doubly linked list.
    const T& front() const {
        return header_->next_->data_;
    }

    // Return the last element of the doubly linked list.
    const T& back() const {
        return trailer_->prev_->data_;
    }

    // Display the contents of doubly linked list
    // O(n)
    void display() const {
        Node<T>* tracer = header_->next_;

        std::cout << "header <-> ";

        while(tracer != trailer_) {
            std::cout << tracer->data_ << " <-> ";

            tracer = tracer->next_;
        }

        std::cout << "trailer" << std::endl;
    }

};

#endif //DOUBLYLINKEDLIST_H
