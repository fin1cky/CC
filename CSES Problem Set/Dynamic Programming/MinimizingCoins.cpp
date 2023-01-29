/*
Approach : Let dp[i] represent the minimum number of coins required to get target value i.
The answer is dp[x]. Initialise all values from 1 to x as INT_MAX assuming we can't get there.
Then, for every coin in the coins vector, set the dp[coin value] = 1 as we only need one 
coin to get that target value. We can sort the coins vector in ascending order. Now, we
traverse from i=1 to x. For every coin in coins vector that is less than the target value
i, we check if dp[i-coins[j]] is attainable i.e. NOT INT_MAX. If it is attainable, we set
dp[i] = minimum of dp[i] and 1+dp[i-coins[j]] since we would need one coin whose
value is coins[j] to go from i-coins[j] to i. Finally, after we populate the dp vector,
we check if dp[x] is attainable, i.e. NOT INT_MAX. If yes, we print the value of dp[x], else
we print -1.  
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int>dp(x+1,INT_MAX);
    vector<int>coins(n);
    for(int i=0;i<n;i++){
    	cin >> coins[i];
    }
    sort(coins.begin(),coins.end());
    for(int i=0;i<n&&coins[i]<=x;i++){
    	dp[coins[i]] = 1;
    }
    for(int i=1;i<=x;i++){
    	for(int j=0;j<n;j++){
    		if(coins[j]>=i){
    			break;
    		}
    		else{
    			if(dp[i-coins[j]]!=INT_MAX){
    				dp[i] = min(dp[i],1+dp[i-coins[j]]);
    			}
    		}
    	}
    }

    if(dp[x]==INT_MAX){
    	cout << -1;
    }
    else{
    	cout << dp[x];
    }
	return 0;
}	