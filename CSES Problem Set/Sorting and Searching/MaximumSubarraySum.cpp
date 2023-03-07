/*Kadane's Algorithm : Let go of the past(sum here) when it becomes a burden*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long int>v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
    	v.push_back(x);
    }
    long long int best = v[0];
    long long int sum = v[0];
    for(int i=1;i<n;i++){
    	sum = max(sum+v[i],v[i]);
    	best = max(sum,best);
    }
    cout << best << "\n";
	return 0;
}