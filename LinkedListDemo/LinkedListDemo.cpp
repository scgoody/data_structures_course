// LinkedListDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Linkedlist.h"
#include "DoublyLinkedList.h"
using namespace std;

int main()
{
   
    // in-class practice
   // create a linked list and name it
    Linkedlist<char> myList;
    myList.addFirst('A');
    myList.addFirst('B');
    myList.addFirst('C');
    myList.addFirst('D');
    myList.printList();
    cout << endl;

    /*
    myList.insertAfter('C', 'X');
    myList.printList();
    cout << endl;

    myList.insertBefore('B', 'Y');
    myList.printList();
    cout << endl;

    myList.Remove('C');
    myList.printList();
    cout << endl;

    myList.addLast('P');
    myList.printList();
    cout << endl;

    Linkedlist<char> copyList;
    cout << "Copied list: ";
    copyList = myList.Copy();
    copyList.printList();
    cout << endl;
    */

    
    // Assigntment 1: problem 2
    Linkedlist<char> reverseList;
    cout << "Reversed list: ";
    reverseList = myList.Reverse();
    reverseList.printList();
    cout << endl;
    

    //Assignment 1: problem 3 & 4
    DoublyLinkedList<char> list;
    list.addFirst('A');
    list.addFirst('B');
    list.addFirst('C');
    list.addFirst('D');
    list.printList();
    list.Remove('C');
    list.printList();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
