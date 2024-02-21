//==============================================================
// Ryan Daawson, Philip Perry Pearce-Pearson and Aniket Gauba
// 21st January 2023
// test_minqueue_example.cpp
// This file contains the minqueue class test cases.  
//==============================================================

#include <iostream>
#include "usecase.cpp"
#include <chrono>
using namespace std;


void test_minqueue()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect result from empty constructor. Expected an empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq_str = mq.to_string();

        if (mq_str != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect result from empty constructor. Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error creating the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_insert()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.insert(0);
        string mq_str = empty.to_string();

        if (mq_str != "0")
        {
            cout << "Incorrect insert result. Epected 0 but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq.insert(25);
        mq.insert(0);
        mq_str = mq.to_string();

        if (mq_str != "0 2 1 3 6 4 8 10 7 9 25 5")
        {
            cout << "Incorrect insert result. Expected 0 2 1 3 6 4 8 10 7 9 25 5 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_min()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        int min = empty.min();
        if (min != 0)
        {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }

        MinQueue<int> mq(int_data, 10);
        min = mq.min();
        if (min != 1)
        {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_extract_min()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        int min = empty.extract_min();
        string mq_str = empty.to_string();

        if (min != 0 || mq_str != "")
        {
            cout << "Incorrect extract min result. Expected 0 and an empty queue but got : " << min << " and a queue of : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        min = mq.extract_min();
        mq_str = mq.to_string();

        if (min != 1 || mq_str != "2 3 4 7 6 5 8 10 9")
        {
            cout << "Incorrect extract min result. Expected 0 and the queue 2 3 4 7 6 5 8 10 9 but got : " << min << " and a queue of : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_decrease_key()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.decrease_key(0, 0);
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq.decrease_key(0, -6);
        mq.decrease_key(9, -1);
        mq_str = mq.to_string();

        if (mq_str != "-6 -1 4 3 2 5 8 10 7 6")
        {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in decreasing key : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_heapify()
{

    int *empty_data = new int[0];

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.min_heapify(1);
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect heapify result. Expected empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        string o_mq_str = mq.to_string();
        mq.set(1, 11);
        mq.min_heapify(1);

        mq_str = mq.to_string();

        if (mq_str != "1 3 4 7 6 5 8 10 11 9")
        {
            cout << "Incorrect heapify result in heapifying index 1 in the minqueue " << o_mq_str << " after setting to 11. Expected 1 3 4 7 6 5 8 10 11 9 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in heapify : " << e.what() << endl;
    }

    delete[] empty_data;
    delete[] int_data;
}

void test_build_min_heap()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> mq;
        mq.allocate(10);

        for (int i = 0; i < 10; i++)
        {
            mq.set(i, int_data[i]);

        }
        
        string o_mq_str = mq.to_string();

        mq.build_heap();
        string mq_str = mq.to_string();

        if (mq_str != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect build_heap result from " << o_mq_str << ". Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in building min heap : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_heapsort()
{

    int *empty_data = new int[0];

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.sort(empty_data);

        MinQueue<int> heap(int_data, 10);
        heap.sort(int_data);

        string sorted_str = to_string(int_data[0]);

        for (int i = 1; i < 10; i++)
        {
            sorted_str += (" " + to_string(int_data[i]));
        }

        if (sorted_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect heapsort result. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << sorted_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in sorting : " << e.what() << endl;
    }

    delete[] empty_data;
    delete[] int_data;
}

void test_sliding_window()
{

    int *empty = new int[0];
    int nums[8] = {1, 3, -1, -3, 5, 3, 6, 7};

    try
    {

        string window_result = sliding_window(empty, 0, 0);

        if (window_result != "")
        {
            cout << "Incorrect sliding window result. Expected and empty string but got : " << window_result << endl;
        }

        window_result = sliding_window(nums, 8, 3);

        if (window_result != "-1 -3 -3 -3 3 3")
        {
            cout << "Incorrect sliding window result. Expected -1 -3 -3 -3 3 3 but got : " << window_result << endl;
        }

        window_result = sliding_window(nums, 1, 1);

        if (window_result != "1")
        {
            cout << "Incorrect sliding window result. Expected 1 but got : " << window_result << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in generating sliding window result : " << e.what() << endl;
    }

    delete[] empty;
}

void time_test()
{
    MinQueue<int> mq;
    // TO-DO: generate large minqueue
    int size = -1; // TO-DO: set size of large minqueue
    int total = 0;

    int val = rand() % 100000;
    auto begin = std::chrono::high_resolution_clock::now();
    mq.insert(val);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();

    begin = std::chrono::high_resolution_clock::now();

    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "min time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();

    begin = std::chrono::high_resolution_clock::now();

    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "extract min time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();

    int last_index = size - 1;  // indexing starts at 0
    int new_val = mq.min() - 1; // ensure we're decreasing the key
    begin = std::chrono::high_resolution_clock::now();
    mq.decrease_key(last_index, new_val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "decrease key time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();
    cout << "Total time: " << total << endl;
}


void test_duplicate_values()
{
    cout << "For testing MinQueue with the same values" << endl;

    int data[] = {5,3,5,2,2,4,4};
    int n = sizeof(data) / sizeof(data[0]);

    MinQueue<int> mq(data, n); // create a minqueue with the data array
    cout << "initial queue:" << mq.to_string() << endl;

    
    cout << "Extracting min: " << mq.extract_min() << endl;
    cout << "Queue after extract_min: " << mq.to_string() << endl;

    
    int indexToDecrease = 3; 
    int newValue = 1; // New value for the element at indexToDecrease
    mq.decrease_key(indexToDecrease, newValue);
    cout << "Queue after decrease_key operation: " << mq.to_string() << endl;

    // Extract min again to see if the queue is correctly reorganized
    cout << "Extracting min again: " << mq.extract_min() << endl;
    cout << "Final Queue: " << mq.to_string() << endl;

}

int main()
{

    test_minqueue();
    test_insert();
    test_min();
    test_extract_min();
    test_decrease_key();
    test_heapify();
    test_build_min_heap();
    test_heapsort();
    test_duplicate_values();

    test_sliding_window();

    time_test();

    cout << "Testing completed" << endl;  	    
    return 0;
}
