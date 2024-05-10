//
// Created by Admin on 10.05.2024.
//

#ifndef S_D_LINKED_LISTS_DOUBLENODE_H
#define S_D_LINKED_LISTS_DOUBLENODE_H

#include <memory>
using namespace std;
namespace double_node{
    template <typename T>
    struct NodeDouble{
        T data;
        shared_ptr<NodeDouble> next;
        weak_ptr<NodeDouble> previous;

        NodeDouble(T value) : data(value) {};
    };
}
#endif //S_D_LINKED_LISTS_DOUBLENODE_H
