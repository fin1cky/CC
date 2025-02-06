#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	string ans;
	for(int i=0;i<str.length();i++){
		if(str[i]=='N'){
			ans += 'S';
		}
		else if(str[i]=='S'){
			ans += 'N';
		}
		else if(str[i]=='W'){
			ans += 'E';
		}
		else if(str[i]=='E'){
			ans += 'W';
		}
	}
	cout << ans;
	return 0;
}