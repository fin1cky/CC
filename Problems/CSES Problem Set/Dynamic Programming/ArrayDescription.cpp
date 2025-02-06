/*
Approach: Consider two adjacent elements x and y. WLOG, we can assume that they are related
to each other by one of these three possibilities: x = y-1, x = y, x = y+1.

We define a 2D vector dp such that dp[i][j] represents the total number of arrays that end at
index i with element j. So, based on the initial observation, the number of such arrays depend
on the SUM of the number of arrays that end at index i-1 with elements j-1, j and j+1 and this
recursion would go on all the way till we reach index 0. At every index, there are a few checks
that must be performed:
1. Index must be >= 0
2. Value of (j-1/j/j+1) must be in [1, m]
3. If the value of the element at index i in the original array is non-zero, let it be val. Then,
dp[i][k] = 0 for all k != val. The reason is because we cannot alter the value of a non-zero element.

At index 0, if the value of array[0] is non-zero and equal to say val, then once again,
dp[0][k] = 0 for all k != val. However, in that case dp[0][val] = 1 because there is EXACTLY
one array that ends at index 0 with element val. However, if the value of array[0] is 0, then
the value of dp[0][k] = 1 because this is the base case ---> for all k in [1, m], if the only 
element in an array of size 1 is 0, then this element can be transformed to any element in [1, m].

We basically need to find dp[n-1][g] where g represents all VALID values. Let val = array[n-1]. 
To find out what the valid values are:
1. If val != 0, then val is the only valid value and answer = dp[n-1][val].
2. If val == 0, then the valid values are in [1, m]. But this can be further optimized. If we can
find the last non-zero element in the array (let's call it a) and its index b, then the last value
of the array must be in [max(1, a - (n-1-b)), min(m, a + (n-1-b))]. This is because, from x,
the maximum possible value would be obtained if we kept adding 1 to x for every index from 
index b to index n-1. Similarly, from x, the minimum possible value would be obtained if we 
kept subtracting 1 from x for every index from index b to index n-1. But these minimum and maximum
values are bound by 1 and m respectively.

Time Complexity: O(n*m), there are n*m states that are computed AT MOST once. Without memoization,
the time complexity would have been O(3^n) since three recursion calls are made for each index. Just
simulate the problem with index of size 10 with last element 51, you'll realize why its O(n*m).

Space Complexity: O(n*m)
*/

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
vector<vector<long long int>> dp;

long long int solve_back(int idx, int val, vector<int>& v, int n, int m){
	if(idx < 0){
		return 0;
	}
	if(val > m || val < 1){
		return 0;
	}
	if(v[idx] != 0 && v[idx] != val){
		return 0;
	}
	if (dp[idx][val] != -1){
		return dp[idx][val];
	}
	if(idx == 0){
		if(v[idx] != 0 && v[idx] == val){
			dp[idx][val] = 1;
			return dp[idx][val];
		}
		else if(v[idx] != 0 && v[idx] != val){
			dp[idx][val] = 0;
			return 0;
		}
		else if(v[idx] == 0 && val <= m && val >= 1){
			dp[idx][val] = 1;
			return dp[idx][val];
		}
	}
	dp[idx][val] = (solve_back(idx-1, val-1, v, n, m)%mod + 
					solve_back(idx-1, val, v, n, m)%mod +
					solve_back(idx-1, val+1, v, n, m)%mod)%mod;
	return dp[idx][val];
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	dp = vector<vector<long long int>>(n+1,vector<long long int>(m+1,-1));
	
	long long int ans = 0;
	if(v[n-1] != 0){
		int val = v[n-1];
		if(n>1){
			ans = (solve_back(n-1-1, val-1, v, n, m)%mod + 
					solve_back(n-1-1, val, v, n, m)%mod +
					solve_back(n-1-1, val+1, v, n, m)%mod)%mod;
		}
		else{
			ans = 1;
		}
	}
	else{
		if(n>1){
			int start = 1;
			int end = m;
			for(int i=n-1;i>=0;i--){
				if(v[i] != 0){
					start = max(1, v[i] - (n-1-i));
					end = min(m, v[i] + (n-1-i));
					break;
				}
			}
			for(int val=end;val>=start;val--){
				ans = (ans + (solve_back(n-1-1, val-1, v, n, m)%mod + 
								solve_back(n-1-1, val, v, n, m)%mod +
								solve_back(n-1-1, val+1, v, n, m)%mod))%mod;
			}
		}
		else{
			ans = m;
		}
		
	}
	cout << ans;
	return 0;
}
