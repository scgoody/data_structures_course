#pragma once
#include <iostream>
using namespace std;
template <class T>
class ArrayStack
{
public: 
	const int DEFAULT_CAPACITY = 15;
	int capacity; //capacity for the array stack
	T* A; //declare an array A in data type T
	int top; //the index of the top element

	//default construct func
	ArrayStack() 
	{
		A = new T[DEFAULT_CAPACITY];
		capacity = DEFAULT_CAPACITY;
		top = -1;
		//create an empty array stack with default capacity
	}

	// explicit construct func
	ArrayStack(int initialCapacity)
	{
		if (initialCapacity < 0)
		{
			A = new T[DEFAULT_CAPACITY];
			capacity = DEFAULT_CAPACITY;
		}
		else 
		{
			A = new T[initialCapacity];
			capacity = initialCapacity;
		}
		top = -1;
		//create an empty array stack with initialCapacity
	}

	bool IsEmpty()
	{
		return top == -1;
	}

	bool IsFull()
	{
		return top == capacity - 1;
	}

	T Peek()
	{
		if (IsEmpty())
		{
			throw runtime_error("Stack is empty");
		}
		else
		{
			return A[top];
		}
	}

	T Pop()
	{
		T tmp = Peek();
		A[top] = NULL;
		top--;
		return tmp;
	}

	void Push(T newItem)
	{
		if (IsFull())
		{
			throw runtime_error("Stack overflow!");
		}
		else
		{
			top++;
			A[top] = newItem;
		}
	}

	void PrintStack()
	{
		if (IsEmpty())
		{
			cout << "Empty stack" << endl;
		}
		else
		{
			//print from bottom to top
			for (int i = 0; i <= top; i++)
			{
				cout << A[i] << " | ";
			}
			cout << endl;
		}
	}

	void Clear()
	{
		for (int i = 0; i <= top; i++)
		{
			A[i] = NULL;
		}
		top = -1;
	}



};

