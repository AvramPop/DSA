#include <iostream>
#include "Heap.h"

//theta(1)
Heap::Heap(int k, int n) : n(n) {
	heap = new TElem[k];
	len = 0;
}

//theta(1)
int Heap::parent(int index) {
	return (index - 1) / n;
}

//theta(1)
void Heap::swap(TElem& a, TElem& b) {
	TElem AUX = a;
	a = b;
	b = AUX;
}
//O(log n (len))
void Heap::minHeapify() {
	int pos = len;
	while (pos > 0) {
		if (heap[pos] < heap[parent(pos)]) {
			swap(heap[pos], heap[parent(pos)]);
		}
		pos = parent(pos);
	}
}

//O(log n (len))
void Heap::add(TElem elem) {
	heap[len] = elem;
	minHeapify();
	len++;
}

//theta(1)
TElem Heap::operator[](int index) {
	return heap[index];
}

//theta(1)
Heap::~Heap()
{
	delete[] heap;
}

//O(n*log n(len))
void Heap::addMaxing(TElem elem) {
	if (elem > heap[0]) {
		int poz = 0;
		heap[0] = elem;
		while (true) {
			int minChild = -1;
			if (poz * n + 1 < len) {
				minChild = poz * n + 1;
			}
			int bound = minChild + n - 1 < len - 1 ? minChild + n - 1 : len - 1;
			if (minChild == -1) return;
			for (int i = minChild; i <= bound; i++) {
				if (heap[i] < heap[minChild]) {
					minChild = i;
				}
			}
			if (minChild != -1 && heap[minChild] < elem) {
				swap(heap[poz], heap[minChild]);
				poz = minChild;
			}
			else {
				return;
			}
		}
	}
}

//O(k*log n(len) + (size-k) * n * log n(len) + k)
long long computeProduct(std::vector<TElem> vector, int k, int n) {
	if (k <= 0) throw std::exception();
	if (k <= vector.size()) {
		Heap heap(k, n);
		for (int i = 0; i < k; i++) {
			heap.add(vector[i]);
		}
		for (int i = k; i < vector.size(); i++) {
			heap.addMaxing(vector[i]);
		}
		long long p = 1;
		for (int i = 0; i < k; i++) {
			p *= heap[i];
		}
		return p;
	}
	return 0;
	
}