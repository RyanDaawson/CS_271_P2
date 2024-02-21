//==============================================================
// Ryan Daawson, Philip Perry Pearce-Pearson and Aniket Gauba
// 19th January 2023
// minqueue.cpp
// This file contains the sliding window program for the usecase
//==============================================================

#include "minqueue.cpp"
using namespace std;

template <typename T>
string sliding_window(T arr[], int len, int window)
{

	if (len == 0)
		return "";
	
	if (len <= window or len == 1)
	{
		MinQueue<T> tempHeap(arr, len);
		return std::to_string(tempHeap.min());		 
	}

	T *temp = new T[window];
	string x;
	 
	for (int i = 0; i < len-window+1; i++){
		for (int j = 0; j < window; j++)
			temp[j] = arr[i+j];
		MinQueue<T> tempHeap(temp, window);
		x += std::to_string(tempHeap.min()) + " ";
	}

	return x.substr(0, x.size()-1);
		

}
