/*
Approach: To count the number of ways to get to a cell (i,j) in a grid,
we to need to find the sum of the number of ways to get to cell to the left
of (i,j) and the number of ways to get to cell above (i,j) which are 
(i, j-1) and (i-1, j) respectively (they must be within bounds). Ensure 
that (i,j) is not a trap ('*') nor are the cells (i-1,j) and (i,j-1). Maintain
two vectors, one for current row, one for previous row. For (i-1,j) use
previous_row[j]. For (i, j-1), use current_row[j-1]. At the end of each i (row),
update previous_row = current_row and set current_row to empty vector.

Time complexity: O(n^2)
Space complexity (at any point in time, how much space are we using): O(n)
*/

#include <bits/stdc++.h> 
using namespace std;

int main(){
	int mod = 1e9 + 7;
	int n;
	cin >> n;
	vector<vector<char>> grid(n, vector<char>(n, '0'));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> grid[i][j];
		}
	}
	// dp 2D vec where paths[i][j] is the number of ways to go from (0,0) to (i,j)
	vector<vector<int>> paths(n, vector<int>(n, 0));
	vector<int> prev_path_row(n, 0);
	vector<int> cur_path_row(n, 0);
	if(grid[0][0] != '*'){
		cur_path_row[0] = 1; //only one way to go from (0,0) to (0,0)
	} 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==0 && j==0){
				continue;
			}
			if(grid[i][j] != '*'){
				if(i-1 >= 0 && grid[i-1][j] != '*'){
					cur_path_row[j] = (cur_path_row[j]%mod + prev_path_row[j]%mod)%mod;
				}
				if(j-1 >= 0 && grid[i][j-1] != '*'){
					cur_path_row[j] = (cur_path_row[j]%mod + cur_path_row[j-1]%mod)%mod;
				}
			}
		}
		prev_path_row = cur_path_row;
		cur_path_row = vector<int>(n, 0);
	}
	cout << prev_path_row[n-1];
	return 0;
}