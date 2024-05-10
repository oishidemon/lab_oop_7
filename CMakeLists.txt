cmake_minimum_required(VERSION 3.26)
project(s_d_linked_lists)

set(CMAKE_CXX_STANDARD 17)

add_executable(s_d_linked_lists main.cpp
        DoubleLinkedList.h
        doubleNode.h)
