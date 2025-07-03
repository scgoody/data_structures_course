#pragma once
#include <iostream>
#include "Linkedlist.h"
using namespace std;
template <class T>
class LinkedlistQueue : public Linkedlist<T>
{
public: 

	bool isEmpty()
	{
		return Linkedlist<T>::isEmpty();
	}
	void enqueue(T data)
	{
		Linkedlist<T>::addLast(data);
	}
	T dequeue()
	{
		if (isEmpty())
		{
			throw runtime_error("Empty queue. ");
		}
		else
		{
			T removed = Linkedlist<T>::RemoveFirst();
			return removed;
		}
	}

	void clear()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}

	void printQueue()
	{
		Linkedlist<T>::printList(); 
	}

	void reverseQueue()
	{
		Linkedlist<T>::reverseList();
	}

};

