#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> mods(4, 0);
		for(int i=0;i<n;i++){
			mods[i%4]++;
		}
		if(mods[0]==mods[3] and mods[1]==mods[2]){
			cout << "Bob" << "\n";
		}
		else{
			cout << "Alice" << "\n";
		}
	}
	return 0;
}