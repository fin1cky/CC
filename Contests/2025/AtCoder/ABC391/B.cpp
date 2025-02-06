#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<char>> S(n, vector<char>(n, '.'));
	vector<vector<char>> T(m, vector<char>(m, '.'));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> S[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin >> T[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			bool flag = true;
			for(int ti=0;ti<m;ti++){
				for(int tj=0;tj<m;tj++){
				  if(!(i+ti < n && j+tj < n) || T[ti][tj] != S[i+ti][j+tj]){
				    flag = false;
				    break;
				  }
				}
				if(!flag){
				  break;
				}
			}
			if(flag){
				cout << i+1 << " " << j+1;
			}
		}
	}
	return 0;
}