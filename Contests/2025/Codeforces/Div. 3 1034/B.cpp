#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, j, k;
		cin >> n >> j >> k;
		int val = 0;
		vector<int> v;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			if (i==j-1){
				val = x;
				// cout << val << "\n";
			}
			else{
				v.push_back(x);
			}
		}
		sort(v.begin(), v.end());
		v.push_back(val);
		if(n==k){
			cout << "YES" << "\n";
		}
		else{
			if(v[n-k] >= v[n-k-1]){
				cout << "YES" << "\n";
			}
			else{
				cout << "NO" << "\n";
			}
		}
	}
	return 0;
}