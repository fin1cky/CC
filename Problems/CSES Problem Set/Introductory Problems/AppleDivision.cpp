#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
int n;
ll arr[20];

ll solve(int i,ll set1,ll set2){
	if(i==n){
		return abs(set1-set2);
	}
	return min(solve(i+1, set1 + arr[i], set2),solve(i+1, set1, set2 + arr[i]));
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
    	cin >> arr[i];
    }
    cout << solve(0,0,0);
	return 0;
}

/*using bitmasks
int main(){
	int n;
	cin >> n;
	ll weights[n];
	for(int i=0;i<n;i++){
	cin >> weights[i];
	}
	ll ans = (ll)1e18;
	for(int mask=0;mask<(1<<n);mask++){
		ll s1=0,s2=0;
		for(int j=0;j<n;j++){
	        if(mask&(1<<j)){//if j-th bit is on
	           s1 += weights[j];
	        }
	        else{
	           s2 += weights[j];
	        }
		}
	    ans = min(ans,abs(s1-s2));
	}
	cout << ans;
	return 0;
}
*/