#pragma once
#include <iostream>
using namespace std;
// create template class T to broaden data type for the data element of the node
template <class T>
class Linkedlist
{
public:
	struct Node {
		T data;		// define data element with data type T
		Node* next;		// define the next as a node reference/pointer

		// default constructor for Node
		Node() 
		{
			data = NULL;
			next = nullptr;
		}

		// Explicit constructor for Node
		Node(T initData, Node* initNext)
		{
			data = initData;
			next = initNext;
		}
	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int listSize = 0; // the number of nodes in linked list

	void addFirst(T key)
	{
		// steps 1 & 2: create new node by declaring the data (key) & the next reference (head)
		Node* tmp = new Node(key, head);
		// step 3: change head reference to the new node
		head = tmp;
		// step 4: inc. list size by 1
		listSize++;

	}

	// print list func to print out the node values from the first node to the last node
	void printList()
	{
		Node* tmp = head;
		while (tmp!= nullptr)
		{
			cout << tmp -> data << "->";
			tmp = tmp -> next; 
		}
	}

	int insertAfter(T key, T toInsert) {
		Node* tmp = head;
		while (tmp != nullptr && tmp->data != key) {
			tmp = tmp->next;
		}
		if (tmp != nullptr) {
			//this is the case we locate the key, tmp is currently referencing the key node
			tmp->next = new Node(toInsert, tmp->next);
			listSize++;
			return 0;
		}
		else {
			//key is not exist in the linkedlist
			return -1;
		}
	}

	int insertBefore(T key, T toInsert) {
		if (head == nullptr) {
			cout << "The linkedlist is empty" << endl;
			return -1;
		}
		if (head->data == key) {
			addFirst(toInsert);
			return 0;
		}
		Node* prev = nullptr;
		Node* cur = head;
		while (cur != nullptr && cur->data != key) {
			prev = cur;
			cur = cur->next;
		}
		if (cur != nullptr) {
			//cur is pointing at the key node, ready to insert
			prev->next = new Node(toInsert, cur);
			listSize++;
			return 0;
		}
		else {
			//cur is point at null, the key node not exist in the linked list
			cout << "The key does not exist in the linkedlist." << endl;
			return -1;
		}
	}

	int Remove(T key)
	{
		if (head == nullptr) {
			cout << "The linkedlist is empty" << endl;
			return -1;
		}
		if (head->data == key) {
			Node* tmp;
			tmp = head;
			head = head->next;
			delete tmp;
			head = nullptr;
			listSize--;
			return 0;
		}
		Node* prev = nullptr;
		Node* cur = head; 
		while (cur != nullptr && cur->data != key) 
		{
			prev = cur;
			cur = cur->next;
		}
		if (cur != nullptr) {
			//cur is pointing at the key node, ready to remove
			prev->next = cur->next;
			delete cur;
			listSize--;
			return 0;
		}
		else {
			//cur is point at null, the key node not exist in the linked list
			cout << "The key does not exist in the linkedlist." << endl;
			return -1;
		}
	}

	void addLast(T key)
	{
		if (head == nullptr) {
			addFirst(key);
		}
		else
		{
			Node* tmp = head;
			while (tmp-> next != nullptr)
			{
				tmp = tmp->next;
			}
			tmp->next = new Node(key, nullptr);
			listSize++;
		}
	}

	Linkedlist Copy() 
	{
		Node* tmp = head;
		Linkedlist<char> copiedList;
		while (tmp != nullptr)
		{
			copiedList.addLast(tmp->data);
			tmp = tmp->next;
		}
		return copiedList;
	}

	Linkedlist Reverse()
	{
		Node* tmp = head;
		Linkedlist<char> reversedList;
		while (tmp != nullptr)
		{
			reversedList.addFirst(tmp->data);
			tmp = tmp->next;
		}
		return reversedList;
	}

	bool IsEmpty()
	{
		return head == nullptr;
	}

	// return data of first node without deleting
	T getFirst()
	{
		if (IsEmpty())
		{
			throw runtime_error("Empty Linked List!");
		}
		else
		{
			return head->data;
		}
	}

	// remove first node and return value 
	T RemoveFirst()
	{
		if (IsEmpty())
		{
			throw runtime_error("Empty Linked List!");
		}
		else
		{
			T tmp = head->data;
			head = head->next;
			listSize--;
			return tmp;
		}
	}
};

