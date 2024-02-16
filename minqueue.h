#include <iostream>
using namespace std;
#ifndef MINQUEUE_H
#define MINQUEUE_H
template <typename P>
class List
{
public:
    List(void);
    List(const List<P> &l);
    ~List(void);
    List<P> operator=(const List<P> &l);
    void append(P item);
    void insert(P item, int position);
    int length(void) const;
    P &operator[](int position);
    void remove(int position);
    bool isEmpty(void) const;
    List<P> operator+(const List<P> &l) const;
    void clear(void);

    friend ostream &operator<<(ostream &os, const List<P> &l)
    {
        os << "[ ";
        for (int i = 0; i < l.size - 1; i++)
            os << l.list[i] << ", ";
        if (l.size != 0)
            os << l.list[l.size - 1] << " ]";
        else
            os << " ]";
        return os;
    }

private:
    // the maximum capacity of the array storing the list
    int capacity;
    // the current number of items in the list
    int heapsize;
    // the dynamically allocated array storing the list
    P *heap;

    // make the array twice as big to hold more items
    void reallocate(void)
    {
        capacity = capacity * 2;

        P *lst;
        lst = new P[capacity];
        for (int i = 0; i < size; i++)
            lst[i] = list[i];

        delete[] list;
        list = new P[capacity];
        for (int i = 0; i < size; i++)
            list[i] = lst[i];

        delete[] lst;
    };
};

#include "List.cpp" // this is necessary because the list
                    // class is a template and cannot be
                    // compiled separately.
#endif
