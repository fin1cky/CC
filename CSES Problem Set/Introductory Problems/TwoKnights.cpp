/*
Approach: Solving by the Inclusion-Exclusion Principle

A : Total number of ways we can place two knights on a k X k chess board,
    which is equal to (k*k)C2 = ((k*k)(k*k - 1))/2

B : Total number of ways we can place two knights such that they attack each other
    We can observe that whenever there's a 2 X 3 or a 3 X 2 segment of a chessboard, for each
    such segment, knights can be placed in two ways such that they attack each other.
    Number of 2 X 3 segments = (k-1)*(k-2)
    Number of possible ways = 2*(k-1)*(k-2)
    Similarly, the number of 3 X 2 segments = (k-2)*(k-1)
    Number of possible ways = 2*(k-2)*(k-1)
    Total number of ways = 2*(k-1)*(k-2) + 2*(k-2)*(k-1) = 4*(k-1)*(k-2)

Final answer : A - B
               which is ((k*k)(k*k - 1))/2 - 4*(k-1)*(k-2)

Because of k^4, max value of n can be 10^4 only as long long int takes max value approx 10^18.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(long long int k = 1;k <= n;k++){
		cout << ((k*k)*(k*k - 1))/2 - 4*(k-1)*(k-2) << "\n";
	}
	return 0;
}