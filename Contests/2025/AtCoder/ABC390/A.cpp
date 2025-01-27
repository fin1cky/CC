#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v = {1,2,3,4,5};
	vector<int> inp(5, 0);
	for(int i=0; i<5; i++){
		cin >> inp[i];
	}
	int count = 0;
	bool flag = true;
	for(int i=0; i<4;){
		if(v[i] != inp[i]){
			if(count == 0 && v[i]==inp[i+1] && v[i+1]==inp[i]){
				count += 1;
				i+=2;
			}
			else{
				cout << "No";
				return 0;
			}
		}
		i++;
	}
	if(count == 1){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	return 0;
}