#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include "arraySequence.h"
#include "../../../collections/dynamicArrayDirectory/dynamicArrayUnitTests.h"

void testArrayConstructors();
void mutableArraySequenceGetTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int index, int elem);
void mutableArraySequenceGetFirstTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int elem);
void mutableArraySequenceGetLastTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int elem);
void mutableArraySequenceAppendTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int elem);
void mutableArraySequencePrependTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int elem);
void mutableArraySequenceInsertAtTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int index, int elem);
void mutableArraySequenceGetSubSequenceTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int startIndex, int endIndex, const int *expected);
void mutableArraySequenceConcatTest(MutableArraySequence<int> &object1, MutableArraySequence<int> &object2, const std::string &typeOfCollection, const int *expected);
void testArraySequence();
