//
// Created by Admin on 14.05.2024.
//

#ifndef S_D_LINKED_LISTS_QUEUE_H
#define S_D_LINKED_LISTS_QUEUE_H
#include <iostream>
using namespace std;
template <typename T>
class Queue{
private:
    int tail,head;
    int size;
    T *arr;
public:
    Queue(int s)
            :size{s}{
        head = tail = -1;
        arr = new T[s];
    }
    void Enqueue(T data);
    T Dequeue();
    T Peek();
    bool isEmpty();
    bool isFull();
};

template<typename T>
bool Queue<T>::isFull() {
    return (tail == size - 1 && head == 0) || (tail == head - 1);
}

template<typename T>
bool Queue<T>::isEmpty() {
    return head == -1;
}

template<typename T>
T Queue<T>::Peek() {
    if(head == -1){
        cout<<"Queue is empty"<<endl;
        return 404;
    }

    return arr[head];
}


template<typename T>
T Queue<T>::Dequeue() {
    if(head == -1){
        cout<<"Queue is empty"<<endl;
        return 404;
    }
    T data = arr[head];
    arr[head] = -1;
    if(head == tail){
        head = tail = -1;
    }else if(head == size - 1){
        head = 0;
    }else{
        head++;
    }
    return data;
}


template<typename T>
void Queue<T>::Enqueue(T data) {
    if((tail == size - 1 && head == 0) || (tail == head - 1)){
        cout<<"Queue is full"<<endl;
        return;
    }
    if(head == -1){
        head = tail = 0;
        arr[tail] = data;
    }else if( tail == size - 1 && head != 0 ){
        tail = 0;
        arr[tail] = data;
    }else{
        tail++;
        arr[tail] = data;
    }
    cout<<"Inserted element: "<<data<<endl;
}


#endif //S_D_LINKED_LISTS_QUEUE_H
