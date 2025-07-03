// ArrayStackDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ArrayStack.h"
using namespace std;

int main()
{
    try
    {
        ArrayStack<int> myArrayStack;
        myArrayStack.Push(2);
        myArrayStack.Push(3);
        myArrayStack.Push(4);
        myArrayStack.Push(6);
        myArrayStack.Push(8);
        myArrayStack.PrintStack();
        cout << "top: " << myArrayStack.Peek() << endl;
        myArrayStack.Pop();
        myArrayStack.Pop();
        myArrayStack.PrintStack();
        myArrayStack.Clear();
        myArrayStack.PrintStack();
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
