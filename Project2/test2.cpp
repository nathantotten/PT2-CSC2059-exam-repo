#include <iostream>
#include <string>
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

int main2()
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


// ========		(c)		========

/* demonstration program for hashing-based search */
// H1. write a good hash function (such as the one used in the lecture notes), which
// converts a string key to a hash index in a hash table of the given tableSize
size_t Hash_(string key, size_t tableSize)
{
	size_t index = 0;
	for (int i = 0; i < key.size(); i++)
		index = 37 * index + key[i];
	return index % tableSize;
}

int main()
{
	// choose a suitable tableSize (e.g. 223), allocate an int array (i.e. the hash
	// table) of this size pointed by pht
	int tableSize = 223;
	int* pht = new int[tableSize];
	// H2. store the numbers in the hash table, e.g., 12 in a location specified by
	// Hash("12", tableSize)
	pht[Hash_("12", tableSize)] = 12;
	pht[Hash_("211", tableSize)] = 211;
	pht[Hash_("48", tableSize)] = 48;
	pht[Hash_("501", tableSize)] = 501;
	pht[Hash_("91", tableSize)] = 91;
	pht[Hash_("82", tableSize)] = 82;
	pht[Hash_("110", tableSize)] = 110;
	pht[Hash_("4", tableSize)] = 4;

	// run three search tests
	for (int test = 1; test <= 3; test++) {
		// take a search request from keyboard
		cout << "Specify the number to be searched for: ";
		int key;
		cin >> key;
		// H3. perform hashing-based search for the key number in the table;
		// print the index if found or -1 otherwise
		// need to make key into a string first so that we can put it into Hash_ function.
		string sKey = to_string(key);
		// get the hash index of the key (after converting to string for compatibility with Hash_)
		int hashIndex = Hash_(sKey, tableSize);
		// If the int at the index found using Hash_ in pht == key
		if (int(pht[hashIndex]) == key)
			// return the index
			cout << hashIndex << endl;
		else
			// else return -1
			cout << -1 << endl;

		// H4. complete the statement, where XXX is what you think the
		// complexity is in terms of a suitable measure
		cout << "The hashing-based search is potentially O(1)" << endl;
	}
	delete[] pht;
	return 0;
}