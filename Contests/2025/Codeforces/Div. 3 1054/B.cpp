#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n, 0);
		for(int i=0; i<n; i++){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int ans = -1;
		for(int i=1; i<n; i+=2){
			ans = max(ans, (v[i]-v[i-1]));
		}
		cout << ans << "\n";
	}
	

	return 0;
}