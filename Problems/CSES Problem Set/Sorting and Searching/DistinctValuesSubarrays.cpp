/*
Approach: For every subarray starting at index l and ending at index r, the number 
of subarrays that end at that position is given by r-l+1. The answer to this problem
is the sum of all subarrays with distinct elements that start at index l' and end at
index r' such that l' and r' can take on multiple values between 0 and n and at every time
the value of l' is less than or equal to the value of r'. In this problem, we maintain an 
unordered map to find out the latest position of a particular number 
in the subarray. Everytime we traverse the input array using the right pointer r, 
we try to see if this element has already occurred in the current subarray i.e. 
if the element exists in the unordered map AND its position is greater than or equal to
the beginning position of the current subarray, l. If yes, we update the value of l 
to unordered_map[array[r]] + 1 to denote the beginning of a new subarray with distinct
elements beginning at index l and ending at index r. For every element,
update its position in the unordered_map.

Time Complexity: O(n)

Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	unordered_map<int, int> us;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	int l=0, r=0;
	long long int ans = 0;
	while(r<n){
		if(us.find(v[r]) != us.end() && us[v[r]] >= l){
			l = us[v[r]] + 1;
		}
		ans += r-l+1;
		us[v[r]] = r;
		r++;
	}

	cout << ans;
	return 0;
}