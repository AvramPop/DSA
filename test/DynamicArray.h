//
// Created by dani on 3/6/19.
//

#ifndef LAB1_DYNAMICARRAY_H
#define LAB1_DYNAMICARRAY_H


typedef int TElem;

class DAIterator;

class DynamicArray {
    friend class DAIterator;
private:
    int arrayLength;
    int arrayCapacity;
    int *array;
    void stretchArray(int newCapacity);

public:
    //constructor
    //throws exception if capacity is 0 or negative
    DynamicArray(int capacity);

    //returns the size (number of elements) from the DynamicArray
    int size() const;

    //returns the element from a given position (indexing starts from 0)
    //throws exception if pos is not a valid position
    TElem getElement(int pos) const;

    //changes the element from a position to a different value
    //returns the old element from position poz
    //throws exception if pos is not a valid position
    TElem setElement(int pos, TElem newElem);

    //adds a new element to the end of the DynamicArray
    void addToEnd(TElem newElem);

    //adds a new element to a given position in a DynamicArray
    //throws exception if pos is not a valid position
    void addToPosition(int pos, TElem newElem);

    //removes an element from a given position
    //returns the removed element
    //throws exception if pos is not a valid position
    TElem remove(int pos);

    //returns an iterator for the DynamicArray
    DAIterator iterator() const;

    //destructor
    ~DynamicArray();

};


#endif //LAB1_DYNAMICARRAY_H
