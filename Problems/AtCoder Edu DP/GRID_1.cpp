/*
Approach: You can only move to current cell (i, j) from cells (i-1, j) and (i, j-1).
If the current cell is a wall, then you cant move to it so number of paths to it is 0.
prev[1] = 1 is set before the loop runs the first time so that the value for cell (1, 1) 
comes out to be 1, since Taro is already there in that cell at the start.

Time Complexity: O(h*w)

Space Complexity: O(w)
*/

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main(){
	int h, w;
	cin >> h >> w;
	vector<int> prev(w+1, 0);
	prev[1] = 1;
	for(int i=1; i<=h; i++){
		vector<int> cur(w+1, 0);
		for(int j=1; j<=w; j++){
			char ch;
			cin >> ch;
			if(ch == '#'){
				cur[j] = 0;
			}
			else{
				cur[j] = (prev[j]%mod + cur[j-1]%mod)%mod;
			}
		}
		prev = cur;
	}
	cout << prev[w];
	return 0;
}