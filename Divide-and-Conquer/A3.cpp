#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll quicksort(vector<int> &arr, int i, int j){

	if (j - i <= 1) return 0;

	int pivot_index;

	int mid = (i + j - 1)/ 2;

	if ((arr[mid] > arr[i] and arr[mid] < arr[j - 1]) or (arr[mid] < arr[i] and arr[mid] > arr[j - 1])) pivot_index = mid;
	else if ((arr[i] > arr[mid] and arr[i] < arr[j - 1]) or (arr[i] < arr[mid] and arr[i] > arr[j - 1])) pivot_index = i;
	else pivot_index = j - 1;

	int pivot = arr[pivot_index];

	arr.erase(arr.begin() + pivot_index);

	int m = i, n = j - 2;

	while(m <= n){

		if (arr[m] <= pivot) m++;
		else if (arr[n] > pivot) n--;
		else swap(arr[m++], arr[n--]); 
	}

	arr.insert(arr.begin() + m, pivot);

	int l = quicksort(arr, i, m);
	int r = quicksort(arr, m + 1, j);

	return l + r + (j - i - 1);
}

int main(){

	vector<int> arr;

	int n = 10000;

	for (int i = 0; i < n; i++){
		int  tmp;
		cin >> tmp;

		arr.push_back(tmp);
	}

	cout << quicksort(arr, 0, n) << endl;

	return 0;
}