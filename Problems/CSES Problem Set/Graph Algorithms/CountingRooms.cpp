/*
Approach : Basic DFS, from a dot find all the dots that can be reached in
all 4 directions and mark them as visited. Each time the DFS stack is empty, 
we will have obtained a new room.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>>v;
    for(int i=0;i<n;i++){
        vector<char>v2;
    	for(int j=0;j<m;j++){
    		char ch;
    		cin >> ch;
    		v2.push_back(ch);
    	}
        v.push_back(v2);
    }
    vector<vector<int>>visited(n,vector<int>(m,0));
    stack<pair<int,int>> s;
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j] == 1){
                continue;
            }
            else if(v[i][j] == '#'){
                visited[i][j] = 1;
            }
            else{
                count++;
                s.push({i,j});
                visited[i][j] = 1;
                while(s.empty()!=true){
                    int r = (s.top()).first;
                    int c = (s.top()).second;
                    s.pop();
                    if(c+1<m && visited[r][c+1]==0){
                        if(v[r][c+1] == '.'){
                            s.push({r,c+1});
                        }
                        visited[r][c+1] = 1;
                    }
                    if(r+1<n && visited[r+1][c]==0){
                        if(v[r+1][c] == '.'){
                            s.push({r+1,c});
                        }
                        visited[r+1][c] = 1;
                    }
                    if(c-1>=0 && visited[r][c-1]==0){
                        if(v[r][c-1] == '.'){
                            s.push({r,c-1});
                        }
                        visited[r][c-1] = 1;
                    }
                    if(r-1>=0 && visited[r-1][c]==0){
                        if(v[r-1][c] == '.'){
                            s.push({r-1,c});
                        }
                        visited[r-1][c] = 1;
                    }
                }
            }
        }
    }
    cout << count ;
	return 0;
}