/*
Approach : The problem is equivalent to "Is the graph formed by the friendships among students Bipartite?"
A graph is Bipartite if it is possible to colour the graph entirely using only two colours such that no 
two adjacent vertices have the same colour. A graph is usually Bipartite if it has no cycle with odd number 
of edges. However, in this code, a DFS approach is followed. Initially an adjacent list is made corresponding 
to all the friendships. Then, all the vertices are traversed. If a vertex is not visited, it is checked for
bipartiteness. Initially it is marked with a colour say colour 1, then, all its neighbouring vertices are 
checked. If they were visited before, they must have a different colour i.e. -1 otherwise we have found
two adjacent vertices that have the same colour and hence that translates to two friends and we can't form
two separate teams. 
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> friendships(100001,vector<int>());

bool check_not_Bipartite(int vertex, vector<int>& visited, vector<int>& colour, int colour_value){
	visited[vertex] = 1;
	colour[vertex] = colour_value;
	for(int j=0;j<friendships[vertex].size();j++){
		if(visited[friendships[vertex][j]]==0){
			bool flag = check_not_Bipartite(friendships[vertex][j], visited, colour, -colour_value);
			if(flag == false){
				return false;
			}
		}
		else if(colour[friendships[vertex][j]] == colour_value){
			return false;
		}
	}
	return true;
}

int main(){
	int n,m;
	cin >> n >> m;
	friendships.clear();
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		friendships[a].push_back(b);
		friendships[b].push_back(a);
	}
	vector<int> visited(n+1,0);
	vector<int> colour(n+1,0);
	for(int i=1;i<=n;i++){
		if(visited[i] == 0){
			bool flag = check_not_Bipartite(i, visited, colour, 1);
			if(flag == false){
				cout << "IMPOSSIBLE";
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(colour[i]==-1){
			colour[i] = 2;
		}
		cout << colour[i] << " ";
	}
	return 0;
}