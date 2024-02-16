#include <iostream>
using namespace std;

#ifndef LIST_H
#define LIST_H

#define DEFAULT_LIST_SIZE 10

template <typename T>
class List
{
public:
            List        ( void );
            List        ( const List<T> &l );
           ~List        ( void );
    List<T> operator=   ( const List<T> &l );
    void    append      ( T item );
    void    insert      ( T item, int position );
    int     length      ( void ) const;
    T &     operator[]  ( int position );
    void    remove      ( int position );
    bool    isEmpty     ( void ) const;
    List<T> operator+   ( const List<T> &l ) const;
    void    clear       ( void );

    friend ostream & operator << ( ostream &os, const List<T> &l )
    {
        os << "[ ";
        for ( int i = 0; i < l.size-1; i++ )
            os << l.list[i] << ", ";
        if ( l.size != 0 )
            os << l.list[l.size-1] << " ]";
        else
            os << " ]";
        return os;
    }

private:
    // the maximum capacity of the array storing the list
    int     capacity;
    // the current number of items in the list
    int     size;
    // the dynamically allocated array storing the list
    T       *list;

    // make the array twice as big to hold more items
    void    reallocate  ( void )
    {
	capacity = capacity*2;
	
	T *lst;
	lst = new T[capacity];
	for (int i = 0; i < size; i++)
		lst[i] = list[i]; 
	
	delete []list;
	list = new T[capacity];
	for (int i = 0; i < size; i++)
		list[i] = lst[i];
	
	delete []lst;   
    };
};

#include "List.cpp" // this is necessary because the list
                    // class is a template and cannot be
                    // compiled separately.
#endif
