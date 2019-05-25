class Bag:

    # creates a new, empty Bag
    # theta (1)
    def __init__(self):
        self.__elementsBuffer = []
        self.__frequenciesBuffer = []

    # adds a new element to the Bag
    # O (n)
    def add(self, e):
        if e in self.__elementsBuffer:
            i = self.__elementsBuffer.index(e)
            self.__frequenciesBuffer[i] += 1
        else:
            self.__elementsBuffer.append(e)
            self.__frequenciesBuffer.append(1)

    # removes one occurrence of an element from a Bag
    # returns True if an element was actually removed (the Bag contained the element e), or False if nothing was removed
    # O (n)
    def remove(self, e):
        if e in self.__elementsBuffer:
            i = self.__elementsBuffer.index(e)
            self.__frequenciesBuffer[i] -= 1
            if self.__frequenciesBuffer[i] == 0:
                del self.__frequenciesBuffer[i]
                del self.__elementsBuffer[i]
            return True
        else:
            return False

    # searches for an element e in the Bag
    # returns True if the Bag contains the element, False otherwise
    # O(n)
    def search(self, e):
        return e in self.__elementsBuffer

    # counts and returns the number of times the element e appears in the bag
    # O(n)
    def nrOccurrences(self, e):
        if e in self.__elementsBuffer:
            return self.__frequenciesBuffer[self.__elementsBuffer.index(e)]
        else:
            return 0

    # returns the size of the Bag (the number of elements)
    # theta (n)
    def size(self):
        numberOfElems = 0
        for elem in self.__frequenciesBuffer:
            numberOfElems += elem
        return numberOfElems

    # returns True if the Bag is empty, False otherwise
    # theta (1)
    def isEmpty(self):
        return not self.__frequenciesBuffer

    # returns a BagIterator for the Bag
    def iterator(self):
        return BagIterator(self)


class BagIterator:

    #creates an iterator for the Bag b, set to the first element of the bag, or invalid if the Bag is empty
    # theta (1)
    def __init__(self, b):
        self.__elems = b._Bag__elementsBuffer
        self.__freqs = b._Bag__frequenciesBuffer
        self.__index = 0
        self.__freq = 1

    # returns True if the iterator is valid
    def valid(self):
        return self.__index < len(self.__elems)

    # returns the current element from the iterator.
    # throws ValueError if the iterator is not valid
    # theta (1)
    def getCurrent(self):
        if self.valid():
            return self.__elems[self.__index]
        else:
            raise ValueError

    # moves the iterator to the next element
    # throws ValueError if the iterator is not valid
    # theta (1)
    def next(self):
        if self.valid():
            if self.__freq < self.__freqs[self.__index]:
                self.__freq += 1
            else:
                self.__index += 1
                self.__freq = 1
        else:
            raise ValueError

    # sets the iterator to the first element from the Bag
    # theta (1)
    def first(self):
        self.__index = 0
        self.__freq = 1