#pragma once
#include <iostream>
#include "Linkedlist.h"
using namespace std;
template <class T>
class LinkedListPQ : public Linkedlist<T>
{
public:
	void enqueuePQ(T newData, int newPriority)
	{
		Linkedlist<T> ::addLast(newData, newPriority);
	}
	void printQueue()
	{
		Linkedlist<T> ::printList();
	}
	T dequeuePQ()
	{
		if (Linkedlist<T> ::isEmpty())
		{
			throw runtime_error("Empty Queue!");
		}
		else
		{
			T highestPriorityData = Linkedlist<T> ::getHighestPriority();
			Linkedlist<T> ::Remove(highestPriorityData);
			return highestPriorityData;
		}
	}

};

