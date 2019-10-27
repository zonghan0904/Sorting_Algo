# include "SortAlgo.h"

// ####################		Helper function		####################

void swap(int& a, int& b){
	int c = a;
	a = b;
	b = c;
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

void BuildMaxHeap(vector<int> &V){
	int n = V.size();
	for (int i = n/2; i > 0; i--) Max_Heapify(V, i, n);
}

void Max_Heapify(vector<int> &V, int index, int size){
	int largest = index-1;
	if (2*index-1 < size && V[2*index-1] > V[largest]) largest = 2*index-1;
	if (2*index < size && V[2*index] > V[largest]) largest = 2*index;
	if (largest != index-1){
		swap(V[largest], V[index-1]);
		Max_Heapify(V, largest+1, size);
	}  
}

int RandomInteger(int low, int high){
	srand(0);
	return rand()%(high-low+1) + low;
}

int Partition(vector<int> &V, int l, int r){
	int randnum = RandomInteger(l, r);
	swap(V[randnum], V[r]);
	int i = l-1, x = V[r];
	for (int j = l; j < r; j++){
		if (V[j] <= x){
			i++;
			swap(V[i], V[j]);
		}
	}
	swap(V[++i], V[r]);
	return i;
}

int GetDigit(int num){
	int digit = 0;
	if (num == 0) return 1;
	while (num){
		digit++;
		num /= 10;
	}
	return digit;
}

// ####################		comparison sort		####################

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

void BubbleSort(vector<int> &V){
	int n = V.size();
	bool sorted;
	for (int i = n-1; i > 0; i--){
		sorted = true;
		for (int j = 0; j < i; j++){
			if (V[j] > V[j+1]){
				swap(V[j], V[j+1]);
				sorted = false;
			}
		}
		if (sorted) break;
	}
}

void MergeSort(vector<int> &V, int l, int r){
	if (l < r){
		int m = (l + r)/2;
		MergeSort(V, l, m);
		MergeSort(V, m+1, r);
		Merge(V, l, m, r);
	}
}

void HeapSort(vector<int> &V){
	BuildMaxHeap(V);
	int n = V.size();
	while (n){
		swap(V[0], V[n-1]);
		Max_Heapify(V, 1, --n);
	}
}

void QuickSort(vector<int> &V, int l, int r){
	if (l < r){
		int m = Partition(V, l, r);
		QuickSort(V, l, m-1);
		QuickSort(V, m+1, r);
	}
}

// ###################	  non comparison sort	 ###################

void CountingSort(vector<int> &V, int high){
	vector<int> box(high, 0);
	vector<int> copy(V.begin(), V.end());
	vector<int>::iterator it;
	vector<int>::reverse_iterator r_it;
	for (it = copy.begin(); it != copy.end(); it++){
		box[*it]++;
	}
	for (it = box.begin()+1; it != box.end(); it++){
		*it += *(it-1);
	}
	for (r_it = copy.rbegin(); r_it != copy.rend(); r_it++){
		V[box[*r_it]-1] = *r_it;
		box[*r_it]--;
	}
}

void RadixSort(vector<int> &V, int digit){
	vector<int> copy;
	vector<int> box;
	vector<int>::iterator it;
	vector<int>::reverse_iterator r_it;
	int mul = 1;
	for (int i = 0; i < digit; i++){
		box = vector<int> (10, 0);
		copy = V;
		for (it = copy.begin(); it != copy.end(); it++){
			box[*it/mul%10]++;
		}
		for (it = box.begin()+1; it != box.end(); it++){
			*it += *(it-1);
		}
		for (r_it = copy.rbegin(); r_it != copy.rend(); r_it++){
			V[box[*r_it/mul%10]-1] = *r_it;
			box[*r_it/mul%10]--;
		}
		mul *= 10;
	}
}

void BucketSort(vector<int> &V, int digit){
	vector<vector<int> > bucket(10, vector<int>());
	int max = 1;
	while (digit > 1){
		max *= 10;
		digit--;
	} 
	vector<int>::iterator it;
	vector<int>::iterator s_it;
	vector<vector<int> >::iterator v_it;
	for (it = V.begin(); it != V.end(); it++){
		bucket[*it/max].push_back(*it);
	}
	for (v_it = bucket.begin(); v_it != bucket.end(); v_it++){
		if (!v_it->empty()) InsertionSort(*v_it);
	}
	v_it = bucket.begin();
	it = V.begin();
	while (it != V.end()){
		while (v_it != bucket.end() && v_it->empty()) v_it++;
		for (s_it = v_it->begin(); s_it != v_it->end(); s_it++){
			*it = *s_it;
			it++;
		}
		v_it++;
	}
}