//==============================================================
// Ryan Daawson, Philip Perry Pearce-Pearson and Aniket Gauba
// 19th January 2023
// minqueue.cpp
// This file contains the MinQueue class declaration.  
//==============================================================

#ifndef MINQUEUE_H
#define MINQUEUE_H
#include <sstream>
#include <string>
using namespace std;
template <typename T>
class MinQueue
{
private:
    T *heapArray; // pointer to the array that stores elements of Heap data structure.
    int capacity; // maximum number of items the queue can hold.
    int heapsize; // current number of items in the queue.

    void increase_capacity() // function to enlarge the size of the heapArray when it is full
    {
        int newCapacity = capacity * 2;
        T *newHeap = new T[newCapacity];
        for (int i = 0; i < heapSize; ++i)
            newHeap[i] = heapArray[i];

        delete[] heapArray;
        heapArray = newHeap;
        capacity = newCapacity;
    };

    void swap(T &a, T &b) // helper function for swapping two values
    {
        T temp = a;
        a = b;
        b = temp;
    };

public:
    MinQueue(void);                                   // Constructor - creates a new empty Queue with given capacity */
    MinQueue(T *A, int n);                            // Copy constructor - copies from an existing object.
    ~MinQueue();                                      // Destructor - frees up memory allocated by the data class
    MinQueue<T> operator=(const MinQueue<T> &myHeap); // Assignment operator
    void insert(const T &x);                          // Inserts item x into the queue. If it is full, returns error.
    T& min() const;                                    // Returns smallest item in the queue. If it is empty, returns error.
    T& extract_min();                                  // Removes smallest item from the queue and returns it. If it is empty, returns
    void decrease_key(int i, const T &k);             // Decreases key value of node at index i to k. If it is not present or
    void min_heapify(int i);                              // Ensure the subtree rooted at index i follows the heap property
    void build_heap();                            // Builds a min heap from the contents of the array.
    void sort(T *A);                              // Sorts the array using Heapsort algorithm
    string to_string() const;                         // Return a string representation of the queue
    void set(int i, const T &val);                    // Set element at position i to value val
    void allocate(int n);                             // Allocates space for n elements.
    
    friend ostream & operator << ( ostream &os, const MinQueue<T> &l )
    {
        os << "[ ";
        for ( int i = 0; i < l.heapsize-1; i++ )
            os << l.heapArray[i] << ", ";
        if ( l.heapsize != 0 )
            os << l.heapArray[l.heapsize-1] << " ]";
        else
            os << " ]";
        return os;
    }
};

#endif /* MINQUEUE_H */
