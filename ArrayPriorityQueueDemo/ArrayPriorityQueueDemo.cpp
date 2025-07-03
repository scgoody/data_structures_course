// ArrayPriorityQueueDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ArrayPriorityQueue.h"
using namespace std;

int main()
{
    ArrayPriorityQueue<string> myPQ;
    try {
        myPQ.enqueuePQ("apple", 3);
        myPQ.enqueuePQ("orange", 2);
        myPQ.enqueuePQ("apple", 3);
        myPQ.enqueuePQ("orange", 2);
        myPQ.enqueuePQ("peach", 5);
        myPQ.enqueuePQ("pear", 4);
        myPQ.printQueue();
        cout << "The highest priority item's data is: " << myPQ.getHighestPriority() << endl;
        myPQ.dequeueHighestPQ();
        myPQ.dequeueHighestPQ();
        myPQ.printQueue();
        cout << "The lowest priority item's data is: " << myPQ.getLowestPriority() << endl;
        myPQ.dequeueLowestPQ();
        myPQ.printQueue();
    }
    catch (const exception& e)
    {
        cout << "Runtime Error: " << e.what() << endl;
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
