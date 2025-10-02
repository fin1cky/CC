#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long int> odds;
		long long int evens_sum = 0;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			if(x%2==0){
				evens_sum += x;
			}
			else{
				odds.push_back(x);
			}
		}
		sort(odds.begin(), odds.end());
		long long int ans = 0;
		if(odds.size() > 0){
			ans += evens_sum;
			ans += odds[odds.size()-1];
		}
		int l = 0;
		int r = odds.size()-2;
		while(l<r){
			ans += odds[r];
			l++;
			r--;
		}
		cout << ans << "\n";
	}
	return 0;
}