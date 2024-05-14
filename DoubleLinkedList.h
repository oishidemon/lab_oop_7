//
// Created by Admin on 10.05.2024.
//

#ifndef S_D_LINKED_LISTS_DOUBLELINKEDLIST_H
#define S_D_LINKED_LISTS_DOUBLELINKEDLIST_H
#include "DoubleNode.h"
#include <iostream>
#include "DoubleNode.h"
#include <iostream>
using namespace std;
using namespace double_node;

template <typename T>
class DoubleLinkedList {
private:
    shared_ptr<Node<T>> head;
    shared_ptr<Node<T>> tail;
    int size;
public:
    DoubleLinkedList() : head{nullptr},tail{nullptr}, size{0} {};

    void unshift(T data);
    void push(T data);
    void pop();
    void shift();

    T at(int index);
    void atInsert(int index,T data);
    void atRemove(int index);
    bool isEmpty();
    bool search(T data);
    void show();
};

template<typename T>
bool DoubleLinkedList<T>::search(T data) {
    shared_ptr<Node<T>> current = head;
    while (current) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() {
    if(head == tail){
        return true;
    }
    return false;
}

template<typename T>
void DoubleLinkedList<T>::atRemove(int index) {
    if(index == 0){
        shift();
        return;
    }
    if(index == size){
        pop();
        return;
    }
    shared_ptr<double_node::Node<T>> current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->previous.lock()->next = current->next;
    current->next->previous = current->previous;
    size--;
}

template<typename T>
void DoubleLinkedList<T>::atInsert(int index, T data) {
    if(index == 0){
        unshift(data);
        return;
    }
    if(index == size){
        push(data);
        return;
    }
    shared_ptr<Node<T>> current = head;
    shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);
    for(int i = 0; i < index;i++){
        current = current->next;
    }
    newNode->next = current->next;
    newNode->previous = current->previous;
    current->next->previous = newNode;
    current->next = newNode;
    size++;
}

template<typename T>
T DoubleLinkedList<T>::at(int index) {

    if(index == -1){
        if(!tail){
            return 404;
        }else{
            return tail->data;
        }
    }

    if(index<0||index>=size){
        throw out_of_range("Index out of range");
    }


    shared_ptr<Node<T>> current = head;
    for(int i = 0; i < index;i++){
        current = current->next;
    }
    return current->data;

}

template<typename T>
void DoubleLinkedList<T>::shift() {
    if(!head){
        return;
    }
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->previous.reset();
    }
    --size;
}

template<typename T>
void DoubleLinkedList<T>::pop() {
    if(!tail){
        return;
    }
    if(head == tail){
        head = tail = nullptr;
    }else{
        tail = tail->previous.lock();
        tail->next = nullptr;
    }
    --size;
}

template<typename T>
void DoubleLinkedList<T>::show() {
    shared_ptr<Node<T>> current = head;
    while (current){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

template<typename T>
void DoubleLinkedList<T>::push(T data) {
    shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);
    if(!tail){
        head=tail=newNode;
    } else{
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    size++;
}

template<typename T>
void DoubleLinkedList<T>::unshift(T data) {
    shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);
    if(!head){
        head=tail=newNode;
    }else{
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    size++;
}

#endif //S_D_LINKED_LISTS_DOUBLELINKEDLIST_H
