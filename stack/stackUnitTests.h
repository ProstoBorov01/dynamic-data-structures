#pragma once
#include <iostream>
#include <cassert>
#include "stack.h"


bool isEven(int element) {
    return element % 2 == 0;
}
int increment(int element) {
    return element + 1;
}


void testStackCreationAndIsEmpty() {
    Stack<int> stack;
    assert(stack.isEmpty());
    std::cout << "testStackCreationAndIsEmpty passed!" << std::endl;
}

void testPushAndGetLength() {
    Stack<int> stack;
    int a = 1, b = 2, c = 3;
    stack.push(a);
    stack.push(b);
    stack.push(c);
    assert(stack.getLength() == 3);
    std::cout << "testPushAndGetLength passed!" << std::endl;
}

void testPeek() {
    Stack<int> stack;
    int a = 1, b = 2, c = 3;
    stack.push(a);
    stack.push(b);
    stack.push(c);
    assert(stack.peek() == 3);
    std::cout << "testPeek passed!" << std::endl;
}

void testPop() {
    Stack<int> stack;
    int a = 1, b = 2, c = 3;
    stack.push(a);
    stack.push(b);
    stack.push(c);
    assert(stack.pop() == 3);
    assert(stack.getLength() == 2);
    assert(stack.pop() == 2);
    assert(stack.getLength() == 1);
    assert(stack.pop() == 1);
    assert(stack.isEmpty());
    std::cout << "testPop passed!" << std::endl;
}

void testWhere() {
    Stack<int> stack;
    int a = 1, b = 2, c = 3;
    stack.push(a);
    stack.push(b);
    stack.push(c);
    Stack<int>* evenStack = stack.where(isEven);
    assert(evenStack->getLength() == 1);
    assert(evenStack->peek() == 2);
    delete evenStack;
    std::cout << "testWhere passed!" << std::endl;
}

void testMap() {
    Stack<int> stack;
    int a = 1, b = 2, c = 3;
    stack.push(a);
    stack.push(b);
    stack.push(c);
    Stack<int>* incrementedStack = stack.map(increment);
    assert(incrementedStack -> getLength() == 3);
    assert(incrementedStack -> pop() == 2);
    assert(incrementedStack -> pop() == 3);
    assert(incrementedStack -> pop() == 4);
    assert(incrementedStack -> isEmpty());
    delete incrementedStack;
    std::cout << "testMap passed!" << std::endl;
}

void testConcat() {
    Stack<int> stack1, stack2;
    int a = 1, b = 2, c = 3, d = 4;
    stack1.push(a);
    stack1.push(b);
    stack2.push(c);
    stack2.push(d);
    Stack<int>* concatenatedStack = stack1.concat(stack2);
    assert(concatenatedStack -> getLength() == 4);
    assert(concatenatedStack -> pop() == 4);
    assert(concatenatedStack -> pop() == 3);
    assert(concatenatedStack -> pop() == 2);
    assert(concatenatedStack -> pop() == 1);
    assert(concatenatedStack -> isEmpty());
    delete concatenatedStack;
    std::cout << "testConcat passed!" << std::endl;
}

void testGetSub() {
    Stack<int> stack;
    int a = 1, b = 2, c = 3, d = 4;
    stack.push(a);
    stack.push(b);
    stack.push(c);
    stack.push(d);
    Stack<int>* subStack = stack.getSubsequence(1, 3);
    assert(subStack -> getLength() == 3);
    assert(subStack -> pop() == 3);
    assert(subStack -> pop() == 2);
    assert(subStack -> pop() == 1);
    assert(subStack -> isEmpty());
    delete subStack;
    std::cout << "testGetSub passed!" << std::endl;
}

void testContainsSubsequence() {
    Stack<int> stack1, stack2;
    int a = 1, b = 2, c = 3, d = 4;
    stack1.push(a);
    stack1.push(b);
    stack1.push(c);
    stack2.push(b);
    stack2.push(c);
    assert(stack1.containsSubsequence(stack2));
    stack2.push(d);
    assert(!stack1.containsSubsequence(stack2));
    std::cout << "testContainsSubsequence passed!" << std::endl;
}

void startStackUnitTests() {
    testStackCreationAndIsEmpty();
    testPushAndGetLength();
    testPeek();
    testPop();
    testWhere();
    testMap();
    testConcat();
    testGetSub();
    testContainsSubsequence();
    std::cout << "All tests passed!" << std::endl;
}