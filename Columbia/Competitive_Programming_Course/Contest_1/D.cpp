/*
Approach: In order to form k subarrays, we need to choose k-1 indexes to form
k-1 subarrays since a subarray is always formed with index 0. Suppose, we need to form
4 subarrays. Hence, the starting points can be 0, i, j, k. Now the cost is
(arr[i-1] - arr[0]) + (arr[j-1] - arr[i]) + (arr[k-1] - arr[j]) + (arr[n-1] - arr[k]).
Since the array is sorted, all these terms are positive. If we rearrange the terms inside
the brackets, we get (arr[n-1] - arr[0]) + (arr[i-1] - arr[i]) + (arr[j-1] - arr[j]) + 
(arr[k-1] - arr[k]). We need to minimize the cost, so we need to minimize this expression.
(arr[n-1] - arr[0]) is constant. The remaining part of the expression can be written as
- [(arr[i] - arr[i-1]) + (arr[j] - arr[j-1]) + (arr[k] - arr[k-1])]. We need to maximize
the sum in the square brackets inorder to obtain the minimum cost. Hence, we need to choose
k-1 indices such that the difference between them and their previous terms is the among the 
k-1 largest.

Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	long long int total_cost = v[n-1] - v[0];
	if(k==1){
		cout << total_cost;
		return 0;
	}
	if(n==1){
		cout << 0;
		return 0;
	}
	vector<int> differences;
	for(int i=1; i<n; i++){
		differences.push_back({v[i] - v[i-1]});
	}
	sort(differences.rbegin(), differences.rend());
	for(int i=0; i<k-1; i++){
		total_cost -= differences[i];
	}
	cout << total_cost;
	return 0;
}