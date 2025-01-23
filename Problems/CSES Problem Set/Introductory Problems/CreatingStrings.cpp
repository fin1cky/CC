#include <bits/stdc++.h>
using namespace std;
int n;
vector<string>v;
int ch[26]={};

void solve(string curr){
	if(curr.length()==n){
		v.push_back(curr);
		return;
	}
    for(int i=0;i<26;i++){
        if(ch[i]>0){
        	ch[i]--;
        	solve(curr+(char)('a'+i));
        	ch[i]++;
        }
    }
}


int main(){
    string str;
    cin >> str;
    n = str.length();
    for(int i=0;i<n;i++){
    	ch[str[i]-'a']++;
    }
    solve("");
    cout << v.size() << endl;
    for(auto it:v){
    	cout << it << endl;
    }
    /* //using next_permutation
    sort(str.begin(),str.end());
    do{
        v.push_back(str);
    }while(next_permutation(str.begin(),str.end()));
    */
	return 0;
}