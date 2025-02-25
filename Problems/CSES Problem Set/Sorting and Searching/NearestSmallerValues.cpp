/*
FROM USACO GOLD.

Approach: For every element a_i at index i, we need to find the nearest element a_j at index j 
such that a_j < a_i. Maintain a stack that stores (number, index). Maintain a vector where each
index stores the index of the nearest smaller element, initialize it to 0 so that we dont have to
separately handle cases where current element is smaller than all values before it. 
For each element in input array, keep checking the top value of the stack and popping it until 
the stack is empty or till we reach a top element such that its value is lesser than the current 
element. If we obtain such an element of lesser value, store the position of this element in ans[i]. 
If none of the elements so far have lesser value, we need to store ans[i] = 0 (we dont have to since ans
is initialized with 0). Push the current element into the stack.

If next element is greater than current element --> the top element would be the current element
which is the nearest smaller value. (we are pushing each element to stack, so when we are processing
next element, current element would exist in stack)
If next element is smaller than or equal to current element --> the process described above in approach
will be followed.

Time Complexity: O(n), Each element would be added and removed from stack exactly once.
Space Complexity: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	stack<pair<int, int>> st;
	vector<int> ans(n, 0);
	for(int i=0; i<n; i++){
		while(!(st.empty())){
			pair<int, int> p = st.top();
			if(v[i] > p.first){
				ans[i] = p.second + 1; // 1-based indexing
				break;
			}
			else{
				st.pop();
			}
		}
		st.push(make_pair(v[i], i));
	}

	for(int pos: ans){
		cout << pos << " ";
	}
	return 0;
}