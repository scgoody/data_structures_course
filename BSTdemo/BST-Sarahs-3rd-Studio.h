#pragma once
#include <iostream>
using namespace std;
class BST
{
public:
	struct Node {
		int data;
		Node* left;
		Node* right;

		// default constructor
		Node()
		{
			data = 0;
			left = nullptr;
			right = nullptr;
		}

		// explicit constructor - initialize data only
		Node(int initData)
		{
			data = initData;
			left = nullptr;
			right = nullptr;
		}

		// explicit constructor - initialize all 
		Node(int initData, Node* initLeft, Node* initRight)
		{
			data = initData;
			left = initLeft;
			right = initRight;
		}
	};

	Node* root;
	int size; // the number of nodes in the binary search tree 
	bool inverted = 0;

	// default constructor
	BST()
	{
		root = nullptr;
		size = 0;
	}

	// insert
	Node* insert(Node* parent, int toInsert)
	{
		// case 1: found position for insert and it's not occupied
		if (parent == nullptr)
		{
			return new Node(toInsert);
		}
		// case 2: don't allow duplicate node
		if (parent->data == toInsert)
		{
			return parent;
		}
		// case 3: position is occupied but parent key is greater than toInsert
		if (toInsert < parent->data)
		{
			parent->left = insert(parent->left, toInsert);
		}
		// case 4: position is occupied but parent key is less than to insert
		if (toInsert > parent->data)
		{
			parent->right = insert(parent->right, toInsert);
		}
		return parent;
	}

	// makes sure insert comparision starts from the root
	void insert(int toInsert)
	{
		root = insert(root, toInsert);
	}

	bool search(Node* parent, int toSearch) {
		//Case 1: the parent is empty, mean search key not exist
		if (parent == nullptr) {
			return false;
		}
		//Case 2: the parent data is the same as search key, means the search key found
		if (parent->data == toSearch) {
			return true;
		}
		//Case 3: the parent data is less than the search key, we search on the right subtree
		if (parent->data < toSearch) {
			return search(parent->right, toSearch);
		}

		//Case 4: the parent data is greater than the search key, we search on the left subtree
		if (parent->data > toSearch) {
			return search(parent->left, toSearch);
		}
	}

	//Search
	//@Input: the key to search
	//@Output: true as found the search key, false as not found the search key
	bool search(int toSearch) {
		return search(root, toSearch);
	}

	//Transversals
	//@ print a sequence of data in each node
	//@ pre-order transversal
	//@ in-order transversal
	//@ post-order transversal
	//@ leveled-order transversal

	//Pre-order transversal
	void preOrderTransversal()
	{
		preOrderTransversal(root);
	}
	void preOrderTransversal(Node* parent) {
		if (parent != nullptr) {
			cout << parent->data << ",";
			preOrderTransversal(parent->left);
			preOrderTransversal(parent->right);
		}
		//Base case parent==null, no action needed, so it is an implicit base case.
	}

	//In-order transversal
	void inOrderTransversal()
	{
		inOrderTransversal(root);
	}
	void inOrderTransversal(Node* parent) {
		if (parent != nullptr) {
			inOrderTransversal(parent->left);
			cout << parent->data << ",";
			inOrderTransversal(parent->right);
		}
		//Base case parent==null, no action needed, so it is an implicit base case.
	}

	//post-order transversal
	void postOrderTransversal()
	{
		postOrderTransversal(root);
	}
	void postOrderTransversal(Node* parent) {
		if (parent != nullptr) {
			postOrderTransversal(parent->left);
			postOrderTransversal(parent->right);
			cout << parent->data << ",";
		}
		//Base case parent==null, no action needed, so it is an implicit base case.
	}
	

	// level order transversal / breadth first transversal
	// print out the nodes level by level from top to bottom, each level left to right
	void levelOrderTransversal()
	{
		int h = height(root);
		for (int i = 0; i <= h; i++)
		{
			levelOrderTransversal(root, i);
			cout << endl;
		}
	}

	void levelOrderTransversal(Node* parent, int level)
	{
		// case 1: reach end of bst
		if (parent == nullptr)
		{
			return;
		}
		// case 2: reach leaf node of bst OR bst only has 1 node
		else if(level == 0)
		{
			cout << parent->data << ", ";
		}
		// case 3: when parent node has left subtree and/or right subtree, recursivly transverse left and/or right
		else if (level > 0)
		{
			levelOrderTransversal(parent->left, level - 1);
			levelOrderTransversal(parent->right, level - 1);
		}
	}

	// compute height of tree
	int getTreeHeight()
	{
		return height(root);
	}

	// compute height of specfic node
	int height(Node* node)
	{
		// base case
		if (node == nullptr)
		{
			return -1;
		}
		else
		{
			int leftHeight = height(node->left);
			int rightHeight = height(node->left);

			// compare left height to right height, take larger height + 1
			if (leftHeight > rightHeight)
			{
				return(leftHeight + 1);
			}
			else
			{
				return(rightHeight + 1); 
			}
		}
	}

	//Delete
	//@input: the data of the node to be deleted
	void deleteNode(int toDelete) {
		root = deleteNode(root, toDelete);
	}

	Node* deleteNode(Node* parent, int toDelete) {
		//Case 1: toDelete is not in the tree
		if (parent == nullptr) {
			cout << "The node does not exist" << endl;
			return nullptr;
		}

		//Find the position of toDelete in the BST
		else if (toDelete < parent->data) {
			parent->left = deleteNode(parent->left, toDelete);
		}
		else if (toDelete > parent->data) {
			parent->right = deleteNode(parent->right, toDelete);
		}

		//toDelete is found
		else {  //toDelete==parent->data
			//Case 2: the left child is empty and right child is empty, which means
			//the toDelete is a leaf node, we just delete the node
			if (parent->left == nullptr && parent->right == nullptr) {
				return nullptr;
			}
			//Case 3: The left child is empty and it has right child
			else if (parent->left == nullptr) {
				return parent->right;
			}
			//Case 4: The right child empty and it has left child
			else if (parent->right == nullptr) {
				return parent->left;
			}
			//Case 5: has two children
			else {
				//Step 1: get data from the right most (largest node) in the left subtree
				//and replace the parent data to the value of the right most node in the left subtree
				parent->data = getLargest(parent->left);
				// step 2: delete the duplicate node in left subtree
				parent->left = deleteNode(parent->left, parent->data);
			}
			return parent;
		}

	}

	// get data of right most node
	int getLargest(Node* currentNode)
	{
		while (currentNode->right != nullptr)
		{
			currentNode = currentNode->right;
		}
		return currentNode->data;
	}



	// project 2 Q1:
	void invertTree(Node* &root)
	{
		if (root == nullptr)
		{
			return;
		}
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
	}
	void invert()
	{
		invertTree(root);
		if (inverted == 0)
			inverted = 1;
		else
			inverted = 0;
	}

	// project 2 Q2:
	
	int getLargestLessThanK(Node* root, int k) {
    int result = -1; 
    while (root != nullptr) 
	{
        if (root->data < k) 
		{
            result = root->data;
            root = root->right; 
        }
		else 
		{
            root = root->left;  
        }
    }
    return result;
}
	
	int kth_Largest(int k)
	{
		if (inverted == 1)
		{
			invert();
		}
		int kth_largest_value = getLargest(root);
		while (k > 1)
		{
			kth_largest_value = getLargestLessThanK(root, kth_largest_value);
			k--;
		}
		return kth_largest_value;
	}
	
};

