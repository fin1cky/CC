/*
Approach : In this problem, we need to find if there is a cycle and if so, we need to output the length of
the cycle and the vertices in this cycle. We can follow a dfs approach where we traverse all the vertices of
the graph. For every unvisited vertex, we pass in that vertex and its previous vertex (in the first iteration
of every unvisited node, previous vertex of the unvisited vertex will be the unvisited vertex itself) to
the checkCycle function which checks if there is a cycle starting from the vertex passed to it. There are two
global variables namely "start_end_vertex" which is use to identify which is the vertex that starts (and therefore
ends) the cycle and "cycle_start_end" which is used to identify if all the nodes in the cycle have been
stored in the path. The checkCycle function initially marks the current vertex as visited. It then traverses
through all the neighbours of this current vertex. If it encounters an unvisited vertex, it will again call 
itself with the unvisited vertex as the vertex to be explored and the current vertex as the previous vertex and
this will go on till we either encounter a cycle or we explore all the vertices in the graph (in which case
the function return false). We can say we encountered a cycle (of length atleast 3 edges) when we visit a vertex 
that is already visited but is also not the same as the previous_vertex of the current vertex whose neighbours 
are currently being explored. When that happens push this node to a vector which stores the nodes in the 
cycle (path vector) and set the "start_end_vertex" to this vertex and return true. Now the control goes back 
to checkCycle function (that called itself) and since the flag is true, we have encountered a cycle and 
we just need to keep pushing all those vertices into the path vector (recursively) till we encounter the 
"start_end_vertex" vertex again. Then, we set the "cycle_start_end" variable to true and from then on we 
don't need to push anymore vertices into the path vector because we already stored all the vertices in the 
cycle (which begins and ends with the "start_end_vertex").
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> route(100002, vector<int>());
vector<int> path;
vector<int> visited(100002,0);
int start_end_vertex = -1;
bool cycle_start_end = false;

bool checkCycle(int vertex, int prev_vertex){
	visited[vertex] = 1;
	for(int j=0;j<route[vertex].size();j++){
		if(visited[route[vertex][j]] == 0){
			bool flag = checkCycle(route[vertex][j], vertex);
			if(flag==true){
				if(cycle_start_end == false){
					path.push_back(route[vertex][j]);
					if(route[vertex][j] == start_end_vertex){
						cycle_start_end = true;
					}
				}
				return true;
			}
		}
		else{
			if(route[vertex][j] != prev_vertex){
				path.push_back(route[vertex][j]);
				start_end_vertex = route[vertex][j];
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		route[a].push_back(b);
		route[b].push_back(a);
	}
	vector<int> path_cur;
	bool flag = false;
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			flag = checkCycle(i, i);
			if(flag==true){
				if(cycle_start_end == false){
					path.push_back(i);
					if(i == start_end_vertex){
						cycle_start_end = true;
					}
				}
				break;
			}
		}
	}
	if(flag==true){
		reverse(path.begin(),path.end());
		cout << path.size() << "\n";
		for(int x:path){
			cout << x << " ";
		}
	}
	else{
		cout << "IMPOSSIBLE";
	}
	return 0;
}