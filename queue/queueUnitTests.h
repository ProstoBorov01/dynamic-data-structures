//#include <cassert>
//#include <iostream>
//#include "queue.h"
//
//void testIsEmpty() {
//    Queue<int> queue;
//    assert(queue.isEmpty() == true);
//    std::cout << "testIsEmpty passed!" << std::endl;
//}
//
//void testPush() {
//    Queue<int> queue;
//    queue.push(1);
//    assert(queue.isEmpty() == false);
//    assert(queue.getFront() == 1);
//    std::cout << "testPush passed!" << std::endl;
//}
//
//void testPop() {
//    Queue<int> queue;
//    queue.push(1);
//    int poppedElement = queue.pop();
//    assert(poppedElement == 1);
//    assert(queue.isEmpty() == true);
//    std::cout << "testPop passed!" << std::endl;
//}
//
//void testGetFront() {
//    Queue<int> queue;
//    queue.push(1);
//    int frontElement = queue.getFront();
//    assert(frontElement == 1);
//    std::cout << "testGetFront passed!" << std::endl;
//}
//
//void testGetBack() {
//    Queue<int> queue;
//    queue.push(1);
//    int backElement = queue.getBack();
//    assert(backElement == 1);
//    std::cout << "testGetBack passed!" << std::endl;
//}
//
//void testConcat2() {
//    Queue<int> queue1;
//    queue1.push(1);
//
//    Queue<int> queue2;
//    queue2.push(2);
//
//    Queue<int>* concatenatedQueue = queue1.concat(&queue2);
//    assert(concatenatedQueue -> getLength() == 2);
//    assert(concatenatedQueue -> getFront() == 1);
//    assert(concatenatedQueue -> getBack() == 2);
//    delete concatenatedQueue;
//
//    std::cout << "testConcat passed!" << std::endl;
//}
//
//void testContainsSubsequence() {
//    Queue<int> queue;
//    queue.push(1);
//    queue.push(2);
//    queue.push(3);
//
//    Queue<int> subsequence;
//    subsequence.push(2);
//    subsequence.push(3);
//
//    assert(queue.containsSubsequence(&subsequence) == true);
//    std::cout << "testContainsSubsequence passed!" << std::endl;
//}
//
//void testGetSub() {
//    Queue<int> queue;
//
//    queue.push(1);
//    queue.push(2);
//    queue.push(3);
//
//    Queue<int>* subQueue = queue.getSub(1, 3);
//    assert(subQueue -> getLength() == 2);
//    assert(subQueue -> getFront() == 2);
//    assert(subQueue -> getBack() == 3);
//    delete subQueue;
//    std::cout << "testGetSub passed!" << std::endl;
//}
//
//void startQueueUnitTests() {
////    testIsEmpty();
////    testPush();
////    testPop();
////    testGetFront();
////    testGetBack();
////    testConcat();
////    testContainsSubsequence();
////    testGetSub();
//
//    std::cout << "All tests passed!" << std::endl;
//}
