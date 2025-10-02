#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>v(3, 0);
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			if(x==-1){
				v[2]++;
			} 
			else{
				v[x]++;
			}
		}
		int ans = v[0];
		if(v[2]%2==1){
			ans+=2;
		}
		cout << ans << "\n";
	}
	return 0;
}