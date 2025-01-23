/*
Approach: Binary Exponentiation / Modular Exponentiation
We need to find 2^n for large n;
In order to calculate (a^b)%c for large a or b, we cannot do it the conventional way by simple multiplication
or using the pow(a,b) function. So, we need to use binary exponentiation.
In this technique, we consider the binary expansion of b. For example we need to calculate 3^13.
The binary representation of 13 is 1101. So, we can write :
3^13 = 3^(2^0 + 2^2 + 2^3)  = 3^(2^0) * 3^(2^2) * 3^(2^3) = 3*81*6561 (reading bits of 1101 from left to right).
We don't consider the term 3^(2^1) because the corresponding bit in 1101 is not set(it is 0).
Hence, we can observe that whenever the rightmost bit of b is set, b contributes to the answer but
when it is 0, it doesn't. So, we can right shift b for each iteration while it is greater than 0.
We also observe that whenever we go from left to right in a binary representation the current number is the 
square of the previous number but to multiply it or not depends on whether the rightmost bit in b is set. 
To explain this technique simply, suppose we start with the base number and square it with itself as many
times as the length of the power in binary is and store each of the power in an array. Corresponding to the
set bits in the binary representation of the power, we update the result with the corresponding number in 
the array.
Modular exponentiation is based on a*b mod c equiv to ((a mod c)*(b mod c))mod c. Modulo doesn't interfere
with multiplication so we can just include a modulo wherever we see a multiplication. 
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	long long int mod = 1000000007;
	long long int res = 1;
	long long int base = 2; //dealing with binary strings here so only two possibilites : 0 or 1

	while(n>0)
	{
		if(n&1) //if the last bit is set
		{
			res = (res*base)%mod;
		}
		base = (base*base)%mod; //making the numbers squared as we go from left to right in binary repres
		n = n>>1; //right shifting
	}

	cout << res;
	return 0;
}