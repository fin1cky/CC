/*
Approach : standard bfs with storing pair<pair<x,y>,path> in queue works but it exceeds
time limit on one case (check the latest wrong submission). This is because additional
time is used to update the path string every time. Hence, we keep a 2D matrix namely
prevstep which for each cell tells the step that was taken to get to that cell.
Up:0, Right:1, Down:2, Left:3. (This is stored as a string "URDL") dx[i] and dy[i] 
arrays represent the direction of movement corresponding to URDL. Once we reach 'B', we 
simply backtrack from that cell with the help of prevstep matrix till we reach 'A'. 
Reversing this path gives the path we need to follow to reach 'B' from 'A'.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>>v;
    int sr = 0, sc = 0;
    int er = 0, ec = 0;
    for(int i=0;i<n;i++){
    	vector<char>v2;
    	char ch;
    	for(int j=0;j<m;j++){
    		cin >> ch;
    		if(ch == 'A'){
    			sr = i;
    			sc = j;
    		}
            if(ch == 'B'){
                er = i;
                ec = j;
            }
    		v2.push_back(ch);
    	}
    	v.push_back(v2);
    }
    vector<vector<int>> visited(n, vector<int>(m,0));
    queue<pair<int,int>>q;
    vector<vector<int>> prevstep(1000, vector<int>(1000,5));
    string dir = "URDL";
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    q.push({sr,sc});
    visited[sr][sc] = 1;
    while(q.empty()!=true){
        int r = (q.front()).first;
        int c = (q.front()).second;
        q.pop();
        if(r==er && c==ec){
            break;
        }
        for(int i=0;i<4;i++){
            pair<int,int>move = {r+dx[i],c+dy[i]};
            if(move.first > n-1 || move.first < 0 || move.second > m-1 || move.second < 0){
                continue;
            }
            if(visited[move.first][move.second] == true){
                continue;
            }
            if(v[move.first][move.second]=='#'){
                continue;
            }
            q.push(move);
            visited[move.first][move.second] = 1;
            prevstep[move.first][move.second] = i;
        }
    }
    if(visited[er][ec]==1){
        cout << "YES" << "\n";
        vector<int>path;
        while(!(er == sr && ec == sc)){
            int step = prevstep[er][ec];
            path.push_back(step);
            er = er - dx[step];
            ec = ec - dy[step];
        }
        reverse(path.begin(),path.end());
        cout << path.size() << "\n";
        for(int x:path){
            cout << dir[x];
        }
    }
    else{
        cout << "NO";
    }
	return 0;
}