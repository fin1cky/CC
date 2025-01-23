/*
The greedy approach of trying to always remove the maximum value digit is also correct.
But this is DP!
Approach : Using just recursion gives TLE, hence there is a need to memoize. When there is
only a single digit from 1 to 9, thats when we need only one removal(subtraction) to make 
the number 0. Initialise the dp vector with all -1 and 1 for numbers 1 to 9. Then, call the
recursive function with the current number. If the dp value of that number is not -1, we can
straight away return dp[number] because it already has the minimum number of subtractions.
Maintain a set and store all non-zero digits of that number. Store the ans as minimum
of ans and 1 + recursive_function(n-digit) (1 because we are performing one subtraction to 
o from n to n-x). Do this for all digits. Store the minimum ans in dp[number]. 
Return dp[number].
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int ans, vector<int>& v){
	if(v[n] != -1){
		return v[n];
	}
	set<int>s;
	int k = n;
	while(k>0){
		if(k%10 != 0){
			s.insert(k%10);
		}
		k /= 10;
	}
	for(int x : s){
		ans = min(ans,1+solve(n-x,ans,v));
	}
	v[n] = ans;
	return v[n];
}

int main(){
    int n;
    cin >> n;
    int ans = INT_MAX;
    vector<int>v(1000002,-1);
    for(int i=1;i<=9;i++){
    	v[i] = 1;
    }
    ans = solve(n, ans, v);
    cout << ans;
	return 0;
}