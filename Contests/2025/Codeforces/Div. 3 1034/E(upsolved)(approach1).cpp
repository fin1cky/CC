/*
Approach 1: Let m be the MEX of the original array. If we remove any element, the
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

Now, we need to remove k elements from the array meaning that we need to keep
n-k elements. We must not choose any occurrence from the freq(x) occurrences of x.
So, there are n-freq(x) elements to choose n-k elements from. We know that k > freq(x)
since it is a constraint for x to be the MEX. This means that n-k < n-freq(x) which
implies that it is definitely possible to choose n-k elements without using any
occurrence of x.

For each k, we store all possible MEX values in a set after removing k elements. 
As the value of k changes, what happens to this set? Suppose k changes from k-1 to k. Since, for an element
to be a possible MEX, it must be <= n-k, earlier this value was n-(k-1). Now, n-(k-1)
is greater than n-k, hence this particular element must be removed from the set. Also,
for an element to be a possible MEX, freq(element) <= k. Earlier it was freq(element) <= k-1.
So, all elements whose freq is k and element is <= m and element is <= n-k can be 
inserted into the set. The size of the set is the answer of the number of 
possible values of MEX at that k.
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
		set<int> nums;
		for(int i=0; i<=n; i++){
			nums.insert(i);
		}
		for(int i=0; i<n; i++){
			cin >> v[i];
			freq[v[i]]++;
			nums.erase(v[i]);
		}
		int mex = *nums.begin();
		map<int, vector<int>> inverse_freq;
		for(pair<int,int> p: freq){
			inverse_freq[p.second].push_back(p.first);
		}
		set<int> vals;
		vals.insert(mex);
		for(int k=0; k<=n; k++){
			vals.erase(n-(k-1));
			for(int i: inverse_freq[k]){
				if(i <= mex and i <= n-k){
					vals.insert(i);
				}
			}
			cout << vals.size() << " ";
		}
		cout << "\n";
	}
	return 0;
}