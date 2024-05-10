//
// Created by Admin on 10.05.2024.


#ifndef S_D_LINKED_LISTS_SINGLELINKEDLIST_H
#define S_D_LINKED_LISTS_SINGLELINKEDLIST_H
#include "SingleNode.h"
#include <iostream>
using namespace std;
using namespace single_Node;

template <typename T>
class SingleLinkedList {
private:
    unique_ptr<Node<T>> head;
    int size;
public:
    SingleLinkedList() :head{nullptr}, size{0} {};

    void unshift(T data);
    void push(T data);
    void shift();
    void pop();

    void at(int index);
    void atInsert(int index,T data);
    void atRemove(int index);

    int search(T value);

    bool isEmpty();

    void show() const;
};

template<typename T>
int SingleLinkedList<T>::search(T value) {
    Node<T> *current = head.get();
    int index = 0;
    while (current){
        if(current->data == value) {
            return index;
        }
        current = current->next.get();
        index++;
    }
    return -1;
}

template<typename T>
bool SingleLinkedList<T>::isEmpty() {
    if(!head){
        return true;
    }
    return false;
}

template<typename T>
void SingleLinkedList<T>::atRemove(int index) {
    if(index < 0 || index >= size){
        throw out_of_range("Index out of range");
    }
    Node<T> *current = head.get();
    for(int i = 0; i < index; i++){
        current = current->next.get();
    }
    current->next = move(current->next->next);
    --size;
}

template<typename T>
void SingleLinkedList<T>::atInsert(int index,T data) {
    if(index < 0 || index >= size){
        throw out_of_range("Index out of range");
    }
    Node<T> *current = head.get();
    unique_ptr<Node<T>> newNode = make_unique<Node<T>>(data);
    if(index == 0){
        unshift(data);
        return;
    }else if(index == size - 1){
        push(data);
        return;
    }
    for(int i = 0; i < index; i++){
        current = current->next.get();
    }
    newNode->next = move(current->next);
    current->next = move(newNode);
    size++;

}

template<typename T>
void SingleLinkedList<T>::at(int index) {
    Node<T> *current = head.get();
    if(index < 0 || index >= size){
        throw out_of_range("Index out of range");
    }

    for(int i = 0; i < index; i++){
        current = current->next.get();
    }
    cout<<"Data at index "<<index<<" : "<<current->data<<endl;
}

template<typename T>
void SingleLinkedList<T>::pop() {
    if(!head){
        throw out_of_range("List empty");
    }
    if(size == 1){
        head.reset();
        size--;
        return;
    }
    Node<T> *current = head.get();
    while(current->next->next){
        current = current->next.get();
    }
    current->next.reset();
    size--;
}

template<typename T>
void SingleLinkedList<T>::shift() {
    if(!head){
        throw out_of_range("List empty");
    }
    head = move(head->next);
    size--;
}

template<typename T>
void SingleLinkedList<T>::show() const {
    Node<T> *current = head.get();
    while (current != nullptr){
        cout<<current->data<<" ";
        current = current->next.get();
    }
    cout<<endl;
}

template<typename T>
void SingleLinkedList<T>::unshift(T data) {
    unique_ptr<Node<T>> newNode = make_unique<Node<T>>(data);
    newNode->next = move(head);
    head = move(newNode);
    size++;
}

template<typename T>
void SingleLinkedList<T>::push(T data) {
    unique_ptr<Node<T>> newNode = make_unique<Node<T>>(data);
    Node<T> *current = head.get();
    if(!current){
        head = move(newNode);
        size++;
        return;
    }
    while (current->next){
        current = current->next.get();
    }
    current->next = move(newNode);
    size++;
}
#endif //S_D_LINKED_LISTS_SINGLELINKEDLIST_H
