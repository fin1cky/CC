/*
Approach: My first accepted solution was not optimal. This is the approach recommended
in the editorial. The idea is to find the first occurrence of "AB" and then to the right
of it find the occurrence of "BA". If this does not give us a result, then try to find
the first occurrence of "BA" and then to the right of it find the occurrence of "AB".
If that is also not found, then just return "NO".

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	int n = str.length();
	
	for(int i=0; i<n-1;){
		if(str[i]=='A' && str[i+1]=='B'){
			for(int j=i+2; j<n-1; j++){
				if(str[j]=='B' && str[j+1]=='A'){
					cout << "YES";
					return 0;
				}
			}
		}
		i++;
	}

	for(int i=0; i<n-1;){
		if(str[i]=='B' && str[i+1]=='A'){
			for(int j=i+2; j<n-1; j++){
				if(str[j]=='A' && str[j+1]=='B'){
					cout << "YES";
					return 0;
				}
			}
		}
		i++;
	}

	cout << "NO";
	return 0;
}