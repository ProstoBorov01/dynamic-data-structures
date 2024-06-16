#pragma once

#include <cassert>
#include <iostream>
#include <string>
#include "dynamicArray.h"


void testGet(const DynamicArray<int> &array, std:: string &typeOfCollection, int element, int index);
int  testGetSize(const DynamicArray<int>& array);
void testConstructor(const DynamicArray<int> &array, std::string &typeOfCollection, int size);
void testSet(DynamicArray<int> &array, std:: string &typeOfCollection, int element, int index);
void testResize(DynamicArray<int> &array, std::string &typeOfCollection);
void emptyDynamicArrayTest();
void dynmaicArrayTest();
void startDynamicTest();

