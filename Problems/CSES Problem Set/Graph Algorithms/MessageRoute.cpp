/*
Approach : Take in the input as vector of vectors and since this is an undirected graph,
push each of the integer in a connection into the other integer's list of connections.
Maintain two more vectors (namely explored and prev_vertex) which can tell whether a
vertex has been explored and the previous vertex in the path from node 1 respectively.
The previous vertex of vertex 1 which is the starting vertex will be 1 itself. Mark
vertex 1 as explored in the explored vertex. Now make a queue of pairs to represent 
vertex, its previous vertex. Push the neighbours of vertex 1 into the queue with 1 as
their previous vertex like (neighbour1, 1), (neighbour2, 1) and so on. While the queue
is not empty, process each pair in the queue. Take the first pair - the first element 
in the pair will tell which vertex to process next and the second element in the pair
will tell the previous vertex of this vertex. Mark the previous vertex of this vertex with
the second element and mark this vertex as explored. Check if the vertex is the 
final vertex. If so, break out of the while loop. If not, push the neighbours of the
vertex into the queue. The process will repeat till the final vertex is found or if
the queue becomes empty in which case sending the message will be "IMPOSSIBLE". Otherwise,
from the final vertex, with the help of the prev_vertex find the vertices in the path
from vertex n to vertex 1 and store them in another vertex (namely path). Reverse this
vector to get the path from vertex 1 to vertex n.
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>>vertices(n+1);
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		vertices[a].push_back(b);
		vertices[b].push_back(a);
	}
	vector<int> explored(n+1,0);
	vector<int> prev_vertex(n+1,0);
	prev_vertex[1] = 1;
	explored[1] = 1;
	queue<pair<int,int>> q;
	for(int i=0;i<vertices[1].size();i++){
		q.push({vertices[1][i],1});
	}
	while(!q.empty()){
		int vertex = q.front().first;
		int prev = q.front().second;
		q.pop();
		if(explored[vertex] == 0){
			prev_vertex[vertex] = prev;
			explored[vertex] = 1;
			if(vertex == n){
				break;
			}
			else{
				for(int i=0;i<vertices[vertex].size();i++){
					q.push({vertices[vertex][i],vertex});
				}
			}
		}
	}
	if(explored[n] == 1){
		vector<int>path;
		path.push_back(n);
		int place = n;
		while(place != 1){
			place = prev_vertex[place];
			path.push_back(place);
		}
		reverse(path.begin(), path.end());
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