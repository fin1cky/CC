#include <bits/stdc++.h>
using namespace std;
int ans = 0;
string inp[8];
bool col[8];
bool diag1[15];//bottom left to top right diagonal=(x+y)
bool diag2[15];//bottom right to top left diagonal=(x-y+n-1) where n is number of rows/queens

void backtrack(int row){//placing queen in that row
	if(row==8){
		ans++;// we found for last row also, so search can be stopped
		return;
	}
	for(int i=0;i<8;i++){
       if(inp[row][i]=='.'&&!col[i]&&!diag1[row+i]&&!diag2[i-row+7]){
       	col[i] = diag1[row+i] = diag2[i-row+7] = true;
       	backtrack(row+1);
       	col[i] = diag1[row+i] = diag2[i-row+7] = false;
       }
	}
}

int main(){
    for(int i=0;i<8;i++){
    	cin >> inp[i];
    }
    backtrack(0);
    cout << ans << endl;
	return 0;
}