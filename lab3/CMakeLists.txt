cmake_minimum_required(VERSION 3.13)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab3 main.cpp SortedMap.cpp SortedMap.h SMIterator.cpp SMIterator.h ExtendedTest.cpp ExtendedTest.cpp ShortTest.h ShortTest.cpp SortedDoublyLinkedList.cpp SortedDoublyLinkedList.h)