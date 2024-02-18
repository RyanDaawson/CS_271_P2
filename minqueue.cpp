//==============================================================
// Ryan Daawson, Philip Perry Pearce-Pearson and Aniket Gauba
// 19th January 2023
// minqueue.cpp
// This file is the implementation file for the minqueue class
//==============================================================

#include <iostream>
#include <stdexcept>
#include "minqueue.h"
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

	MinQueue<T>::MinQueue	(T *A, int n)
{
	for (int i = 0; i < n; i++)	
		heapArray.push_back(A[i]);
	build_heap();
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
	MinQueue<T>::~MinQueue	()                                      
{
	heapArray.clear();
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
MinQueue<T>	MinQueue<T>::operator=	(const MinQueue<T> &myHeap)
{
	heapArray.clear();
	for (vector<int>::size_type i = 0; i < myHeap.heapArray.size(); i++)	
		heapArray.push_back(myHeap.heapArray[i]);
	build_heap();
        return *this;     	
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
	heapArray.push_back(x);
	build_heap();
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
T&	MinQueue<T>::min	() const
{
    if (isEmpty()) {
        throw std::runtime_error("MinQueue is empty.");
    }
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
T&	MinQueue<T>::extract_min	()
{
	T& min = heapArray[0];
	heapArray[0] = heapArray.at(heapArray.size()-1);
	cout << *heapArray.end() << endl;
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
    if (i < 0 || i >= heapArray.size()) {
        throw std::out_of_range("Index is out of range.");
    }
    if (k > heapArray[i]) {
        throw std::invalid_argument("New key is greater than current key.");
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
	if (heapSize == 0)
		return "[]";

	std::stringstream answer;
	answer << "[";

	for (int i = 0; i < heapSize; ++1)
	{
		answer << heapArray[i];
		if (i != heapSize - 1)
			answer << ", ";
	}
	answer << "]";
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
/*template <typename T>
void MinQueue<T>::set(int i, const T &val) if (i < 0 || i heapSize)
{
	throw std::out_of_range("Index out of range");
}

heapArray[i] = val;*/

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
/*template <typename T>
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
}*/
