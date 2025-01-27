#include <bits/stdc++.h>
using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	vector<vector<char>> v(h, vector<char>(w,'.'));
	pair<int,int> left = {0, 1001};
	pair<int,int> up = {1001, 0}; 
	pair<int,int> right = {0, -1};
	pair<int,int> down = {-1, 0};
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin >> v[i][j];
			if(v[i][j] == '#'){
				if(i < up.first){
					up = {i,j};
				}
				if(i > down.first){
					down = {i,j};
				}
				if(j > right.second){
					right = {i,j};
				}
				if(j < left.second){
					left = {i,j};
				}
			}
		}
	}
	// cout << up.first << " " << up.second << "\n";
	// cout << down.first << " " << down.second << "\n";
	// cout << left.first << " " << left.second << "\n";
	// cout << right.first << " " << right.second << "\n";
	bool flag = true;
	for(int i=up.first; i<=down.first; i++){
		for(int j=left.second; j<=right.second; j++){
			if(v[i][j] == '.'){
				flag = false;
				break;
			}
		}
	}

	if(flag){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	return 0;
}