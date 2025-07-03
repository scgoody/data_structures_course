#pragma once
#include <iostream>
using namespace std;
template <class T>
//create a template class T to broad the data type for the data element of the node
class Linkedlist
{
public:
	struct Node {
		T data;   //define data element with data type T
		int priority; // define the priority of the node
		Node* next; //define the next as a node reference/pointer

		//Default construct for Node
		Node() {
			data = NULL;
			priority = -1;
			next = nullptr;
		}

		//Explicit construct for Node
		Node(T initData, Node* initNext, int initPriority) {
			data = initData;
			next = initNext;
			priority = initPriority;
		}
	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int ListSize = 0; //The number of nodes in the linkedlist

	void addFirst(T key, int newPriority) {
		//Step 1&2: create a new node by declare the data (key) and the next reference (head)
		Node* tmp = new Node(key, head, newPriority);
		head = tmp;  //Step3: change head reference to the new node
		ListSize++;  //Step4: increase list size by 1
	}

	//the printlist function to print out the node values from the first node to the last node
	void printList() {
		Node* tmp = head;
		while (tmp != nullptr) {
			cout << " ( " << tmp->data << ", " << tmp->priority << " ) ->";
			tmp = tmp->next;
		}
		cout << endl;
	}

	int insertAfter(T key, T toInsert, int newPriority) {
		Node* tmp = head;
		while (tmp != nullptr && tmp->data != key) {
			tmp = tmp->next;
		}
		if (tmp != nullptr) {
			//this is the case we locate the key, tmp is currently referencing the key node
			tmp->next = new Node(toInsert, tmp->next, newPriority);
			ListSize++;
			return 0;
		}
		else {
			//key does not exist in the linkedlist
			return -1;
		}
	}

	int insertBefore(T key, T toInsert, int newPriority) {
		if (head == nullptr) {
			cout << "The linkedlist is empty" << endl;
			return -1;
		}
		if (head->data == key) {
			addFirst(toInsert, newPriority);
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
			prev->next = new Node(toInsert, cur, newPriority);
			ListSize++;
			return 0;
		}
		else {
			//cur is point at null, the key node not exist in the linked list
			cout << "The key is not exist in the linkedlist." << endl;
			return -1;
		}
	}

	int Remove(T key) {
		if (head == nullptr) {
			cout << "This is an empty linkedlist." << endl;
			return -1;
		}
		if (head->data == key) {
			Node* tmp;
			tmp = head;
			head = head->next;
			delete tmp;
			ListSize--;
			return 0;
		}
		Node* prev = nullptr;
		Node* cur = head;
		while (cur != nullptr && cur->data != key) {
			prev = cur;
			cur = cur->next;
		}
		if (cur != nullptr) {
			//cur is pointing at the key node

			prev->next = cur->next;
			delete cur;
			ListSize--;
			return 0;
		}
		else {
			cout << "The key is exist in the linkedlist" << endl;
			return -1;
		}
	}

	void addLast(T key, int newPriority) {
		if (head == nullptr) {
			addFirst(key, newPriority);
		}
		else {
			Node* tmp = head;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new Node(key, nullptr, newPriority);
			ListSize++;
		}
	}

	Linkedlist copy() {
		Node* tmp = head;
		Linkedlist copyed_linkedlist;
		while (tmp != nullptr) {
			copyed_linkedlist.addLast(tmp->data, tmp->priority);
			tmp = tmp->next;
		}
		return copyed_linkedlist;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	//return the data of the first node without delete it
	T getFirst() {
		if (isEmpty()) {
			throw runtime_error("Empty Linkedlist!");
		}
		else {
			return head->data;
		}
	}

	//remove the first node and return the value of the original first node
	T RemoveFirst() {

		if (isEmpty())
			throw runtime_error("Empty List!");
		else {
			Node* temp = head;

			T removed = temp->data;
			head = temp->next;
			
			delete temp;
			ListSize--;

			return removed;
		}
	}

	T getHighestPriority()
	{
		if (isEmpty())
		{
			throw runtime_error("Empty List!");
		}
		else
		{
			Node* cur = head;
			int highestPriority = head->priority;
			T highestPriorityData = head->data;
			while (cur != nullptr)
			{
				if (highestPriority < cur->priority)
				{
					highestPriority = cur->priority;
					highestPriorityData = cur->data;
				}
				cur = cur->next;
			}
			return highestPriorityData;
		}
	}
};

