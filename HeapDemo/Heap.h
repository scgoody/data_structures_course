#pragma once
#include <iostream>
using namespace std;

class Heap
{
public:
	int* heap; // int array named heap
	int size; // number of nodes in the heap
	int const CAPACITY = 15; // default capacity
	int cap;

	// default constructor
	Heap()
	{
		size = 0;
		heap = new int[CAPACITY];
		cap = CAPACITY;
	}

	// explicit constructor
	Heap(int myarray[], int arraysize)
	{
		// step 1: create empty heap with defined cap and size
		if (arraysize > CAPACITY)
		{
			cap = arraysize + 1;
			heap = new int[cap];
			size = arraysize;
		}
		else
		{
			cap = CAPACITY;
			heap = new int[cap];
			size = arraysize;
		}

		// step 2: copy elements from myarray one by one
		for (int i = 1; i <= size + 1; i++)
		{
			heap[i] = myarray[i - 1];
		}

		// step 3: heapify each subtree from the last parental node to the root
		buildheap();
	}

	void buildheap()
	{
		for (int i = size / 2; i > 0; i--)
		{
			heapify(i); // for node i, compare it with its child/children and apply the swap in the heapify function
		}

	}

	void heapify(int k)
	{
		int tmp = heap[k]; // value of the current parent node
		int child;

		while (2 * k <= size)
		{
			child = 2 * k; // left child
			if (child != size && heap[child] < heap[child + 1])
			{
				child++; // child is index of largest child
			}
			if (tmp < heap[child])
			{
				swap(heap[k], heap[child]); 
			}
			else
				break;
			k = child; // new position also needs parental dominance
		}
	}

	void printHeap()
	{
		// print heap array
		for (int i = 1; i <= size; i++)
		{
			cout << heap[i] << ", ";
		}
		cout << endl;
	}

	// insert new node with value x
	void insert(int x)
	{
		if (size >= cap)
		{
			throw runtime_error("Heap overflowed");
		}
		else
		{
			int pos = size + 1;
			size++;
			heap[pos] = x;
			while (pos > 1 && x > heap[pos / 2])
			{
				swap(heap[pos], heap[pos / 2]);
				pos = pos / 2;
			}
		} 
	}


};

