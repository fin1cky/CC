/*
Approach: The problem is finding the individual sum of all possible subsets that can be formed using nums. 
Maintain a vector subset_sums which stores all possible sums of subsets for the coins encountered so far.
This would begin with just a 0 for the first coin. Maintain an unordered map to keep track of the unique sums. 
For each coin, traverse the subset_sums vector till its current size and if the sum of current coin and current
subset sum does not exist in the unordered map, append it to subset_sums.

Time Complexity: O(2^n)

Space Complexity: O(2^n)

INCORRECT WILL USE THE DP WAY - KNAPSACK
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	unordered_map<int,int> ump;
	vector<int> subset_sums;
	subset_sums.push_back(0);
	for(int i=0; i<n; i++){
		int k = subset_sums.size();
		for(int j=0; j<k; j++){
			if(ump.find(nums[i] + subset_sums[j]) == ump.end()){
				subset_sums.push_back(nums[i] + subset_sums[j]);
				ump[nums[i] + subset_sums[j]] = 1; 
			}
		}
	}
	sort(subset_sums.begin(), subset_sums.end());
	cout << subset_sums.size() - 1 << "\n";
	for(int i=1; i<subset_sums.size(); i++){
		cout << subset_sums[i] << " "; 
	}

	return 0;
}