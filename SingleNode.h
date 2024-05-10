//
// Created by Admin on 10.05.2024.
//

#ifndef S_D_LINKED_LISTS_SINGLENODE_H
#define S_D_LINKED_LISTS_SINGLENODE_H

#include <memory>
namespace single_Node{
    template <typename T>
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        explicit Node(T newData)
                :data{newData}, next{nullptr}{};
    };
}

#endif //S_D_LINKED_LISTS_SINGLENODE_H
