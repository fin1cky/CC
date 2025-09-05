/*
Approach: In any permutation, 1 will be a guaranteed fixed point. Apart from that,
the other fixed points are prime numbers pn such that 2*pn > n. For any set of numbers
containing more than 1 element and share a common factor y, we can easily arrange 
the numbers such that the gcd(num, pos) > 1 like a+y, a+2y, a+3y, ..., a. The optimal
way to build this set of numbers would be to traverse starting with the largest prime till
2, collect all the multiples of the prime number including itself and include all of them 
in this set and arrange them as discussed. It is a better idea to traverse from larger primes to smaller primes so that we prevent
adding the same number to multiple sets and risking the chance of creating more fixed
points by taking away numbers that have multiple prime factors from the largest prime
meaning their set cannot be arranged leading to the formation of a fixed point. We place
a number in its most restrictive group. We do not have to worry about a lower prime
being a fixed point because. Lets say there are two primes c and d such that d > c.
Now, if we are worried about d*c going to the set containing d and not the set 
containing c, we can rest assured that c*c < d*c and since c is prime, c*c will definitely
be the part of the group containing c and since it has more than 1 element in its group
it can be arranged so that it is good.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nums(1e5+1, 0);
vector<int> primes;

void sieve(){
	for(int i=2; i*i<=1e5; i++){
		if(nums[i]==0){
			for(int j=i*i; j<=1e5; j+=i){
				nums[j] = 1;
			}
		}
	}

	for(int i=2; i<=1e5; i++){
		if(nums[i]==0){
			primes.push_back(i);
		}
	}
}

void solve(int n){
	vector<int> p(n+1, 0);
	sort(primes.rbegin(), primes.rend());
	for(int prime: primes){
		vector<int> multiples;
		for(int i=prime; i<=n; i+=prime){
			if(p[i]==0){
				multiples.push_back(i);
			}
		}
		int m = multiples.size();
		for(int i=0; i<m; i++){
			p[multiples[i]] = multiples[(i+1)%m];
		}
		
	}
	for(int i=1; i<=n; i++){
		if(p[i] == 0){
			cout << i << " ";
		}
		else{
			cout << p[i] << " ";
		}
	}
	cout << "\n";
}

int main(){
	sieve();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		solve(n);
	}
	return 0;
}