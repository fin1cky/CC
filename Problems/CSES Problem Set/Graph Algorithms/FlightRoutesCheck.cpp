/*
Approach : If there exists a city that can go to every other city and if all other cities
can go this city, then we can travel from any city to any other city. So, if there are 2 cities
a and b such that we cannot reach a from b or reach b from a, we need to report that. Let's
say we pick 1 as a city. We need to find out if from 1 we can go to all other cities and from
all other cities we can go to 1. If this condition is satisfied, then the answer is YES, (since
from 1 we can go to any city and from any city we can go to any other city via through city 1.)
Otherwise we have to report (1, city x) / (city x, 1) which does not satisfy the condition. So,
first, we can DFS from city 1 to find out all the cities that are reachable from it and mark
them as visited in the visited vector. If there is any city that is unvisited, then 1 and that
city is the answer. If all the cities are marked as visited, then that means from city 1,
we can go to all other cities. Then we reinitialise the unvisited vector to all false. Then, we
check from all cities if we can reach 1. To do this, in the beginning itself, while making the
adjacency lists of the flights from u -> v, make another adjacency list that stores to_values
i.e. v -> u values so we can store what are the cities that can reach the current city. We only
need to find one city that is like a root -> from that city we can go to all cities and from
all cities we can reach the root city. We are just picking 1 to be this root city.

Solution doesn't feel so intuitive to me at this point in time.

Good proof : https://usaco.guide/problems/cses-1682-flight-routes-check/solution 
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(100001, false);
vector<vector<int>> flights(100001);
vector<vector<int>> rev_flights(100001);

void dfs_to(int node){
	if(visited[node] == true){
		return;
	}
	visited[node] = true;
	for(int x:flights[node]){
		dfs_to(x);
	}
}

void dfs_from(int node){
	if(visited[node] == true){
		return;
	}
	visited[node] = true;
	for(int x:rev_flights[node]){
		dfs_from(x);
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		--a;
		--b;
		flights[a].push_back(b);
		rev_flights[b].push_back(a);
	}
	
	dfs_to(0);

	for(int i=0;i<n;i++){
		if(visited[i] == false){
			cout << "NO" << "\n";
			cout << 1 << " " << i+1;
			return 0;
		}
	}

	fill(visited.begin(), visited.end(), false);
	dfs_from(0);

	for(int i=0;i<n;i++){
		if(visited[i] == false){
			cout << "NO" << "\n";
			cout << i+1 << " " << 1;
			return 0;
		}
	}

	cout << "YES";
	return 0;
}