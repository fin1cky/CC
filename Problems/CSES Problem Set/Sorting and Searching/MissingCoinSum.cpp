/*
Initially sort the given list of +ve numbers. If the smallest number is not 1, then obviously the answer is 1.
If it is 1, then initialise the variable sum to 1(till now it is the only number we have)
and the variable ans to the next smallest number which is 2(=sum+1). Iterate over the vector to the next 
element. If this element is lesser than or equal to ans, update sum by adding this element to it and update  
ans equal to sum+1 (because it is possible to create subsets which give sums from 1 to sum of all elements 
in the subset) and go to the next element in the vector. Otherwise, print ans because if the number is greater 
than ans(=sum+1) it means that there lies a smallest number equal to sum+1(=ans) before the element which is 
the required answer.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
    	cin >> v[i];
    }
    sort(v.begin(),v.end());
    long long int sum = v[0];
    if(sum!=1){
    	cout << 1 << "\n";
    	return 0;
    }
    long long int ans = sum+1;
    for(int i=1;i<n;i++){
    	if(v[i]<=ans){
    		sum+=v[i];
    		ans = sum+1;
    	}
    	else{
    		break;
    	}
    }
    cout << ans << "\n";
	return 0;
}