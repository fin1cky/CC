/*
Two approaches are possible. This is approach 1. Refer the other file for approach 2.
This solution is built for string of length n assuming that we have the solution for string of length n-1.
Every time a binary string's length increases by 1, the number of possible strings become double of the
previous count.

Suppose we need to find sequence of length 5 gray code.
There are 32 binary strings of length 5 and 16 binary strings of length 4. So, we can model
strings of length 5 as 16 strings having first bit as 0 followed by the length 4 binary strings and 16 strings
having first bit as 1 followed by the length 4 binary strings (16+16 = 32). However, we have assumed that
the sequence of length 4 binary strings already follow the gray code hamming distance rule. The only place 
where the problem occurs is when going from the 16th binary string which starts with 0 and the 17th binary
string which starts with 1. Here, the hamming distance is not 1 because the last string of length 4 gray codes
is followed by the first string of length 4 gray codes. It looks like :

0 . . . . . . . . <----                   
0                     |
0                     |
.                     |
.                     |  These two dotted strings will be same. Therefore, the 16th (0 .....) binary
.                     |  string and the 17th (1 .....) binary string will differ in more than one bit.
0 . . . . . . . .     |    
1 . . . . . . . . ____| 
1
.
.
.
1

To counter this problem, for strings starting with 1, we flip the sequence of length 4 gray codes. Now,
the 16th and the 17th binary strings will differ in only place which is the first bit(0 and 1) and from the
18th string onwards, the gray code condition is satisfied since the strings will always differ in one bit
if we go top to bottom or bottom to top.
*/

#include <bits/stdc++.h> 
using namespace std;

vector<string> get(int n){
    vector<string>str;
    if(n==1){
        str.push_back("0");
        str.push_back("1");
        return str;
    }
    vector<string>previous = get(n-1); //generate gray code of length n-1
    for(int i=0;i<previous.size();i++){ //generating the first half of sequence starting with '0'
        string s;
        s += "0";
        s += previous[i];
        str.push_back(s);
    }
    for(int i=previous.size()-1;i>=0;i--){ //Generating the second half of sequence starting with '1' -
        string s;                          //-starts from size - 1 so that last string starting with '0'-
        s += "1";                          //-and first string starting with '1' differ only in first bit.
        s += previous[i];
        str.push_back(s);
    }
    return str;
}

int main(){
    int n;
    cin >> n;
    vector<string>ans = get(n);
    for(string str:ans){
        cout << str << "\n";
    }
	return 0;
}