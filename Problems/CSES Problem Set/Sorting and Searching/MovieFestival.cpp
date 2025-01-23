/*Taking movies which finish early*/

#include <bits/stdc++.h> 
using namespace std;

struct sort_second{
	bool operator()(const pair<int,int> &left, const pair<int,int> &right){
		return left.second < right.second;
	}
};

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
    	int a,b;
    	cin >> a >> b;
    	v.push_back({a,b});
    }
    sort(v.begin(),v.end(),sort_second());
    /*for(int i=0;i<n;i++){
    	cout << v[i].first << " " << v[i].second << "\n";
    }*/
    int count = 0;
    //int start = v[0].first;
    int end = INT_MIN;
    for(int i=0;i<n;i++){
       if(v[i].first>=end){
        //cout << v[i].first << " " << end << endl;
        end = v[i].second;
        count++;
       }
    }
    cout << count << "\n";
	return 0;
}