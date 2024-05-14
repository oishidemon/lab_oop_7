#include <iostream>
#include "DoubleLinkedList.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
int main() {
//        Queue<int> Queue(1);
//    cout<<Queue.isEmpty()<<endl;
//    cout<<"IS FULL: "<<Queue.isFull()<<endl;
//    Queue.Enqueue(3);
//    cout<<Queue.isEmpty()<<endl;
//    cout<<"IS FULL: "<<Queue.isFull()<<endl;
    Stack<int> Stack;
    cout<<"isEmpty: "<<Stack.isEmpty()<<endl;
    Stack.push(25);
    cout<<"last element: "<<Stack.peek()<<endl;
    Stack.push(35);
    cout<<"last element: "<<Stack.peek()<<endl;
    Stack.pop();
    cout<<"last element: "<<Stack.peek()<<endl;
    return 0;

    return 0;
}
