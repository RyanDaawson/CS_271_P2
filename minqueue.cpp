<<<<<<< Updated upstream
=======
//==============================================================
// Ryan Daawson, Philip Perry Pearce-Pearson and Aniket Gauba
// 19th January 2023
// minqueue.cpp
// This file is the implementation file for the minqueue class
//==============================================================

#include <iostream>
using namespace std;
#include "minqueue.h"

#include <string>

//==============================================================
// default constructor
// 	- creates a new empty Queue
//
// Parameters:
//	Void
// Return Value:
//	Void
//==============================================================
template <typename T>
MinQueue<T>::MinQueue(void)
{
}

//==============================================================
// copy constructor
// Philip
// 	- create a minimum priority queue (min heap) of the n elements in A
//
// Parameters:
//	array A, number of elements n
// Return Value:
//	Void
//==============================================================
template <typename T>

MinQueue<T>::MinQueue(T *A, int n)
{
}

//==============================================================
// destructor
// Philip
// 	- frees up memory allocated by the data class
//
// Parameters:
//	Void
// Return Value:
//	Void
//==============================================================
template <typename T>
MinQueue<T>::~MinQueue();
{
	delete[] heapArray;
}

//==============================================================
// assignment
// Philip
// 	- Assignment operator
//
// Parameters:
//	MinQueue<T>
// Return Value:
//	MinQueue<T>
//==============================================================
template <typename T>
MinQueue<T> MinQueue<T>::operator=(const MinQueue<T> &myHeap)
{
}

//==============================================================
// insert
// Philip
// 	- Inserts item x into the queue. If it is full, returns error.
//
// Parameters:
//	element x
// Return Value:
//	Void
//==============================================================
template <typename T>
void MinQueue<T>::insert(const T &x)
{
}

//==============================================================
// min
// Aniket
// 	- Returns smallest item in the queue. If it is empty, returns error.
//
// Parameters:
//	Void
// Return Value:
//	T
//==============================================================
template <typename T>
T &MinQueue<T>::min() const
{
}

//==============================================================
// extract_min
// Philip
// 	- Removes smallest item from the queue and returns it. If it is empty, returns error
//
// Parameters:
//	Void
// Return Value:
//	T
//==============================================================
template <typename T>
T &MinQueue<T>::extract_min()
{
}

//==============================================================
// decrease_key
// Aniket
// 	- Decreases key value of node at index i to k. If it is not present or
//
// Parameters:
//	index i, key k
// Return Value:
//	Void
//==============================================================
template <typename T>
void MinQueue<T>::decrease_key(int i, const T &k)
{
}

//==============================================================
// min_heapify
// Aniket
// 	- Ensure the subtree rooted at index i follows the heap property
//
// Parameters:
//	index i
// Return Value:
//	Void
//==============================================================
template <typename T>
void MinQueue<T>::min_heapify(int i)
{
}

//==============================================================
// build_heap
// Philip
// 	- Builds a min heap from the contents of the array.
//
// Parameters:
//	index i
// Return Value:
//	Void
//==============================================================
template <typename T>
void MinQueue<T>::build_heap()
{
}

//==============================================================
// sort
// Philip
// 	- Sorts the array using Heapsort algorithm
//
// Parameters:
//	array A
// Return Value:
//	Void
//==============================================================
template <typename T>
void MinQueue<T>::sort(T *A)
{
}

//==============================================================
// to_string
// Ryan
// 	- Return a string representation of the queue
//
// Parameters:
//	Void
// Return Value:
//	string
//==============================================================
template <typename T>
string MinQueue<T>::to_string() const
{
}

//==============================================================
// set
// Ryan
// 	- Set element at position i to value val
//
// Parameters:
//	index i, element val
// Return Value:
//	Void
//==============================================================
template <typename T>
void MinQueue<T>::set(int i, const T &val)
{
}

//==============================================================
// allocates
// Ryan
// 	- ensures the member array has a capacity of at least n
//
// Parameters:
//	capacity n
// Return Value:
//	Void
//==============================================================
template <typename T>
void MinQueue<T>::allocate(int n)
{
	if (n <= capacity)
	{
		return;
	}

	int newCapacity = (n > capacity * 2) ? n : capacity * 2;
	T *newHeap = new T[newCapacity];

	for (int i = 0; i < heapSize; ++1)
	{
		newHeap[i] = heapArray[i];
	}
	delete[] heapArray;
	heapArray = newHeap;
	capacity = newCapacity;
}
>>>>>>> Stashed changes
