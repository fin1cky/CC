/*
Sorting 1,2,3,....,n is equivalent to sorting 0,1,2,....,n-1. So we perform a v[i]-- for each element to avoid
hassles wrt 0-based indexing. Then we store the positions of each number in a second vector. and traverse it
intially beginning with the number 1 since we need to collect in ascending order. We can move to the next 
element only if its position is to the right of the current number i.e. having a greater index. Otherwise,
if it lies to the left of the number, we have to make another round because its index is lesser than the current
index. This way we increment the count variable. Its initial value is 1, because the least number of rounds 
is 1 which would happen if all the numbers are already arranged in an ascending order. 
*/

#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
    	cin >> v[i];
    	v[i]--;
    }
    vector<int> position(n);
    for(int i=0;i<n;i++){
    	position[v[i]] = i;
    }
    int count = 1;
    for(int i=1;i<n;i++){
    	if(position[i]<position[i-1]){ //if current number lies to left of previous number
    		count++;
    	}
    }
    cout << count << "\n";
	return 0;
}