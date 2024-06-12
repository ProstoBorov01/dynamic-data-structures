//#include <iostream>
//#include "SegmentedDeque.h"
//
//void testIsEmpty() {
//    SegmentedDeque<int> deque(3, 0);
//
//    std::cout << "Running testIsEmpty... ";
//    if (!deque.isEmpty()) {
//        std::cerr << "FAILED: Deque should be empty initially.\n";
//    } else {
//        std::cout << "PASSED\n";
//    }
//}
//
//void testPushBackAndPopBack() {
//    SegmentedDeque<int> deque(3, 0);
//
//    std::cout << "Running testPushBackAndPopBack... ";
//    int value1 = 10;
//    int value2 = 20;
//    deque.pushBack(value1);
//    deque.pushBack(value2);
//
//    if (deque.popBack() != value2) {
//        std::cerr << "FAILED: popBack() should return 20.\n";
//    } else if (deque.popBack() != value1) {
//        std::cerr << "FAILED: popBack() should return 10.\n";
//    } else if (!deque.isEmpty()) {
//        std::cerr << "FAILED: Deque should be empty after popping all elements.\n";
//    } else {
//        std::cout << "PASSED\n";
//    }
//}
//
//void testPushFrontAndPopFront() {
//    SegmentedDeque<int> deque(3, 0);
//
//    std::cout << "Running testPushFrontAndPopFront... ";
//    int value1 = 10;
//    int value2 = 20;
//    deque.pushFront(value1);
//    deque.pushFront(value2);
//
//    if (deque.popFront() != value2) {
//        std::cerr << "FAILED: popFront() should return 20.\n";
//    } else if (deque.popFront() != value1) {
//        std::cerr << "FAILED: popFront() should return 10.\n";
//    } else if (!deque.isEmpty()) {
//        std::cerr << "FAILED: Deque should be empty after popping all elements.\n";
//    } else {
//        std::cout << "PASSED\n";
//    }
//}
//
//void testPeekFrontAndBack() {
//    SegmentedDeque<int> deque(3, 0);
//
//    std::cout << "Running testPeekFrontAndBack... ";
//    int value1 = 10;
//    int value2 = 20;
//    deque.pushBack(value1);
//    deque.pushBack(value2);
//
//    if (deque.peekFront() != value1) {
//        std::cerr << "FAILED: peekFront() should return 10.\n";
//    } else if (deque.peekBack() != value2) {
//        std::cerr << "FAILED: peekBack() should return 20.\n";
//    } else {
//        std::cout << "PASSED\n";
//    }
//}
//
//void testExceptionOnEmptyPop() {
//    SegmentedDeque<int> deque(3, 0);
//
//    std::cout << "Running testExceptionOnEmptyPop... ";
//    try {
//        deque.popFront();
//        std::cerr << "FAILED: popFront() should throw exception when deque is empty.\n";
//    } catch (const std::out_of_range& e) {
//        std::cout << "PASSED (Front)\n";
//    }
//
//    try {
//        deque.popBack();
//        std::cerr << "FAILED: popBack() should throw exception when deque is empty.\n";
//    } catch (const std::out_of_range& e) {
//        std::cout << "PASSED (Back)\n";
//    }
//}
//
//int main() {
//    testIsEmpty();
//    testPushBackAndPopBack();
//    testPushFrontAndPopFront();
//    testPeekFrontAndBack();
//    testExceptionOnEmptyPop();
//
//    std::cout << "All tests completed.\n";
//    return 0;
//}