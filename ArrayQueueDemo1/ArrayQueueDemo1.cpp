// ArrayQueueDemo1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "ArrayQueue.h"

int main()
{
    ArrayQueue<int> myQueue;

    try {
        myQueue.enqueue(9);
        myQueue.enqueue(8);
        myQueue.enqueue(7);
        myQueue.enqueue(6);
        myQueue.enqueue(5);
        /*
        myQueue.printQueue();
        myQueue.dequeue();
        myQueue.dequeue();
        myQueue.printQueue();
        cout << "Front: " << myQueue.getFront();
        myQueue.clear();
        */
        cout << "Original Queue: ";
        myQueue.printQueue();

        // Assignment 2 - Question 1 - Reverse Array Queue
        myQueue.reverseQueue();
        cout << "Reversed Queue: ";
        myQueue.printQueue();

    }
    catch (const exception& e)
    {
        cout << "Message of Exception: " << e.what() << endl;
    }
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
