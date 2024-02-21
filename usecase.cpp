//==============================================================
// Ryan Daawson, Philip Perry Pearce-Pearson and Aniket Gauba
// 21st January 2023
// minqueue.cpp
// This file contains the sliding window program for the usecase
//==============================================================

#include "minqueue.cpp"
using namespace std;


//==============================================================
// insert
// Philip, Aniket, Ryan
// 	- Returns a space separated string of the min sliding window
//
// Parameters:
//	array, int n, int window
// Return Value:
//	string
//==============================================================
template <typename T>
string sliding_window(T arr[], int len, int window)
{
	// returns empty strings for empty arrays
	if (len == 0 or window == 0)
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
/*
template <typename T>
std::string sliding_window(T arr[], int len, int window) {
    if (window <= 0 || len <= 0) return "";

    MinQueue<T> mq; // Assuming MinQueue is properly implemented
    std::string result;

    for (int i = 0; i < len; ++i) {
        // Add current element to MinQueue
        mq.push(arr[i]);

        // Remove elements outside the current window
        if (i >= window) {
            mq.pop(); // Assuming pop removes the element entered window-size steps back
        }

        // Append the minimum of the current window to the result string
        if (i >= window - 1) {
            result += std::to_string(mq.min()) + " ";
        }
    }

    return result.substr(0, result.size() - 1); // Remove the trailing space
}*/