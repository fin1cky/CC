/*
Median : mid-point by position of the array (NOT by value). 
The median is the value separating the higher half from the lower half of a data sample. 
Median gives you the shortest sum of distance from other nodes to it.
Given a series of points, let us  say we have a random point x. Suppose there are m points to the left of x
and n points to the right of x. If we move x to the right by 1 unit, we would be 1 unit away from all m points 
to the left of x and 1 unit closer to all the n points to the right of x. Therefore sum increases by m and
decreases by n. New_sum = Old_sum + m - n. As long as the value of n is greater than m, we should keep
moving right because it will reduce the sum. Only when m = n, the New_sum and Old_sum will remain the same
and by definition, this point is the Median. Note that further moving right will only increase the sum because
now m > n.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> lengths(n);
    for(int i=0;i<n;i++){
    	cin >> lengths[i];
    }
    sort(lengths.begin(),lengths.end());
    long long int ans = 0;
    for(int i=0;i<n;i++){
    	ans += abs(lengths[i] - lengths[n/2]);
    }
    cout << ans << "\n";
	return 0;
}