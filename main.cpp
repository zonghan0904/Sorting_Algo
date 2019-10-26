# include <iostream>
# include "SortAlgo.h"

using namespace std;

int main(){
	vector<int> testcase;
	for (int i = 10; i > 0; i--){
		testcase.push_back(i);
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
	HeapSort(testcase);
// #############	Sorting Algorithm	#############

	cout << "## AFTER  SORTING ##" << endl; 	
	for (it = testcase.begin(); it != testcase.end(); ++it){
		cout << *it << " ";
	}
	cout << "\n";
	cout << "####################\n"<< endl;


	return 0;
}