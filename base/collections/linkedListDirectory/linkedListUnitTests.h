#pragma once

#include <iostream>
#include <cassert>
#include "linkedList.h"

template<typename T>
void getFirstTest(LinkedList<T> *list, std::string *typeOfCollection, int firstElement);
template<typename T>
void getLastTest(LinkedList<T> *list, std::string *typeOfCollection, int lastElement);
template<typename T>
void getTest(LinkedList<T> *list, std::string *typeOfCollection, int element);
template<typename T>
void getSubListTest(LinkedList<T> *list, std::string *typeOfCollection);
template<typename T>
void appendMethodTest(LinkedList<T> *list, std::string *typeOfCollection);
template<typename T>
void prependMethodTest(LinkedList<T> *list, std::string *typeOfCollection);
template<typename T>
void insertAtMethodTest(LinkedList<T>& list, std::string* typeOfCollection);
void emptyLinkedListTest();
void linkedListTest();
void startLinkedListTest();