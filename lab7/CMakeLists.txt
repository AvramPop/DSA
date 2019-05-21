cmake_minimum_required(VERSION 3.14)
project(lab7)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab7 main.cpp SortedBag.cpp SortedBag.h SortedBagIterator.cpp SortedBagIterator.h ExtendedTest.h ExtendedTest.cpp ShortTest.h ShortTest.cpp)