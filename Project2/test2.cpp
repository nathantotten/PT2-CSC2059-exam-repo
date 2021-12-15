#include <iostream>

using namespace std;

// ========		(a)		========

/* demonstration program for linear search */
int main1()
{
	// L1. allocate an int array, pointed by pi, and store each number in an
	// element of the array (e.g., pi[0] = 12, pi[1] = 211, ..., pi[7] = 4)
	int* pi = new int[8];
	pi[0] = 12;
	pi[1] = 211;
	pi[2] = 48;
	pi[3] = 501;
	pi[4] = 91;
	pi[5] = 82;
	pi[6] = 110;
	pi[7] = 4;

	// run three search tests
	for (int test = 1; test <= 3; test++) {
		// take a search request from keyboard
		cout << "Specify the number to be searched for: ";
		int key;
		cin >> key;
		// L2. implement linear search through the array for the 1st occurrence
		// of the key number; print the index if found or -1 otherwise
		
		int i;
		// to make more robust - if this wasn't a demo of linear search
		// if would be advisable to have i < arraySize to make this loop compatible
		// with any sized array. Where arraySize is the size of the array being searched.
		for (i = 0; i < 8; i++)
			if (pi[i] == key)
				cout << "Key found at index " << i << endl;
			cout << -1 << endl;
		// L3. complete the statement, where XXX is what you think the
		// complexity is in terms of the order(s) of the size of the data set
		cout << "The complexity of the linear search is O(N)" << endl;
	}
	// L4. free the memory used by the array
	delete[] pi;

	return 0;
}

// ========		(b)		========

/* demonstration program for binary search */
// B1. implement binary search, below, through an int array pointed by pi from first
// to last for a specified key number; return the index if found or -1 otherwise
int binarySearch(int* pi, int first, int last, int key)
{
	// base case - not found
	if (first > last) return -1;

	// recursive case

	//midpoint
	
	int mid = (first + last) / 2;

	
	// get the integer at the midpoint
	int val = pi[mid];
	
	// if the value is equal to the key then return the index (midpoint)
	if (val == key)
		return mid;
	// else if the key is smaller than the value at the midpoint, navigate
	//	to the left subtree
	else if (key < val)
		return binarySearch(pi, first, mid - 1, key);
	else
		// else it must be in the right subtree
		return binarySearch(pi, mid + 1, last, key);

}

int main()
{
	// B2. allocate an int array, pointed by pi, and store each number in an
	// element of the array

	int* pi = new int[8];
	pi[0] = 4;
	pi[1] = 12; 
	pi[2] = 48;
	pi[3] = 82;
	pi[4] = 91;
	pi[5] = 110;
	pi[6] = 211;
	pi[7] = 501;

	// run three search tests
	for (int test = 1; test <= 3; test++) {
		// take a search request from keyboard
		cout << "Specify the number to be searched for: ";
		int key;
		cin >> key;
		// B3. call binarySearch to search for the key number; print the
		// index if found or -1 otherwise
		
		cout << binarySearch(pi, 0, 7, key) << endl;
		// B4. complete the statement, where XXX is what you think the
		// complexity is in terms of the order(s) of the size of the data set
		cout << "The complexity of the binary search is O(logN)" << endl;
	}
	delete[] pi;
	return 0;
}