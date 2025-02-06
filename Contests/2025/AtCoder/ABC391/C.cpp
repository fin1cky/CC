#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,q;
	cin >> n >> q;
	vector<int> pigeons(n+1);
	map<int,int> holes;
	int ans = 0;
	for(int i=1;i<=n;i++){
		pigeons[i] = i;
		holes[i] = 1;
	}
	for(int i=1;i<=q;i++){
		int type;
		cin >> type;
		if(type == 1){
			int pigeon_num, hole_num;
			cin >> pigeon_num >> hole_num;
			int pigeon_hole = pigeons[pigeon_num];
			pigeons[pigeon_num] = hole_num;
			holes[pigeon_hole]--;
			if(holes[pigeon_hole]==1){
				ans--;
			}
			if(holes[hole_num]==1){
				ans++;
			}
			holes[hole_num]++;
		}
		else{
			cout << ans << "\n";
		}
		// cout << type << ": ";
		// for(auto x: holes){
		// 	cout << x.second << " ";
		// }
		// cout << "\n";
		// cout << "ans: " << ans << "\n";
	}
	return 0;
}