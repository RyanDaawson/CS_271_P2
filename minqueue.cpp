//==============================================================
// Ryan Daawson, Philip Perry Pearce-Pearson and Aniket Gauba
// 21st January 2023
// minqueue.cpp
// This file is the implementation file for the minqueue class
//==============================================================

#include <iostream>
#include <stdexcept>
#include "minqueue.h"
#include <sstream>
using namespace std;

#include <string>

//==============================================================
// default constructor
// Aniket
// 	- creates a new empty Queue
//
// Parameters:
//	Void
// Return Value:
//	Void
//==============================================================
template <typename T>
	MinQueue<T>::MinQueue	(void)
{

}
   
   
   
   
//==============================================================
// Copy constructor
// Philip
// Pre-condition: A pointer to an array 'A' and its size 'n'.
// Post-condition: Creates a MinQueue object by creating a min heap with 'n' elements from array 'A'.

// Parameters:
// - T *A:
//	Void
//==============================================================
template <typename T>

MinQueue<T>::MinQueue(T *A, int n)
{
	// Loop through array 'A' and add elements to 'heapArray'
	for (int i = 0; i < n; i++)
		heapArray.push_back(A[i]); // Adds A[i] to heapArray
	build_heap(); // Build the heap based on heapArray
}
   
    
//==============================================================
// Destructor 
// Philip
// Pre-condition: None
// Post-condition: The heapArray is cleared
// Parameters:
//	Void
// Return Value:
//	Void
//==============================================================
template <typename T>
MinQueue<T>::~MinQueue()
{
	heapArray.clear(); // Clears the heapArray 
}

    
//==============================================================
// Assignment
// Philip
// Pre-condition: An existing MinQueue object is assigned to another MinQueue object.
// Post-condition: The current MinQueue object contains a copy of myHeap's elements and maintains the min-heap property.
// Parameters:
//	MinQueue<T>
// Return Value:
//	MinQueue<T>
//==============================================================
template <typename T>
MinQueue<T> MinQueue<T>::operator=(const MinQueue<T> &myHeap)
{
	heapArray.clear();// Clears the heapArray
	for (vector<int>::size_type i = 0; i < myHeap.heapArray.size(); i++) // Iterates over the source heapArray.
		heapArray.push_back(myHeap.heapArray[i]); // Adds each element from the source heapArray to the new heapArray.
	build_heap(); // Rebuilds the heap for the min-heap property after copying.
	return *this; // Allows you to do multiple assignments in one go
}



//==============================================================
// insert
// Philip
// 	- Inserts item x into the queue.
//
// Parameters:
//	element x
// Return Value:
//	Void
//==============================================================
template <typename T>
void	MinQueue<T>::insert	(const T &x)                          
{
    // Add the new element at the end of the heap array
    heapArray.push_back(x);
   
    // Get the index of the newly added element
    int i = heapArray.size() - 1;
   
    // Heapify-up: Adjust the position of the new element to maintain the min-heap property
    while (i != 0 && heapArray[(i - 1) / 2] > heapArray[i]) {
        // Swap the new element with its parent
        std::swap(heapArray[i], heapArray[(i - 1) / 2]);
       
        // Move up to the parent's index
        i = (i - 1) / 2;
    }
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
T	MinQueue<T>::min	() const
{


	if (heapArray.size() < 1)
		return T();

    return heapArray[0];
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
T	MinQueue<T>::extract_min	()
{
	
	if ( heapArray.size() < 1)
		return T();
		
	T min = heapArray[0];
	heapArray[0] = heapArray.at(heapArray.size()-1);

	heapArray.resize(heapArray.size()-1);
	build_heap();
	
	return min;
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
void MinQueue<T>::decrease_key(int i, const T &k) {
	int n = heapArray.size();
	if (i < 0 || i >= n) {
		return;
	    }
	    if (k > heapArray[i]) {
		return;
	    }
		
	    heapArray[i] = k;
	    while (i > 0 && heapArray[(i - 1) / 2] > heapArray[i]) {
		std::swap(heapArray[i], heapArray[(i - 1) / 2]);
		i = (i - 1) / 2; // Move up to the parent index
	    }
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
void	MinQueue<T>::min_heapify	(int i)
{
    int smallest = i; // Initialize smallest as root Since we are using 0 based indexing
    vector<int>::size_type l = 2 * i + 1; // left = 2*i + 1
    vector<int>::size_type r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is smaller than root
    if (l < heapArray.size() && heapArray[l] < heapArray[smallest])
        smallest = l;
 
    // If right child is samller than smallest so far
    if (r < heapArray.size() && heapArray[r] < heapArray[smallest])
        smallest = r;
 
    // If smallest is not root
    if (smallest != i) {
        swap(heapArray[i], heapArray[smallest]);
 
        // Recursively heapify the affected sub-tree
        min_heapify(smallest);
    }
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
void	MinQueue<T>::build_heap	()
{
	int n = heapArray.size();
	for (int i = n/2; i > -1; i--)
		min_heapify(i);
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
void	MinQueue<T>::sort	(T *A)
{
	vector<T> tempHeap = heapArray;
	int n = heapArray.size();

	for (int i = 0; i < n; i++)
	{
		A[i] = heapArray[0];
		heapArray[0] = heapArray.at(heapArray.size()-1);
		heapArray.resize(heapArray.size()-1);
		min_heapify(0);		
	}
	heapArray.clear();
	heapArray = tempHeap;
	
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
	stringstream answer;
	if (heapArray.size() == 0)
		return "";



	for (vector<int>::size_type i = 0; i < heapArray.size(); i++)
	{
		answer << heapArray[i];
		if (i != heapArray.size() - 1)
			answer << " ";
	}
	return answer.str();
	
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
	int n = heapArray.capacity();
	if (i < 0 || i > n-1)
		return;
	heapArray[i] = val;
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
	int capacity = heapArray.capacity();
	if (n <= capacity)
	{
		return;
	}

	int newCapacity = (n > capacity) ? n : capacity * 2; 

	heapArray.resize(newCapacity);
}