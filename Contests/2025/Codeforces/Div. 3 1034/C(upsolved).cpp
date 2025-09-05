/*
Approach: For every array a consisting of two elements ONLY, it is possible to transform
a into a[i] for each element. This is because, one of the two elements is maximum and the 
other is minimum since it is given that all the elements are distinct.
For every element, 
- for the prefix that ends with that element, it can be replaced
by the minimum of all elements in that prefix. For the remaining elements in the
suffix, they can be replaced by the maximum of all the elements in the suffix.
- for the suffix that starts with that element, it can be replaced
by the maximum of all elements in that suffix. For the remaining elements in the
prefix, they can be replaced by the minimum of all the elements in the prefix.

In both cases, we will be left with only two elements in the array and hence, 
it is possible to choose the favourable operation that keeps the current element.
Ofcourse this is the scenario when the current element is either the min element of
the prefix that ends with the current index or the max element of the suffix that
starts with the current index. 

What if that's not the case?
Then, we wont be able to convert a into a[i] since it is not possible to remove
the largest element of the suffix that starts with i or the smallest element of the 
prefix that ends with i without removing the current element a[i]. This is because if 
a[k] for k < i is the smallest element in the prefix and we are claiming there 
is another element that is smaller than a[k], then surely the index of this element 
is after i, so if we choose this prefix, we will also remove a[i]. Similarly, if we remove
a[l] for l > i (the largest element in the suffix) and we are claiming there is another
element that is larger than a[l], then surely the index of this element is before i and if
we choose this suffix, we will also remove a[i].

Suppose we choose a suffix to remove a[k], then this will also remove a[i] since it is
not the largest in the suffix. Likewise, if we choose a prefix to remove a[l],
then this will also remove a[i] since it is not the smallest in the prefix.

So, the first operation that removes one of a[k], a[i], a[l] will also remove a[i] and
hence, it is impossible to convert a into a[i].
*/

#include <bits/stdc++.h> 
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n, 0);
		for(int i=0; i<n; i++){
			cin >> v[i];
		}
		string str(n, '0');
		int minval = INT_MAX;
		for(int i=0;i<n;i++){
			minval = min(minval, v[i]);
			if(v[i] == minval){
				str[i] = '1';
			}
		}
		int maxval = INT_MIN;
		for(int i=n-1;i>=0;i--){
			maxval = max(maxval, v[i]);
			if(v[i] == maxval){
				str[i] = '1';
			}
		}
		cout << str << "\n";
	}
	return 0;
}