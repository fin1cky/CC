/*
Approach : count the number of powers of 5 in all numbers from 1 to n;(5,25,125,625.....)
*/

#include <bits/stdc++.h> 
using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int fivepow = 5;
    long long int count = 0;
    while(fivepow<=n){
    	count += n/fivepow;
    	fivepow *= 5;
    }
    cout << count << "\n";
	return 0;
}