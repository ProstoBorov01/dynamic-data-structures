#include <iostream>
#include <cassert>
#include "stack.h"

void testPush() {
    Stack<int> stack;
    std::cout << "Test Push" << std::endl;
    stack.push(1);
    assert(stack.peek() == 1);
    std::cout << "Passed: Stack push and peek working" << std::endl;
}

void testPop() {
    Stack<int> stack;
    std::cout << "Test Pop" << std::endl;

    stack.push(1);
    stack.push(2);

    int element = stack.pop();

    assert(element == 2);
    std::cout << "Passed: Stack pop removes top element" << std::endl;
    assert(stack.peek() == 1);
    std::cout << "Passed: Stack peek shows new top element" << std::endl;
    element = stack.pop();
    assert(element == 1);
    std::cout << "Passed: Stack pop removes last element" << std::endl;

    try {
        stack.pop();
    } catch (const std::invalid_argument &exception) {
        assert(std::string (exception.what()) == "Error! Stack is empty");
        std::cout << "Passed: Stack pop throws exception on empty stack" << std::endl;
    }
}

void testConcat() {
    Stack<int> stack1;
    Stack<int> stack2;
    std::cout << "Test Concat" << std::endl;

    stack1.push(1);
    stack1.push(2);
    stack2.push(3);
    stack2.push(4);

    Stack<int> *concatenatedStack = stack1.concat(&stack2);

    assert(concatenatedStack -> pop() == 4);
    assert(concatenatedStack -> pop() == 3);
    assert(concatenatedStack -> pop() == 2);
    assert(concatenatedStack -> pop() == 1);
    std::cout << "Passed: Stack concat works correctly" << std::endl;

    delete concatenatedStack;
}

void testGetSub() {
    Stack<int> stack;
    std::cout << "Test GetSub" << std::endl;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    Stack<int> *subStack = stack.getSub(1, 3);

    assert(subStack -> pop() == 3);
    assert(subStack -> pop() == 2);
    std::cout << "Passed: Stack getSub works correctly" << std::endl;

    delete subStack;
}

void testContainsSubsequence() {
    Stack<int> stack;
    Stack<int> subsequence;
    std::cout << "Test ContainsSubsequence" << std::endl;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    subsequence.push(2);
    subsequence.push(3);

    if (stack.containsSubsequence(&subsequence)) {
        std::cout << "Passed: Stack containsSubsequence works correctly" << std::endl;
    }
}

int main() {
    testPush();
    testPop();
    testConcat();
    testGetSub();
    testContainsSubsequence();

    return 0;
}