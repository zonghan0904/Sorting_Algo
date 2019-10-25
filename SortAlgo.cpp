# include "SortAlgo.h"

void swap(int& a, int& b){
	int c = a;
	a = b;
	b = c;
}

void InsertionSort(vector<int> & V){
	int key, i, j;
	for (i = 1; i < V.size(); i++){
		key = V[i];
		j = i - 1;
		while(j >= 0 && V[j] > key){
			V[j+1] = V[j];
			j--;
		}
		V[j+1] = key;
	}
}

void SelectionSort(vector<int> &V){
	int i, j, k, min;
	for (i = 0; i < V.size(); i++){
		min = V[i];
		for (j = i + 1; j < V.size(); j++){
			if (V[j] < min){
				min = V[j];
				k = j;
			}
		}
		if (min < V[i]) swap(V[i], V[k]);
	}
}

void Merge(vector<int> &V, int l, int m, int r){
	vector<int> left(V.begin()+l, V.begin()+m+1);
	vector<int> right(V.begin()+m+1, V.begin()+r+1);
	int i = 0, j = 0;
	while (i < left.size() && j < right.size()){
		if (left[i] < right[j]) V[l+i+j] = left[i++];
		else V[l+i+j] = right[j++];
	}
	while (i < left.size()) V[l+i+j] = left[i++];
	while (j < right.size()) V[l+i+j] = right[j++]; 
}

void MergeSort(vector<int> &V, int l, int r){
	if (l < r){
		int m = (l + r)/2;
		MergeSort(V, l, m);
		MergeSort(V, m+1, r);
		Merge(V, l, m, r);
	}
}
