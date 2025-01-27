#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long double> v(n, 0);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	if(n==2){
		cout << "Yes";
	}
	else{
		bool flag = true;
		for(int i=1;i<n-1;i++){
			long double midterm = v[i]*v[i];
			long double firstlast = v[i-1]*v[i+1];
			if(midterm != firstlast){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "Yes";
		}
		else{
			cout << "No";
		}
	}
	return 0;
}