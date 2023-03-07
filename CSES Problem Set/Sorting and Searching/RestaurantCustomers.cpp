#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<long long int,long long int>>v;
    for(int i=0;i<n;i++){
    	long long int x,y;
    	cin >> x >> y;
    	v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    vector<pair<long long int,int>>v2;
    for(int i=0;i<n;i++){
    	v2.push_back({v[i].first,1});
    	v2.push_back({v[i].second,2});
    }
    sort(v2.begin(),v2.end());
    /*for(int i=0;i<v2.size();i++){
        cout << v2[i].first << " ";
    }*/
    //cout << endl;
    int oc=0,tc=0;
    int ans = 0;
    for(int i=0;i<v2.size();i++){
    	if(v2[i].second==1){
    		oc++;
    		ans = max(ans,oc);
    	}
    	else{
            oc--;
    	}
    }
    cout << ans << "\n";

	return 0;
} 