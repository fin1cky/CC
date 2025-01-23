/*
Two approaches are possible. This is approach 2. Refer the other file for approach 1.
This is an algorithmic approach in contrast to the earlier recursive one. To generate gray code strings
from the existing binary code strings, take the first bit of the binary string as it is. Then from the
second bit onwards, the bit value is equal to the xor of the corresponding bit and the previous bit in the 
binary string.
Example for length 2 :
Binary      Gray Code
0 0         0 0 ( xor of 0 and 0 is 0)
0 1         0 1 ( xor of 0 and 1 is 1)
1 0         1 1 ( xor of 1 and 0 is 1)
1 1         1 0 ( xor of 1 and 1 is 0)
*/
#include <bits/stdc++.h>
using namespace std;

bool bitvalue(int number,int position){ //function which gives bit of number at any given position
	return (number&(1<<position));
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<(1<<n);i++){//for all values from 0 to n-1
    	cout << bitvalue(i,n-1);//first bit of binary string
    	for(int j=n-2;j>=0;j--){//going from n-2 because in bitvalue func we left shift by j value  
    		cout << (bitvalue(i,j)^bitvalue(i,j+1));//xor of current bit and previous bit (when we go from left
    	}                                           // to right, the left shift value decreases, so previous bit
        cout << "\n";                               //would be at j+1 position
    }
	return 0;
}