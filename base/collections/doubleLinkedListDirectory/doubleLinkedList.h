#pragma once
#include <iostream>
    
template <typename T>
class DoubleNode {
public:
    DoubleNode<T> *pointerOnNextElement;
    DoubleNode<T> *pointerOnPrevElement;
    T data;

    explicit DoubleNode(T data = T(), DoubleNode<T> *pointerOnNextElement = nullptr, DoubleNode<T> *pointerOnPrevElement = nullptr) {
        this -> pointerOnNextElement = pointerOnNextElement;
        this -> pointerOnPrevElement = pointerOnPrevElement;
        this -> data = data;
    }
};

template<typename T>
class DoubleLinkedList {
private:
   
public:
    DoubleNode<T> *head;
    DoubleNode<T> *tail;
    size_t length{};

    explicit DoubleLinkedList(DoubleNode<T> *head = nullptr, DoubleNode<T> *tail = nullptr, size_t length = size_t()) {
        this -> head = head;
        this -> tail = tail;
        this -> length = length;
    }

    ~DoubleLinkedList() {
        DoubleNode<T> *current = this -> head;
        while (current != nullptr) {
            DoubleNode<T> *next = current -> pointerOnNextElement;
            delete current;
            current = next;
        }
    }

    void append(T element);
    void prepend(T element);
    T getFirst() const;
    T getLast() const;
    T get(int index) const;
    size_t getLength() const;
};

template<typename T>
size_t DoubleLinkedList<T>::getLength() const {
    return this -> length;
}

template<typename T>
void DoubleLinkedList<T>::append(T element) {
    auto *newNode = new DoubleNode<T>(element);
    DoubleNode<T> *oldTail = this -> tail;

    if (this -> head != nullptr) {
        newNode -> pointerOnPrevElement = oldTail;
        this -> tail = newNode;
        oldTail -> pointerOnNextElement = this -> tail;
        this -> length += 1;

        return;
    }

    this -> length += 1;
    this -> head = newNode;
    this -> tail = newNode;
}

template<typename T>
void DoubleLinkedList<T>::prepend(T element) {
    auto *newNode = new DoubleNode<T>(element);

    if (this -> head == nullptr) {
        this -> head = newNode;
        this -> tail = newNode;
    } else {
        newNode -> pointerOnNextElement = this -> head;
        this -> head -> pointerOnPrevElement = newNode;
        this -> head = newNode;
    }

    this -> length++;
}

template<typename T>
T DoubleLinkedList<T>::getFirst() const {
    return this -> head -> data;
}

template<typename T>
T DoubleLinkedList<T>::getLast() const {
    return this -> tail -> data;
}

template<typename T>
T DoubleLinkedList<T>::get(int index) const {
    if (index < 0 or index >= this -> length) {
        throw std::out_of_range("Index out of range");
    }

    DoubleNode<T> *current;
    if (index < this -> length / 2) {
        current = this -> head;

        for (int i = 0; i < index; i ++) {
            current = current -> pointerOnNextElement;
        }
    } else {
        current = this -> tail;

        for (int i = this -> length - 1; i > index; i --) {
            current = current -> pointerOnPrevElement;
        }
    }

    return current -> data;
}

