/*
Approach: The sum of 1, 2, ..., n numbers is (n*(n+1))/2. If we divide these numbers
into two sets (S1 and S2) having equal sum, the sums of these sets will be ((n*(n+1))/2)/2
which is (n*(n+1))/4. In other words, (n*(n+1)) must be divisible by 4, inorder for
the numbers to be divided into two sets of equal sum. We can show that it is possible
each time for a given sum to generate only one of the two sets to determine the other set.
This is because, since the numbers are limited (from 1 to n), if we know the elements
in one set S1, we can easily determine the numbers in the other set S2. So, our problem is
now to find the number of sets that sum up to (n*(n+1))/4. 

Using brute force, we can generate all sets for a given n and then find the ones
that sum up to the required sum. But this process is O(2^n) which will be TLE for
n=500. However, if we notice, the maximum sum we need to find the number of sets for
is only (500*501)/4 which is of the order ~ O(10^5) which is good. So, for every element
from 1 to n, we only need to check from (n*(n+1))/4 to element, how many sums can be generated
using the elements from 1 to current element (knapsack approach). The previous values in the list
represent the case when we dont take the current element. When we add the value of the current element, we will be 
generating new sets whose sums can be from 1 to sum of all element from 1 to current element. In this list, at each position,
we are storing the NUMBER of sets formed using elements from 1 to current element (we will not be using all of them every time) whose
sum is equal to that position. Once we finish this loop for n, the element at position (n*(n+1))/4 
will contain the number of sets formed using numbers from 1 to n whose sum is (n*(n+1))/4. 

But thats not the case!! We will be finding ALL the sets whose sum is (n*(n+1))/4 which means
that this will include both S1 and S2. So, we need to divide the final value by 2.

But thats not the correct thing to do either! This is because, we are using modulo to store the
values and we need ((a/b) % mod) but we currently have (a%mod) and simply dividing by (b%mod) is 
not correct since ((a/b) % mod) is NOT EQUAL to ((a%mod)/(b%mod)). 

We can write ((a/b) % mod) as (a*(b^(-1)))/((b*(b^(-1))) % mod = (a*(b^(-1)))/1 % mod = ((a%mod) * ((b^(-1))%mod))%mod.
b^-1 is the modular inverse of b such that b*(b^(-1)) is congruent to 1 % mod. From Fermat's
Little Theorem, when mod is prime, and mod and b are co-prime, then b^(mod-1) = b*b^(mod-2) is congruent to 1 % mod. So,
here b^(-1) is b^(mod-2). For b=2, that is 2^(mod-2).

Hence, the final answer is value at index (n*(n+1))/4 multiplied by 2^(mod-2).
*/

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

long long int bin_exp(long long int base, long long int exponent){
	if(exponent==0){
		return 1;
	}
	long long int res = 1;
	while(exponent > 0){
		if(exponent&1){
			res = ((res%mod) * (base%mod))%mod;
		}
		base = ((base%mod)*(base%mod))%mod;
		exponent = exponent/2;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	int total_sum = (n*(n+1))/2;
	if(total_sum%2 != 0){
		cout << 0;
	}
	else{
		int sum_of_each_set = total_sum/2;
		vector<int> dp(sum_of_each_set+1, 0);
		dp[0] = 1;
		for(int num=1; num<=n; num++){
			for(int j=sum_of_each_set; j>=num; j--){
				dp[j] = (dp[j] + dp[j-num])%mod;
			}
		}
		long long int mod_inv_of_two = bin_exp(2, mod-2); //fermat's little theorem
		long long int ans = ((dp[sum_of_each_set]%mod) * (mod_inv_of_two%mod))%mod; 
		cout << ans;		
	}
	
	return 0;
}