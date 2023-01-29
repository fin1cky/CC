/*
Approach : Let dp[i] represent the total ways we can use coins from coins vector such that 
the sum of those coins is i. Initialise all the indices of the dp vector as 0 assuming there
are no ways to get any of them. Then, put dp[0] = 1 since the only way we can get sum 0 from
the combinations of coins from coins vector is to NOT select any of the coins. Sort the
coins vector in increasing order. From then on, traverse from i=1 to the target value i=x.
If for a target value i, there are coins from coins vector whose value is less than i,
check if it is possible to attain i-coins[j], i.e. dp[i-coins[j]] must not be zero. If it is
zero, since we there are no ways to get i-coins[j], there can be no ways to get i with the
help of coins[j] either. If it is non-zero, then that means, to dp[i], we add all dp[i-coins[j]]
that are non-zero. We print dp[x] as the final answer.
*/

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
    	cin >> coins[i];
    }
    sort(coins.begin(),coins.end());
    vector<long long int>dp(x+1,0);
    //there is only one way of getting coin sum 0 which is by NOT selecting any coins.
    dp[0] = 1;  
    for(int i=1;i<=x;i++){
    	for(int j=0;j<n && coins[j]<=i;j++){
    		if(dp[i-coins[j]] != 0){
    			dp[i] = (dp[i] + dp[i-coins[j]])%mod;
    		}
    	}
    }
    cout << dp[x];
	return 0;
}	