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
		Node* next; //define the next as a node reference/pointer

		//Default construct for Node
		Node() {
			data = NULL;
			next = nullptr;
		}

		//Explicit construct for Node
		Node(T initData, Node* initNext) {
			data = initData;
			next = initNext;
		}
	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int ListSize = 0; //The number of nodes in the linkedlist

	void addFirst(T key) {
		//Step 1&2: create a new node by declare the data (key) and the next reference (head)
		Node* tmp = new Node(key, head);
		head = tmp;  //Step3: change head reference to the new node
		ListSize++;  //Step4: increase list size by 1
	}

	//the printlist function to print out the node values from the first node to the last node
	void printList() {
		Node* tmp = head;
		while (tmp != nullptr) {
			cout << tmp->data << "->";
			tmp = tmp->next;
		}
		cout << endl;
	}

	int insertAfter(T key, T toInsert) {
		Node* tmp = head;
		while (tmp != nullptr && tmp->data != key) {
			tmp = tmp->next;
		}
		if (tmp != nullptr) {
			//this is the case we locate the key, tmp is currently referencing the key node
			tmp->next = new Node(toInsert, tmp->next);
			ListSize++;
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
			//cur is point at the key node
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

	void addLast(T key) {
		if (head == nullptr) {
			addFirst(key);
		}
		else {
			Node* tmp = head;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new Node(key, nullptr);
			ListSize++;
		}
	}

	Linkedlist copy() {
		Node* tmp = head;
		Linkedlist copyed_linkedlist;
		while (tmp != nullptr) {
			copyed_linkedlist.addLast(tmp->data);
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

	void reverseList()
	{
		if (isEmpty())
		{
			throw runtime_error("Empty queue");
		}
		else
		{
			Node* prev = nullptr;
			Node* current = head;
			Node* next = nullptr;

			// store the original head to update tail later
			Node* oldHead = head;

			// reverse the linked list
			while (current != nullptr)
			{
				next = current->next; // store next node
				current->next = prev; // reverse the link
				prev = current;       // move prev forward
				current = next;       // move current forward
			}

			// reverse head and tail pointers
			head = prev;   // new head is the previous tail
			tail = oldHead; // new tail is the original head
			tail->next = nullptr; // makes sure new tail points to nullptr
		}
	}

};

