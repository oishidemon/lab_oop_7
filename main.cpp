#include <iostream>
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
using namespace std;
int main() {
    SingleLinkedList<int> list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.atInsert(0,0);
    list.show();
    list.atRemove(1);
    list.show();
    cout<<"find: "<<list.search(1)<<endl;

    return 0;
}
