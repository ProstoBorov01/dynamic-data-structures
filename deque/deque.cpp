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
    void pushBack(DynamicArray<T> element);
    void pushFront(DynamicArray<T> element);
    DynamicArray<T> *popBack();
    DynamicArray<T> *popFront();
    DynamicArray<T> *peekBack();
    DynamicArray<T> *peekFront();
};

template<typename T>
DynamicArray<T> *Deque<T>::peekFront() {
    return this -> data -> getFirst();
}

template<typename T>
DynamicArray<T> *Deque<T>::peekBack() {
    return this -> data -> getLast();
}

template<typename T>
DynamicArray<T> *Deque<T>::popBack() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! Queue is empty");
    }

    DynamicArray<T> *element = this -> data -> getLast();
    auto *oldTail = this -> data -> tail;
    this -> data -> tail = this -> data -> tail -> pointerOnPrevElement;
    delete oldTail;

    return element;
}

template<typename T>
DynamicArray<T> *Deque<T>::popFront() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! Queue is empty");
    }

    DynamicArray<T> *element = this -> data -> getFirst();
    auto *oldHead = this -> data -> head;
    this -> data -> head = this -> data -> head -> pointerOnNextElement;
    delete oldHead;

    return element;
}

template<typename T>
void Deque<T>::pushFront(DynamicArray<T> element) {
    this -> data -> prepend(element);
}

template<typename T>
void Deque<T>::pushBack(DynamicArray<T> element) {
    this -> data -> append(element);
}

template<typename T>
size_t Deque<T>::getLength() {
    return this -> data -> length;
}

template<typename T>
bool Deque<T>::isEmpty() {
    return this -> data -> head == nullptr;
}
