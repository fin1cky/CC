/*
Approach: If the maximum pile is greater than twice the minimum pile, the answer is NO because even
          if we remove only 1 from the min pile and 2 from the max pile, min pile becomes empty while
          max pile is still non-empty. (Constraint 1)
          Suppose we do (-2,-1) operation x number of times and (-1,-2) operation y number of times.
          Let the two piles have a coins and b coins respectively. So, in order for both the piles to reach 0,
          a - 2x - y = 0     ==>  a = 2x + y
          b - 2y - x = 0     ==>  b = 2y + x
          Taking sum, a+b = 3x + 3y = 3(x+y) ==> a+b must be divisible by 3. (Constraint 2)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
    	long long int a,b;
    	cin >> a >> b;
    	if(max(a,b) <= 2*min(a,b)){
            if((a+b)%3==0){
                cout << "YES" << "\n";
            }	
            else{
                cout << "NO" << "\n";
            }
    	}
    	else{
    		cout << "NO" << "\n";
    	}
    }
	return 0;
}