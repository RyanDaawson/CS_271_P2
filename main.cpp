#include "usecase.cpp"
#include <iostream>
int main()
{
	int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
	int arr1[] = {1, 2};

	cout << sliding_window(arr, 8, 3) << endl;
	
	cout << sliding_window(arr1, 2, 1) << endl;
	return 0;
}
