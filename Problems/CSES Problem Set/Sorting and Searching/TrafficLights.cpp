/*
Approach: My original solution involving priority queue + lazy deletion was 
logically correct but it is too slow performance-wise and it TLEd. For this problem,
it is better to use multiset that supports multiple duplicate elements and in sorted 
order and has insert/find/erase operations in O(log n) time. The idea is to maintain
a set to store positions of the traffic lights and a multiset to store the distances.
Whenever, we get a position, we need to determine at what position it will be present
on the street. For that we can use lower_bound(pos) to get the next best position and 
use prev to get the element at the position before it. These two positions will help
us understand where the current traffic light will be situated. Now, since there is
a new traffic light in between the two previous traffic lights, the distance between
them needs to be removed and the two new distances namely new-prev and next-prev need
to be added to the multiset. The new pos needs to be added to the set. We can simply use
*rbegin() to get the current largest element of the multiset.

Time Complexity: O(nlogn)

Space Complexity: O(n) 
*/

#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int x, n;
	cin >> x >> n;
	set<int> s;
	s.insert(0);
	s.insert(x);
	multiset<int> lens;
	lens.insert(x-0);

	for(int i=0; i<n; i++){
		int p;
		cin >> p;
		auto it = s.lower_bound(p);
		int next_bigger = *it;
		int prev_smaller = *prev(it);
		s.insert(p);
		auto old = lens.find((next_bigger-prev_smaller));
		lens.erase(old);
		lens.insert(p-prev_smaller);
		lens.insert(next_bigger-p);
		cout << *lens.rbegin() << " ";
	}
	return 0;
}