#pragma once
#include <iostream>
#include "../dynamicArrayDirectory/dynamicArray.h"


template<typename T>
class Segment {
public:
    Segment<T> *pointerOnNextElement;
    Segment<T> *pointerOnPrevElement;
    DynamicArray<T> data;

    explicit Segment(T data = DynamicArray<T>(), Segment<T> *pointerOnNextElement = nullptr, Segment<T> *pointerOnPrevElement = nullptr) {
        this -> pointerOnNextElement = pointerOnNextElement;
        this -> pointerOnPrevElement = pointerOnPrevElement;
        this -> data = data;
    }
};

template<typename T>
class DoubleLinkedListBasedOnDynamicArray {
public:
    Segment<T> *head;
    Segment<T> *tail;
    int defaultSegmentSize; // максимальная длина сегмента
    size_t length{};

    explicit DoubleLinkedListBasedOnDynamicArray(Segment<T> *head = nullptr, Segment<T> *tail = nullptr, size_t length = size_t()) {
        this -> head = head;
        this -> tail = tail;
        this -> length = length;
    }

    explicit DoubleLinkedListBasedOnDynamicArray(const DoubleLinkedListBasedOnDynamicArray<T> *object) {

    }

    ~DoubleLinkedListBasedOnDynamicArray() {
        Segment<T> *current = this->head;
        while (current != nullptr) {
            Segment<T> *next = current->pointerOnNextElement;
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
    Segment<T> *findEmptySegment(){
        for (int i = 0; i < this -> getLength(); i ++) {
            DynamicArray<T> segmentArray = this -> get(i);
            for (int j = 0; j < segmentArray.getSize(); j ++) {
                if (segmentArray[j] == nullptr) {
                    return *segmentArray;
                }
            }
        }

        return new Segment(defaultSegmentSize);
    }
};

template<typename T>
size_t DoubleLinkedListBasedOnDynamicArray<T>::getLength() {
    return this -> length;
}

template<typename T>
void DoubleLinkedListBasedOnDynamicArray<T>::append(T element) {
    auto *newNode = new Segment<T>(element);
    Segment<T> *oldTail = this -> tail;

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
    auto *newNode = new Segment<T>(element);

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

    Segment<T> *current;
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
