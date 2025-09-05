/*
Approach: DFS but maintain the current number of consecutive cats also along with the
vertex as a pair in the stack. Since n >= 2, include check for root node while incrementing
ans variable (root node won't be a leaf node).

Time Complexity: O(N)
Space Complexity: O(N) 
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> cats(n+1, 0);
	for(int i=1; i<n+1; i++){
		cin >> cats[i];
	}
	vector<vector<int>> graph(n+1);
	for(int i=0; i<n-1; i++){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	stack<pair<int,int>> s;
	vector<int> visited(n+1, 0);
	s.push({1,0});
	int ans = 0;
	while(s.size() > 0){
		pair<int,int> p = s.top();
		s.pop();
		int vx = p.first;
		int con_cats = p.second;
		if(cats[vx] == 1){
			con_cats += 1;
		}
		else{
			con_cats = 0;
		}
		visited[vx] = 1;
		if(con_cats <= m){
			vector<int> neighbours = graph[vx];
			for(int i=0; i<neighbours.size(); i++){
				if(visited[neighbours[i]] == 0){
					s.push({neighbours[i], con_cats});
				}
			}
			if(neighbours.size() == 1 && vx != 1){
				ans+=1;
			}
		}
	}

	cout << ans;
	return 0;
}