#pragma once
#include <cassert>
#include <iostream>
#include "deque.h"

void testIsEmptyDeque() {
    Deque<int> deque;
    assert(deque.isEmpty() == true);
    std::cout << "testIsEmpty passed!" << std::endl;
}

void testPushFrontDeque() {
    Deque<int> deque;
    deque.pushFront(1);
    assert(deque.isEmpty() == false);
    assert(deque.peekFront() == 1);
    std::cout << "testPushFront passed!" << std::endl;
}

void testPushBackDeque() {
    Deque<int> deque;
    deque.pushBack(1);
    assert(deque.isEmpty() == false);
    assert(deque.peekBack() == 1);
    std::cout << "testPushBack passed!" << std::endl;
}

void testPopFrontDeque() {
    Deque<int> deque;
    deque.pushFront(1);
    int poppedElement = deque.popFront();
    assert(poppedElement == 1);
    assert(deque.isEmpty() == true);
    std::cout << "testPopFront passed!" << std::endl;
}

void testPopBackDeque() {
    Deque<int> deque;
    deque.pushBack(1);
    deque.pushBack(2);
    deque.pushBack(3);

    assert(deque.popBack() == 3);
    assert(deque.popBack() == 2);
    assert(deque.popBack() == 1);

    std::cout << "testPopBack passed!" << std::endl;
}

void testConcatDeque() {
    Deque<int> deque1;
    deque1.pushBack(1);
    deque1.pushBack(2);

    Deque<int> deque2;
    deque2.pushBack(3);
    deque2.pushBack(4);

    Deque<int>* concatenatedDeque = deque1.concat(&deque2);

    assert(concatenatedDeque->popFront() == 1);
    assert(concatenatedDeque->popFront() == 2);
    assert(concatenatedDeque->popFront() == 3);
    assert(concatenatedDeque->popFront() == 4);
    assert(concatenatedDeque->isEmpty());

    delete concatenatedDeque;
    std::cout << "testConcat2 passed\n";
}

int multiplyByTwoDeque(int element) {
    return element * 2;
}

void testMapDeque() {
    Deque<int> deque;
    deque.pushBack(1);
    deque.pushBack(2);
    deque.pushBack(3);

    Deque<int> *result = deque.map(multiplyByTwoDeque);

    assert(result -> getLength() == 3);
    assert(result -> popFront() == 2);
    assert(result -> popFront() == 4);
    assert(result -> popFront() == 6);
    delete result;
    std::cout << "testDequeMap test passed!" << std::endl;
}

bool isEvenDeque(int element) {
    return element % 2 == 0;
}

void testWhereDeque() {
    Deque<int> deque;
    deque.pushBack(1);
    deque.pushBack(2);
    deque.pushBack(3);
    deque.pushBack(4);
    deque.pushBack(5);
    Deque<int> *result = deque.where(isEvenDeque);
    assert(result -> getLength() == 2);
    assert(result -> popFront() == 2);
    assert(result -> popFront() == 4);
    delete result;
    std::cout << "testDequeWhere passed!" << std::endl;
}

void testContainsSubsequenceDeque() {
    Deque<int> deque;
    deque.pushBack(1);
    deque.pushBack(2);
    deque.pushBack(3);

    Deque<int> subsequence;
    subsequence.pushBack(2);
    subsequence.pushBack(3);

    assert(deque.containsSubsequence(&subsequence) == true);
    std::cout << "testContainsSubsequence passed!" << std::endl;
}

void testGetSubDeque() {
    Deque<int> deque;
    deque.pushBack(1);
    deque.pushBack(2);
    deque.pushBack(3);

    Deque<int>* subDeque = deque.getSub(1, 3);
    assert(subDeque -> getLength() == 2);
    assert(subDeque -> peekFront() == 2);
    assert(subDeque -> peekBack() == 3);
    delete subDeque;
    std::cout << "testGetSub passed!" << std::endl;
}

void startDequeUnitTests() {
    std::cout << "#######################################[ DequeUnitTests ]#######################################\n";
    testIsEmptyDeque();
    testPushFrontDeque();
    testPushBackDeque();
    testPopFrontDeque();
    testPopBackDeque();
    testConcatDeque();
    testWhereDeque();
    testMapDeque();
    testContainsSubsequenceDeque();
    testGetSubDeque();

    std::cout << "#######################################[DequeUnitTests was passed ]#######################################\n";
}
