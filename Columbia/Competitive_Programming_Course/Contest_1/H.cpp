#include <bits/stdc++.h>
using namespace std;

int main(){
	int h, w, n;
	cin >> h >> w >> n;
	vector<vector<int>> grid(h+1, vector<int>(w+1, 0));
	for(int i=0; i<n; i++){
		int r,c;
		cin >> r >> c;
		grid[r][c] = -1;
	}
	grid[1][1] = 1;
	int mod = 1e9 + 7;
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			if(i==1 && j==1){
				continue;
			}
			if(grid[i][j] == -1){
				continue;
			}
			int val1 = 0, val2 = 0;
			if(i-1>=1 && grid[i-1][j] != -1){
				val1 = grid[i-1][j];
			}
			if(j-1>=1 && grid[i][j-1] != -1){
				val2 = grid[i][j-1];
			}
			// cout << val1 << " " << val2 << "\n";
			grid[i][j] = (val1%mod + val2%mod)%mod;
		}
	}

	cout << grid[h][w];
	return 0;
}