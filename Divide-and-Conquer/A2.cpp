#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll inversions(vector<int> &arr, int i, int j){
	
	if (j - i <= 1) return 0;

	int mid = (i + j)/2;

	ll l = inversions(arr, i, mid);
	ll r = inversions(arr, mid, j);

	ll s = 0;

	int m = i, n = mid;
	vector<int> tmp;

	while(m < mid and n < j){
		
		if (arr[m] <= arr[n]){
			tmp.push_back(arr[m++]);
		}
		else {
			tmp.push_back(arr[n++]);
			s += (mid - m);
		}
	}

	while(m < mid) tmp.push_back(arr[m++]);
	while(n < j) tmp.push_back(arr[n++]);

	for (m = i; m < j; m++) arr[m] = tmp[m - i];

	return l + r + s;	
}

int main(){
	
	vector<int> arr;

	int n = 100000;

	for (int i = 0; i < n; i++){
	
		int tmp;
		cin >> tmp;

		arr.push_back(tmp);
	}

	cout << inversions(arr, 0, n) << endl;

	return 0;
}
