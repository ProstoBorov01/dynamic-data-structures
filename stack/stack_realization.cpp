#include <iostream>
#include "../base/collections/linkedListDirectory/linkedList.h"

template<typename T>
class Stack {
private:
    LinkedList<T> *data;
public:
    Stack() {
        this -> data = new LinkedList<T>();
    }

    explicit Stack(const Stack *object) {
        this -> data = new LinkedList<T>(*(object -> data));
    }

    bool containsSubsequence(Stack<T> *subsequence);
    template<typename ... Types>
    Stack<T> *where(bool (*func)(T, Types* ...), Types* ... tail);
    template<typename ... Types>
    Stack<T> *map(T (*func)(T, Types* ...), Types* ... tail);
    Stack<T> *concat(Stack<T> *object1);
    Stack<T> *getSub(size_t startIndex, size_t endIndex);
    bool isEmpty();
    void push(T element);
    T *pop();
    T *peek();

    ~Stack() {
        delete this -> data;
    }
};


template<typename T>
bool Stack<T>::containsSubsequence(Stack<T> *subsequence) {
    if (subsequence->isEmpty()) {
        return true;
    }

    if (this->isEmpty()) {
        return false;
    }

    for (int i = 0; i <= this->data->getLength() - subsequence->data->getLength(); i++) {
        bool match = true;

        for (int j = 0; j < subsequence->data->getLength(); j++) {
            if (this->data->get(i + j) != subsequence->data->get(j)) {
                match = false;
                break;
            }
        }

        if (match) {
            return true;
        }
    }

    return false;
}

template<typename T>
Stack<T> *Stack<T>::getSub(size_t startIndex, size_t endIndex) {
    auto *resultStack = new Stack<T>();

    for (size_t i = startIndex; i < endIndex; i ++) {
        resultStack -> data -> append(this -> data -> get(i));
    }

    return resultStack;
}

template<typename T>
Stack<T> *Stack<T>::concat(Stack<T> *object1) {
    auto *resultStack = new Stack<T>(object1);

    for (int i = 0; i < object1 -> data -> getLength(); i++) {
        resultStack -> data -> append(object1 -> data -> get(i));
    }

    return resultStack;
}

template<typename T>
template<typename... Types>
Stack<T> *Stack<T>::map(T (*func)(T, Types *...), Types *... tail) {
    auto *resultStack = new Stack<T>();

    for (int i = 0; i < this -> data -> getLength(); i++) {
        resultStack -> data -> append(func(this -> data -> get(i), tail...));
    }

    return resultStack;
}

template<typename T>
template<typename... Types>
Stack<T> *Stack<T>::where(bool (*func)(T, Types* ...), Types* ... tail) {
    auto *resultStack = new Stack<T>();

    for (int i = 0; i < this -> data -> getLength(); i++) {
        if (func(this -> data -> get(i), tail...)) {
            resultStack -> data -> append(this -> data -> get(i));
        }
    }

    return resultStack;
}

template<typename T>
void Stack<T>::push(T element) {
    this -> data -> prepend(element);
}

template<typename T>
bool Stack<T>::isEmpty() {
    return this -> data -> head == nullptr;
}

template<typename T>
T *Stack<T>::pop() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! Stack is empty");
    }

    T *element = this -> data -> getFirst();
    auto *oldHead = this -> data -> head;
    this -> data -> head = this -> data -> head -> pointerOnNextElement;
    delete oldHead;

    return element;
}

template<typename T>
T *Stack<T>::peek() {
    if (this -> isEmpty()) {
        throw std::invalid_argument("Error! Stack is empty");
    }

    return this -> data -> getFirst();
}
