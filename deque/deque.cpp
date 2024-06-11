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
    template<typename ... Types>
    Deque<T> *map(T (*func)(T element, Types* ...), Types* ... tail);
    template<typename ... Types>
    Deque<T> *where(bool (*func)(T element, Types* ...), Types* ... tail);
    Deque<T> *concat(Deque<T> *object);
    Deque<T> *getSub(size_t startIndex, size_t endIndex);
    bool containsSubsequence(Deque<T> *subsequence);
    void pushBack(DynamicArray<T> element);
    void pushFront(DynamicArray<T> element);
    DynamicArray<T> *popBack();
    DynamicArray<T> *popFront();
    DynamicArray<T> *peekBack();
    DynamicArray<T> *peekFront();
};

template<typename T>
Deque<T> *Deque<T>::getSub(size_t startIndex, size_t endIndex) {
    auto *resultQueue = new Deque();

    for (size_t i = startIndex; i < endIndex; i ++) {
        resultQueue -> pushBack(this -> get(i));
    }

    return resultQueue;
}

template<typename T>
bool Deque<T>::containsSubsequence(Deque <T> *subsequence) {
    if (subsequence -> isEmpty()) {
        return true;
    }

    if (this -> isEmpty()) {
        return false;
    }

    size_t mainQueueLength = this -> data -> getLength();
    size_t subQueueLength = subsequence -> data -> getLength();

    if (subQueueLength > mainQueueLength) {
        return false;
    }

    for (size_t i = 0; i <= mainQueueLength - subQueueLength; ++i) {
        bool found = true;

        for (size_t j = 0; j < subQueueLength; ++j) {
            if (this -> data -> get(i + j) != subsequence -> data -> get(j)) {
                found = false;
                break;
            }
        }

        if (found) {
            return true;
        }
    }

    return false;
}

template<typename T>
Deque<T> *Deque<T>::concat(Deque<T> *object) {
    auto *resultQueue = new Deque<T>(object);

    for (int i = 0; i < object -> data -> getLength(); i++) {
        resultQueue -> data -> append(object -> data -> get(i));
    }

    return resultQueue;
}

template<typename T>
template<typename... Types>
Deque<T> *Deque<T>::where(bool (*func)(T, Types *...), Types *... tail) {
    auto *resultQueue = new Deque<T>();

    for (int i = 0; i < this -> data -> getLength(); i++) {
        if (func(this -> data -> get(i), tail ...)) {
            resultQueue -> data -> append(this -> data -> get(i));
        }
    }

    return resultQueue;
}

template<typename T>
template<typename... Types>
Deque<T> *Deque<T>::map(T (*func)(T, Types *...), Types *... tail) {
    auto *resultDeque = new Deque<T>();

    for (int i = 0; i < this -> data -> getLength(); i++) {
        resultDeque -> data -> append(func(this -> data -> get(i), tail...));
    }

    return resultDeque;
}

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
        throw std::invalid_argument("Error! Deque is empty");
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
        throw std::invalid_argument("Error! Deque is empty");
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
