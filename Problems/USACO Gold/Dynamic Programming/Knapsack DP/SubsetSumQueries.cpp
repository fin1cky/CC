/*
Approach: This is a knapsack problem, here knapsack[j] represents the number of ways of obtaining
sum j with the balls encountered so far. Everytime we receive a "+ x" operation, we iterate backwards
from sum k till sum x on the knapsack vector and update knapsack[j] += knapsack[j-x]. We iterate
in this direction because, by changing the values from the end, we are only using the older values
to obtain the new values and prevent reusing the values. However, if we were to iterate from sum x to sum k, there is a chance
we may be reusing the updated values within the same iteration. When we receive a "- x" operation,
for each sum from x till sum k, we need to remove contributions from the subsets that utilize x, so we perform
knapsack[j] = knapsack[j] - knapsack[j-x] + mod. We are adding mod because, there is a possibility that
that value will be negative. We go in this direction for "- x" operation because, we need the updated
values from smaller sums before moving on to bigger sums.

NOTE: My first approach (check on Atcoder) though logically correct is not optimal since 
it had a time complexity of O(q*q*k) (I think). If you look closely at the code, you'll realize
that we only need two vectors - previous and current as opposed to my 2D vector. Then if you think
about it, depending on the direction you iterate for + and - operations (read approach above),
you can actually use JUST ONE vector!

Time Complexity: O(qk)
Space Complexity: O(k)

*/

#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;

int main(){
	int q,k;
	cin >> q >> k;
	vector<int> knapsack(k+1, 0);
	knapsack[0] = 1;
	while(q--){
		char ops;
		int x;
		cin >> ops >> x;
		if(ops == '-'){
			for(int j=x; j<=k; j++){
				knapsack[j] = (knapsack[j]-knapsack[j-x]+mod)%mod;
			}
		}
		else{
			for(int j=k; j>=x; j--){
				knapsack[j] = (knapsack[j]+knapsack[j-x])%mod;
			}
		}
		cout << knapsack[k] << "\n";
	}
	return 0;
}