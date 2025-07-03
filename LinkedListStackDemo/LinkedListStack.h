#pragma once
#include "Linkedlist.h"
#include <iostream>
using namespace std;
template <class T>
class LinkedListStack : public Linkedlist<T>
{
public: 
	void Push(T newData)
	{
		Linkedlist<T>::addFirst(newData);
	}
	void PrintStack()
	{
		Linkedlist<T>::printList();
		cout << endl;
	}
	T Peek()
	{
		return Linkedlist<T>::getFirst();
	}
	T Pop()
	{
		return Linkedlist<T>::RemoveFirst();
	}
	void Clear()
	{
		if (Linkedlist<T>::IsEmpty()) {
			cout << "Empty Stack!" << endl;
		}
		else
		{
			while (!Linkedlist<T>::IsEmpty())
			{
				Pop();
			}
		}
	}
};

