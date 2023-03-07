/*
Approach : In this question the order matters. So, everytime we pickup a cube from the input vector,
we need to check the smallest cube that is larger than the current cube so that we can place the
current cube on this larger cube to make a tower. It makes sense to use the smallest cube which is
larger than the current cube because if we place it on any other larger cube, there is a chance that
if we get a cube bigger than the current cube later, we may not have a place to place it on top of
existing cubes and we have to increase the number of towers which is against the requirement of
building the minimum number of towers. So, we use upper_bound to find the smallest cube that is larger
than the current cube and place the current cube on top of this cube. We need to update the value
to the current cube since the cube on top is smaller than before.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long long int> v(n,0);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	vector<long long int> ans;
	vector<long long int>::iterator it = ans.begin();
	for(int i=0;i<n;i++){
		it = upper_bound(ans.begin(),ans.end(), v[i]);
		if(it != ans.end()){
			int index = it-ans.begin();
			ans[index] = v[i];
		}
		else{
			ans.push_back(v[i]);
		}
	}
	cout << ans.size();
	return 0;
}