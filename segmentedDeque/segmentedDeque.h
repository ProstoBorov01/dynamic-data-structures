#pragma once
#include <iostream>
#include "../base/collections/dynamicArrayDirectory/dynamicArray.h"
#include "../base/collections/doubleLinkedListBasedOnDynamicArray/doubleLinkedListBasedOnDynamicArr.h"

template<typename T>
class SegmentedDeque {
private:
    DoubleLinkedListBasedOnDynamicArray<T> *data;
public:
    SegmentedDeque() {
        this -> data = new DoubleLinkedListBasedOnDynamicArray<T>();
    }

    explicit SegmentedDeque(const SegmentedDeque<T> *object) {
        this -> data = new DoubleLinkedListBasedOnDynamicArray<T>(*(object -> data));
    }

    ~SegmentedDeque() {
        delete this -> data;
    }

    bool isEmpty() const;
    size_t getLength() const;
    void pushBack(T element);
    void pushFront(T element);
    T *popBack();
    T *popFront();
    T *peekBack();
    T *peekFront();
};

template<typename T>
T *SegmentedDeque<T>::peekFront() {
    return this -> data -> getFirst()[0];
}

template<typename T>
T *SegmentedDeque<T>::peekBack() {
    return this -> data -> getLast()[this -> data -> getLast().getSize() - 1];
}

template<typename T>
T *SegmentedDeque<T>::popFront() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! SegmentedDeque is empty");
    }

    DynamicArray<T> firstArray = this -> data -> getFirst();
    auto *buf = new DynamicArray<T>(firstArray.getSize() - 1);
    T element = firstArray[firstArray.getSize() - 1];

    for (int i = 0; i < firstArray.getSize() - 1; i ++) {
        buf -> set(i, firstArray[i]);
    }

    auto *newSegment = new Segment<T>(buf);
    Segment<T> *afterTheHead = this -> data -> head -> pointerOnNextElement;
    newSegment -> pointerOnNextElement = afterTheHead;
    delete this -> data -> head;
    this -> data -> head = newSegment;

    return *element;
}

template<typename T>
T *SegmentedDeque<T>::popBack() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! SegmentedDeque is empty");
    }
    DynamicArray<T> lastArray = this -> data -> getLast();
    auto *buf = new DynamicArray<T>(lastArray.getSize() - 1);
    T element = lastArray[lastArray.getSize() - 1];

    for (int i = 0; i < lastArray.getSize() - 1; i ++) {
        buf ->set(i, lastArray[i]);
    }

    auto *newSegment = new Segment<T>(buf);
    Segment<T> *beforeTheTail = this -> data -> tail -> pointerOnPrevElement;
    newSegment -> pointerOnPrevElement = beforeTheTail;
    delete this -> data -> tail;
    this -> data -> tail = newSegment;

    return *element;
}

template<typename T>
void SegmentedDeque<T>::pushBack(T element) {
    if (this -> isEmpty()) {
        DynamicArray<T> *dynamicArray = this -> data -> getLast();

        if (dynamicArray -> getSize() < this -> data -> defaultSegmentSize) {
            dynamicArray -> resize(dynamicArray -> getSize() + 1);
            dynamicArray -> set(dynamicArray -> getSize() - 1, element);

            return;
        }
    }

    this -> data -> append(new DynamicArray<T>(1));
    this -> data -> getLast().set(0, element);
}

template<typename T>
void SegmentedDeque<T>::pushFront(T element) {
    if (this -> isEmpty()) {
        DynamicArray<T> *dynamicArray = this->data->getFirst();

        if (dynamicArray->getSize() < this -> data -> defaultSegmentSize) {
            dynamicArray->resize(dynamicArray -> getSize() + 1);
            dynamicArray->set(dynamicArray -> getSize() - 1, element);

            return;
        }
    }
    this -> data -> prepend(new DynamicArray<T>(1));
    this -> data -> getFirst().set(0, element);
}

template<typename T>
size_t SegmentedDeque<T>::getLength() const {
    return this -> data -> getLength();
}

template<typename T>
bool SegmentedDeque<T>::isEmpty() const {
    return this -> data -> head == nullptr;
}
