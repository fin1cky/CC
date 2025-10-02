#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<vector<int>> v;

void solve(int node){
	for(int j=0; j<v[node].size(); j++){
		int neighbor = v[node][j];
		if(dp[node]+1>dp[neighbor]){
			dp[neighbor] = dp[node]+1;
			solve(neighbor);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	v = vector<vector<int>> (n+1);
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	dp = vector<int>(n+1, 0);
	int ans = 0;

	for(int i=1; i<=n; i++){
		if(dp[i]==0){
			solve(i);
		}
	}

	for(int i=1; i<=n; i++){
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}