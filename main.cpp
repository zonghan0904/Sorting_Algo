# include <iostream>
# include "SortAlgo.h"

using namespace std;

int main(){
	vector<int> testcase;
	for (int i = 10; i > 0; i--) testcase.push_back(i);

	//InsertionSort(testcase);
	//SelectionSort(testcase);
	MergeSort(testcase, 0, testcase.size()-1);
	
	vector<int>::iterator it;
	for (it = testcase.begin(); it != testcase.end(); ++it) cout << *it << " ";
	cout << "\n";

	return 0;
}