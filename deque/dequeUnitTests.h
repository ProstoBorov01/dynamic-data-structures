//#pragma once
//#include <cassert>
//#include <iostream>
//#include "deque.h"
//
//void testIsEmpty() {
//    Deque<int> deque;
//    assert(deque.isEmpty() == true);
//    std::cout << "testIsEmpty passed!" << std::endl;
//}
//
//void testPushFront() {
//    Deque<int> deque;
//    deque.pushFront(1);
//    assert(deque.isEmpty() == false);
//    assert(deque.peekFront() == 1);
//    std::cout << "testPushFront passed!" << std::endl;
//}
//
//void testPushBack() {
//    Deque<int> deque;
//    deque.pushBack(1);
//    assert(deque.isEmpty() == false);
//    assert(deque.peekBack() == 1);
//    std::cout << "testPushBack passed!" << std::endl;
//}
//
//void testPopFront() {
//    Deque<int> deque;
//    deque.pushFront(1);
//    int poppedElement = deque.popFront();
//    assert(poppedElement == 1);
//    assert(deque.isEmpty() == true);
//    std::cout << "testPopFront passed!" << std::endl;
//}
//
//void testPopBack() {
//    Deque<int> deque;
//    deque.pushBack(1);
//    int poppedElement = deque.popBack();
//    assert(poppedElement == 1);
//    assert(deque.isEmpty() == true);
//    std::cout << "testPopBack passed!" << std::endl;
//}
//
//void testConcat() {
//    Deque<int> deque1;
//    deque1.pushBack(1);
//
//    Deque<int> deque2;
//    deque2.pushBack(2);
//
//    Deque<int>* concatenatedDeque = deque1.concat(&deque2);
//    assert(concatenatedDeque -> getLength() == 2);
//    assert(concatenatedDeque -> peekFront() == 1);
//    assert(concatenatedDeque -> peekBack() == 2);
//    delete concatenatedDeque;
//    std::cout << "testConcat passed!" << std::endl;
//}
//
//void testContainsSubsequence() {
//    Deque<int> deque;
//    deque.pushBack(1);
//    deque.pushBack(2);
//    deque.pushBack(3);
//
//    Deque<int> subsequence;
//    subsequence.pushBack(2);
//    subsequence.pushBack(3);
//
//    assert(deque.containsSubsequence(&subsequence) == true);
//    std::cout << "testContainsSubsequence passed!" << std::endl;
//}
//
//void testGetSub() {
//    Deque<int> deque;
//    deque.pushBack(1);
//    deque.pushBack(2);
//    deque.pushBack(3);
//
//    Deque<int>* subDeque = deque.getSub(1, 3);
//    assert(subDeque ->getLength() == 2);
//    assert(subDeque -> peekFront() == 2);
//    assert(subDeque -> peekBack() == 3);
//    delete subDeque;
//    std::cout << "testGetSub passed!" << std::endl;
//}
//
//void startDequeUnitTests() {
//    testIsEmpty();
//    testPushFront();
//    testPushBack();
//    testPopFront();
//    testPopBack();
//    testConcat();
//    testContainsSubsequence();
//    testGetSub();
//
//    std::cout << "All tests passed!" << std::endl;
//}
