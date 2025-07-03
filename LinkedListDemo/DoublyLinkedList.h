#pragma once
#include <iostream>
using namespace std;
// create template class T to broaden data type for the data element of the node
template <class T>
class DoublyLinkedList
{
public:
	struct Node {
		T data;		// define data element with data type T
		Node* next;		// define the next as a node reference/pointer
		Node* prev;

		// default constructor for Node
		Node()
		{
			data = NULL;
			next = nullptr;
			prev = nullptr;
		}

		// Explicit constructor for Node
		Node(T initData, Node* initNext, Node* initPrev)
		{
			data = initData;
			next = initNext;
			prev = initPrev;
		}
	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int listSize = 0; // the number of nodes in linked list

	void addFirst(T key)
	{
		// steps 1 & 2: create new node by declaring the data (key), the next reference (head), & the last reference (tail)
		Node* tmp = new Node(key, head, tail);
		// step 3: change head & tail reference 
		if (head == nullptr)
		{
			head = tmp;
		}
		else
		{
			tmp->next = head;
			head->prev = tmp;
			head = tmp;
		}
		// step 4: inc. list size by 1
		listSize++;

	}

	// print list func to print out the node values from the first node to the last node
	void printList()
	{
		Node* tmp = head;
		cout << "NULL<-";
		while (tmp != nullptr)
		{
			cout << tmp->data << "<->";
			tmp = tmp->next;
		}
		cout << "NULL->" << endl;
	}

	int Remove(T key)
	{
		if (head == nullptr) {
			cout << "The linkedlist is empty" << endl;
			return -1;
		}

		Node* cur = head;

		while (cur != nullptr && cur->data != key)
		{
			cur = cur->next;
		}
		if (cur == head)
		{
			//delete head
			head = head->next;
			if (head != nullptr)
			{
				head->prev = nullptr;
			}
			delete cur;
			listSize--;
			return 0;
		}
		else if (cur != nullptr) 
		{
			//delete middle or end (not head)
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			delete cur;
			listSize--;
			return 0;
		}
		else {
			//cur is point at null, the key node does not exist in the linked list
			cout << "The key does not exist in the linkedlist." << endl;
			delete cur;
			return -1;
		}
	}

};