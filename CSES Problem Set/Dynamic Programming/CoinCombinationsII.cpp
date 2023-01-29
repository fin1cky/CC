/*
Approach : Since we need the ordered ways, once we use a coin, we can only choose the
coins whose value is atleast as large as the current value. Using the coin with the smallest
value, find out all the sums that we can generate by traversing from 0 to the target sum. For
those sums that were reachable, we have found one way/combination to do so. Now, for the next 
coin do the same. In this case, there may already be sums that were reached earlier and 
have now been reached again. This means that we have found out a new combination to generate 
that sum. In coin combinations I, the order did not matter so we can use any coin in any order 
but here we need the coins to be ordered and to generate the target sum.

we can reach state[i] using coins[j] by adding coins[j] to state[i-coins[j]].
Hence, state[i] = state[i] + state[i-coins[j]];

*/

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
    	cin >> coins[i];
    }
    sort(coins.begin(),coins.end());
    vector<long long int> numberofCombinations(x+1,0);
    numberofCombinations[0] = 1;
    for(int j=0;j<n;j++){
        for(int i=1;i<=x;i++){
    		if(i-coins[j]>=0){ //we cant get sum < 0
                //cout << i << " " << coins[j] << "\n";
    			numberofCombinations[i] = (numberofCombinations[i]+numberofCombinations[i-coins[j]])%mod;
    		}
    	}
    }

    cout << numberofCombinations[x];
	return 0;
}