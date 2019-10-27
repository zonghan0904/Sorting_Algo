# include <iostream>
# include <vector>
# include <cstdlib>
# include "SortAlgo.h"

# define SEED 0
# define CASE 10
# define MAX  10

using namespace std;

int main(){
	srand(SEED);
	vector<int> testcase;
	for (int i = 0; i < CASE; i++){
		testcase.push_back(rand()%MAX);
	}

	vector<int>::iterator it;
	cout << "\n";
	cout << "## BEFORE SORTING ##" << endl; 
	for (it = testcase.begin(); it != testcase.end(); ++it){
		cout << *it << " ";
	}
	cout << "\n";
	cout << "####################\n"<< endl;

// #############	Sorting Algorithm	#############
	//InsertionSort(testcase);
	//SelectionSort(testcase);
	//BubbleSort(testcase);
	//MergeSort(testcase, 0, testcase.size()-1);
	//HeapSort(testcase);
	//QuickSort(testcase, 0, testcase.size()-1);
	//CountingSort(testcase, MAX);
	//RadixSort(testcase, GetDigit(MAX));
	BucketSort(testcase, GetDigit(MAX));
// #############	Sorting Algorithm	#############

	cout << "## AFTER  SORTING ##" << endl; 	
	for (it = testcase.begin(); it != testcase.end(); ++it){
		cout << *it << " ";
	}
	cout << "\n";
	cout << "####################\n"<< endl;

	return 0;
}