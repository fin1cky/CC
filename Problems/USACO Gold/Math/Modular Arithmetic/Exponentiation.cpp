/*
Approach: Binary Exponentiation. Every power can be written in its binary form.
3^13 = 3^(1101 in binary) = (3^1) * (3^4) * (3^8). Since the 2nd last bit is 0,
we do not use 3^2. Notice that in every term, the power is simply the square
of the previous power. 
Traverse this binary form, right shifting it bit by bit. While it is greater than 0,
check if the last bit is set, then it means that number raised to (2^(position of this bit)) 
is used to perform exponentiation (which we can keep track of by squaring the base number
in every loop run), multiple the ans variable with this value.
Since mod needs to be used, include it in every multiplication.
(a*b)%mod = ((a%mod)*(b%mod))%mod --- if you apply this to the final result and trace the steps
backwards, you will begin to see why %mod can be applied anywhere there is multiplication.
*/

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

long long binexp(long long int x, long long int y){
	long long ans = 1;
	while(y > 0){
		if(y&1){
			ans = ((ans%mod) * (x%mod)) % mod;
		}
		x = ((x%mod)*(x%mod)) % mod;
		y = y >> 1;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	while(n--){
		long long int a, b;
		cin >> a >> b;
		// cout << a << b;
		long long int ans = binexp(a,b);
		cout << ans << "\n";
	}
	return 0;
}