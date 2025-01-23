#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int main(){
	int n;
	cin >> n;
	vector<int> v;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	vector<int> zeros;
	for(int i=0; i<n; i++){
		int givers = pq.size();
		int new_alien = v[i] + givers;
		while(pq.size()>0){
			pair<int,int> p = pq.top();
			if((p.first - (i-p.second))==0){
				zeros.push_back(p.second);
				pq.pop();
			}
			else{
				break;
			}
		}
		pq.push(make_pair(new_alien, i));
	}
	vector<int> ans(n,0);
	for(int i=0; i<zeros.size(); i++){
		ans[zeros[i]] = 0;
	}
	while(pq.size()>0){
		pair<int,int> p = pq.top();
		ans[p.second] = max(0, p.first - (n-1-p.second));
		pq.pop();
	}
	for(int i=0; i<n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}