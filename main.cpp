//==============================================================
// Ryan Daawson, Philip Perry Pearce-Pearson and Aniket Gauba
// 21st January 2023
// main.cpp
// This file contains the usecase test cases.  
//==============================================================

#include "usecase.cpp"
#include <iostream>
int main()
{
	int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
	int arr1[] = {1, 2};
	int arr2[100];
	for (int i= 0; i < 100; i++)
		arr2[i] = i;
	cout << sliding_window(arr, 8, 3) << endl;
	
	cout << sliding_window(arr1, 2, 3) << endl;
	cout << sliding_window(arr2, 100, 0) << endl;
	return 0;
}
