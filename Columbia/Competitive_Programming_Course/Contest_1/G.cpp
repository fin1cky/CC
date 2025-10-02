/*
Approach: Elements are "pairwise distinct". In other words, all elements are
unique. Firstly, check if array b is a subsequence of array a. If it isnt, then 
print -1.

Traverse array a and till we find the element equal to the next element in b,
keep track of the number of elements and the highest element encountered in this segment.
If the number of elements is less than k, then that means a fireball is not possible and
only berserk can be done. But in order to berserk, all the elements in that segment
must be less than the one/two elements of b that are the boundaries of this segment. 
(One element case would occur if there are elements in array a to the left of the first 
element that is present in both a and b AND if there are elements in array 
a to the right of the last element that is present in both a and b.)
If the number of elements is greater than or equal to k, at a MINIMUM you will
need (num_elements%k) number of berserk operations because fireball takes out
exactly k elements only. In a segment, since we have no bias towards any element
since the cost is the same for all elements and in a group of unique elements, there
is bound to exist one element that is the greatest among that group, berserk operations
are always possible inside a segment irrespective of whether you include the
boundary elements of b or not. For the remaining, num_elements - (num_elements%k)
elements, there is one filter to consider - is the largest element of the segment
smaller than the one/two elements of b. If yes, you can either do all berserk
or all fireballs but the fireball takes out k elements, so while comparing
the cost, always compare the cost of one fireball with the cost to berserk k elements.
Choose the one that gives the minimum cost. However, if the largest element is greater than
the one/two elements of b, a minimum of one fireball is needed. Since a fireball takes
out k elements, for the remaining (num_element-k) elements, check the cost to
fireball and berserk, and choose the minimum.

Time Complexity: O(n)

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int n, m;
	cin >> n >> m;
	long long int x, k, y;
	cin >> x >> k >> y;
	vector<long long int> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	vector<long long int> b(m);
	for(int i=0; i<m; i++){
		cin >> b[i];
	}
	int j=0;
	for(int i=0; i<n && j<m; i++){
		if(a[i]==b[j]){
			j++;
		}
	}
	if(j!=m){
		cout << -1;
		return 0;
	}

	long long int lval = -1, rval = b[0];
	int lind = -1, rind = 0;
	long long int ans = 0;
	long long int max_in_this_seg = 0;
	long long int num_in_this_seg = 0;
	for(int i=0; i<n+1; i++){
		if((i<n && a[i]==rval) || i==n){
			if(num_in_this_seg > 0){
				if(num_in_this_seg < k){
					if(max_in_this_seg > rval && max_in_this_seg > lval){
						cout << -1;
						return 0;
					}
					else{
						ans += y*num_in_this_seg;
					}
				}
				else{
					long long int min_cost = y*((num_in_this_seg%k));
					num_in_this_seg -= (num_in_this_seg%k);
					long long int num_fireballs = (num_in_this_seg)/k;
					long long int k_berserk_cost = k*y;
					if(max_in_this_seg > rval && max_in_this_seg > lval){
						min_cost += min(num_fireballs*x, x + (((num_in_this_seg-k)/k)*(k_berserk_cost)));
					}
					else{
						min_cost += min((num_in_this_seg/k)*k_berserk_cost, num_fireballs*x);
					}
					ans += min_cost;
				}
			}
			num_in_this_seg = 0;
			max_in_this_seg = 0;
			lval = rval;
			lind = rind;
			if(rind+1<m){
				rind = rind+1;
				rval = b[rind];
			}
		}
		else{
			num_in_this_seg++;
			max_in_this_seg = max(a[i], max_in_this_seg);
		}
	}

	cout << ans;
	return 0;
}