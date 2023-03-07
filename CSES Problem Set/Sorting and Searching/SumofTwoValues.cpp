/* Using simple two pointer approach */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
    	int x;
    	cin >> x;
    	v.push_back({x,i+1});
    }
    sort(v.begin(),v.end());
    /*for(int i=0;i<n;i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }*/
    int l = 0;
    int r = n-1;
    bool flag = false;
    while(l<r){
    	if(v[l].first + v[r].first == x){
    		cout << v[l].second  << " " << v[r].second  << "\n";
    		flag = true;
    		break;
    	}
    	else if(v[l].first + v[r].first > x){
    		r--;
    	}
    	else{
    		l++;
    	}
    }
    if(!flag){
    	cout << "IMPOSSIBLE" << "\n";
    }
	return 0;
}