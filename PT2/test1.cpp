#include <iostream>
#include "TreeNode.h"

using namespace std;

// (a) 
int alternating_sum(int n)
{
	// base case
	if (n == 1) return 1;

	// recursive step
	int sum = 0;
	if (n % 2 == 1) sum += n;
	else sum -= n;
	return sum + alternating_sum(n - 1);
}

// (b)
template<typename T>
void print(TreeNode<T>* tree)
{
	// Print a given binary tree using PRE-ORDER traversal
	// base case
	if (tree == NULL)
		return;

	// recursive step
	// pre-order
	cout << tree->item << endl;
	print(tree->leftTree);
	print(tree->rightTree);
}

// (c)
template<typename T>
TreeNode<T>* search(T key, TreeNode<T>* tree)
{
	if (tree == NULL) // key not in tree, insert
		tree = new TreeNode<T>(key);
	else if (key < tree->item)
		tree->leftTree = search(key, tree->leftTree);
	else if (key > tree->item)
		tree->rightTree = search(key, tree->rightTree);
	return tree;
}

// (c) (1)
int main()
{
	// (c) (1) rebuild a balanced BST
	TreeNode<int>* bst = NULL;
	bst = search(212, bst);
	bst = search(111, bst);
	bst = search(20, bst);
	bst = search(150, bst);
	bst = search(531, bst);
	bst = search(412, bst);
	bst = search(718, bst);

	// (c) (2) Call the print function to print my bst
	// This will also test (b)
	print(bst);

	// (c) (3) Print out the complexity of the balanced BST
	cout << "The complexity of the balanaced BST is " << "O(logN)" << endl;

	// (a) testing the function
	// Test alternating_sum
	//cout << alternating_sum(100) << endl;
	//cout << alternating_sum(20) << endl;
	return 0;
}