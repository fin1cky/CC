/*
Approach: This is a greedy problem. The value you get from any gap is the same and
each gap decreases at the same rate. Simply sort ALL the gaps in decreasing order. 
Calculate the amount of gap that is still alive. Since the infection spreads from
both sides of a gap, at each time for a gap, the alive part is gap - 2*time.
- If this part is greater than 1, then on the first day, we can save one of the ends 
of the gap first, then the other end of the gap gets infected and then on the second
day, we can save the new other end of the gap and the infection spreads elsewhere but
in this part, we have basically saved gap - 2*time - 1. 
- If this part is equal to 1, since we can save before the infection spreads, we can
save 1.
- If this part is less than or equal to 0, there is nothing left to be saved and since
we are using a max heap, we can stop the loop.

The answer we need to report is the number of infected houses, so answer is 
number of houses - number of saved houses.

Time Complexity: O(mlogm)

Space Complexity: O(m)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long int n, m;
		cin >> n >> m;
		vector<long long int> v(m);
		priority_queue<long long int, vector<long long int>> pq;
		for(long long int i=0; i<m; i++){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for(long long int i=1; i<m; i++){
			if(v[i] - v[i-1] - 1 > 0){
				pq.push((v[i] - v[i-1]-1));
			}
		}
		if(v[0]-1 + n-v[m-1] > 0){
			pq.push((v[0]-1 + n-v[m-1]));
		}

		long long int time = 0;
		long long int ans = 0;
		while(pq.size() > 0){
			long long int x = pq.top();
			pq.pop();
			long long int alive = x - 2*time;
			if(alive>1){
				ans += (alive-1);
				time += 2;
			}
			else if(alive==1){
				ans += 1;
				time += 1;
			}
			else{
				break;
			}
		}
		cout << n-ans << "\n";
	}
	return 0;
}