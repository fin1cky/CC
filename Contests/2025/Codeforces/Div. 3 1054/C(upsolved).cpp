#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		int k_count = 0;
		set<int> s;
		for(int i=0; i<n; i++){
			cin >> v[i];
			if(v[i]<k){
				s.insert(v[i]);
			}
			else if(v[i]==k){
				k_count++;
			}
		}
		int ops_needed = k-s.size();
		cout << max(ops_needed, k_count) << "\n";
	}
	return 0;
}