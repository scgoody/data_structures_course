#pragma once
#include <iostream>
using namespace std;
template <class T>
class ArrayQueue
{
public:
	const int DEFAULT_CAPACITY = 10;
	int capacity; // capacity of array queue
	int front; // front index reference to first element
	int back; // back index reference to last element
	int length; // current length of the queue; number of items in queue

	T* A; // array A for array queue

	// default constructor
	ArrayQueue()
	{
		capacity = DEFAULT_CAPACITY;
		A = new T[DEFAULT_CAPACITY];
		length = 0;
		front = 0;
		back = -1;
	}

	// explicit constructor
	ArrayQueue(int initCapacity)
	{
		if (initCapacity <= 0)
		{
			capacity = DEFAULT_CAPACITY;
		}
		else
		{
			capacity = initCapacity;
		}
		A = new T[capacity];
		length = 0;
		front = 0;
		back = -1;
	}

	bool isEmpty()
	{
		return length == 0;
	}
	bool isFull()
	{
		return length == capacity;
	}

	void enqueue(T data)
	{
		if (isFull())
		{
			throw runtime_error("The queue is full!");
		}
		else
		{
			back++;
			A[back % capacity] = data;
			length++;
		}
	}
	void printQueue()
	{
		if (isEmpty())
		{
			cout << "Empty queue." << endl;
		}
		else
		{
			int tmp = front;
			while (tmp != back)
			{
				cout << A[tmp%capacity] << " | ";
				tmp++;
			}
			cout << A[tmp % capacity] << " | " << endl;

		}
	}
	T dequeue()
	{
		if (isEmpty())
		{
			throw runtime_error("Empty queue. ");
		}
		else
		{
			T tmp = A[front % capacity];
			A[front % capacity] = NULL;
			front++;
			length--;
			return tmp;
		}
	}
	T getFront()
	{
		if (isEmpty())
		{
			throw runtime_error("Empty queue. ");
		}
		else
		{
			return A[front % capacity];
		}
	}
	void clear()
	{
		int current;
		while (!isEmpty())
		{
			A[current].dequeue();
			current++;
		}
	}

	// Assignment 2 - Question 1 - Reverse Array Queue
	void reverseQueue()
	{
		if (isEmpty())
		{
			throw runtime_error("Empty queue. ");
		}
		else
		{
			// create temp array to store reverse queue
			T* temp = new T[length];

			// store elements into temp in reverse by looping back to front
			int curIndex = 0;
			for (int i = back; curIndex < length; i--)
			{
				temp[curIndex] = A[i % capacity];
				curIndex++;
			}

			// reset the original queue with the reversed queue
			for (int i = 0; i < length; i++)
			{
				A[(front + i) % capacity] = temp[i];
			}
			delete temp;
		}
	}
};

