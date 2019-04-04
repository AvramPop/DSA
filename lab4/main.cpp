#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "LinkedList.h"

using namespace std;
int main(){
//    testAll();
//    testAllExtended();
    LinkedList list;
    list.add(1);
    list.removeFrom(0);
    list.removeFrom(0);
    for(int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}