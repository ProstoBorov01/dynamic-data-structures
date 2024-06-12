#pragma once
#include <iostream>
#include "../base/sequence/implementations/listSequence/listSequence.h"

template<typename T>
class Stack {
private:
    MutableListSequence<T> *data;
public:
    Stack() {
        this -> data = new MutableListSequence<T>();
    }

    explicit Stack(const Stack *object) {
        this -> data = new MutableListSequence<T>(*(object -> data));
    }

    ~Stack() {
        delete this -> data;
    }

    size_t getLength() const;
    bool isEmpty() const;
    bool containsSubsequence(Stack<T> *subsequence) const;
    T *pop();
    T *peek() const;
    template<typename ... Types>
    Stack<T> *where(bool (*func)(T element, Types* ...), Types* ... tail) const;
    template<typename ... Types>
    Stack<T> *map(T (*func)(T element, Types* ...), Types* ... tail);
    Stack<T> *concat(Stack<T> *object);
    Stack<T> *getSub(size_t startIndex, size_t endIndex) const;
    Stack<T> *push(T element);
};

template<typename T>
size_t Stack<T>::getLength() const {
    return this -> data -> getLength();
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return this -> data -> getLength() == 0;
}

template<typename T>
bool Stack<T>::containsSubsequence(Stack<T> *subsequence) const {
    if (subsequence -> isEmpty()) {
        return true;
    }

    if (this -> isEmpty()) {
        return false;
    }

    for (int i = 0; i <= this -> data -> getLength() - subsequence -> data -> getLength(); i++) {
        bool found = true;

        for (int j = 0; j < subsequence -> data -> getLength(); j++) {
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
T *Stack<T>::pop() {
    if (this -> data -> isEmpty()) {
        throw std::invalid_argument("Error! Stack is empty");
    }

    T element = this -> peek();
    this -> data -> changeHead(this -> data -> get(1));

    return element;
}

template<typename T>
T *Stack<T>::peek() const {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! Stack is empty");
    }

    return this -> data -> getFirst();
}

template<typename T>
Stack<T> *Stack<T>::getSub(size_t startIndex, size_t endIndex) const {
    return this -> data -> getSubSequence(startIndex, endIndex);
}

template<typename T>
Stack<T> *Stack<T>::concat(Stack<T> *object) {
    auto *resultStack = new Stack<T>();

    for (int i = this -> data -> getLength() - 1; i >= 0; i--) {
        resultStack -> push(this -> data -> get(i));
    }

    for (int i = object -> data -> getLength() - 1; i >= 0; i--) {
        resultStack -> push(object -> data -> get(i));
    }

    return resultStack;
}

template<typename T>
template<typename... Types>
Stack<T> *Stack<T>::map(T (*func)(T element, Types *...), Types *... tail) {
    auto *resultStack = new Stack<T>();

    for (int i = 0; i < this -> data -> getLength(); i++) {
        resultStack -> data -> append(func(this -> data -> get(i), tail...));
    }

    return resultStack;
}

template<typename T>
template<typename... Types>
Stack<T> *Stack<T>::where(bool (*func)(T element, Types* ...), Types* ... tail) {
    auto *resultStack = new Stack<T>();

    for (int i = 0; i < this -> data -> getLength(); i++) {
        if (func(this -> data -> get(i), tail...)) {
            resultStack -> data -> append(this -> data -> get(i));
        }
    }

    return resultStack;
}

template<typename T>
Stack<T> *Stack<T>::push(T element) {
    this -> data -> prepend(element);
}

