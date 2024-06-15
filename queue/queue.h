#pragma once
#include "../base/collections/doubleLinkedListDirectory/doubleLinkedList.h"

template<typename T>
class Queue {
private:
    DoubleLinkedList<T> *data; // односвязный список с хвостом
public:
    Queue() {
        this -> data = new DoubleLinkedList<T>();
    }

    explicit Queue(const Queue<T> *object) {
        this -> data = new DoubleLinkedList<T>(*(object -> data));
    }

    ~Queue() {
        delete this -> data;
    }

    template<typename ... Types>
    Queue<T> *map(T (*func)(T element, Types* ...), Types* ... tail);
    template<typename ... Types>
    Queue<T> *where(bool (*func)(T element, Types* ...), Types* ... tail);
    Queue<T> *concat(Queue<T> *object);
    Queue<T> *getSub(size_t startIndex, size_t endIndex);
    bool containsSubsequence(Queue<T> *subsequence);
    T pop();
    T getFront();
    T getBack();
    void push(T element);
    bool isEmpty();
    size_t getLength();
};

template<typename T>
size_t Queue<T>::getLength() {
    return this -> data -> getLength();
}

template<typename T>
bool Queue<T>::containsSubsequence(Queue<T> *subsequence) {
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
Queue<T> *Queue<T>::getSub(size_t startIndex, size_t endIndex) {
    auto *resultQueue = new Queue();

    for (size_t i = startIndex; i < endIndex; i ++) {
        resultQueue -> push(this -> data -> get(i));
    }

    return resultQueue;
}

template<typename T>
Queue<T> *Queue<T>::concat(Queue<T> *object) {
    auto *resultQueue = new Queue<T>();

    for (int i = 0; i < this -> data -> getLength(); i ++) {
        resultQueue -> data -> append(this -> data -> get(i));
    }

    for (int i = 0; i < object -> data -> getLength(); i++) {
        resultQueue -> data -> append(object -> data -> get(i));
    }

    return resultQueue;
}

template<typename T>
template<typename... Types>
Queue<T> *Queue<T>::where(bool (*func)(T element, Types *...), Types *... tail) {
    auto *resultQueue = new Queue<T>();

    for (int i = 0; i < this -> data -> getLength(); i++) {
        if (func(this -> data -> get(i), tail ...)) {
            resultQueue -> data -> append(this -> data -> get(i));
        }
    }

    return resultQueue;
}

template<typename T>
template<typename... Types>
Queue<T> *Queue<T>::map(T (*func)(T element, Types *...), Types *... tail) {
    auto *resultQueue = new Queue<T>();

    for (int i = 0; i < this -> data -> getLength(); i++) {
        resultQueue -> data -> append(func(this -> data -> get(i), tail...));
    }

    return resultQueue;
}

template<typename T>
T Queue<T>::pop() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! Queue is empty");
    }

    T element = this -> data -> getLast();
    auto *oldTail = this -> data -> tail;
    this -> data -> tail = this -> data -> tail -> pointerOnPrevElement;
    this -> data -> length -= 1;

    if (this -> data -> length == 0) {
        this -> data -> head = nullptr;
    }
    delete oldTail;

    return element;
}

template<typename T>
T Queue<T>::getFront() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! Queue is empty");
    }

    return T(this -> data -> getFirst());
}

template<typename T>
T Queue<T>::getBack() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! Queue is empty");
    }

    return T(this -> data -> getLast());
}

template<typename T>
void Queue<T>::push(T element) {
    this -> data -> append(element);
}

template<typename T>
bool Queue<T>::isEmpty() {
    return this -> data -> getLength() == 0;
}
