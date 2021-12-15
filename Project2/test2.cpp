#include <iostream>

using namespace std;

/* demonstration program for linear search */
int main()
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