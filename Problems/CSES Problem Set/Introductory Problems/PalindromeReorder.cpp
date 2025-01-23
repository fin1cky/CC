/*
Approach : take an array of size 26 and count the instances of each letter in the string.
           if each letter occurs an even number of times and only one letter occurs an odd number of times, 
           a solution exists else NOT.
           Solution would be to print each letter half the times as the number of its instances, take the reverse
           of this string then print the letter that exists odd number of times and attach the reverse of the
           first part at the end.
*/

#include <bits/stdc++.h> 
using namespace std;

int main(){
    int letters[26] = {};
    string str;
    cin >> str;
    int oc = 0;
    for(int i=0;i<str.length();i++){
    	letters[str[i]-'A']++;
    }
    /*for(int i=0;i<26;i++){
        cout << letters[i] <<"\n";
    }*/
    string ans = "";
    int oi = -1;
    for(int i=0;i<26;i++){
    	if(letters[i]%2==1){
            oc++;
            if(oc>1){
                cout << "NO SOLUTION";
                return 0;
            }
            oi = i;
    	}
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<letters[i]/2;j++){
            ans+=char('A'+i);
        }
    }
    cout << ans;
    if(oi!=-1){
        cout << char('A'+oi);
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
	return 0;
}