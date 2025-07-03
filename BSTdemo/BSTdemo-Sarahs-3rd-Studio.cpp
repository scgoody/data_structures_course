// BSTdemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    
    // in class practice
    /*
    BST myBST;
    cout << "############Test Insert#########" << endl;
    myBST.insert(11);
    myBST.insert(6);
    myBST.insert(8);
    myBST.insert(19);
    myBST.insert(4);
    myBST.insert(10);
    myBST.insert(5);
    myBST.insert(17);

    cout << "Leveled-order transversal:";
    cout << endl;
    myBST.levelOrderTransversal();
    cout << endl;

    
    cout << "###########Test the in-depth transversals" << endl;
    cout << "Pre-order transversal:";
    myBST.preOrderTransversal();
    cout << endl;

    cout << "In-order transversal:";
    myBST.inOrderTransversal();
    cout << endl;

    cout << "Post-order transversal:";
    myBST.postOrderTransversal();
    cout << endl;

    cout << "The search result for key 19 is:" << myBST.search(19) << endl;
    cout << "The search result for key 12 is:" << myBST.search(12) << endl;

    cout << "Leveled-order transversal:";
    cout << endl;
    myBST.levelOrderTransversal();
    cout << endl;

    cout << "Detele a node" << endl;
    myBST.deleteNode(11);
    myBST.levelOrderTransversal();
    */

    // project 2:
    BST bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.insert(7);
    bst.insert(6);
    bst.insert(9);
    // Q1:
    cout << "Leveled-order transversal before inversion:";
    cout << endl;
    bst.levelOrderTransversal();
    cout << endl;
    bst.invert();
    cout << "Leveled-order transversal with inversion:";
    cout << endl;
    bst.levelOrderTransversal();
    cout << endl;
    // Q2:
    cout << "1st Largest: " << bst.kth_Largest(1) << endl;
    cout << "4th Largest: " << bst.kth_Largest(4) << endl;
    cout << "10th Largest (out of range): " << bst.kth_Largest(10) << endl;
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
