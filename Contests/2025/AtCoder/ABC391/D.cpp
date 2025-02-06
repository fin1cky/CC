// INCORRECT !!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, w;
	cin >> n >> w;
	vector<vector<pair<int,int>>> tetris(w+1);
	map<int,int> existence; // time taken to reach last row --> so after this time + 0.5, they will be out
	for(int i=0;i<n;i++){
		int x, y;
		cin >> x >> y;
		tetris[x].push_back(make_pair(y,i+1));
	}
	int limiter = INT_MAX;
	for(int i=1;i<=w;i++){
		sort(tetris[i].begin(), tetris[i].end());
		int cells = tetris[i].size();
		limiter = min(limiter, cells);
	}
	
	int ptr = 0;
	int elapsed_time = 0;
	for(int j=0;j<limiter;j++){
		int min_required_time = 0;
		for(int i=1;i<=w;i++){
			min_required_time = max(min_required_time, elapsed_time+tetris[i][j].first-1);
		}
		elapsed_time = min_required_time;
		for(int i=1;i<=w;i++){ //
			existence[tetris[i][j].second] = min_required_time;
		}
	}
	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		int time, block;
		cin >> time >> block;
		if(existence.find(block)!=existence.end()){
			double tb = existence[block] + 1;
			double tout = time + 0.5;
			if(tout >= tb){
				cout << "No" << "\n";
			}
			else{
				cout << "Yes" << "\n";
			}
		}
		else{
			cout << "Yes" << "\n";
		}
	}
	// for(auto x: existence){
	// 	cout << x.first << " " << x.second << "\n";
	// }
	return 0;
}