#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, d;
	cin >> n >> d;
	vector<int> t(n, 0);
	vector<int> l(n, 0);
	for(int i=0; i<n; i++){
		cin >> t[i] >> l[i];
	}
	for(int i=1; i<=d; i++){
		priority_queue<int, vector<int>> pq;
		for(int j=0; j<n; j++){
			int val = t[j]*l[j] + i*t[j];
			pq.push(val);
		}
		cout << pq.top() << "\n";
	}
	return 0;
}