#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<char>> labyrinth(n, vector<char>(m));
	vector<pair<int,int>> monsters_ini;
	vector<vector<int>> monster_moves(n, vector<int>(m, INT_MAX));
	int xme=-1, yme=-1;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> labyrinth[i][j];
			if(labyrinth[i][j] == 'M'){
				monsters_ini.push_back({i, j});
				monster_moves[i][j] = 0;
			}
			if(labyrinth[i][j] == 'A'){
				xme = i;
				yme = j;
			}
		}
	}
	if(xme==0 || xme==n-1 || yme==0 || yme==m-1){
		cout << "YES" << "\n" << 0;
		return 0;
	}
	queue<vector<int>> monsters;
	vector<int> dx = {-1, 0, 0, 1};
	vector<int> dy = {0, 1, -1, 0};
	for(pair<int,int>p : monsters_ini){
		int x = p.first;
		int y = p.second;
		for(int i=0; i<4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx>=0 && xx<n && yy>=0 && yy<m && labyrinth[xx][yy]!='#' && monster_moves[xx][yy]>1){
				monsters.push({xx, yy, 1});
			}
		}
	}

	while(monsters.size()>0){
		vector<int> move = monsters.front();
		monsters.pop();
		if(monster_moves[move[0]][move[1]] > move[2]){
			monster_moves[move[0]][move[1]] = move[2];
			int x = move[0];
			int y = move[1];
			for(int i=0; i<4; i++){
				int xx = x + dx[i];
				int yy = y + dy[i];
				if(xx>=0 && xx<n && yy>=0 && yy<m && labyrinth[xx][yy]!='#' && monster_moves[xx][yy]>1){
					monsters.push({xx, yy, move[2]+1});
				}
			}
		}
	}

	vector<vector<pair<int,char>>> my_moves(n, vector<pair<int,char>>(m, {INT_MAX,'-'}));
	my_moves[xme][yme] = {0, '-'};
	queue<vector<int>> me;
	vector<char> dirs = {'U', 'R', 'L', 'D'};
	for(int i=0; i<4; i++){
		int xx = xme + dx[i];
		int yy = yme + dy[i];
		if(xx>=0 && xx<n && yy>=0 && yy<m && labyrinth[xx][yy]!='#' && 1<monster_moves[xx][yy]){
			me.push({xx, yy, 1, dirs[i]});
		}
	}

	int xf = -1, yf = -1;
	while(me.size() > 0){
		vector<int> move = me.front();
		me.pop();
		if(move[0]==n-1 || move[1]==m-1 || move[0]==0 || move[1]==0){
			xf = move[0];
			yf = move[1];
			my_moves[move[0]][move[1]].first = move[2];
			my_moves[move[0]][move[1]].second = move[3];
			break;
		}
		if(my_moves[move[0]][move[1]].first>move[2] && move[2]<monster_moves[move[0]][move[1]]){
			my_moves[move[0]][move[1]].first = move[2];
			my_moves[move[0]][move[1]].second = move[3];
			int x = move[0];
			int y = move[1];
			for(int i=0; i<4; i++){
				int xx = x + dx[i];
				int yy = y + dy[i];
				if(xx>=0 && xx<n && yy>=0 && yy<m && labyrinth[xx][yy]!='#' && my_moves[xx][yy].first>move[2]+1 && move[2]+1<monster_moves[xx][yy]){
					me.push({xx, yy, move[2]+1, dirs[i]});
				}
			}
		}
	}

	if(xf != -1 && yf != -1){
		map<char, pair<int,int>> anti;
		anti['L'] = {0, 1};
		anti['R'] = {0, -1};
		anti['U'] = {1, 0};
		anti['D'] = {-1, 0};
		string path = "";
		while(true){
			if(xf==xme && yf==yme){
				break;
			}
			path += my_moves[xf][yf].second;
			pair<int, int> mvmt = anti[my_moves[xf][yf].second];
			xf = xf + mvmt.first;
			yf = yf + mvmt.second;
		}
		cout << "YES" << "\n";
		reverse(path.begin(), path.end());
		cout << path.length() << "\n" << path;
	}
	else{
		cout << "NO";
	}
	return 0;

}