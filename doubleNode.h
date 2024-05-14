//
// Created by Admin on 10.05.2024.
//

#ifndef S_D_LINKED_LISTS_DOUBLENODE_H
#define S_D_LINKED_LISTS_DOUBLENODE_H

#include <memory>
using namespace std;
namespace double_node{
    template <typename T>
    struct Node{
        T data;
        shared_ptr<Node> next;
        weak_ptr<Node> previous;

        Node(T value) : data(value) {};
    };
}

#endif //S_D_LINKED_LISTS_DOUBLENODE_H
