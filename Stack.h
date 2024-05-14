//
// Created by Admin on 14.05.2024.
//

#ifndef S_D_LINKED_LISTS_STACK_H
#define S_D_LINKED_LISTS_STACK_H
#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;
template <typename T>
class Stack{
private:
    DoubleLinkedList<T> StackList;
public:
    Stack()
            :StackList(){};
    void push(T data);
    void pop();
    T peek();
    bool isEmpty();
};

template<typename T>
bool Stack<T>::isEmpty() {
    return StackList.isEmpty();
}

template<typename T>
T Stack<T>::peek() {
    return StackList.at(-1);
}

template<typename T>
void Stack<T>::pop() {
    StackList.pop();
}

template<typename T>
void Stack<T>::push(T data) {
    StackList.push(data);
}

#endif //S_D_LINKED_LISTS_STACK_H
