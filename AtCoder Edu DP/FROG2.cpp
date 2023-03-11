#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int arr[n]={};
    for(int i=0;i<n;i++){ 
    	cin >> arr[i];
    }
    int dp[n] = {};
    for(int i=0;i<n;i++){
        dp[i]=INT_MAX;
    }
    dp[0] = 0;
    dp[1] = abs(arr[1]-arr[0]);
    for(int i = 2;i<n;i++){
        for(int j=i-1;j>=max(i-k,0);j--){
            dp[i] = min(dp[i],dp[j]+abs(arr[i]-arr[j]));
        }
    }
    cout << dp[n-1] << endl;
	return 0;
}   