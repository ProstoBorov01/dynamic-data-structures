#pragma once
#include <cassert>
#include <iostream>
#include "queue.h"

void testIsEmptyQueue() {
    Queue<int> queue;
    assert(queue.isEmpty() == true);
    std::cout << "testIsEmpty passed!" << std::endl;
}

void testPushQueue() {
    Queue<int> queue;
    queue.push(1);
    assert(queue.isEmpty() == false);
    assert(queue.getFront() == 1);
    std::cout << "testPush passed!" << std::endl;
}

void testPopQueue() {
    Queue<int> queue;
    queue.push(1);
    int poppedElement = queue.pop();
    assert(poppedElement == 1);
    assert(queue.isEmpty() == true);
    std::cout << "testPop passed!" << std::endl;
}

void testGetFrontQueue() {
    Queue<int> queue;
    queue.push(1);
    int frontElement = queue.getFront();
    assert(frontElement == 1);
    std::cout << "testGetFront passed!" << std::endl;
}

void testGetBackQueue() {
    Queue<int> queue;
    queue.push(1);
    int backElement = queue.getBack();
    assert(backElement == 1);
    std::cout << "testGetBack passed!" << std::endl;
}

void testConcatQueue() {
    Queue<int> queue1;
    queue1.push(1);

    Queue<int> queue2;
    queue2.push(2);

    Queue<int>* concatenatedQueue = queue1.concat(&queue2);
    assert(concatenatedQueue -> getLength() == 2);
    assert(concatenatedQueue -> getFront() == 1);
    assert(concatenatedQueue -> getBack() == 2);
    delete concatenatedQueue;

    std::cout << "testConcat passed!" << std::endl;
}

int multiplyByTwoQueue(int element) {
    return 2 * element;
}

void testMapQueue() {
    Queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    Queue<int> *resultQueue = queue.map(multiplyByTwoQueue);

    assert(resultQueue -> pop() == 6);
    assert(resultQueue -> pop() == 4);
    assert(resultQueue -> pop() == 2);

    delete resultQueue;
    std::cout << "testMapQueue passed\n";
}

bool isEvenQueue(int element) {
    return element % 2 == 0;
}

void testWhereQueue() {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    
    Queue<int>* resultQueue = queue.where(isEvenQueue);

    assert(resultQueue -> pop() == 4);
    assert(resultQueue -> pop() == 2);
    delete resultQueue;

    std::cout << "testWhere passed\n";
}
void testContainsSubsequenceQueue() {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    Queue<int> subsequence;
    subsequence.push(2);
    subsequence.push(3);

    assert(queue.containsSubsequence(&subsequence) == true);
    std::cout << "testContainsSubsequence passed!" << std::endl;
}

void testGetSubQueue() {
    Queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    Queue<int>* subQueue = queue.getSub(1, 3);
    assert(subQueue -> getLength() == 2);
    assert(subQueue -> getFront() == 2);
    assert(subQueue -> getBack() == 3);
    delete subQueue;
    std::cout << "testGetSub passed!" << std::endl;
}

void startQueueUnitTests() {
    std::cout << "#######################################[ QueueUnitTest ]#######################################\n";
    testIsEmptyQueue();
    testPushQueue();
    testPopQueue();
    testGetFrontQueue();
    testGetBackQueue();
    testMapQueue();
    testWhereQueue();
    testConcatQueue();
    testContainsSubsequenceQueue();
    testGetSubQueue();
    std::cout << "All tests passed!" << std::endl;
    std::cout << "#######################################[ QueueUnitTest was passed ]#######################################\n";
}
