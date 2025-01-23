#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long long int> v;
	for(int i=0; i<n; i++){
		long long int x;
		cin >> x;
		v.push_back(x);
	}
	long long int ans = 0;
	for(int i=0; i<n; i++){
		long long int val = v[i]*2;
		auto it = lower_bound(v.begin(), v.end(), val);
		if(it != v.end()){
			long long int count = n - (it - v.begin());
			ans += count;
		}
	}
	cout << ans;
	return 0;
}