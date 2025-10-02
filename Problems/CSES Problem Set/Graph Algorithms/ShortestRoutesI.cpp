#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<pair<long long int,long long int>>> flights(n+1);
	for(int i=0; i<m; i++){
		long long int a,b,cost;
		cin >> a >> b >> cost;
		flights[a].push_back({b, cost});
	}

	vector<long long int> costs(n+1, 1000000000000000 + 7);
	costs[1] = 0;
	priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> connections;
	connections.push({0, 1});
	while(connections.size()>0){
		pair<long long int, long long int> p = connections.top();
		connections.pop();
		long long int cost = p.first;
		long long int city = p.second;
		if(cost > costs[city]){
			continue;
		}
		costs[city] = cost;
		for(pair<long long int, long long int> flight: flights[city]){
			if(cost + flight.second < costs[flight.first]){
				costs[flight.first] = cost + flight.second;
				connections.push({cost + flight.second, flight.first});
			}
		}
	}

	for(int i=1; i<n+1; i++){
		cout << costs[i] << " ";
	}
	return 0;
}