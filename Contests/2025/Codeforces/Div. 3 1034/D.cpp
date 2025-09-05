#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int oc = 0;
		string str;
		cin >> str;
		for(int i=0; i<str.length(); i++){
			if(str[i]=='1'){
				oc++;
			}
		}
		if(oc<=k){
			cout << "Alice" << "\n";
		}
		else{
			if(k>(n/2)){
				cout << "Alice" << "\n";
			}
			else{
				cout << "Bob" << "\n";
			}
		}
	}
	return 0;
}