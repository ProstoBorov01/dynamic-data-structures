#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include "listSequence.h"
#include "../../../collections/linkedListDirectory/linkedListUnitTests.h"

void mutableListSequenceGetTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int index, int elem);
void mutableListSequenceGetFirstTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int elem);
void mutableListSequenceAppendTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int elem);
void mutableListSequencePrependTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int elem);
void mutableListSequenceInsertAtTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int index, int elem);
void mutableListSequenceGetSubSequenceTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int startIndex, int endIndex, const int *expected);
void mutableListSequenceConcatTest(MutableListSequence<int> &object1, MutableListSequence<int> &object2, const std::string &typeOfCollection, const int *expected);
void testListSequence();
