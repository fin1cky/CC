/*
Approach: First encounter of a problem do +2 otherwise do +1.

Time Complexity: O(nlogn)

Space Complexity: O(n)

O(n), O(1) sol possible with vector.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string str;
		cin >> str;
		set<char> s;
		int ans = 0;
		for(int i=0; i<str.length(); i++){
			int x = s.size();
			s.insert(str[i]);
			int y = s.size();
			if(y>x){
				ans+=2;
			}
			else{
				ans+=1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}