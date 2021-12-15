#include "List.h"
#include "ListNode.h"
#include <iostream>
#include <time.h>

using namespace std;

// ========		(a)		========

void quickSort(int* a, int first, int last) {
	
	int i = first; int j = last;
	int pivot = a[(first + last) / 2];

	while (i <= j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;

		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;
		}
	}
	if (first < i - 1) quickSort(a, first, i - 1);
	if (i < last) quickSort(a, i, last);
}

// (1)
void printTopX(int* rand_array, int N, int X)
{
	// quicksort
	quickSort(rand_array, 0, N-1);

	for (int i = (N - X); i < N; i++)
		cout << rand_array[i] << endl;
	 
}

// (2)
int main2()
{
	// initialise an int array with N unordered random numbers
	srand(time(NULL));
	int arraySize = 256;
	int* randArr = new int[arraySize];
	for (int i = 0; i < arraySize; i++) {
		randArr[i] = rand() % 10000;
	}
	// print out top 5
	printTopX(randArr, arraySize, 5);
	cout << "\n";
	// print out top 10
	printTopX(randArr, arraySize, 10);

	//Time complexity of printTopX is that of the loop which depends on X
	//	for the top X elements as this is slower than quicksort (O(N Log_2 N)) and
	//	the general complexity taken is that of the worst constituent part of an
	//	algorithm therefore O(X)
	cout << "The time complexity of printTopX is " << "O(X)" << endl;

	return 0;
}

int main1()
{
cout << "Suppose Quick Sort takes 5 ms to sort an array of size 512." << endl;
// fill ... below and print out your answer
cout << "Quick Sort (4096) should take ~53 ms." << endl
<< "Because: Quick sort has a time complexity of O(N log_2 N)" << endl
<< "Therefore:" << endl;
return 0;
}

// ========		(c)		========

// (1)
List<int>* insertionSort(List<int>* l)
{
	for (int i = 1; i < l->size(); i++) {
		// item in position i
		int item_i = l->get(i);
		int j = i - 1;
		// for positions from j to 0 find the 1st position j with item <= item_i
		while (j >= 0 && l->get(j) > item_i) {
			l->set(j + 1, l->get(j));
			j--;
		}
		// insert item_i into position j + 1
		l->set(j + 1, item_i);
	}
	// complexity - where XXX is what you think the complexity is in terms of the
	// order(s) of the size of the list

	// (3)
	cout << "The complexity of this list-based insertion sort is O(N^2)" << endl;
	return l;
}

int main()
{
	srand(time(NULL));
	List<int> iList;
	for (int i = 0; i < 2000; i++)
		iList.insert_end(rand() % 1000);
	iList.print();

	// (2)
	insertionSort(&iList)->print();

	return 0;
}