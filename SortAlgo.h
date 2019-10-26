# ifndef SORTALGO_H
# define SORTALGO_H

# include <iostream>
# include <vector>
# include <cstdlib>
using namespace std;

void swap(int &a, int&b);

void Merge(vector<int> &V, int l, int m, int r);

void BuildMaxHeap(vector<int> &V);

void Max_Heapify(vector<int> &V, int index, int size);

int  RandomInteger(int low, int high);

int  Partition(vector<int> &V, int l, int r);

void InsertionSort(vector<int> &V);

void SelectionSort(vector<int> &V);

void BubbleSort(vector<int> &V);

void MergeSort(vector<int> &V, int l, int r);

void HeapSort(vector<int> &V);

void QuickSort(vector<int> &V, int l, int r);

# endif