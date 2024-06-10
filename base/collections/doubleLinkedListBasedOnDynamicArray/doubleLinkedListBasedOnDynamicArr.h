#pragma once
#include <iostream>
#include "../dynamicArrayDirectory/dynamicArray.h"

template<typename T>
class DoubleLinkedListBasedOnDynamicArray {
private:
    template<typename NodeGeneric>
    class Node{
    public:
        Node<T> *pointerOnNextElement;
        Node<T> *pointerOnPrevElement;
        DynamicArray<T> data;

        explicit Node(T data = DynamicArray<T>(), Node<T> *pointerOnNextElement = nullptr, Node<T> pointerOnPrevElement = nullptr) {
            this -> pointerOnNextElement = pointerOnNextElement;
            this -> pointerOnPrevElement = pointerOnPrevElement;
            this -> data = data;
        }
    };
public:
    Node<T> *head;
    Node<T> *tail;
    size_t length{};

    explicit DoubleLinkedListBasedOnDynamicArray(Node<T> *head = nullptr, Node<T> *tail = nullptr, size_t length = size_t()) {
        this -> head = head;
        this -> tail = tail;
        this -> length = length;
    }

    explicit DoubleLinkedListBasedOnDynamicArray(const DoubleLinkedListBasedOnDynamicArray<T> *object) {

    }

    ~DoubleLinkedListBasedOnDynamicArray() {
        Node<T> *current = this->head;
        while (current != nullptr) {
            Node<T> *next = current->pointerOnNextElement;
            delete current;
            current = next;
        }
    }

    void append(T element);
    void prepend(T element);
    DynamicArray<T> getFirst();
    DynamicArray<T> getLast();
    DynamicArray<T> get(int index);
    size_t getLength();


};

template<typename T>
size_t DoubleLinkedListBasedOnDynamicArray<T>::getLength() {
    return this -> length;
}

template<typename T>
void DoubleLinkedListBasedOnDynamicArray<T>::append(T element) {
    auto *newNode = new Node<T>(element);
    Node<T> *oldTail = this -> tail;

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
void DoubleLinkedListBasedOnDynamicArray<T>::prepend(T element) {
    auto *newNode = new Node<T>(element);

    if (this -> head == nullptr) {
        this -> head = newNode;
        this -> tail = newNode;
    } else {
        newNode -> pointerOnNextElement = this -> head;
        this -> head -> pointerOnPreviousElement = newNode;
        this -> head = newNode;
    }

    this -> length++;
}

template<typename T>
DynamicArray<T> DoubleLinkedListBasedOnDynamicArray<T>::getFirst() {
    return this -> head -> data;
}

template<typename T>
DynamicArray<T> DoubleLinkedListBasedOnDynamicArray<T>::getLast() {
    return this -> tail -> data;
}

template<typename T>
DynamicArray<T> DoubleLinkedListBasedOnDynamicArray<T>::get(int index) {
    if (index < 0 or index >= this -> length) {
        throw std::out_of_range("Index out of range");
    }

    Node<T> *current;
    if (index < this -> length / 2) {
        current = this -> head;
        for (int i = 0; i < index; i ++) {
            current = current -> pointerOnNextElement;
        }
    } else {
        current = this -> tail;
        for (int i = this -> length - 1; i > index; i --) {
            current = current -> pointerOnPreviousElement;
        }
    }

    return current -> data;
}
