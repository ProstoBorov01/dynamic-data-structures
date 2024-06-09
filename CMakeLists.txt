cmake_minimum_required(VERSION 3.27)
project(lab_03)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_03 main.cpp
        base/collections/dynamicArrayDirectory/dynamicArray.h
        stack/stack_realization.cpp
        base/collections/dynamicArrayDirectory/dynamicArrayUnitTests.h
        base/collections/linkedListDirectory/linkedList.h
        base/collections/linkedListDirectory/linkedListUnitTests.h
        base/sequence/sequenceAbstract.h
        base/sequence/implementations/listSequence/listSequence.h
        base/sequence/implementations/listSequence/listSequenceUnitTests.h
        base/sequence/implementations/arraySequenceImpl/arraySequence.h
        base/sequence/implementations/arraySequenceImpl/arraySequenceUnitTests.h
        stack/stackUnitTests.cpp
        queue/queue_realization.cpp
)
