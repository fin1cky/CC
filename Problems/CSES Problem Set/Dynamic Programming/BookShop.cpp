/*
Approach: Recursive approach choosing whether or not to buy
each book cannot be pursued (though i did try in my earlier submissions)
because if you assume 2 possibilities for each book (to buy vs not to buy),
the complexity becomes O(2^N). Here N can be as large as 1000. 2^1000 is too big
and leads to TLE. Hence, the approach of finding all combinations and then checking the ones
which are within the price limit to determine the best combination that leads to the maximum
number of pages goes out of the window.

Hence, 0/1 knapsack approach is needed. The 2D DP vector has n+1 rows and x+1 columns
where dp[i][j] represents the maximum number of pages that can be obtained from the first 
i books using money j. For each i, traverse the j from 1 to x and for a j such that j >= price of book i,
there are two possibilities - one can either buy the book or not buy the book. In order to obtain the
maximum number of pages, we need to determine if we get more pages from the first i-1 books using the same money j
OR if we get more pages by buying the current book for its price and then from the first i-1 books checking what
can be purchased using money (j - price of current book). For j < price of book i, one cannot afford it so the best
outcome is checking what can purchased from the first i-1 books using the same amount of money j.

We use the "first i" books because it is possible that we buy book k (>i) first and then book i but
ultimately whether we buy book k first and then book i or buy book i first and then book k, we will end up
paying money = price of book i + price of book k to obtain pages = pages of book i + pages of book k. Hence, instead
of accounting for the books purchased so far(maybe using a set or bitset) inorder to make sure we don't use them again,
we will just process the books inorder.

Time Complexity: O(nx)
Space Complexity: O(2X) = O(X) We only need the current book row and the previous book row to performt the
calculations since by definition dp[i][j] represents the maximum number of pages from the "first i books"
using money j.

1st ACCEPTED SUBMISSION DOES NOT HAVE THIS OPTIMIZATION!
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> prices(n+1, 0);
	vector<int> pages(n+1, 0);
	for(int i=1; i<=n; i++){
		cin >> prices[i];
	}
	for(int i=1; i<=n; i++){
		cin >> pages[i];
	}
	// dp[i][j] represents the maximum number of pages
	// that can be bought with all books from 0 to i (inclusive)
	// and money j
	// Optimization: we only need the current row and the previous row to
	// perform our calculation. Interesting observation!
	vector<vector<int>> dp(2, vector<int>(x+1,0));
	for(int i=1; i<=n; i++){ // if i=0 --> 0 books, no book can be bought
		// For the next iteration, set previous row vector to become current row vector
		// Current row vector elements are all initialised to 0
		dp[0] = dp[1];
		for(int j=0; j<=x; j++){
			dp[1][j] = 0;
		}
		for(int j=1; j<=x; j++){ // if j=0 --> 0 money, nothing can be bought
			if(j >= prices[i]){
				// if you have the money to purchase the current book,
				// you have two choices --> buy or don't buy
				// don't buy --> with the same amount of money choose from first i-1 books
				// buy --> buy current book and check from first i-1 books, what can be bought
				// using the remaining money
				dp[1][j] = max(dp[0][j], pages[i] + dp[0][j-prices[i]]);
			}
			else{
				// if you dont have enough money to purchase the current book,
				// then check what you can purchase from the first i-1 books using the
				// same amount of money
				dp[1][j] = dp[0][j];
			}
		}
	}
	// we need to find what is the maximum number of pages that can be bought using
	// the first n books and using x money which will be stored in dp[n][x]
	cout << dp[1][x];
	return 0;
}