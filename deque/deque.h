#pragma once

#include "../base/collections/doubleLinkedListDirectory/doubleLinkedList.h"


template<typename T>
class Deque {
private:
    DoubleLinkedList<T> *data;
public:
    Deque() {
        this -> data = new DoubleLinkedList<T>();
    }

    explicit Deque(const Deque<T> *object) {
        this -> data = new DoubleLinkedList<T>(*(object -> data));
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
    void pushBack(T element);
    void pushFront(T element);
    T popBack();
    T popFront();
    T peekBack();
    T peekFront();
};

template<typename T>
Deque<T> *Deque<T>::getSub(size_t startIndex, size_t endIndex) {
    auto *resultQueue = new Deque();

    for (size_t i = startIndex; i < endIndex; i ++) {
        resultQueue -> pushBack(this -> data -> get(i));
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
    auto *resultQueue = new Deque<T>();

    for (int i = 0; i < this -> getLength(); i++) {
        resultQueue->pushBack(this -> data -> get(i));
    }

    for (int i = 0; i < object -> getLength(); i++) {
        resultQueue -> pushBack(object -> data -> get(i));
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
T Deque<T>::peekFront() {
    return this -> data -> getFirst();
}

template<typename T>
T Deque<T>::peekBack() {
    return this -> data -> getLast();
}

template<typename T>
T Deque<T>::popBack() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! Deque is empty");
    }

    T element = this -> data -> getLast();
    DoubleNode<T> *oldTail = this -> data -> tail;
    this -> data -> tail = this -> data -> tail -> pointerOnPrevElement;
    this -> data -> length -= 1;

    if (this -> data -> length == 0) {
        this -> data -> head = nullptr;
    }

    delete oldTail;
    return element;
}

template<typename T>
T Deque<T>::popFront() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! Deque is empty");
    }

    T element = this -> data -> getFirst();
    DoubleNode<T> *oldHead = this -> data -> head;
    this -> data -> head = this -> data -> head -> pointerOnNextElement;
    this -> data -> length -= 1;

    if (this -> data -> length == 0) {
        this -> data -> tail = nullptr;
    }

    delete oldHead;

    return element;
}

template<typename T>
void Deque<T>::pushFront(T element) {
    this -> data -> prepend(element);
}

template<typename T>
void Deque<T>::pushBack(T element) {
    this -> data -> append(element);
}

template<typename T>
size_t Deque<T>::getLength() {
    return this -> data -> length;
}

template<typename T>
bool Deque<T>::isEmpty() {
    return this -> data -> length == 0;
}
