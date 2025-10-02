/*
Approach: Simulation, find the number such that all its non-zero digits can
divide it.

Time Complexity: LCM of 1,2, .. , 9 is 2520. So if we simulate to the next multiple
of 2520, any digit from 1 to 9 can divide the number. So, O(19 * 2520) --> 19 to scan
length of 1e18. So, O(1).

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long int n;
		cin >> n;
		long long int ans = -1;
		while(true){
			long long int k = n;
			bool flag = true;
			while(k>0){
				int x = k%10;
				k /= 10;
				if(x!=0 && n%x!=0){
					flag = false;
					break;
				}
			}
			if(flag){
				ans = n;
				break;
			}
			n++;
		}
		cout << ans << "\n";
	}
	return 0;
}