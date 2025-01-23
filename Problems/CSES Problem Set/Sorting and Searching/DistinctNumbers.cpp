 #include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<long long int>s;
    for(int i=0;i<n;i++){
    	long long int x;
    	cin >> x;
    	s.insert(x);	
    }
    cout << s.size();
	return 0;
}