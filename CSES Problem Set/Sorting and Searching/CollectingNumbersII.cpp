/*
Inversion : x < x+1 but position[x] >  position[x+1]
For the intial given list proceed in the same way as CollectingNumbers.cpp.
Then onwards, find the possible pairs of the two numbers that are being swapped : 
1. (number1-1,number) 2. (number1,number1+1) 3. (number2-1,number2) 4. (number2,number2+1)
These are the only 4 pairs which will be affected by the swap because from our solution in
CollectingNumbers.cpp, we only check for the positions of the immediate numbers in the position vector.
Here the numbers being swapped can each be in that scenario only twice - 
1. it is the next number to a number before it  2. there is another number after itself
which is why there is a maximum of only 4 possible pairs (2 for each -> 2+2=4)
Because we would be swapping, we have to REMOVE the existing inversions among the possible pairs (which only 
exist because of the current configuration -- once they swap there will be a different configuration with respect
to the immediate numbers before and after it. here immediate numbers mean numbers before and after it as on
a number line NOT how they occur in the numbers vector. WHY? because our position vector follows that configuration) 
before we swap the numbers which is why we subtract the number of inversions from the answer.
Then we swap the positions of the numbers and then swap the numbers.
Then we again check for inversion among the pairs and add 1 to the answer for every inversion.
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>numbers(n+1);
    vector<int>position(n+1);
    for(int i=1;i<=n;i++){
    	int x;
    	cin >> x;
    	numbers[i] = x;
    	position[numbers[i]] = i;
    }
    int ans = 1;
    for(int i=1;i<n;i++){
    	if(position[i]>position[i+1]){
    		ans++;
    	}
    }
    set<pair<int,int>>possiblePairs;
    int l,r;
    for(int i=1;i<=m;i++){
    	cin >> l >> r;
    	if(numbers[l]<n){
    		possiblePairs.insert({numbers[l],numbers[l]+1});
    	}
    	if(numbers[l]>1){
    		possiblePairs.insert({numbers[l]-1,numbers[l]});
    	}
    	if(numbers[r]<n){
    		possiblePairs.insert({numbers[r],numbers[r]+1});
    	}
    	if(numbers[r]>1){
    		possiblePairs.insert({numbers[r]-1,numbers[r]});
    	}
        for(pair<int,int>swapped : possiblePairs){
        	if(position[swapped.first]>position[swapped.second]){
        		ans--;
        	}
        }
        position[numbers[l]]=r;
        position[numbers[r]]=l;
        swap(numbers[l],numbers[r]);
        for(pair<int,int>swapped : possiblePairs){
        	if(position[swapped.first]>position[swapped.second]){
        		ans++;
        	}
        }
        cout << ans << "\n";
        possiblePairs.clear();
    }
	return 0;
}