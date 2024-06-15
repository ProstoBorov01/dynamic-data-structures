#pragma once
#include <iostream>
#include "segmentedDeque.h"

void testPushBack() {
    SegmentedDeque<int> deque(10);
    deque.pushBack(1);
    if (deque.peekBack() == 1) {
        std::cout << "testPushBack passed." << std::endl;
    } else {
        std::cout << "testPushBack failed." << std::endl;
    }
}

void testPushFront() {
    SegmentedDeque<int> deque(10);
    deque.pushFront(1);
    if (deque.peekFront() == 1) {
        std::cout << "testPushFront passed." << std::endl;
    } else {
        std::cout << "testPushFront failed." << std::endl;
    }
}

void testPopBack() {
    SegmentedDeque<int> deque(10);
    deque.pushBack(1);
    int *element = deque.popBack();
    if (element != nullptr and *element == 1) {
        std::cout << "testPopBack passed." << std::endl;
    } else {
        std::cout << "testPopBack failed." << std::endl;
    }

    delete element;
}

void testPopFront() {
    SegmentedDeque<int> deque(10);
    deque.pushFront(1);
    int *element = deque.popFront();

    if (element != nullptr and *element == 1) {
        std::cout << "testPopFront passed." << std::endl;
    } else {
        std::cout << "testPopFront failed." << std::endl;
    }

    delete element;
}

void testPeekFront() {
    SegmentedDeque<int> deque(10);
    deque.pushFront(1);
    if (deque.peekFront() == 1) {
        std::cout << "testPeekFront passed." << std::endl;
    } else {
        std::cout << "testPeekFront failed." << std::endl;
    }
}

void testPeekBack() {
    SegmentedDeque<int> deque(10);
    deque.pushBack(1);
    if (deque.peekBack() == 1) {
        std::cout << "testPeekBack passed." << std::endl;
    } else {
        std::cout << "testPeekBack failed." << std::endl;
    }
}

void segmentedDequeUnitTests() {
    std::cout << "################################# SEGMETED DECK #################################" << std::endl;
    testPushBack();
    testPushFront();
    testPopBack();
    testPopFront();
    testPeekFront();
    testPeekBack();
}
