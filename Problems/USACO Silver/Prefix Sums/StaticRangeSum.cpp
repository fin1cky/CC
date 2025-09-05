#include <bits/stdc++.h> 
using namespace std;

int main(){
	int n, q;
	cin >> n >> q;
	vector<int> v(n, 0);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	vector<long long int> prefix_sum(n+1, 0);
	for(int i=0; i<n; i++){
		prefix_sum[i+1] = prefix_sum[i] + v[i];
	}
	while(q--){
		int l1, r1;
		cin >> l1 >> r1;
		cout << prefix_sum[r1] - prefix_sum[l1] << "\n";
	}
	return 0;
}