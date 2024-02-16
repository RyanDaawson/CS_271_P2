#ifndef MINQUEUE_H
#define MINQUEUE_H

#include <string>

template <typename T>
class MinQueue {
public:
    // Default constructor
    MinQueue();

    // Initialize MinQueue with elements from array
    MinQueue(P* A, int n);

    // Destructor
    ~MinQueue();

    // Insert element into MinQueue
    void insert(const T& x);

    // Return the minimum element in the MinQueue
    T min() const;

    // Extract and return the minimum element from the MinQueue
    T extract_min();

    // Decrease the value of element at index i to k
    void decrease_key(int i, const T& k);

    // Ensure the subtree rooted at index i follows the heap property
    void heapify(int i);

    // Build a min-heap from the current elements
    void build_min_heap();

    // Sort the elements of MinQueue and store them in array A
    void heapsort(T* A);

    // Return a string representation of the MinQueue
    std::string to_string() const;

    // Set the element at index i to val
    void set(int i, const T& val);

    // Ensure the underlying array has capacity for at least n elements
    void allocate(int n);

private:
    T* heapArray;    // Array to store the heap elements
    int capacity;    // Maximum size of the heap
    int heapSize;    // Current number of elements in the heap

    // Utility functions (if needed)
    void increase_capacity();
    void swap(T& a, T& b);
};

#endif // MINQUEUE_H
