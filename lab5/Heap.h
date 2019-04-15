//
// Created by dani on 4/12/19.
//

#ifndef LAB5_HEAP_H
#define LAB5_HEAP_H
#include <cmath>
#include <vector>

typedef int TElem;

class Heap {
private:
    TElem* heap;
    int len;
    int n;
    int parent(int index);
    void swap(TElem &a, TElem &b);
    void minHeapify();
    double doubleLog(double base, double x) {
        return (log(x) / log(base));
    }
public:
    void addMaxing(TElem elem);
    void add(TElem elem);
    Heap(int size, int n);
    TElem operator[](int index);
    ~Heap();

};

long long computeProduct(std::vector<TElem> vector, int k, int n);


#endif //LAB5_HEAP_H
