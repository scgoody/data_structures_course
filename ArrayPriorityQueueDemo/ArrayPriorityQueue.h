#pragma once
#include <iostream>
using namespace std;
template <class AnyType>
class ArrayPriorityQueue
{
public:
	struct item
	{
		AnyType data;
		int priority;
	};

	const int DEFAULT_CAPACITY = 15;
	int capacity; // actual capacity of priority queue
	int length; // current length of priority queue
	int front; // front index for first item in queue
	int back; // back index for last item in queue
	item* A; // Array A 

	// define default constructor
	ArrayPriorityQueue()
	{
		capacity = DEFAULT_CAPACITY;
		A = new item[capacity];
		front = 0;
		back = -1;
		length = 0;
	}

	// define explicit constructor
	ArrayPriorityQueue(int initCap)
	{
		if (initCap <= 0)
		{
			capacity = DEFAULT_CAPACITY;
		}
		else
		{
			capacity = initCap;
		}
		A = new item[capacity];
		front = 0;
		back = -1;
		length = 0;
	}

	bool isFull()
	{
		return length == capacity;
	}

	bool isEmpty()
	{
		return length == 0;
	}

	void enqueuePQ(AnyType newData, int newPriority)
	{
		if (isFull())
		{
			throw runtime_error("Queue overflowed");
		}
		else 
		{
			item newItem;
			newItem.data = newData;
			newItem.priority = newPriority;
			back++;
			A[back % capacity] = newItem;
			length++;
		}
	}

	AnyType getHighestPriority()
	{
		if (isEmpty())
		{
			throw runtime_error("Queue is empty");
		}
		else
		{
			item highest = A[front % capacity]; // create highest item and initialize it as first item
			int cur = front; // current index
			while (cur != back+1)
			{
				if (highest.priority < A[cur%capacity].priority)
				{
					highest = A[cur % capacity];
				}
				cur++;
			}
			return highest.data; 
		}
	}

	// new getHighestPriority function where smallest number indicates highest priority
	AnyType getLowestPriority()
	{
		if (isEmpty())
		{
			throw runtime_error("Queue is empty");
		}
		else
		{
			item lowest = A[front % capacity]; // create highest item and initialize it as first item
			int cur = front; // current index
			while (cur != back + 1)
			{
				if (lowest.priority > A[cur % capacity].priority)
				{
					lowest = A[cur % capacity];
				}
				cur++;
			}
			return lowest.data;
		}
	}

	void printQueue()
	{
		int cur = front;
		while (cur <= back)
		{
			cout << "| " << A[cur % capacity].data << ", " << A[cur % capacity].priority << " |";
			cur++;
		}
		cout << endl;
	}

	AnyType dequeueHighestPQ()
	{
		if (isEmpty())
		{
			throw runtime_error("Empty queue! ");
		}
		else
		{
			// step 1: locate item with highest priority
			item highest = A[front % capacity];
			int highest_index = front;
			int cur = front;
			while (cur <= back)
			{
				if (A[cur % capacity].priority > highest.priority)
				{
					highest = A[cur % capacity];
					highest_index = cur;
				}
				cur++;
			}
			// step 2: remove item with highest priority from PQ & shift items right of it one step ahead
			if (highest_index != back)
			{
				for (cur = highest_index;cur < back;cur++)
				{
					A[cur%capacity] = A[(cur + 1)%capacity]; 
				}
			}
			else
			{
				A[back % capacity] = item();
			}
			back--;
			length--;
			return highest.data;
		}
	}

	// new dequeue function where smallest number indicates highest priority
	AnyType dequeueLowestPQ()
	{
		if (isEmpty())
		{
			throw runtime_error("Empty queue! ");
		}
		else
		{
			// step 1: locate item with highest priority
			item lowest = A[front % capacity];
			int lowest_index = front;
			int cur = front;
			while (cur <= back)
			{
				if (A[cur % capacity].priority < lowest.priority)
				{
					lowest = A[cur % capacity];
					lowest_index = cur;
				}
				cur++;
			}
			// step 2: remove item with highest priority from PQ & shift items right of it one step ahead
			if (lowest_index != back)
			{
				for (cur = lowest_index;cur < back;cur++)
				{
					A[cur % capacity] = A[(cur + 1) % capacity];
				}
			}
			else
			{
				A[back % capacity] = item();
			}
			back--;
			length--;
			return lowest.data;
		}
	}
};

