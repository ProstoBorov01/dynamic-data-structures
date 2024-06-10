#include <iostream>
#include <mmcobj.h>
#include "../base/collections/doubleLinkedList/doubleLinkedList.h"

template<typename T>
class Queue {
private:
    DoubleLinkedList<T> *data;
public:
    Queue() {
        this -> data = new DoubleLinkedList<T>();
    }

    T *pop();
    T *front();
    T *back();
    void push(T element);
    bool isEmpty();

};

template<typename T>
T *Queue<T>::pop() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! Queue is empty");
    }

    T *element = this -> data -> getFirst();
    auto *oldTail = this -> data -> tail;
    this -> data -> tail = this -> data -> tail -> pointerOnPrevElement;
    delete oldTail;

    return element;
}

template<typename T>
T *Queue<T>::front() {
    return this -> data -> getLast();
}

template<typename T>
T *Queue<T>::back() {
    return this -> data -> getFirst();
}

template<typename T>
void Queue<T>::push(T element) {
    this -> data -> prepend(element);
}

template<typename T>
bool Queue<T>::isEmpty() {
    return this -> data -> head == nullptr;
}
