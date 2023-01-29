/*
Approach : In a single roll of dice, we can get numbers from 1 to 6. So, in order to count
the number of ways in which we can get a number n from several dice, we need to find the sum
of the following - 
1) number of ways to get (n-1) if we get 1 on roll of dice
2) number of ways to get (n-2) if we get 2 on roll of dice
3) number of ways to get (n-3) if we get 3 on roll of dice
4) number of ways to get (n-4) if we get 4 on roll of dice
5) number of ways to get (n-5) if we get 5 on roll of dice
6) number of ways to get (n-6) if we get 6 on roll of dice

Hence, we can say dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]
where dp[i] represents the number of ways in which we can roll dice such that the sum is i.
Base case: dp[0] = 1. The reasoning though a bit not sound is "The only way we can get a sum
of 0 is by doing nothing so we can count that as 1 way".
*/

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<long long> dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=6 && i-j>=0;j++){
            dp[i] += (dp[i-j])%mod;
    	}
    }
    cout << dp[n]%mod;

	return 0;
}