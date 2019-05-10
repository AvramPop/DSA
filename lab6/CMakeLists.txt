cmake_minimum_required(VERSION 3.14)
project(lab6)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab6 main.cpp Bag.cpp Bag.h BagIterator.cpp BagIterator.h ShortTest.cpp ShortTest.h ExtendedTest.cpp ExtendedTest.h)