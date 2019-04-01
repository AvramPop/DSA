#include <iostream>
#include "LinkedListOnArray.h"

int main(){
    LinkedListOnArray list;
    list.add(5);
    list.add(9);
    list.add(22);
    list.add(6);
    list.remove(9);
    list.remove(5);
    list.add(99);
    list.remove(22);
    list.remove(6);
    return 0;
}