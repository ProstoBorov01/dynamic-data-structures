cmake_minimum_required(VERSION 3.27)
project(lab_03)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_03 menu/main.cpp
        base/collections/doubleLinkedListDirectory/doubleLinkedList.h
        base/collections/doubleLinkedListDirectory/doubleLinkedListUnitTests.h
        base/collections/dynamicArrayDirectory/dynamicArray.h
        base/collections/dynamicArrayDirectory/dynamicArrayUnitTests.h
        base/collections/linkedListDirectory/linkedList.h
        base/collections/linkedListDirectory/linkedListUnitTests.h
        base/sequence/implementations/arraySequenceImpl/arraySequence.h
        base/sequence/implementations/arraySequenceImpl/arraySequenceUnitTests.h
        base/sequence/implementations/listSequence/listSequence.h
        base/sequence/implementations/listSequence/listSequenceUnitTests.h
        base/sequence/sequenceAbstract.h
        deque/deque.h
        deque/dequeUnitTests.h
        queue/queue.h
        queue/queueUnitTests.h
        segmentedDeque/segmentedDeque.h
        stack/stack.h
        stack/stackUnitTests.h
        segmentedDeque/segmentedDequeTest.h
)
