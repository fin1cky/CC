/*
Approach 2: Let m be the MEX of the original array. If we remove any element, the
MEX may decrease or remain the same but certainly, it is NOT going to increase
and become greater than m. So, the upper bound for the MEX values is m.
Further, for a number x to be the MEX of the array, the frequency of occurrence of 
this number must be less than or equal to k because, we need to remove all instances
of x for it to be a possible MEX. Hence, freq(x) <= k. Also, if we remove k elements
from an array having n elements in total, the size of the array = the remaining number
of elements in the array becomes n-k. We need x to be <= n-k because if x is greater
than the size of the array, then x cannot be the MEX of the array since even in the 
case with no duplication, the array would be 0,1,...,n-k-1 with n-k elements and the
MEX of this array is n-k. So, if x > n-k, then certainly, it cannot be the MEX of the
array. These are the three conditions that must be satisfied in order for x to be the
MEX of the array.

x <= n-k implies k <= n-x. Hence, freq(x) <= k <= n-x.
So, calculating the values of freq(x) and n-x for a given x from x = 0 to x = n,
gives us k belongs to [freq(x), n-x]. These is the range for the values of k for which
element x can be the MEX. But doing +1 across this range for every x is time-consuming.
Hence, we use a difference array and do a range update first (and then do prefix sum after all updates):
diff[L]++ and diff[R+1]--. This means that we need to add 1 to the range [L,R].
intuition: at index L, we start adding the value and at index R+1, we cancel the effect
so that the added value accumulates from L to R when we do prefix sum and then stops at R+1.

NOTE: We process x as a possible MEX even if x is missing because a valid MEX means 
x is not present. But we stop after that because the next MEX candidate (x+1) 
would require x to be present, and it’s not. 


*/

#include <bits/stdc++.h> 
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		map<int, int> freq;
		for(int i=0; i<n; i++){
			cin >> v[i];
			freq[v[i]]++;
		}
		vector<int> diff(n+2); // 0 to n requires size n+1, but to process n-0+1, we need index n+1 too
		for(int i=0; i<=n; i++){
			diff[freq[i]]++; // freq[i] creates a key in the map
			diff[n-i+1]--;
			if(freq[i]==0){ // freq.find wont work because the key gets created, which is why we check for value = 0
				break; // read NOTE to understand why this check happens after the range update
			}
		}
		vector<int> ans(n+1);
		ans[0] = diff[0];
		for(int k=1; k<=n; k++){
			ans[k] = ans[k-1] + diff[k];
		}

		for(int i=0; i<=n; i++){
			cout << ans[i] << " ";
		}

		cout << "\n";
	}
	return 0;
}

