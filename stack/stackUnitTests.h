#include <iostream>
#include <cassert>
#include "stack.h"

void testPushAndPopStack() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    assert(stack.pop() == 3);
    assert(stack.pop() == 2);
    assert(stack.pop() == 1);
    std::cout << "testPushAndPop passed\n";
}

void testPeekStack() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    assert(stack.peek() == 3);
    stack.pop();
    assert(stack.peek() == 2);
    std::cout << "testPeek passed\n";
}

void testConcatStack() {
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);

    Stack<int> stack2;
    stack2.push(3);
    stack2.push(4);

    Stack<int>* concatenatedStack = stack1.concat(&stack2);
    assert(concatenatedStack -> pop() == 4);
    assert(concatenatedStack -> pop() == 3);
    assert(concatenatedStack -> pop() == 2);
    assert(concatenatedStack -> pop() == 1);

    delete concatenatedStack;
    std::cout << "testConcat passed\n";
}

int multiplyByTwoStack(int element) {
    return element * 2;
}

void testMapStack() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    Stack<int>* resultStack = stack.map(multiplyByTwoStack);

    assert(resultStack -> pop() == 6);
    assert(resultStack -> pop() == 4);
    assert(resultStack -> pop() == 2);

    delete resultStack;
    std::cout << "testMap passed\n";
}

bool isEvenStack(int element) {
    return element % 2 == 0;
}

void testWhereStack() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    Stack<int>* resultStack = stack.where(isEvenStack);

    assert(resultStack -> pop() == 4);
    assert(resultStack -> pop() == 2);
    delete resultStack;

    std::cout << "testWhere passed\n";
}

void testGetSubStack() {
    Stack<int> stack;

    for (int i = 1; i <= 5; i ++) {
        stack.push(i);
    }

    Stack<int>* subStack = stack.getSub(1, 4);
    assert(subStack -> pop() == 2);
    assert(subStack -> pop() == 3);
    assert(subStack -> pop() == 4);

    delete subStack;
    std::cout << "testGetSub passed\n";
}

void testContainsSubsequenceStack() {
    Stack<int> stack;
    for (int i = 1; i <= 5; ++i) {
        stack.push(i);
    }

    Stack<int> subsequence;
    subsequence.push(2);
    subsequence.push(3);
    subsequence.push(4);

    assert(stack.containsSubsequence(&subsequence) == true);

    Stack<int> nonSubsequence;
    nonSubsequence.push(6);
    nonSubsequence.push(7);

    assert(stack.containsSubsequence(&nonSubsequence) == false);

    std::cout << "testContainsSubsequence passed\n";
}

void startStackUnitTests() {
    std::cout << "#######################################[ StackUnitTest ]#######################################\n";
    testPushAndPopStack();
    testPeekStack();
    testConcatStack();
    testMapStack();
    testWhereStack();
    testGetSubStack();
    testContainsSubsequenceStack();
    std::cout << "#######################################[ StackUnitTest was passed ]#######################################\n";
}

