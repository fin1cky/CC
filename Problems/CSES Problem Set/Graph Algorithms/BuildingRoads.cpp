/*
Approach : Use Disjoint Set to find out the number of connected components. The number of
roads required will be the number of connected components - 1. To find what those roads
are, just take the roots of all connected components, fix one of the root let's say the
first root and simply make a road from this fixed root to all other remaining roots.
This way all vertices will be connected. 
*/

#include <bits/stdc++.h>
using namespace std;

class UnionFind{
public:
	vector<int>root;
	vector<int>rank;
	UnionFind(int sz):root(sz),rank(sz){
		for(int i=0;i<sz;i++){
			root[i] = i;
			rank[i] = 1;
		}
	}
	int find(int x){
		if(x == root[x]){
			return x;
		}
		return root[x] = find(root[x]);
	}
	void UnionSet(int x, int y){
		int rootX = find(x);
		int rootY = find(y);
		if(rootX != rootY){
			if(rank[rootX] > rank[rootY]){
				root[rootY] = rootX;
			}
			else if(rank[rootY] >  rank[rootX]){
				root[rootX] = rootY;
			}
			else{
				root[rootY] = rootX;
				rank[rootX]++;
			}
		}
	}
	bool connected(int x, int y){
		return find(x) == find(y);
	}
};

int main(){
	int n,m;
	cin >> n >> m;
	UnionFind uf(n);
	int count = n;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		if(uf.connected(a-1,b-1)==false){ // -1 because we took from 0 to n-1
			uf.UnionSet(a-1,b-1);
			count--;
		}
	}
	set<int>s;
	for(int i=0;i<n;i++){
		s.insert(uf.find(uf.root[i]));
	}
	if(s.size()==1){
		cout << 0;
	}
	else{
		vector<int>v;
		for(int x:s){
			v.push_back(x);
		}
		cout << v.size() - 1 << "\n";
		for(int i=1;i<v.size();i++){
			cout << v[0]+1 << " " << v[i]+1 << "\n"; // +1 because we took from 0 to n-1
		}
	}
	return 0;
}