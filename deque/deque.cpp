#pragma once
#include <iostream>
#include "../base/collections/dynamicArrayDirectory/dynamicArray.h"
#include "../base/collections/doubleLinkedListBasedOnDynamicArray/doubleLinkedListBasedOnDynamicArr.h"

template<typename T>
class Deque {
private:
    DoubleLinkedListBasedOnDynamicArray<T> *data;
public:
    Deque() {
        this -> data = new DoubleLinkedListBasedOnDynamicArray<T>();
    }

    explicit Deque(const Deque<T> *object) {
        this -> data = new DoubleLinkedListBasedOnDynamicArray<T>(*(object -> data));
    }

    ~Deque() {
        delete this -> data;
    }

    bool isEmpty();
    size_t getLength();
    void pushBack(DynamicArray<T> data);
    void pushFront(DynamicArray<T> data);
    DynamicArray<T> *popBack();
    DynamicArray<T> *popFront();

};

template<typename T>
DynamicArray<T> *Deque<T>::popFront() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! Queue is empty");
    }

    T *element = this -> ();
    auto *oldTail = this -> data -> tail;
    this -> data -> tail = this -> data -> tail -> pointerOnPrevElement;
    delete oldTail;

    return element;
}

template<typename T>
DynamicArray<T> *Deque<T>::popBack() {

}

template<typename T>
void Deque<T>::pushFront(DynamicArray<T> data) {
    auto *newNode = new Node<T>(data);
    Node<T> *oldHead = this -> head;

    if (this -> head != nullptr) {
        newNode -> pointerOnNextElement = oldHead;
        this -> head = newNode;
        oldHead -> pointerOnPrevElement = this -> Head;
        this -> length += 1;

        return;
    }

    this -> length += 1;
    this -> head = newNode;
    this -> tail = newNode;
}

template<typename T>
void Deque<T>::pushBack(DynamicArray<T> data) {
    auto *newNode = new Node<T>(data);
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
size_t Deque<T>::getLength() {
    return this -> length;
}

template<typename T>
bool Deque<T>::isEmpty() {
    return this -> head == nullptr;
}
