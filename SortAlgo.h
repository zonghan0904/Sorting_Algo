# ifndef SORTALGO_H
# define SORTALGO_H

# include <iostream>
# include <vector>
using namespace std;

void swap(int &a, int&b);

void InsertionSort(vector<int> &V);

void SelectionSort(vector<int> &V);

void Merge(vector<int> &V, int l, int m, int r);

void MergeSort(vector<int> &V, int l, int r);

# endif