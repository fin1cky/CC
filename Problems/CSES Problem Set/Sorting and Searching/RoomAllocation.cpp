/*
Approach: Maintain a vector where for each entry you store two times - 
{start_time, 0, index_pos} and {end_time, 1, index_pos}. 0 denotes check-in
and 1 denotes check-out. Sort this vector by the increasing order of start time
and for tie-break, use the check-in/check-out such that check-in is given more
priority since the question states that "Two customers can stay 
in the same room if the departure day of the first customer 
is earlier than the arrival day of the second customer.". Maintain another
vector rooms (initialized as empty) to store the rooms that were vacated. 
Now traverse this vector and every time we have type check-in, check if there
are any vacated rooms that can be allotted to a customer. If not, increase the number
of new rooms and allot the new room to the customer. If there are vacated rooms,
allot one of them to the customer and pop it from the rooms vector. Every time we have
type check-out, then it means we need to get the room that is being vacated and push
it to the rooms vector.

Time Complexity: O(nlogn)

Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

bool comparator(const vector<int>& a, const vector<int>& b){
	if(a[0] == b[0]){
		return a[1] < b[1];
	}
	return a[0] < b[0];
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> v;
	for(int i=0; i<n; i++){
		int s, e;
		cin >> s >> e;
		v.push_back({s, 0, i+1});
		v.push_back({e, 1, i+1});
	}
	vector<int> ans(n+1, 0);
	vector<int> rooms;
	sort(v.begin(), v.end(), comparator);
	int room = 0;
	for(vector<int> vv: v){
		if(vv[1] == 0){
			int room_to_allot = -1;
			if(rooms.size() > 0){
				room_to_allot = rooms.back();
				rooms.pop_back();
			}
			else{
				room++;
				room_to_allot = room;
			}
			ans[vv[2]] = room_to_allot;
		}
		else{
			int allotted_room = ans[vv[2]];
			rooms.push_back(allotted_room);
		}
	}
	cout << room << "\n";
	for(int i=1; i<=n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}